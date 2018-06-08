#include "plotters.h"

// Very simple example

void LepNuPairPlotter::set_plotter_settings() {
	set_output_folder_name("lep_nu_pairs");
}

void LepNuPairPlotter::define_plots(){
	add_new_TH2D("lep_nu_E",
		new TH2D(	"lep_nu_E", "lep-#nu-pair energies; E_{l} [GeV]; E_{#nu} [GeV]; Pairs", 20, 0, 100, 20, 0, 100 )
	);
	//
	// add_new_TH2D("lep_nu_theta",
	// 	new TH2D(	"lep_nu_theta", "lep-#nu-pair thetas; #theta_{l} [GeV]; #theta_{#nu} [GeV]; Pairs",
	// 				100, 0, 3.2, 100, 0, 3.2 ) );
	//
	// add_new_TH2D("lep_nu_phi",
	// 	new TH2D(	"lep_nu_phi", "lep-#nu-pair phis; #phi_{l} [GeV]; #phi_{#nu} [GeV]; Pairs",
	// 				100, 0, 3.2, 100, 0, 3.2 ) );
	//
	// add_new_TH2D("lep_nu_E_bjets",
	// 	new TH2D(	"lep_nu_E_bjets", "lep-#nu-pair energies, b jets; E_{l} [GeV]; E_{#nu} [GeV]; Pairs",
	// 				40, 0, 20, 40, 0, 20 ) );
	//
	// add_new_TH2D("lep_nu_theta_bjets",
	// 	new TH2D(	"lep_nu_theta_bjets", "lep-#nu-pair thetas, b jets; #theta_{l} [GeV]; #theta_{#nu} [GeV]; Pairs",
	// 				100, 0, 3.2, 100, 0, 3.2 ) );
	//
	// add_new_TH2D("lep_nu_phi_bjets",
	// 	new TH2D(	"lep_nu_phi_bjets", "lep-#nu-pair phis, b jets; #phi_{l} [GeV]; #phi_{#nu} [GeV]; Pairs",
	// 				100, 0, 3.2, 100, 0, 3.2 ) );
	//
	//
	//
	// add_new_TH2D("lep_nu_E_electrons",
	// 	new TH2D(	"lep_nu_E_electrons", "lep-#nu-pair energies, electrons; E_{l} [GeV]; E_{#nu} [GeV]; Pairs",
	// 				40, 0, 20, 40, 0, 20 ) );
	//
	// add_new_TH2D("lep_nu_theta_electrons",
	// 	new TH2D(	"lep_nu_theta_electrons", "lep-#nu-pair thetas, electrons; #theta_{l} [GeV]; #theta_{#nu} [GeV]; Pairs",
	// 				100, 0, 3.2, 100, 0, 3.2 ) );
	//
	// add_new_TH2D("lep_nu_phi_electrons",
	// 	new TH2D(	"lep_nu_phi_electrons", "lep-#nu-pair phis, electrons; #phi_{l} [GeV]; #phi_{#nu} [GeV]; Pairs",
	// 				100, 0, 3.2, 100, 0, 3.2 ) );
	//
	// add_new_TH2D("lep_nu_E_muons",
	// 	new TH2D(	"lep_nu_E_muons", "lep-#nu-pair energies, muons; E_{l} [GeV]; E_{#nu} [GeV]; Pairs",
	// 				40, 0, 20, 40, 0, 20 ) );
	//
	// add_new_TH2D("lep_nu_theta_muons",
	// 	new TH2D(	"lep_nu_theta_muons", "lep-#nu-pair thetas, muons; #theta_{l} [GeV]; #theta_{#nu} [GeV]; Pairs",
	// 				100, 0, 3.2, 100, 0, 3.2 ) );
	//
	// add_new_TH2D("lep_nu_phi_muons",
	// 	new TH2D(	"lep_nu_phi_muons", "lep-#nu-pair phis, muons; #phi_{l} [GeV]; #phi_{#nu} [GeV]; Pairs",
	// 				100, 0, 3.2, 100, 0, 3.2 ) );

	add_new_TH2D("deboosted_lep_nu_E",
		new TH2D("deboosted_lep_nu_E", "lep-#nu-pair E in parent rest system; #E_{l}; #E_{nu}; vertices", 100, 0, 10, 40, 0, 4 )
	);

	add_new_TH2D("deboosted_lep_nu_theta",
		new TH2D("deboosted_lep_nu_theta", "lep-#nu-pair theta in parent rest system; #theta_{l}; #theta_{nu}; vertices", 32, 0, 3.2, 32, 0, 3.2 )
	);

	add_new_TH2D("deboosted_lep_nu_phi",
		new TH2D("deboosted_lep_nu_phi", "lep-#nu-pair phi in parent rest system; #phi_{l}; #phi_{nu}; vertices", 32, 0, 3.2, 32, 0, 3.2 )
	);

	add_new_TH1D("deboosted_lep_nu_DeltaR",
		new TH1D("deboosted_lep_nu_DeltaR", "#DeltaR(lep, #nu) in parent rest system; #DeltaR(lep,#nu); vertices", 40, 0, 4)
	);

	add_new_TH1D("with_vis_deboosted_lep_nu_DeltaR",
		new TH1D("with_vis_deboosted_lep_nu_DeltaR", "#DeltaR(lep, #nu) in system boosted with visible; #DeltaR(lep,#nu); vertices", 40, 0, 4)
	);


	add_new_TH1D("deboosted_lep_nu_Angle",
		new TH1D("deboosted_lep_nu_Angle", "Angle(lep, #nu) in parent rest system; Angle(lep,#nu); vertices", 32, 0, 3.2)
	);

	add_new_TH1D("with_vis_deboosted_lep_nu_Angle",
		new TH1D("with_vis_deboosted_lep_nu_Angle", "Angle(lep, #nu) in system boosted with visible; Angle(lep,#nu); vertices", 32, 0, 3.2)
	);
}

