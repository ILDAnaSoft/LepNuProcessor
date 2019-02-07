#include "plotters.h"

void NuCalculationCheatedSignPOPPlotter::set_plotter_settings() {
	set_output_folder_name("nu_calculation_cheated_sign_pop");
}

void NuCalculationCheatedSignPOPPlotter::define_plots(){
	add_new_TH2D("nu_E", new TH2D("nu_E", "#splitline{#nu calculation from MC info,}{sign cheated}; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 20, 0, 20, 20, 0, 20) );
	add_new_TH2D("nu_E_Bparents_only_0vertex", new TH2D("nu_E_Bparents_only_0vertex", "#splitline{#nu calculation from MC info,}{cheated sign, only B parents starting at 0}; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 20, 0, 20, 20, 0, 20) );

	add_new_TH2D("p_nu_parallel_vs_Bboost", new TH2D("p_nu_parallel_vs_Bboost", "#splitline{#nu mom. parallel B VS B boost,}{cheated sign, (B only, 0 vertex)}; #gamma_{B}; p_{#nu}^{parallel} [GeV]; #nu's", 30, 1, 60, 150,-50, 100) );


	add_new_TH1D("deboosted_lep_rightsign_nu_DeltaR",
		new TH1D("deboosted_lep_rightsign_nu_DeltaR", "#DeltaR(lep, #nu) in parent rest system, right #nu sign; #DeltaR(lep,#nu); vertices", 40, 0, 4)
	);
	add_new_TH1D("deboosted_lep_wrongsign_nu_DeltaR",
		new TH1D("deboosted_lep_wrongsign_nu_DeltaR", "#DeltaR(lep, #nu) in parent rest system, wrong #nu sign; #DeltaR(lep,#nu); vertices", 40, 0, 4)
	);

	add_new_TH1D("with_vis_deboosted_lep_rightsign_nu_DeltaR",
		new TH1D("with_vis_deboosted_lep_rightsign_nu_DeltaR", "#DeltaR(lep, #nu) in system boosted with visible, right #nu sign; #DeltaR(lep,#nu); vertices", 40, 0, 4)
	);
	add_new_TH1D("with_vis_deboosted_lep_wrongsign_nu_DeltaR",
		new TH1D("with_vis_deboosted_lep_wrongsign_nu_DeltaR", "#DeltaR(lep, #nu) in system boosted with visible, wrong #nu sign; #DeltaR(lep,#nu); vertices", 40, 0, 4)
	);

	add_new_TH1D("with_calc_deboosted_lep_rightsign_nu_DeltaR",
		new TH1D("with_calc_deboosted_lep_rightsign_nu_DeltaR", "#DeltaR(lep, #nu) in system boosted with total calculated, right #nu sign; #DeltaR(lep,#nu); vertices", 40, 0, 4)
	);
	add_new_TH1D("with_calc_deboosted_lep_wrongsign_nu_DeltaR",
		new TH1D("with_calc_deboosted_lep_wrongsign_nu_DeltaR", "#DeltaR(lep, #nu) in system boosted with total calculated, wrong #nu sign; #DeltaR(lep,#nu); vertices", 40, 0, 4)
	);

	add_new_TH1D("deboosted_lep_rightsign_nu_angle",
		new TH1D("deboosted_lep_rightsign_nu_angle", "Angle(lep, #nu) in parent rest system, right #nu sign; Angle(lep,#nu); vertices", 64, 0, 3.2)
	);
	add_new_TH1D("deboosted_lep_wrongsign_nu_angle",
		new TH1D("deboosted_lep_wrongsign_nu_angle", "Angle(lep, #nu) in parent rest system, wrong #nu sign; Angle(lep,#nu); vertices",  64, 0, 3.2)
	);

	add_new_TH1D("with_vis_deboosted_lep_rightsign_nu_angle",
		new TH1D("with_vis_deboosted_lep_rightsign_nu_angle", "Angle(lep, #nu) in system boosted with visible, right #nu sign; Angle(lep,#nu); vertices", 64, 0, 3.2)
	);
	add_new_TH1D("with_vis_deboosted_lep_wrongsign_nu_angle",
		new TH1D("with_vis_deboosted_lep_wrongsign_nu_angle", "Angle(lep, #nu) in system boosted with visible, wrong #nu sign; Angle(lep,#nu); vertices",  64, 0, 3.2)
	);

	add_new_TH1D("with_calc_deboosted_lep_rightsign_nu_angle",
		new TH1D("with_calc_deboosted_lep_rightsign_nu_angle", "Angle(lep, #nu) in system boosted with total calculated, right #nu sign; Angle(lep,#nu); vertices", 64, 0, 3.2)
	);
	add_new_TH1D("with_calc_deboosted_lep_wrongsign_nu_angle",
		new TH1D("with_calc_deboosted_lep_wrongsign_nu_angle", "Angle(lep, #nu) in system boosted with total calculated, wrong #nu sign; Angle(lep,#nu); vertices",  64, 0, 3.2)
	);


	add_new_TH1D("with_wrongcalc_deboosted_lep_rightsign_nu_angle",
		new TH1D("with_wrongcalc_deboosted_lep_rightsign_nu_angle", "Angle(lep, right #nu) in system boosted with total wrong calculated; Angle(lep,#nu); vertices", 64, 0, 3.2)
	);
	add_new_TH1D("with_rightcalc_deboosted_lep_wrongsign_nu_angle",
		new TH1D("with_rightcalc_deboosted_lep_wrongsign_nu_angle", "Angle(lep, wrong #nu) in system boosted with total right calculated; Angle(lep,#nu); vertices",  64, 0, 3.2)
	);

}

bool NuCalculationCheatedSignPOPPlotter::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

TLorentzVector NuCalculationCheatedSignPOPPlotter::get_nu_daughters_tlv( LepNuVertex* vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( isNeutrinoID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

TLorentzVector NuCalculationCheatedSignPOPPlotter::get_charged_lepton_daughters_tlv( LepNuVertex *vertex ) {
	TLorentzVector charged_lep_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { charged_lep_tlv += daughter->MC.tlv; }
	}
	return charged_lep_tlv;
}

TLorentzVector NuCalculationCheatedSignPOPPlotter::get_vis_tlv( LepNuVertex* vertex ){
	// Get non-nu daughter tlvs ( = "visible part of vertex")
	TLorentzVector vis_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( ! isNeutrinoID(daughter->MC.pdg_ID) ) { vis_tlv += daughter->MC.tlv; }
	}
	return vis_tlv;
}

double NuCalculationCheatedSignPOPPlotter::get_deboosted_DeltaR( TLorentzVector tlv_1, TLorentzVector tlv_2, TLorentzVector boost_tlv ) {
	TLorentzVector deboosted_tlv_1 = TLorentzVector(tlv_1);
	deboosted_tlv_1.Boost(-1.0*boost_tlv.BoostVector());
	TLorentzVector deboosted_tlv_2 = TLorentzVector(tlv_2);
	deboosted_tlv_2.Boost(-1.0*boost_tlv.BoostVector());
	return deboosted_tlv_1.DeltaR(deboosted_tlv_2);
}

double NuCalculationCheatedSignPOPPlotter::get_deboosted_angle( TLorentzVector tlv_1, TLorentzVector tlv_2, TLorentzVector boost_tlv ) {
	TLorentzVector deboosted_tlv_1 = TLorentzVector(tlv_1);
	deboosted_tlv_1.Boost(-1.0*boost_tlv.BoostVector());
	TLorentzVector deboosted_tlv_2 = TLorentzVector(tlv_2);
	deboosted_tlv_2.Boost(-1.0*boost_tlv.BoostVector());
	return deboosted_tlv_1.Angle(deboosted_tlv_2.Vect());
}


TLorentzVector NuCalculationCheatedSignPOPPlotter::calculate_nus_from_MC( LepNuVertex* vertex ){
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
	Double_t parents_m = parents_tlv.M();

	// Get (unit) direction of initial particles using difference of starting vertex form 0 position:
	TVector3 init_direction = ( (((Particle*)(vertex->vertex_daughters[0]))->MC.vertex) - (((Particle*)(vertex->vertex_parents[0]))->MC.vertex) ).Unit();

	// Get non-nu daughter tlvs ( = "visible part of vertex")
	TLorentzVector vis_tlv = get_vis_tlv(vertex);

	Double_t vis_E = vis_tlv.E();
	TVector3 vis_p = vis_tlv.Vect();
	Double_t vis_m = vis_tlv.M();
	// Get visible component parallel to assumed direction of parents
	Double_t vis_p_parallel = vis_p.Dot(init_direction);
	// Get visible component perpendicular to assumed direction of parents
	TVector3 perp_to_init = ( vis_p - vis_p_parallel*init_direction ).Unit();
	Double_t vis_p_perp = vis_p.Dot( perp_to_init );


	// Momentum and energy conservation -> Calculation of nu 4vector
	Double_t _D = std::pow( vis_E, 2 ) - std::pow( vis_p_parallel, 2 );
	Double_t _A = vis_p_parallel * ( 2.* std::pow(vis_p_perp, 2) + std::pow(vis_m, 2) - std::pow(parents_m, 2) );
  Double_t _C = 4. * std::pow( vis_p_perp, 2 ) * std::pow( vis_E, 2 ) - std::pow( 2. * std::pow( vis_p_perp, 2 ) + std::pow(vis_m, 2) - std::pow(parents_m, 2) , 2);
  Double_t _F = std::pow( _A, 2 ) - _C * _D;
	// Double_t _C = std::pow( 2.*std::pow(vis_p_perp, 2) + std::pow(vis_m, 2) - std::pow(parents_m, 2), 2);
	// Double_t _F = ( std::pow( vis_p_parallel, 2 ) * _C - 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D ) + _D * _C;

  if ( _F < 0 ) {
  	// std::cout << "WARNING: Value under square root negative: " << _F << " -> Setting sqrt to zero.\n";
    _F = 0;
  }

	if ( _D < 0.000001 )  { 
    // std::cout << "WARNING: _D too small: " << _D << " -> neutrino not reconstructed.\n"; 
	// } else if ( _F < 0 ) {
	// 	std::cout << "WARNING: Value under square root negative: " << _F << " -> neutrino not reconstructed.\n";
	// 	std::cout << "\n\n _A " << _A<< " _D " << _D<< " _C " << _C<< " _F " << _F <<"\n";
	// 	std::cout << " 1 " <<std::pow( vis_p_parallel, 2 ) * _C << " 2 " << 4.* std::pow(vis_E, 2) * std::pow(vis_p_perp, 2) * _D<< " 3 " << _D * _C<<"\n";
	// 	std::cout << "vis_E " << vis_E<< " vis_p_parallel " << vis_p_parallel<< " vis_p_perp " << vis_p_perp<< " vis_m " << vis_m<< " parents_m " << parents_m <<"\n";
	}	else {
		Double_t nu_p_perp = - vis_p_perp;

		// Quadratic equation has two solutions:
		Double_t nu_p_parallel_plus = 1./( 2. * _D ) * ( - _A + sqrt( _F ) );
		TVector3 nu_p_plus = nu_p_parallel_plus * init_direction + nu_p_perp * perp_to_init;
		Double_t nu_E_plus = nu_p_plus.Mag(); // Assume nu massless :P
		TLorentzVector nu_tlv_plus = TLorentzVector( nu_p_plus, nu_E_plus );

		Double_t nu_p_parallel_minus = 1./( 2. * _D ) * ( - _A - sqrt( _F ) );
		TVector3 nu_p_minus = nu_p_parallel_minus * init_direction + nu_p_perp * perp_to_init;
		Double_t nu_E_minus = nu_p_minus.Mag();
		TLorentzVector nu_tlv_minus = TLorentzVector( nu_p_minus, nu_E_minus );

		TLorentzVector true_nu_tlv = get_nu_daughters_tlv( vertex );

		TLorentzVector right_sign_nu_tlv {};
		TLorentzVector wrong_sign_nu_tlv {};
		if ( fabs((nu_tlv_plus - true_nu_tlv).E()) < fabs((nu_tlv_minus - true_nu_tlv).E()) ) {
			right_sign_nu_tlv = nu_tlv_plus;
			wrong_sign_nu_tlv = nu_tlv_minus;
		} else {
			right_sign_nu_tlv = nu_tlv_minus;
			wrong_sign_nu_tlv = nu_tlv_plus;
		}
		nu_tlv = right_sign_nu_tlv;
    
    
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // FOR DEBUGGING
    // int first_parent_pdg = ((Particle*)((vertex->vertex_parents)[0]))->MC.pdg_ID;
    // if ( ( fabs(first_parent_pdg) >= 500 && fabs(first_parent_pdg) < 600 ) || ( fabs(first_parent_pdg) >= 5000 && fabs(first_parent_pdg) < 6000 ) ) { 
    //   if ((right_sign_nu_tlv - true_nu_tlv).E() > 1 ) {
    //     std::cout << "    " << true_nu_tlv.E() << "->" << right_sign_nu_tlv.E() << "(" << wrong_sign_nu_tlv.E() << ") " << " _A " << _A<< " _D " << _D<< " _C " << _C<< " _F " << _F <<"\n";;
    //     std::cout << "    " << parents_tlv.E() << " = " << (vis_tlv + true_nu_tlv).E() << std::endl;
    //     std::cout << "    " << parents_tlv.Px() << " = " << (vis_tlv + true_nu_tlv).Px() << std::endl;
    //     std::cout << "    " << parents_tlv.Py() << " = " << (vis_tlv + true_nu_tlv).Py() << std::endl;
    //     std::cout << "    " << parents_tlv.Pz() << " = " << (vis_tlv + true_nu_tlv).Pz() << std::endl;
    //     std::cout << "    ";
    //     for (int i_parent = 0; i_parent<N_parents; i_parent++) {
    //       Particle* parent = (Particle*)(vertex->vertex_parents)[i_parent];
    //       std::cout << parent->MC.pdg_ID << " ";
    //     }
    //     std::cout << std::endl << "    ";
    //     for (int i_daughter = 0; i_daughter<vertex->vertex_daughters.GetEntries(); i_daughter++) {
    //       Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
    //       std::cout << daughter->MC.pdg_ID << " ";
    //     }
    //     std::cout << std::endl << "    ";
    //     std::cout << ((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Mag() << std::endl;
    //     std::cout << ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag();
    //     std::cout << std::endl << std::endl;
    //   }
    // }
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

		float weight = get_current_weight();
		// get_TH1D("deboosted_lep_rightsign_nu_DeltaR")->Fill( get_deboosted_DeltaR(right_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), parents_tlv) , 1);
		// get_TH1D("deboosted_lep_wrongsign_nu_DeltaR")->Fill( get_deboosted_DeltaR(wrong_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), parents_tlv) , 1);
		// get_TH1D("with_vis_deboosted_lep_rightsign_nu_DeltaR")->Fill( get_deboosted_DeltaR(right_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv) , 1);
		// get_TH1D("with_vis_deboosted_lep_wrongsign_nu_DeltaR")->Fill( get_deboosted_DeltaR(wrong_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv) , 1);
		// get_TH1D("with_calc_deboosted_lep_rightsign_nu_DeltaR")->Fill( get_deboosted_DeltaR(right_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv+right_sign_nu_tlv) , 1);
		// get_TH1D("with_calc_deboosted_lep_wrongsign_nu_DeltaR")->Fill( get_deboosted_DeltaR(wrong_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv+wrong_sign_nu_tlv) , 1);
    // 
		// get_TH1D("deboosted_lep_rightsign_nu_angle")->Fill( get_deboosted_angle(right_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), parents_tlv) , 1);
		// get_TH1D("deboosted_lep_wrongsign_nu_angle")->Fill( get_deboosted_angle(wrong_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), parents_tlv) , 1);
		// get_TH1D("with_vis_deboosted_lep_rightsign_nu_angle")->Fill( get_deboosted_angle(right_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv) , 1);
		// get_TH1D("with_vis_deboosted_lep_wrongsign_nu_angle")->Fill( get_deboosted_angle(wrong_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv) , 1);
		// get_TH1D("with_calc_deboosted_lep_rightsign_nu_angle")->Fill( get_deboosted_angle(right_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv+right_sign_nu_tlv) , 1);
		// get_TH1D("with_calc_deboosted_lep_wrongsign_nu_angle")->Fill( get_deboosted_angle(wrong_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv+wrong_sign_nu_tlv) , 1);
    // 
    // 
		// get_TH1D("with_wrongcalc_deboosted_lep_rightsign_nu_angle")->Fill( get_deboosted_angle(right_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv+wrong_sign_nu_tlv) , 1);
		// get_TH1D("with_rightcalc_deboosted_lep_wrongsign_nu_angle")->Fill( get_deboosted_angle(wrong_sign_nu_tlv, get_charged_lepton_daughters_tlv(vertex), vis_tlv+right_sign_nu_tlv) , 1);
	}

	return nu_tlv;
}

void NuCalculationCheatedSignPOPPlotter::fill_plots(){
	float weight = get_current_weight();

	int i=0;
	// This is the loop over all events
	while ( get_next_event() ) {
		int N_vertices = (evt_info->total_event.lep_nu_vertices).GetEntries();
		// std::cout << i++ << "\n";
		for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
			LepNuVertex* vertex = (LepNuVertex*)evt_info->total_event.lep_nu_vertices[i_vertex];
			TLorentzVector nu_tlv_calculated = calculate_nus_from_MC( vertex );
			TLorentzVector nu_tlv_true = get_nu_daughters_tlv( vertex );
			//std::cout << "nu: true: " << nu_tlv_true.E() << " calc: " << nu_tlv_calculated.E() << " Init_vertex position:" << ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag() << " \n\n";
			get_TH2D("nu_E")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);

			int first_parent_pdg = ((Particle*)((vertex->vertex_parents)[0]))->MC.pdg_ID;
			// if ( fabs(first_parent_pdg) == 511 || fabs(first_parent_pdg) == 521 || fabs(first_parent_pdg) == 531 ) {
      if ( ( fabs(first_parent_pdg) >= 500 && fabs(first_parent_pdg) < 600 ) || ( fabs(first_parent_pdg) >= 5000 && fabs(first_parent_pdg) < 6000 ) ) { 
				float parent_init_pos = ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(); // TODO Adjust to non-zero init vertex
				if ( parent_init_pos < 1.0 ) {
					get_TH2D("nu_E_Bparents_only_0vertex")->Fill(nu_tlv_true.E(), nu_tlv_calculated.E(), 1);
					get_TH2D("p_nu_parallel_vs_Bboost")->Fill( ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), (nu_tlv_calculated.Vect()).Dot(((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Unit()), 1);
				}
			}
			// if ( fabs((nu_tlv_calculated - nu_tlv_true).E()) > 40 ) {
			// 	std::cout << " nooo: Evt "<< i << " nu E: " << nu_tlv_true.E() << "\n" ;
			// }
		}
	}
}

void NuCalculationCheatedSignPOPPlotter::draw_plots(){

	TCanvas *can_1 = new TCanvas("c1", "", 0, 0, 800, 800);
	TH1D *deboosted_lep_rightsign_nu_angle = get_TH1D("deboosted_lep_rightsign_nu_angle");
	TH1D *deboosted_lep_wrongsign_nu_angle = get_TH1D("deboosted_lep_wrongsign_nu_angle");
	deboosted_lep_rightsign_nu_angle->SetLineColor(kBlue);
	deboosted_lep_wrongsign_nu_angle->SetLineColor(kRed);
	deboosted_lep_rightsign_nu_angle->Rebin(2);
	deboosted_lep_wrongsign_nu_angle->Rebin(2);
	TLegend* leg_1 = new TLegend(0.2, 0.73, 0.55, 0.9);
	leg_1->AddEntry(deboosted_lep_rightsign_nu_angle, "Right sign", "l");
	leg_1->AddEntry(deboosted_lep_wrongsign_nu_angle, "Wrong sign", "l");
	deboosted_lep_rightsign_nu_angle->Draw("hist");
	deboosted_lep_wrongsign_nu_angle->Draw("hist same");
	leg_1->Draw();
  can_1->Modified();
  can_1->Update();
	can_1->Print((get_output_directory() + "/deboosted_lep_nu_angle.pdf").c_str());

	TCanvas *can_2 = new TCanvas("c2", "", 0, 0, 800, 800);
	TH1D *with_calc_deboosted_lep_rightsign_nu_angle = get_TH1D("with_calc_deboosted_lep_rightsign_nu_angle");
	TH1D *with_calc_deboosted_lep_wrongsign_nu_angle = get_TH1D("with_calc_deboosted_lep_wrongsign_nu_angle");
	with_calc_deboosted_lep_rightsign_nu_angle->SetLineColor(kBlue);
	with_calc_deboosted_lep_wrongsign_nu_angle->SetLineColor(kRed);
	with_calc_deboosted_lep_rightsign_nu_angle->Rebin(2);
	with_calc_deboosted_lep_wrongsign_nu_angle->Rebin(2);
	TLegend* leg_2 = new TLegend(0.2, 0.73, 0.55, 0.9);
	leg_2->AddEntry(with_calc_deboosted_lep_rightsign_nu_angle, "Right sign", "l");
	leg_2->AddEntry(with_calc_deboosted_lep_wrongsign_nu_angle, "Wrong sign", "l");
	with_calc_deboosted_lep_rightsign_nu_angle->Draw("hist");
	with_calc_deboosted_lep_wrongsign_nu_angle->Draw("hist same");
	leg_2->Draw();
  can_2->Modified();
  can_2->Update();
	can_2->Print((get_output_directory() + "/with_calc_deboosted_lep_nu_angle.pdf").c_str());

	std::string output_dir = get_output_directory();

	for (int i=0; i<get_number_TH2Ds(); i++) {
		TH2D* current_h2 = get_TH2D_i(i);
		TCanvas* current_canvas = new TCanvas(( std::string() + current_h2->GetName() + "_can").c_str(), "", 0, 0, 800, 800);
		current_h2->Draw("colz");
		current_canvas->SetTopMargin(0.13);
		current_canvas->SetRightMargin(0.2);
    current_canvas->Modified();
    current_canvas->Update();
		current_canvas->Print(( output_dir + "/h2_" + current_h2->GetName() + ".pdf").c_str());
		// delete current_canvas;
	}

//
}
