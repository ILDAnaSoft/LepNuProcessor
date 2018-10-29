#include "plotters.h"

void NuCalculationPOPGuessedGammaPlotter::set_plotter_settings() {
	set_output_folder_name("nu_calculation_pop_guessed_gamma");
}

void NuCalculationPOPGuessedGammaPlotter::define_plots(){
	add_new_TH1D("N_vertices", new TH1D("N_vertices", "Number of ch. lep. + #nu vertices in event; N_{l-#nu vertices}; Event", 7, -0.5, 6.5));

	add_new_TH2D("nu_E", new TH2D("nu_E", "#nu calculation from MC info; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_p", new TH2D("nu_p", "#nu calculation from MC info; p_{#nu}^{MC} [GeV]; p_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_theta", new TH2D("nu_theta", "#nu calculation from MC info; #theta_{#nu}^{MC}; #theta_{#nu}^{calc from MC vertex}; #nu's", 32, 0, 3.2, 32, 0, 3.2) );
	add_new_TH2D("nu_phi", new TH2D("nu_phi", "#nu calculation from MC info; #phi_{#nu}^{MC}; #phi_{#nu}^{calc from MC vertex}; #nu's", 32, -3.2, 3.2, 32, -3.2, 3.2) );

	add_new_TH1D("non-reconstructed_nu_parent_init_vertex", new TH1D("non-reconstructed_nu_parent_init_vertex", "Init. vertex radius of first parent of non-reconstructed #nu's; r_{parent}^{MC} [mm]; #nu's", 100, 0, 3000));
	add_new_TH1D("non-reconstructed_nu_E", new TH1D("non-reconstructed_nu_E", "E of non-reconstructed #nu's; E_{#nu}^{MC} [GeV]; #nu's", 30, 0, 30));
	add_new_TH1D("non-reconstructed_nu_theta", new TH1D("non-reconstructed_nu_theta", "#theta of non-reconstructed #nu's; #theta_{#nu}^{MC}; #nu's", 32, 0, 3.2) );
	add_new_TH1D("non-reconstructed_nu_phi", new TH1D("non-reconstructed_nu_phi", "#phi of non-reconstructed #nu's; #phi_{#nu}^{MC}; #nu's", 32, -3.2, 3.2) );

	add_new_TH1D("reconstructed_nu_parent_init_vertex", new TH1D("reconstructed_nu_parent_init_vertex", "Init. vertex radius of first parent of reconstructed #nu's; r_{parent}^{MC} [mm]; #nu's", 100, 0, 3000));
	add_new_TH2D("reconstructed_nu_E", new TH2D("reconstructed_nu_E", "#nu calculation from MC info, only reconstructed #nu's; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("reconstructed_nu_theta", new TH2D("reconstructed_nu_theta", "#nu calculation from MC info, only reconstructed #nu's; #theta_{#nu}^{MC}; #theta_{#nu}^{calc from MC vertex}; #nu's", 32, 0, 3.2, 32, 0, 3.2) );
	add_new_TH2D("reconstructed_nu_phi", new TH2D("reconstructed_nu_phi", "#nu calculation from MC info, only reconstructed #nu's; #phi_{#nu}^{MC}; #phi_{#nu}^{calc from MC vertex}; #nu's", 32, -3.2, 3.2, 32, -3.2, 3.2) );


	add_new_TH2D("nu_E_Bparents_only", new TH2D("nu_E_Bparents_only", "#nu calculation from MC info, only B parents; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex", new TH2D("nu_E_Bparents_only_0vertex", "#nu calculation from MC info, only B parents starting at 0; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr5", new TH2D("nu_E_Bparents_only_0vertex_visEgr5", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>5; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr10", new TH2D("nu_E_Bparents_only_0vertex_visEgr10", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>10; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr15", new TH2D("nu_E_Bparents_only_0vertex_visEgr15", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>15; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr20", new TH2D("nu_E_Bparents_only_0vertex_visEgr20", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>20; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr30", new TH2D("nu_E_Bparents_only_0vertex_visEgr30", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>30; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr50", new TH2D("nu_E_Bparents_only_0vertex_visEgr50", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>50; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );

	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr5", new TH2D("nu_E_Bparents_only_0vertex_lepEgr5", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>5; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr10", new TH2D("nu_E_Bparents_only_0vertex_lepEgr10", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>10; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr15", new TH2D("nu_E_Bparents_only_0vertex_lepEgr15", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>15; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr20", new TH2D("nu_E_Bparents_only_0vertex_lepEgr20", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>20; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr30", new TH2D("nu_E_Bparents_only_0vertex_lepEgr30", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>30; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr50", new TH2D("nu_E_Bparents_only_0vertex_lepEgr50", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>50; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );


	add_new_TH2D("E_deviations", new TH2D("E_deviations", "Mis-calculation VS difference of calc. E from vis. E (B only, 0 vertex); (E_{#nu}^{calc} - E_{vis})/E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 150, -1.50, 1.50, 200, -150, 50) );
	add_new_TH2D("E_deviations_lepE5cut", new TH2D("E_deviations_lepE5cut", "Mis-calculation VS difference of calc. E from vis. E (B only, 0 vertex, E_{lep}>5); (E_{#nu}^{calc} - E_{vis})/E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 150, -1.50, 1.50, 200, -150, 50) );
	add_new_TH2D("E_deviations_visE", new TH2D("E_deviations_visE", "Mis-calculation VS vis. E (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 110, 0, 110, 200, -150, 50) );
	add_new_TH2D("E_deviations_lepE", new TH2D("E_deviations_lepE", "Mis-calculation VS ch. lep. E (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 110, 0, 110, 200, -150, 50) );
	add_new_TH2D("E_deviations_lepEpercentage", new TH2D("E_deviations_lepEpercentage", "Mis-calculation VS ch. lep. E percentage (B only, 0 vertex); E_{lep} / E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 100, 0, 1.0, 200, -150, 50) );
	add_new_TH2D("E_deviations_lepPDG", new TH2D("E_deviations_lepPDG", "Mis-calculation VS ch. lep. PDG (abs) (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 8, 10.5, 18.5, 200, -150, 50) );
	add_new_TH2D("E_deviations_nuTheta", new TH2D("E_deviations_nuTheta", "Mis-calculation VS #theta_{#nu}^{calc} (B only, 0 vertex); #theta_{#nu}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 32, 0, 3.2, 200, -150, 50) );
	add_new_TH2D("E_deviations_correctedE", new TH2D("E_deviations_correctedE", "Mis-calculation VS E_{corrected} (B only, 0 vertex); E_{corrected}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 250, 0, 250, 200, -150, 50) );
	add_new_TH2D("E_deviations_Ndaughters", new TH2D("E_deviations_Ndaughters", "Mis-calculation VS N_{daughters} (B only, 0 vertex); N_{daughters}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 5, 0.5, 5.5, 200, -150, 50) );
	add_new_TH2D("E_deviations_Bboost", new TH2D("E_deviations_Bboost", "Mis-calculation VS B boost (B only, 0 vertex); #gamma_{B}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 64, 1, 65, 200, -150, 50) );
	add_new_TH2D("E_deviations_Bmagnitude", new TH2D("E_deviations_Bmagnitude", "Mis-calculation VS B magnitude (B only, 0 vertex); |l_{B}^{MC}| [mm]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 20, 0, 20, 200, -150, 50) );

	add_new_TH2D("p_nu_parallel_vs_Bboost", new TH2D("p_nu_parallel_vs_Bboost", "#nu mom. parallel B VS B boost, (B only, 0 vertex); #gamma_{B}; p_{#nu}^{parallel} [GeV]; #nu's", 30, 1, 60, 150,-50, 250) );

	add_new_TH1D("B_magnitude", new TH1D("B_magnitude", "magnitude of B endpoint; |l_{B}| [mm]; Event", 100, 0, 10));
	add_new_TH2D("B_E_vs_B_magnitude", new TH2D("B_E_vs_B_magnitude", "B energy VS magnitude of B endpoint; |l_{B}^{MC}| [mm]; E_{B}^{MC}; Event", 40, 0, 4, 200, 0, 200));

	add_new_TH2D("E_deviations_visPperp", new TH2D("E_deviations_visPperp", "Mis-calculation VS ch. visible perp. mom. (B only, 0 vertex); p_{vis}^{perp} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 30, 0, 3, 200, -150, 50) );
	add_new_TH2D("E_deviations_visPratio", new TH2D("E_deviations_visPratio", "Mis-calculation VS ch. visible mom. perp./par. ratio (B only, 0 vertex); p_{vis}^{perp}/ p_{vis}^{par}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 50, 0, 0.5, 200, -150, 50) );
	add_new_TH2D("Bboost_visPratio", new TH2D("Bboost_visPratio", "B boost VS ch. visible mom. perp./par. ratio (B only, 0 vertex); p_{vis}^{perp}/ p_{vis}^{par}; #gamma_{B}; #nu's", 50, 0, 0.5, 20, 0, 20) );
}

bool NuCalculationPOPGuessedGammaPlotter::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

TLorentzVector NuCalculationPOPGuessedGammaPlotter::get_nu_daughters_tlv( LepNuVertex* vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( isNeutrinoID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

TLorentzVector NuCalculationPOPGuessedGammaPlotter::get_vis_tlv( LepNuVertex* vertex ){
	// Get non-nu daughter tlvs ( = "visible part of vertex")
	TLorentzVector vis_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( ! isNeutrinoID(daughter->MC.pdg_ID) ) { vis_tlv += daughter->MC.tlv; }
	}
	return vis_tlv;
}

TLorentzVector NuCalculationPOPGuessedGammaPlotter::get_charged_leptons_tlv( LepNuVertex* vertex ){
	TLorentzVector charged_lep_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { charged_lep_tlv += daughter->MC.tlv; }
	}
	return charged_lep_tlv;
}

int NuCalculationPOPGuessedGammaPlotter::get_first_charged_lepton_pdg( LepNuVertex* vertex ){
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { return daughter->MC.pdg_ID; }
	}
}

TLorentzVector NuCalculationPOPGuessedGammaPlotter::calculate_nus_from_MC( LepNuVertex* vertex ){
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
	TLorentzVector vis_tlv = get_vis_tlv(vertex);

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

	if ( _D < 0.000001 )  { std::cout << "WARNING: _D too small: " << _D << " -> neutrino not reconstructed.\n"; }
	else if ( _F < 0 ) {
		std::cout << "WARNING: Value under square root negative: " << _F << " -> neutrino not reconstructed.\n";
		// std::cout << "\n\n _A " << _A<< " _D " << _D<< " _C " << _C<< " _F " << _F <<"\n";
		// std::cout << " 1 " <<std::pow( vis_p_parallel, 2 ) * _C << " 2 " << 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D<< " 3 " << _D * _C<<"\n";
		// std::cout << "vis_E " << vis_E<< " vis_p_parallel " << vis_p_parallel<< " vis_p_perp " << vis_p_perp<< " vis_m " << vis_m<< " parents_m " << parents_m <<"\n";
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


		long double a = 0.0956;
		long double b = 1.0;
		long double x = vis_p_parallel/vis_E;
		long double guess_beta_B = ( a - b*x ) / ( a*b*x -1 );

		long double guess_gamma_B = 1.0 / std::sqrt(1-std::pow(guess_beta_B,2));

		if ( fabs(guess_gamma_B - tlv_total_plus.Gamma()) < fabs(guess_gamma_B - tlv_total_minus.Gamma()) ) {
			nu_tlv = nu_tlv_plus;
		} else {
			nu_tlv = nu_tlv_minus;
		}

		// long double guess_gamma_B = 946 / std::pow(vis_p_perp/vis_p_parallel, 0.00293) - 948;
		// if (guess_gamma_B < 0) { guess_gamma_B = 0; }
		//
		// if ( fabs(guess_gamma_B - tlv_total_plus.Gamma()) < fabs(guess_gamma_B - tlv_total_minus.Gamma()) ) {
		// 	nu_tlv = nu_tlv_plus;
		// } else {
		// 	nu_tlv = nu_tlv_minus;
		// }
		//
		// long double nu_E_relative_contribution = (nu_tlv.E()-vis_E)/vis_E;
		// if (nu_E_relative_contribution < -0.7) {
		// 	std::cout << nu_E_relative_contribution << "\n";
		// 	nu_tlv = nu_tlv_plus;
		// }


	}

	return nu_tlv;
}

void NuCalculationPOPGuessedGammaPlotter::fill_plots(){
	float weight = get_current_weight();

	// int i=1;
	// This is the loop over all events
	while ( get_next_event() ) {
		int N_vertices = (evt_info->total_event.lep_nu_vertices).GetEntries();
		// std::cout << i++ << "\n";
		get_TH1D("N_vertices")->Fill(N_vertices, 1);
		for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
			LepNuVertex* vertex = (LepNuVertex*)evt_info->total_event.lep_nu_vertices[i_vertex];
			TLorentzVector nu_tlv_calculated = calculate_nus_from_MC( vertex );
			TLorentzVector nu_tlv_true = get_nu_daughters_tlv( vertex );
			//std::cout << "nu: true: " << nu_tlv_true.E() << " calc: " << nu_tlv_calculated.E() << " Init_vertex position:" << ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag() << " \n\n";
			get_TH2D("nu_E")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
			get_TH2D("nu_p")->Fill(nu_tlv_true.P(), nu_tlv_calculated.P(), 1);
			get_TH2D("nu_theta")->Fill(nu_tlv_true.Theta(), nu_tlv_calculated.Theta(), 1);
			get_TH2D("nu_phi")->Fill(nu_tlv_true.Phi(), nu_tlv_calculated.Phi(), 1);

			if ( nu_tlv_calculated.E() == 0 ) {
				get_TH1D("non-reconstructed_nu_parent_init_vertex")->Fill(((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(), 1);
				get_TH1D("non-reconstructed_nu_E")->Fill(nu_tlv_true.E(), 1);
				get_TH1D("non-reconstructed_nu_theta")->Fill(nu_tlv_true.Theta(), 1);
				get_TH1D("non-reconstructed_nu_phi")->Fill(nu_tlv_true.Phi(), 1);
			} else {
				get_TH1D("reconstructed_nu_parent_init_vertex")->Fill(((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(), 1);
				get_TH2D("reconstructed_nu_E")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
				get_TH2D("reconstructed_nu_theta")->Fill(nu_tlv_true.Theta(), nu_tlv_calculated.Theta(), 1);
				get_TH2D("reconstructed_nu_phi")->Fill(nu_tlv_true.Phi(), nu_tlv_calculated.Phi(), 1);
			}

			TLorentzVector vis_tlv = get_vis_tlv(vertex);
			float vis_vertex_E = vis_tlv.E();

			int first_parent_pdg = ((Particle*)((vertex->vertex_parents)[0]))->MC.pdg_ID;
			// if ( fabs(first_parent_pdg) == 511 || fabs(first_parent_pdg) == 521 || fabs(first_parent_pdg) == 531 ) {
      if ( ( fabs(first_parent_pdg) >= 500 && fabs(first_parent_pdg) < 600 ) || ( fabs(first_parent_pdg) >= 5000 && fabs(first_parent_pdg) < 6000 ) ) { 

				get_TH2D("nu_E_Bparents_only")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
				float parent_init_pos = ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(); // TODO Adjust to non-zero init vertex
				if ( parent_init_pos < 1.0 ) {
					get_TH2D("nu_E_Bparents_only_0vertex")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					if ( vis_vertex_E > 5.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr5")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( vis_vertex_E > 10.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr10")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( vis_vertex_E > 15.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr15")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( vis_vertex_E > 20.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr20")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( vis_vertex_E > 30.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr30")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( vis_vertex_E > 50.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr50")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}

					float charged_leps_vertex_E = (get_charged_leptons_tlv(vertex)).E();
					if ( charged_leps_vertex_E > 5.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr5")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
						get_TH2D("E_deviations_lepE5cut")->Fill((nu_tlv_calculated.E()-vis_vertex_E)/vis_vertex_E, nu_tlv_calculated.E()-nu_tlv_true.E(), 1);
					}
					if ( charged_leps_vertex_E > 10.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr10")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( charged_leps_vertex_E > 15.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr15")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( charged_leps_vertex_E > 20.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr20")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( charged_leps_vertex_E > 30.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr30")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					if ( charged_leps_vertex_E > 50.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr50")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					}
					get_TH2D("E_deviations")->Fill((nu_tlv_calculated.E()-vis_vertex_E)/vis_vertex_E, nu_tlv_calculated.E()-nu_tlv_true.E(), 1);
					get_TH2D("E_deviations_visE")->Fill(vis_vertex_E, nu_tlv_calculated.E()-nu_tlv_true.E(), 1);
					get_TH2D("E_deviations_lepE")->Fill(charged_leps_vertex_E, nu_tlv_calculated.E()-nu_tlv_true.E(), 1);
					get_TH2D("E_deviations_lepEpercentage")->Fill(charged_leps_vertex_E/vis_vertex_E, nu_tlv_calculated.E()-nu_tlv_true.E(), 1);
					get_TH2D("E_deviations_nuTheta")->Fill(nu_tlv_calculated.Theta(), nu_tlv_calculated.E()-nu_tlv_true.E(), 1);
					get_TH2D("E_deviations_correctedE")->Fill( nu_tlv_calculated.E()+vis_vertex_E, nu_tlv_calculated.E()-nu_tlv_true.E(), 1);

					int first_lep_pdg = get_first_charged_lepton_pdg(vertex);
					get_TH2D("E_deviations_lepPDG")->Fill(fabs(first_lep_pdg), nu_tlv_calculated.E()-nu_tlv_true.E(), 1);

					int N_daughters = (vertex->vertex_daughters).GetEntries();
					get_TH2D("E_deviations_Ndaughters")->Fill( N_daughters, nu_tlv_calculated.E()-nu_tlv_true.E(), 1);

					get_TH2D("E_deviations_Bboost")->Fill( ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), nu_tlv_calculated.E()-nu_tlv_true.E(), 1);
					get_TH2D("p_nu_parallel_vs_Bboost")->Fill( ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), (nu_tlv_calculated.Vect()).Dot(((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Unit()), 1);

					get_TH1D("B_magnitude")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), 1 );
					get_TH2D("B_E_vs_B_magnitude")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.E(), 1 );

					get_TH2D("E_deviations_Bmagnitude")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), nu_tlv_calculated.E()-nu_tlv_true.E(), 1);

					{
						TVector3 init_direction = ((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Unit();
						float vis_p_parallel = vis_tlv.Vect().Dot(init_direction);
						TVector3 perp_to_init = ( vis_tlv.Vect() - vis_p_parallel*init_direction ).Unit();
						long double vis_p_perp = vis_tlv.Vect().Dot( perp_to_init );
						get_TH2D("E_deviations_visPperp")->Fill( vis_p_perp, nu_tlv_calculated.E()-nu_tlv_true.E(), 1 );
						get_TH2D("E_deviations_visPratio")->Fill( vis_p_perp/vis_p_parallel, nu_tlv_calculated.E()-nu_tlv_true.E(), 1 );
						get_TH2D("Bboost_visPratio")->Fill( vis_p_perp/vis_p_parallel, ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), 1 );
					}
				}
			}

		}
	}
}

void NuCalculationPOPGuessedGammaPlotter::draw_plots(){
	std::string output_dir = get_output_directory();

	TCanvas* c_parent_init_vertices = new TCanvas("parent_init_vertices", "", 0, 0, 800, 900);
	TLegend* vertices_leg = new TLegend(0.35, 0.7, 0.9, 0.9);
	TH1D* non_reco_nu_parent_vertices = get_TH1D("non-reconstructed_nu_parent_init_vertex");
	TH1D* reco_nu_parent_vertices = get_TH1D("reconstructed_nu_parent_init_vertex");
	non_reco_nu_parent_vertices->SetLineColor(kRed);
	reco_nu_parent_vertices->SetLineColor(kBlue);
	vertices_leg->AddEntry(non_reco_nu_parent_vertices, "non-reconstructed #nu's", "l");
	vertices_leg->AddEntry(reco_nu_parent_vertices, "reconstructed #nu's", "l");
	reco_nu_parent_vertices->GetYaxis()->SetTitleOffset(1.4);
	reco_nu_parent_vertices->Draw("hist");
	non_reco_nu_parent_vertices->Draw("hist same");
	c_parent_init_vertices->SetLeftMargin(0.2);
	vertices_leg->Draw();
	c_parent_init_vertices->Print((output_dir + "/parent_vertices.pdf").c_str());
	// delete c_parent_init_vertices;

	for (int i=0; i<get_number_TH2Ds(); i++) {
		TH2D* current_h2 = get_TH2D_i(i);
		TCanvas* current_canvas = new TCanvas(( std::string() + current_h2->GetName() + "_can").c_str(), "", 0, 0, 800, 800);
		current_h2->Draw("colz");
		current_canvas->SetRightMargin(0.2);
		current_canvas->Print(( output_dir + "/h2_" + current_h2->GetName() + ".pdf").c_str());
		// delete current_canvas;
	}
	reco_nu_parent_vertices->GetYaxis()->SetTitleOffset(1.4);
	c_parent_init_vertices->SetLeftMargin(0.2);

	TCanvas* c_nonreco_nu_E = new TCanvas("can_nonreco_nu_E", "", 0, 0, 800, 900);
	TH1D* nonreco_nu_E = get_TH1D("non-reconstructed_nu_E");
	nonreco_nu_E->Draw("hist");
	nonreco_nu_E->GetYaxis()->SetTitleOffset(1.4);
	c_nonreco_nu_E->SetLeftMargin(0.2);
	c_nonreco_nu_E->Print((output_dir + "/h1_nonreco_nu_E.pdf").c_str());
	// delete c_nonreco_nu_E;

	TCanvas* c_nonreco_nu_theta = new TCanvas("can_nonreco_nu_theta", "", 0, 0, 800, 900);
	TH1D* nonreco_nu_theta = get_TH1D("non-reconstructed_nu_theta");
	nonreco_nu_theta->Draw("hist");
	c_nonreco_nu_theta->Print((output_dir + "/h1_nonreco_nu_theta.pdf").c_str());
	// delete c_nonreco_nu_theta;

	TCanvas* c_nonreco_nu_phi = new TCanvas("can_nonreco_nu_phi", "", 0, 0, 800, 900);
	TH1D* nonreco_nu_phi = get_TH1D("non-reconstructed_nu_phi");
	nonreco_nu_phi->Draw("hist");
	c_nonreco_nu_phi->Print((output_dir + "/h1_nonreco_nu_phi.pdf").c_str());
	// delete c_nonreco_nu_phi;

}