bool LepNuPairPlotter::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

TLorentzVector LepNuPairPlotter::get_parents_tlv( LepNuVertex *vertex ) {
	TLorentzVector parents_tlv {};
	int N_parents = (vertex->vertex_parents).GetEntries();
	for (int i_parent = 0; i_parent<N_parents; i_parent++) {
		Particle* parent = (Particle*)(vertex->vertex_parents)[i_parent];
		if ( ! isNeutrinoID(parent->MC.pdg_ID) ) { parents_tlv += parent->MC.tlv; }
	}
	return parents_tlv;
}

TLorentzVector LepNuPairPlotter::get_vis_tlv( LepNuVertex* vertex ){
	// Get non-nu daughter tlvs ( = "visible part of vertex")
	TLorentzVector vis_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( ! isNeutrinoID(daughter->MC.pdg_ID) ) { vis_tlv += daughter->MC.tlv; }
	}
	return vis_tlv;
}

TLorentzVector LepNuPairPlotter::get_charged_lepton_daughters_tlv( LepNuVertex *vertex ) {
	TLorentzVector charged_lep_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { charged_lep_tlv += daughter->MC.tlv; }
	}
	return charged_lep_tlv;
}

TLorentzVector LepNuPairPlotter::get_nu_daughters_tlv( LepNuVertex *vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( isNeutrinoID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

void LepNuPairPlotter::fill_plots(){
	float weight = get_current_weight();

	// This is the loop over all events
	while ( get_next_event() ) {

		int N_vertices = (evt_info->total_event.lep_nu_vertices).GetEntries();
		for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
			LepNuVertex* vertex = (LepNuVertex*)evt_info->total_event.lep_nu_vertices[i_vertex];

			TLorentzVector parents_tlv = get_parents_tlv( vertex );
			TLorentzVector deboosted_charged_leps_tlv = get_charged_lepton_daughters_tlv( vertex );
			TLorentzVector deboosted_nus_tlv = get_nu_daughters_tlv( vertex );
			get_TH2D("lep_nu_E")->Fill(deboosted_charged_leps_tlv.E(), deboosted_nus_tlv.E(), weight);
			deboosted_charged_leps_tlv.Boost(-1.0*parents_tlv.BoostVector());
			deboosted_nus_tlv.Boost(-1.0*parents_tlv.BoostVector());

			get_TH2D("deboosted_lep_nu_E")->Fill(deboosted_charged_leps_tlv.E(), deboosted_nus_tlv.E(), weight);
			get_TH2D("deboosted_lep_nu_theta")->Fill(deboosted_charged_leps_tlv.Theta(), deboosted_nus_tlv.Theta(), weight);
			get_TH2D("deboosted_lep_nu_phi")->Fill(deboosted_charged_leps_tlv.Phi(), deboosted_nus_tlv.Phi(), weight);

			get_TH1D("deboosted_lep_nu_DeltaR")->Fill(deboosted_nus_tlv.DeltaR(deboosted_charged_leps_tlv), weight);
			get_TH1D("deboosted_lep_nu_Angle")->Fill(deboosted_nus_tlv.Angle(deboosted_charged_leps_tlv.Vect()), weight);




			TLorentzVector vis_tlv = get_vis_tlv( vertex );
			TLorentzVector with_vis_deboosted_charged_leps_tlv = get_charged_lepton_daughters_tlv( vertex );
			with_vis_deboosted_charged_leps_tlv.Boost(-1.0*vis_tlv.BoostVector());
			TLorentzVector with_vis_deboosted_nus_tlv = get_nu_daughters_tlv( vertex );
			with_vis_deboosted_nus_tlv.Boost(-1.0*vis_tlv.BoostVector());

			get_TH1D("with_vis_deboosted_lep_nu_DeltaR")->Fill(with_vis_deboosted_nus_tlv.DeltaR(with_vis_deboosted_charged_leps_tlv), weight);
			get_TH1D("with_vis_deboosted_lep_nu_Angle")->Fill(with_vis_deboosted_nus_tlv.Angle(with_vis_deboosted_charged_leps_tlv.Vect()), weight);

			// get_TH1D("deboosted_lep_nu_DeltaR")->Fill(deboosted_nus_tlv.DeltaR(deboosted_charged_leps_tlv), weight);

		// int N_tj_jets = (evt_info->tj_jets).GetEntries();
		// for (int i_jet = 0; i_jet<N_tj_jets; i_jet++ ) {
	// 		TJJet *jet = (TJJet*)evt_info->tj_jets[i_jet];
	// 		int N_pairs = (jet->lep_nu_pairs).GetEntries();
	//
	// 		for (int i_pair = 0; i_pair<N_pairs; i_pair++ ) {
	// 			LepNuPair *pair = (LepNuPair*)jet->lep_nu_pairs[i_pair];
	// 			TLorentzVector tlv_l = pair->tlv_lep;
	// 			TLorentzVector tlv_n = pair->get_total_nu_tlv();
	//
	// 			get_TH2D("lep_nu_E")->Fill(tlv_l.E(), tlv_n.E(), weight);
	// 			get_TH2D("lep_nu_theta")->Fill(tlv_l.Theta(), tlv_n.Theta(), weight);
	// 			get_TH2D("lep_nu_phi")->Fill(tlv_l.Phi(), tlv_n.Phi(), weight);
	//
	// 			if ( fabs(jet->fe_pdgID) == 5 ) {
	// 				get_TH2D("lep_nu_E_bjets")->Fill(tlv_l.E(), tlv_n.E(), weight);
	// 				get_TH2D("lep_nu_theta_bjets")->Fill(tlv_l.Theta(), tlv_n.Theta(), weight);
	// 				get_TH2D("lep_nu_phi_bjets")->Fill(tlv_l.Phi(), tlv_n.Phi(), weight);
	// 			}
	//
	//
	// 			if ( fabs(pair->lep_ID) == 11 ) {
	// 				get_TH2D("lep_nu_E_electrons")->Fill(tlv_l.E(), tlv_n.E(), weight);
	// 				get_TH2D("lep_nu_theta_electrons")->Fill(tlv_l.Theta(), tlv_n.Theta(), weight);
	// 				get_TH2D("lep_nu_phi_electrons")->Fill(tlv_l.Phi(), tlv_n.Phi(), weight);
	// 			}
	//
	//
	// 			if ( fabs(pair->lep_ID) == 13 ) {right
	// 				get_TH2D("lep_nu_E_muons")->Fill(tlv_l.E(), tlv_n.E(), weight);
	// 				get_TH2D("lep_nu_theta_muons")->Fill(tlv_l.Theta(), tlv_n.Theta(), weight);
	// 				get_TH2D("lep_nu_phi_muons")->Fill(tlv_l.Phi(), tlv_n.Phi(), weight);
	// 			}
	// 		}
		}
	}
}

void LepNuPairPlotter::draw_plots(){
	//std::string output_dir = get_output_directory();

	//TCanvas* c1 = new TCanvas("c1", "", 0, 0, 800, 800);
	//get_TH1D("test")->Draw();
	//c1->Print((output_dir + "/test.pdf").c_str());
}
