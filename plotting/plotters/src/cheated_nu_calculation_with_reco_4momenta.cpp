#include "plotters.h"

void CheatedNuCalculationReco4MomentaPlotter::set_plotter_settings() {
	set_output_folder_name("nu_calculation_cheated_with_reco_4momenta");
}

void CheatedNuCalculationReco4MomentaPlotter::define_plots(){
	add_new_TH2D("nu_E", new TH2D("nu_E", "#nu calculation from MC info + reco 4momenta; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	// add_new_TH2D("nu_p", new TH2D("nu_p", "#nu calculation from MC info; p_{#nu}^{MC} [GeV]; p_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	// add_new_TH2D("nu_theta", new TH2D("nu_theta", "#nu calculation from MC info; #theta_{#nu}^{MC}; #theta_{#nu}^{calc from MC vertex}; #nu's", 32, 0, 3.2, 32, 0, 3.2) );
	// add_new_TH2D("nu_phi", new TH2D("nu_phi", "#nu calculation from MC info; #phi_{#nu}^{MC}; #phi_{#nu}^{calc from MC vertex}; #nu's", 32, -3.2, 3.2, 32, -3.2, 3.2) );
	//
	// add_new_TH1D("non-reconstructed_nu_parent_init_vertex", new TH1D("non-reconstructed_nu_parent_init_vertex", "Init. vertex radius of first parent of non-reconstructed #nu's; r_{parent}^{MC} [mm]; #nu's", 100, 0, 3000));
	// add_new_TH1D("non-reconstructed_nu_E", new TH1D("non-reconstructed_nu_E", "E of non-reconstructed #nu's; E_{#nu}^{MC} [GeV]; #nu's", 30, 0, 30));
	// add_new_TH1D("non-reconstructed_nu_theta", new TH1D("non-reconstructed_nu_theta", "#theta of non-reconstructed #nu's; #theta_{#nu}^{MC}; #nu's", 32, 0, 3.2) );
	// add_new_TH1D("non-reconstructed_nu_phi", new TH1D("non-reconstructed_nu_phi", "#phi of non-reconstructed #nu's; #phi_{#nu}^{MC}; #nu's", 32, -3.2, 3.2) );
	//
	// add_new_TH1D("reconstructed_nu_parent_init_vertex", new TH1D("reconstructed_nu_parent_init_vertex", "Init. vertex radius of first parent of reconstructed #nu's; r_{parent}^{MC} [mm]; #nu's", 100, 0, 3000));
	// add_new_TH2D("reconstructed_nu_E", new TH2D("reconstructed_nu_E", "#nu calculation from MC info, only reconstructed #nu's; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	// add_new_TH2D("reconstructed_nu_theta", new TH2D("reconstructed_nu_theta", "#nu calculation from MC info, only reconstructed #nu's; #theta_{#nu}^{MC}; #theta_{#nu}^{calc from MC vertex}; #nu's", 32, 0, 3.2, 32, 0, 3.2) );
	// add_new_TH2D("reconstructed_nu_phi", new TH2D("reconstructed_nu_phi", "#nu calculation from MC info, only reconstructed #nu's; #phi_{#nu}^{MC}; #phi_{#nu}^{calc from MC vertex}; #nu's", 32, -3.2, 3.2, 32, -3.2, 3.2) );
}

bool CheatedNuCalculationReco4MomentaPlotter::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

TLorentzVector CheatedNuCalculationReco4MomentaPlotter::get_nu_daughters_tlv( LepNuVertex* vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( isNeutrinoID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

TLorentzVector CheatedNuCalculationReco4MomentaPlotter::calculate_nus( LepNuVertex* vertex ){
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
		if ( daughter->was_reconstructed ) {
			std::cout << " Daughter MC ID: " << daughter->MC.pdg_ID << " Reco ID: " << daughter->Reco.pdg_ID << "\n";
			std::cout << " Daughter MC E: " << daughter->MC.tlv.E() << " Reco E: " << daughter->Reco.tlv.E() << "\n";
			std::cout << " Daughter MC px: " << daughter->MC.tlv.Vect()[0] << " Reco px: " << daughter->Reco.tlv.Vect()[0] << "\n";
			std::cout << " Daughter MC py: " << daughter->MC.tlv.Vect()[1] << " Reco py: " << daughter->Reco.tlv.Vect()[1] << "\n";
			std::cout << " Daughter MC pz: " << daughter->MC.tlv.Vect()[2] << " Reco pz: " << daughter->Reco.tlv.Vect()[2] << "\n";
			vis_tlv += daughter->Reco.tlv;
		} else {
			std::cout << " non-recod Daughter MC ID: " << daughter->MC.pdg_ID << "\n";
		}
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
	long double _C = std::pow( 2.*std::pow(vis_p_perp, 2) + std::pow(vis_m, 2) - std::pow(parents_m, 2), 2);
	long double _F = ( std::pow( vis_p_parallel, 2 ) * _C - 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D ) + _D * _C;

	std::cout << "\n\n _A " << _A<< " _D " << _D<< " _C " << _C<< " _F " << _F <<"\n";
	std::cout << " 1 " <<std::pow( vis_p_parallel, 2 ) * _C << " 2 " << 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D<< " 3 " << _D * _C<<"\n";
	std::cout << "vis_E " << vis_E<< " vis_p_parallel " << vis_p_parallel<< " vis_p_perp " << vis_p_perp<< " vis_m " << vis_m<< " parents_m " << parents_m <<"\n";
	if ( _D < 0.000001 )  { std::cout << "WARNING: _D too small: " << _D << " -> neutrino not reconstructed.\n"; }
	else if ( _F < 0 ) {
		std::cout << "WARNING: Value under square root negative: " << _F << " -> neutrino not reconstructed.\n";
	}	else {
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

	return nu_tlv;
}

void CheatedNuCalculationReco4MomentaPlotter::fill_plots(){
	float weight = get_current_weight();

	int i=1;
	// This is the loop over all events
	while ( get_next_event() ) {
		int N_vertices = (evt_info->total_event.lep_nu_vertices).GetEntries();
		std::cout << i++ << "\n";
		for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
			LepNuVertex* vertex = (LepNuVertex*)evt_info->total_event.lep_nu_vertices[i_vertex];
			TLorentzVector nu_tlv_calculated = calculate_nus( vertex );
			TLorentzVector nu_tlv_true = get_nu_daughters_tlv( vertex );
			std::cout << "nu: true: " << nu_tlv_true.E() << " calc: " << nu_tlv_calculated.E() << " Init_vertex position:" << ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag() << " \n\n";
			get_TH2D("nu_E")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), weight);
			// get_TH2D("nu_p")->Fill(nu_tlv_true.P(), nu_tlv_calculated.P(), weight);
			// get_TH2D("nu_theta")->Fill(nu_tlv_true.Theta(), nu_tlv_calculated.Theta(), weight);
			// get_TH2D("nu_phi")->Fill(nu_tlv_true.Phi(), nu_tlv_calculated.Phi(), weight);
			//
			// if ( nu_tlv_calculated.E() == 0 ) {
			// 	get_TH1D("non-reconstructed_nu_parent_init_vertex")->Fill(((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(), weight);
			// 	get_TH1D("non-reconstructed_nu_E")->Fill(nu_tlv_true.E(), weight);
			// 	get_TH1D("non-reconstructed_nu_theta")->Fill(nu_tlv_true.Theta(), weight);
			// 	get_TH1D("non-reconstructed_nu_phi")->Fill(nu_tlv_true.Phi(), weight);
			// } else {
			// 	get_TH1D("reconstructed_nu_parent_init_vertex")->Fill(((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(), weight);
			// 	get_TH2D("reconstructed_nu_E")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), weight);
			// 	get_TH2D("reconstructed_nu_theta")->Fill(nu_tlv_true.Theta(), nu_tlv_calculated.Theta(), weight);
			// 	get_TH2D("reconstructed_nu_phi")->Fill(nu_tlv_true.Phi(), nu_tlv_calculated.Phi(), weight);
			// }
		}
	}
}

void CheatedNuCalculationReco4MomentaPlotter::draw_plots(){
	// std::string output_dir = get_output_directory();
	//
	// TCanvas* c_parent_init_vertices = new TCanvas("parent_init_vertices", "", 0, 0, 800, 900);
	// TLegend* vertices_leg = new TLegend(0.35, 0.7, 0.9, 0.9);
	// TH1D* non_reco_nu_parent_vertices = get_TH1D("non-reconstructed_nu_parent_init_vertex");
	// TH1D* reco_nu_parent_vertices = get_TH1D("reconstructed_nu_parent_init_vertex");
	// non_reco_nu_parent_vertices->SetLineColor(kRed);
	// reco_nu_parent_vertices->SetLineColor(kBlue);
	// vertices_leg->AddEntry(non_reco_nu_parent_vertices, "non-reconstructed #nu's", "l");
	// vertices_leg->AddEntry(reco_nu_parent_vertices, "reconstructed #nu's", "l");
	// reco_nu_parent_vertices->GetYaxis()->SetTitleOffset(1.4);
	// reco_nu_parent_vertices->Draw("hist");
	// non_reco_nu_parent_vertices->Draw("hist same");
	// c_parent_init_vertices->SetLeftMargin(0.2);
	// vertices_leg->Draw();
	// c_parent_init_vertices->Print((output_dir + "/parent_vertices.pdf").c_str());
	// delete c_parent_init_vertices;
	//
	// for (int i=0; i<get_number_TH2Ds(); i++) {
	// 	TH2D* current_h2 = get_TH2D_i(i);
	// 	TCanvas* current_canvas = new TCanvas(( std::string() + current_h2->GetName() + "_can").c_str(), "", 0, 0, 800, 800);
	// 	current_h2->Draw("colz");
	// 	current_canvas->SetRightMargin(0.2);
	// 	current_canvas->Print(( output_dir + "/h2_" + current_h2->GetName() + ".pdf").c_str());
	// 	delete current_canvas;
	// }
	// reco_nu_parent_vertices->GetYaxis()->SetTitleOffset(1.4);
	// c_parent_init_vertices->SetLeftMargin(0.2);
	//
	// TCanvas* c_nonreco_nu_E = new TCanvas("can_nonreco_nu_E", "", 0, 0, 800, 900);
	// TH1D* nonreco_nu_E = get_TH1D("non-reconstructed_nu_E");
	// nonreco_nu_E->Draw("hist");
	// nonreco_nu_E->GetYaxis()->SetTitleOffset(1.4);
	// c_nonreco_nu_E->SetLeftMargin(0.2);
	// c_nonreco_nu_E->Print((output_dir + "/h1_nonreco_nu_E.pdf").c_str());
	// delete c_nonreco_nu_E;
	//
	// TCanvas* c_nonreco_nu_theta = new TCanvas("can_nonreco_nu_theta", "", 0, 0, 800, 900);
	// TH1D* nonreco_nu_theta = get_TH1D("non-reconstructed_nu_theta");
	// nonreco_nu_theta->Draw("hist");
	// c_nonreco_nu_theta->Print((output_dir + "/h1_nonreco_nu_theta.pdf").c_str());
	// delete c_nonreco_nu_theta;
	//
	// TCanvas* c_nonreco_nu_phi = new TCanvas("can_nonreco_nu_phi", "", 0, 0, 800, 900);
	// TH1D* nonreco_nu_phi = get_TH1D("non-reconstructed_nu_phi");
	// nonreco_nu_phi->Draw("hist");
	// c_nonreco_nu_phi->Print((output_dir + "/h1_nonreco_nu_phi.pdf").c_str());
	// delete c_nonreco_nu_phi;

}
