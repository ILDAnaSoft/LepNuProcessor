#include "plotters.h"

void NuCalculationPOPPlotter::set_plotter_settings() {
	set_output_folder_name("nu_calculation_pop");
}

void NuCalculationPOPPlotter::define_plots(){
	add_new_TH1D("N_vertices", new TH1D("N_vertices", "Number of ch. lep. + #nu vertices in event; N_{l-#nu vertices}; Event", 7, -0.5, 6.5));

	add_new_TH2D("nu_E", new TH2D("nu_E", "#nu calculation from MC info; E_{#nu}^{MC}; E_{#nu}^{calc from MC vertex}; #nu's", 200, 0, 200, 200, 0, 200) );
}

bool NuCalculationPOPPlotter::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

TLorentzVector NuCalculationPOPPlotter::get_nu_daughters_tlv( LepNuVertex* vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( isNeutrinoID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

TLorentzVector NuCalculationPOPPlotter::calculate_nus_from_MC( LepNuVertex* vertex ){
	/* Take:
			- direction from initial vertex
			- initial mass from parent MC info
			- non-neutrino 4vector from daughter MCs
		-> Try to reconstruct neutrino 4vector
	*/

	TLorentzVector nu_tlv {};

	// Get invariant mass of parents:
	int N_parents = (vertex->vertex_parents).GetEntries();
	TLorentzVector parents_tlv {};
	for (int i_parent = 0; i_parent<N_parents; i_parent++) {
		parents_tlv += ( (Particle*)(vertex->vertex_parents)[i_parent] )->MC.tlv;
	}
	long double parents_m = parents_tlv.M();

	// Get (unit) direction of initial particles using difference of starting vertex form 0 position:
	TVector3 init_direction = ((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Unit();

	// Get non-nu daughter tlvs ( = "visible part of vertex")
	TLorentzVector vis_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( ! isNeutrinoID(daughter->MC.pdg_ID) ) { vis_tlv += daughter->MC.tlv; }
	}

	long double vis_E = vis_tlv.E();
	TVector3 vis_p = vis_tlv.Vect();
	long double vis_m = vis_tlv.M();
	// Get visible component parallel to assumed direction of parents
	long double vis_p_parallel = vis_p.Dot(init_direction);
	// Get visible component perpendicular to assumed direction of parents
	TVector3 perp_to_init = ( vis_p - vis_p_parallel*init_direction ).Unit();
	long double vis_p_perp = vis_p.Dot( perp_to_init );


	// Momentum and energy conservation -> Calculation of nu 4vector
	long double _D = std::pow( vis_E, 2 ) - std::pow( vis_p_parallel, 2 );
	long double _A = vis_p_parallel * ( 2.* std::pow(vis_p_perp, 2) + std::pow(vis_m, 2) - std::pow(parents_m, 2) );
	//long double _B = 4* std::pow(vis_p_perp, 2) * std::pow(vis_E, 2) - std::pow( ( 2*std::pow(vis_p_perp, 2) + std::pow(vis_m, 2) - std::pow(parents_m, 2) ), 2 );
	long double _C = std::pow( 2.*std::pow(vis_p_perp, 2) + std::pow(vis_m, 2) - std::pow(parents_m, 2), 2);
	long double _F = ( std::pow( vis_p_parallel, 2 ) * _C - 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D ) + _D * _C;
	std::cout << "\n\n _A " << _A<< " _D " << _D<< " _C " << _C<< " _F " << _F <<"\n";
	std::cout << " 1 " <<std::pow( vis_p_parallel, 2 ) * _C << " 2 " << 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D<< " 3 " << _D * _C<<"\n";

	std::cout << "vis_E " << vis_E<< " vis_p_parallel " << vis_p_parallel<< " vis_p_perp " << vis_p_perp<< " vis_m " << vis_m<< " parents_m " << parents_m <<"\n";
	// std::cout << "nu_p_parallel " << nu_p_parallel<< " nu_p_perp " << nu_p_perp<<"\n";


	std::cout << " o1: " <<   ( std::pow( vis_p_parallel, 2 ) * _C - 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D ) + _D * _C<< "\n";
	std::cout << " o2: " <<   ( std::pow( vis_p_parallel, 2 ) * _C + 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D ) + _D * _C<< "\n";
	std::cout << " o3: " <<   ( std::pow( vis_p_parallel, 2 ) * _C - 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D ) - _D * _C<< "\n";
	std::cout << " o4: " <<   ( std::pow( vis_p_parallel, 2 ) * _C + 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D ) - _D * _C<< "\n";

	if ( _D < 0.000001 )  { std::cout << "WARNING: _D too small: " << _D << " -> neutrino not reconstructed.\n"; }
	else if ( _F < 0 ) { std::cout << "WARNING: Value under square root negative: " << _F << " -> neutrino not reconstructed.\n"; }
	else {
		long double nu_p_perp = - vis_p_perp;

		// Quadratic equation has two solutions:
		long double nu_p_parallel_plus = 1./( 2. * _D ) * ( - _A + sqrt( _F ) );
		TVector3 nu_p_plus = nu_p_parallel_plus * init_direction + nu_p_perp * perp_to_init;
		long double nu_E_plus = nu_p_plus.Mag(); // Assume nu massless :P
		TLorentzVector nu_tlv_plus = TLorentzVector( nu_p_plus, nu_E_plus );

		long double nu_p_parallel_minus = 1./( 2. * _D ) * ( - _A - sqrt( _F ) );
		TVector3 nu_p_minus = nu_p_parallel_minus * init_direction + nu_p_perp * perp_to_init;
		long double nu_E_minus = nu_p_minus.Mag();
		TLorentzVector nu_tlv_minus = TLorentzVector( nu_p_minus, nu_E_minus );

		// Choose better solution:
		TLorentzVector tlv_total_plus = nu_tlv_plus + vis_tlv;
		long double m_total_plus = tlv_total_plus.M();

		TLorentzVector tlv_total_minus = nu_tlv_minus + vis_tlv;
		long double m_total_minus = tlv_total_minus.M();

		if ( fabs(m_total_plus - parents_m) < fabs(m_total_minus - parents_m) ) {
			nu_tlv = nu_tlv_plus;
		} else {
			nu_tlv = nu_tlv_minus;
		}


	}

// TLorentzVector nu_tlv_true = get_nu_daughters_tlv( vertex );
// TVector3 true_nu_3vec = TVector3( nu_tlv_true[0],nu_tlv_true[1],nu_tlv_true[2]);//nu_tlv_true.Vect();
//  std::cout << " True: p_par: " << true_nu_3vec.Dot(init_direction) << " p_perp: " << true_nu_3vec.Dot(perp_to_init)<< "\n";



	return nu_tlv;
}

void NuCalculationPOPPlotter::fill_plots(){
	float weight = get_current_weight();

	int i=0;
	// This is the loop over all events
	while ( get_next_event() ) {
		int N_vertices = (evt_info->total_event.lep_nu_vertices).GetEntries();
		get_TH1D("N_vertices")->Fill(N_vertices, weight);
		std::cout << i++ << "\n"; 
		for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
			LepNuVertex* vertex = (LepNuVertex*)evt_info->total_event.lep_nu_vertices[i_vertex];
			TLorentzVector nu_tlv_calculated = calculate_nus_from_MC( vertex );
			TLorentzVector nu_tlv_true = get_nu_daughters_tlv( vertex );
			std::cout << "nu: true: " << nu_tlv_true.E() << " calc: " << nu_tlv_calculated.E() << " Init_vertex position:" << ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag() << " \n\n";
		}
	}
}

void NuCalculationPOPPlotter::draw_plots(){
	//std::string output_dir = get_output_directory();

	//TCanvas* c1 = new TCanvas("c1", "", 0, 0, 800, 800);
	//get_TH1D("test")->Draw();
	//c1->Print((output_dir + "/test.pdf").c_str());
}
