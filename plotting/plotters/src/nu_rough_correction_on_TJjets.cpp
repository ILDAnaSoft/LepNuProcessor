#include "plotters.h"

void RoughNuCorrectionOnTJjetsPlotter::set_plotter_settings() {
	set_output_folder_name("rough_nu_correction_on_TJjets");
}

void RoughNuCorrectionOnTJjetsPlotter::define_plots(){

	add_new_TH1D("N_TJjets", new TH1D("N_TJjets", "Number TJjets; N_{jets}; Events", 15, -0.5, 14.5));

	add_new_TProfile("TJjet_meanEseen_vs_Etrue", new TProfile("TJjet_meanEseen_vs_Etrue", "< E_{jet}^{reco} > : E_{jet}^{MC}; E_{jet}^{MC} [GeV]; <E_{jet}^{reco}> [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_meanEseencorrected_vs_Etrue", new TProfile("TJjet_meanEseencorrected_vs_Etrue", "< E_{jet}^{reco, corrected} > : E_{jet}^{MC}, only MC B and C corrected; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected}> [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue", new TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue", "< E_{jet}^{reco, corrected w/ MC #nu} > : E_{jet}^{MC}, only MC B and C corrected; <E_{jet}^{MC} [GeV]; E_{jet}^{reco, corrected w/ MC #nu}> [GeV]", 20, 0, 200) );


	add_new_TProfile("TJjet_meanEseen_vs_Etrue_bjets", new TProfile("TJjet_meanEseen_vs_Etrue_bjets", "< E_{jet}^{reco} > : E_{jet}^{MC}, b jets; E_{jet}^{MC} [GeV]; <E_{jet}^{reco}> [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_meanEseencorrected_vs_Etrue_bjets", new TProfile("TJjet_meanEseencorrected_vs_Etrue_bjets", "< E_{jet}^{reco, corrected} > : E_{jet}^{MC}, only MC B and C corrected, b jets; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected}> [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_bjets", new TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_bjets", "< E_{jet}^{reco, corrected w/ MC #nu} > : E_{jet}^{MC}, only MC B and C corrected, b jets; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected w/ MC #nu}> [GeV]", 20, 0, 200) );


	add_new_TProfile("TJjet_pullEseen_vs_Etrue_bjets", new TProfile("TJjet_pullEseen_vs_Etrue_bjets", "< E_{jet}^{reco} - E_{jet}^{MC} > : E_{jet}^{MC}, b jets; E_{jet}^{MC} [GeV]; <E_{jet}^{reco} - E_{jet}^{MC} > [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_pullEseencorrected_vs_Etrue_bjets", new TProfile("TJjet_pullEseencorrected_vs_Etrue_bjets", "< E_{jet}^{reco, corrected} - E_{jet}^{MC} > : E_{jet}^{MC}, only MC B and C corrected, b jets; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected} - E_{jet}^{MC} > [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_bjets", new TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_bjets", "< E_{jet}^{reco, corrected w/ MC #nu} - E_{jet}^{MC} > : E_{jet}^{MC}, only MC B and C corrected, b jets; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected w/ MC #nu} - E_{jet}^{MC} > [GeV]", 20, 0, 200) );


	add_new_TH1D("TJjet_Etrue_bjets", new TH1D("TJjet_Etrue_bjets", "TJ jet energy distribution, MC, bjets; E_{jet}^{MC}; Jets", 20, 0, 200));
	add_new_TH1D("TJjet_Eseen_bjets", new TH1D("TJjet_Eseen_bjets", "TJ jet energy distribution, reco, bjets; E_{jet}^{reco}; Jets", 20, 0, 200));
	add_new_TH1D("TJjet_Eseencorrected_bjets", new TH1D("TJjet_Eseencorrected_bjets", "TJ jet energy distribution, corrected, bjets; E_{jet}^{corrected}; Jets", 20, 0, 200));
	add_new_TH1D("TJjet_EseencorrectedwithMC_bjets", new TH1D("TJjet_EseencorrectedwithMC_bjets", "TJ jet energy distribution, reco + with MC #nu, bjets; E_{jet}^{with MC #nu}; Jets", 20, 0, 200));


	add_new_TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets", new TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets", "< E_{jet}^{reco} > : E_{jet}^{MC}, b jets w/ semilep. C/B; E_{jet}^{MC} [GeV]; <E_{jet}^{reco}> [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_meanEseencorrected_vs_Etrue_semilepbjets", new TProfile("TJjet_meanEseencorrected_vs_Etrue_semilepbjets", "< E_{jet}^{reco, corrected} > : E_{jet}^{MC}, only MC B and C corrected, b jets w/ semilep. C/B; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected}> [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_semilepbjets", new TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_semilepbjets", "< E_{jet}^{reco, corrected w/ MC #nu} > : E_{jet}^{MC}, only MC B and C corrected, b jets w/ semilep. C/B; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected w/ MC #nu}> [GeV]", 20, 0, 200) );

	add_new_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets", new TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets", "< E_{jet}^{reco} - E_{jet}^{MC} > : E_{jet}^{MC}, b jets w/ semilep. C/B; E_{jet}^{MC} [GeV]; <E_{jet}^{reco} - E_{jet}^{MC} > [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_pullEseencorrected_vs_Etrue_semilepbjets", new TProfile("TJjet_pullEseencorrected_vs_Etrue_semilepbjets", "< E_{jet}^{reco, corrected} - E_{jet}^{MC} > : E_{jet}^{MC}, only MC B and C corrected, b jets w/ semilep. C/B; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected} - E_{jet}^{MC} > [GeV]", 20, 0, 200) );
	add_new_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_semilepbjets", new TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_semilepbjets", "< E_{jet}^{reco, corrected w/ MC #nu} - E_{jet}^{MC} > : E_{jet}^{MC}, only MC B and C corrected, b jets w/ semilep. C/B ; E_{jet}^{MC} [GeV]; <E_{jet}^{reco, corrected w/ MC #nu} - E_{jet}^{MC} > [GeV]", 20, 0, 200) );
}

bool RoughNuCorrectionOnTJjetsPlotter::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

TLorentzVector RoughNuCorrectionOnTJjetsPlotter::get_nu_daughters_tlv( LepNuVertex* vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( isNeutrinoID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

TLorentzVector RoughNuCorrectionOnTJjetsPlotter::get_vis_tlv( LepNuVertex* vertex ){
	// Get non-nu daughter tlvs ( = "visible part of vertex")
	TLorentzVector vis_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( ! isNeutrinoID(daughter->MC.pdg_ID) ) { vis_tlv += daughter->MC.tlv; }
	}
	return vis_tlv;
}

TLorentzVector RoughNuCorrectionOnTJjetsPlotter::get_charged_leptons_mc_tlv( LepNuVertex* vertex ){
	TLorentzVector charged_lep_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { charged_lep_tlv += daughter->MC.tlv; }
	}
	return charged_lep_tlv;
}

TLorentzVector RoughNuCorrectionOnTJjetsPlotter::get_charged_leptons_reco_tlv( LepNuVertex* vertex ){
	TLorentzVector charged_lep_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( daughter->was_reconstructed ) {
			if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { 
				charged_lep_tlv += daughter->Reco.tlv;
			}
		}
	}
	return charged_lep_tlv;
}

bool  RoughNuCorrectionOnTJjetsPlotter::is_Bmeson_ID( int pdgID ) {
  if ( ( fabs(pdgID) >= 500 && fabs(pdgID) < 600 ) || ( fabs(pdgID) >= 5000 && fabs(pdgID) < 6000 ) ) { 
      return true;
  } else {
    return false;
  }
}

bool  RoughNuCorrectionOnTJjetsPlotter::is_Cmeson_ID( int pdgID ) {
  if ( ( fabs(pdgID) >= 400 && fabs(pdgID) < 500 ) || ( fabs(pdgID) >= 4000 && fabs(pdgID) < 5000 ) ) {
      return true;
  } else {
    return false;
  }
}

double RoughNuCorrectionOnTJjetsPlotter::fitted_mean_x( double E_lep ){
	double a = 0.77;
	double b = 2.5;
	return a*E_lep / ( b + E_lep );
}

double RoughNuCorrectionOnTJjetsPlotter::fitted_delta_mean_x( double E_lep ){
	double a = 0.238;
	double b = -0.00124;
	return a + b*E_lep;
}

double RoughNuCorrectionOnTJjetsPlotter::nu_energy_error_estimate( double E_lep ) {
	double mean_x = fitted_mean_x(E_lep);
	double d_mean_x = fitted_delta_mean_x(E_lep);
	return d_mean_x/mean_x * E_lep;
}

double RoughNuCorrectionOnTJjetsPlotter::nu_energy_correction( double E_lep ){
	if ( E_lep > 0 ) {
		double mean_x = fitted_mean_x(E_lep);
		return (1.0/mean_x - 1) * E_lep;
	} else {
		return 0;
	}
}

void RoughNuCorrectionOnTJjetsPlotter::fill_plots(){
	float weight = get_current_weight();

	// int i=1;
	// This is the loop over all events
	while ( get_next_event() ) {
		int N_jets = (evt_info->tj_jets).GetEntries();
		get_TH1D("N_TJjets")->Fill(N_jets, weight);
		for (int i_jet = 0; i_jet<N_jets; i_jet++) {
			TJJet* jet = (TJJet*)evt_info->tj_jets[i_jet];
			int N_vertices = (jet->lep_nu_vertices).GetEntries();

			double jet_E_true = jet->tlv_true.E();
			double jet_E_seen = jet->tlv_seen.E();
			double jet_E_seen_corrected = jet->tlv_seen.E();
			double jet_E_seen_corrected_with_MCnu = jet->tlv_seen.E();

			bool has_semilep_CB_decay = false;

			for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
				LepNuVertex* vertex = (LepNuVertex*)jet->lep_nu_vertices[i_vertex];

				int first_parent_pdg = ((Particle*)((vertex->vertex_parents)[0]))->MC.pdg_ID;

				float E_lep = (get_charged_leptons_mc_tlv(vertex)).E();
				double nu_E = nu_energy_correction( E_lep );
				TLorentzVector nu_tlv_true = get_nu_daughters_tlv( vertex );

				if ( is_Cmeson_ID(first_parent_pdg) || is_Bmeson_ID(first_parent_pdg) ) {
					has_semilep_CB_decay = true;
					jet_E_seen_corrected += nu_E;
					jet_E_seen_corrected_with_MCnu += nu_tlv_true.E();
				}


			}

			get_TProfile("TJjet_meanEseen_vs_Etrue")->Fill(jet_E_true, jet_E_seen, weight);
			get_TProfile("TJjet_meanEseencorrected_vs_Etrue")->Fill(jet_E_true, jet_E_seen_corrected, weight);
			get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue")->Fill(jet_E_true, jet_E_seen_corrected_with_MCnu, weight);

			if ( fabs(jet->fe_pdgID) == 5 ) {
				get_TProfile("TJjet_meanEseen_vs_Etrue_bjets")->Fill(jet_E_true, jet_E_seen, weight);
				get_TProfile("TJjet_meanEseencorrected_vs_Etrue_bjets")->Fill(jet_E_true, jet_E_seen_corrected, weight);
				get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_bjets")->Fill(jet_E_true, jet_E_seen_corrected_with_MCnu, weight);

				get_TProfile("TJjet_pullEseen_vs_Etrue_bjets")->Fill(jet_E_true, jet_E_seen - jet_E_true, weight);
				get_TProfile("TJjet_pullEseencorrected_vs_Etrue_bjets")->Fill(jet_E_true, jet_E_seen_corrected - jet_E_true, weight);
				get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_bjets")->Fill(jet_E_true, jet_E_seen_corrected_with_MCnu - jet_E_true, weight);

				get_TH1D("TJjet_Etrue_bjets")->Fill(jet_E_true, weight);
				get_TH1D("TJjet_Eseen_bjets")->Fill(jet_E_seen, weight);
				get_TH1D("TJjet_Eseencorrected_bjets")->Fill(jet_E_seen_corrected, weight);
				get_TH1D("TJjet_EseencorrectedwithMC_bjets")->Fill(jet_E_seen_corrected_with_MCnu, weight);

				if (has_semilep_CB_decay) {
					get_TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets")->Fill(jet_E_true, jet_E_seen, weight);
					get_TProfile("TJjet_meanEseencorrected_vs_Etrue_semilepbjets")->Fill(jet_E_true, jet_E_seen_corrected, weight);
					get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_semilepbjets")->Fill(jet_E_true, jet_E_seen_corrected_with_MCnu, weight);

					get_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets")->Fill(jet_E_true, jet_E_seen - jet_E_true, weight);
					get_TProfile("TJjet_pullEseencorrected_vs_Etrue_semilepbjets")->Fill(jet_E_true, jet_E_seen_corrected - jet_E_true, weight);
					get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_semilepbjets")->Fill(jet_E_true, jet_E_seen_corrected_with_MCnu - jet_E_true, weight);
				}
			}
		}
	}
}

void RoughNuCorrectionOnTJjetsPlotter::draw_plots(){
	std::string output_dir = get_output_directory();

	TCanvas* c_jetE_bjets_distr = new TCanvas("c_jetE_bjets_distr", "", 0, 0, 800, 800);
	TLegend* leg_jetE_bjets_distr = new TLegend(0.55, 0.65, 0.8, 0.85);
	get_TH1D("TJjet_Etrue_bjets")->SetLineColor(9101);
	get_TH1D("TJjet_Etrue_bjets")->SetMaximum(700);
	get_TH1D("TJjet_Eseen_bjets")->SetLineColor(9102);
	get_TH1D("TJjet_Eseencorrected_bjets")->SetLineColor(9103);
	get_TH1D("TJjet_EseencorrectedwithMC_bjets")->SetLineColor(9104);
	get_TH1D("TJjet_Etrue_bjets")->Draw("hist same");
	get_TH1D("TJjet_Eseen_bjets")->Draw("hist same");
	get_TH1D("TJjet_Eseencorrected_bjets")->Draw("hist same");
	get_TH1D("TJjet_EseencorrectedwithMC_bjets")->Draw("hist same");
	leg_jetE_bjets_distr->AddEntry(get_TH1D("TJjet_Etrue_bjets"), "true", "l");
	leg_jetE_bjets_distr->AddEntry(get_TH1D("TJjet_Eseen_bjets"), "seen", "l");
	leg_jetE_bjets_distr->AddEntry(get_TH1D("TJjet_Eseencorrected_bjets"), "corrected", "l");
	leg_jetE_bjets_distr->AddEntry(get_TH1D("TJjet_EseencorrectedwithMC_bjets"), "with MC #nu", "l");
	leg_jetE_bjets_distr->Draw("same");
	c_jetE_bjets_distr->Print((output_dir + "/jetE_Distributions.pdf").c_str());




	TCanvas* c_jetE = new TCanvas("c_jetE", "", 0, 0, 800, 800);
	TLegend* leg_jetE = new TLegend(0.2, 0.62, 0.55, 0.85);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue")->SetLineColor(9101);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue")->SetMarkerColor(9101);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseen_vs_Etrue")->SetLineColor(9102);
	get_TProfile("TJjet_meanEseen_vs_Etrue")->SetMarkerColor(9102);
	get_TProfile("TJjet_meanEseen_vs_Etrue")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue")->SetLineColor(9103);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue")->SetMarkerColor(9103);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue")->Draw();
	get_TProfile("TJjet_meanEseen_vs_Etrue")->Draw("same");
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue")->Draw("same");
	leg_jetE->AddEntry(get_TProfile("TJjet_meanEseen_vs_Etrue"), "uncorrected");
	leg_jetE->AddEntry(get_TProfile("TJjet_meanEseencorrected_vs_Etrue"), "corrected");
	leg_jetE->AddEntry(get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue"), "with MC #nu");
	leg_jetE->Draw();
	gPad->Update();
	TLine* profile_line = new TLine(0, 0, gPad->GetFrame()->GetY2(), gPad->GetFrame()->GetY2());
	profile_line->SetLineWidth(1);
	profile_line->Draw("same");
	c_jetE->SetTopMargin(0.1);
	c_jetE->Print((output_dir + "/jetEreco_comparison.pdf").c_str());


	TCanvas* c_jetE_bjets = new TCanvas("c_jetE_bjets", "", 0, 0, 800, 800);
	TLegend* leg_jetE_bjets = new TLegend(0.2, 0.62, 0.55, 0.85);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue_bjets")->SetLineColor(9101);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue_bjets")->SetMarkerColor(9101);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue_bjets")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseen_vs_Etrue_bjets")->SetLineColor(9102);
	get_TProfile("TJjet_meanEseen_vs_Etrue_bjets")->SetMarkerColor(9102);
	get_TProfile("TJjet_meanEseen_vs_Etrue_bjets")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_bjets")->SetLineColor(9103);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_bjets")->SetMarkerColor(9103);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_bjets")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseen_vs_Etrue_bjets")->SetMinimum(0);
	get_TProfile("TJjet_meanEseen_vs_Etrue_bjets")->Draw();
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue_bjets")->Draw("same");
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_bjets")->Draw("same");
	leg_jetE_bjets->AddEntry(get_TProfile("TJjet_meanEseen_vs_Etrue_bjets"), "uncorrected");
	leg_jetE_bjets->AddEntry(get_TProfile("TJjet_meanEseencorrected_vs_Etrue_bjets"), "corrected");
	leg_jetE_bjets->AddEntry(get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_bjets"), "with MC #nu");
	leg_jetE_bjets->Draw();
	gPad->Update();
	TLine* profile_line_bjets = new TLine(0, 0, gPad->GetFrame()->GetY2(), gPad->GetFrame()->GetY2());
	profile_line_bjets->SetLineWidth(1);
	profile_line_bjets->Draw("same");
	c_jetE_bjets->SetTopMargin(0.1);
	c_jetE_bjets->Print((output_dir + "/jetEreco_comparison_bjets.pdf").c_str());


	TCanvas* c_jetEpull_bjets = new TCanvas("c_jetEpull_bjets", "", 0, 0, 800, 800);
	TLegend* leg_jetEpull_bjets = new TLegend(0.2, 0.2, 0.5, 0.45);
	get_TProfile("TJjet_pullEseencorrected_vs_Etrue_bjets")->SetLineColor(9101);
	get_TProfile("TJjet_pullEseencorrected_vs_Etrue_bjets")->SetMarkerColor(9101);
	get_TProfile("TJjet_pullEseencorrected_vs_Etrue_bjets")->SetMarkerSize(2);
	get_TProfile("TJjet_pullEseen_vs_Etrue_bjets")->SetLineColor(9102);
	get_TProfile("TJjet_pullEseen_vs_Etrue_bjets")->SetMarkerColor(9102);
	get_TProfile("TJjet_pullEseen_vs_Etrue_bjets")->SetMarkerSize(2);
	get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_bjets")->SetLineColor(9103);
	get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_bjets")->SetMarkerColor(9103);
	get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_bjets")->SetMarkerSize(2);
	get_TProfile("TJjet_pullEseen_vs_Etrue_bjets")->Draw();
	get_TProfile("TJjet_pullEseencorrected_vs_Etrue_bjets")->Draw("same");
	get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_bjets")->Draw("same");
	leg_jetEpull_bjets->AddEntry(get_TProfile("TJjet_pullEseen_vs_Etrue_bjets"), "uncorrected");
	leg_jetEpull_bjets->AddEntry(get_TProfile("TJjet_pullEseencorrected_vs_Etrue_bjets"), "corrected");
	leg_jetEpull_bjets->AddEntry(get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_bjets"), "with MC #nu");
	leg_jetEpull_bjets->Draw();
	gPad->Update();
	TLine* pull_line_bjets = new TLine(0, 0, gPad->GetFrame()->GetX2(), 0);
	pull_line_bjets->SetLineWidth(1);
	pull_line_bjets->Draw("same");
	c_jetEpull_bjets->SetTopMargin(0.1);
	c_jetEpull_bjets->Print((output_dir + "/jetEpull_comparison_bjets.pdf").c_str());



	TCanvas* c_jetE_semilepbjets = new TCanvas("c_jetE_semilepbjets", "", 0, 0, 800, 800);
	TLegend* leg_jetE_semilepbjets = new TLegend(0.2, 0.62, 0.55, 0.85);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue_semilepbjets")->SetLineColor(9101);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue_semilepbjets")->SetMarkerColor(9101);
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue_semilepbjets")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets")->SetLineColor(9102);
	get_TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets")->SetMarkerColor(9102);
	get_TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_semilepbjets")->SetLineColor(9103);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_semilepbjets")->SetMarkerColor(9103);
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_semilepbjets")->SetMarkerSize(2);
	get_TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets")->SetMinimum(0);
	get_TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets")->Draw();
	get_TProfile("TJjet_meanEseencorrected_vs_Etrue_semilepbjets")->Draw("same");
	get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_semilepbjets")->Draw("same");
	leg_jetE_semilepbjets->AddEntry(get_TProfile("TJjet_meanEseen_vs_Etrue_semilepbjets"), "uncorrected");
	leg_jetE_semilepbjets->AddEntry(get_TProfile("TJjet_meanEseencorrected_vs_Etrue_semilepbjets"), "corrected");
	leg_jetE_semilepbjets->AddEntry(get_TProfile("TJjet_meanEseencorrectedwithMC_vs_Etrue_semilepbjets"), "with MC #nu");
	leg_jetE_semilepbjets->Draw();
	gPad->Update();
	TLine* profile_line_semilepbjets = new TLine(0, 0, gPad->GetFrame()->GetY2(), gPad->GetFrame()->GetY2());
	profile_line_semilepbjets->SetLineWidth(1);
	profile_line_semilepbjets->Draw("same");
	c_jetE_semilepbjets->SetTopMargin(0.1);
	c_jetE_semilepbjets->Print((output_dir + "/jetEreco_comparison_semilepbjets.pdf").c_str());


	TCanvas* c_jetEpull_semilepbjets = new TCanvas("c_jetEpull_semilepbjets", "", 0, 0, 800, 800);
	TLegend* leg_jetEpull_semilepbjets = new TLegend(0.2, 0.2, 0.5, 0.45);
	get_TProfile("TJjet_pullEseencorrected_vs_Etrue_semilepbjets")->SetLineColor(9101);
	get_TProfile("TJjet_pullEseencorrected_vs_Etrue_semilepbjets")->SetMarkerColor(9101);
	get_TProfile("TJjet_pullEseencorrected_vs_Etrue_semilepbjets")->SetMarkerSize(2);
	get_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets")->SetLineColor(9102);
	get_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets")->SetMarkerColor(9102);
	get_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets")->SetMarkerSize(2);
	get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_semilepbjets")->SetLineColor(9103);
	get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_semilepbjets")->SetMarkerColor(9103);
	get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_semilepbjets")->SetMarkerSize(2);
	// get_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets")->SetMinimum(-44);
	// get_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets")->SetMaximum(16);
	get_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets")->Draw();
	get_TProfile("TJjet_pullEseencorrected_vs_Etrue_semilepbjets")->Draw("same");
	get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_semilepbjets")->Draw("same");
	leg_jetEpull_semilepbjets->AddEntry(get_TProfile("TJjet_pullEseen_vs_Etrue_semilepbjets"), "uncorrected");
	leg_jetEpull_semilepbjets->AddEntry(get_TProfile("TJjet_pullEseencorrected_vs_Etrue_semilepbjets"), "corrected");
	leg_jetEpull_semilepbjets->AddEntry(get_TProfile("TJjet_pullEseencorrectedwithMC_vs_Etrue_semilepbjets"), "with MC #nu");
	leg_jetEpull_semilepbjets->Draw();
	gPad->Update();
	TLine* pull_line_semilepbjets = new TLine(0, 0, gPad->GetFrame()->GetX2(), 0);
	pull_line_semilepbjets->SetLineWidth(1);
	pull_line_semilepbjets->Draw("same");
	c_jetEpull_semilepbjets->SetTopMargin(0.1);
	c_jetEpull_semilepbjets->Print((output_dir + "/jetEpull_comparison_semilepbjets.pdf").c_str());

	// for (int i=0; i<get_number_TH2Ds(); i++) {
	// 	TH2D* current_h2 = get_TH2D_i(i);
	// 	TCanvas* current_canvas = new TCanvas(( std::string() + current_h2->GetName() + "_can").c_str(), "", 0, 0, 800, 800);
	// 	current_h2->Draw("colz");
	// 	current_canvas->SetRightMargin(0.2);
	// 	current_canvas->Print(( output_dir + "/h2_" + current_h2->GetName() + ".pdf").c_str());
	// 	// delete current_canvas;
	// }

}
