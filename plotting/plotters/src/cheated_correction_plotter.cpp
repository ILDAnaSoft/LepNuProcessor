#include "plotters.h"

void CheatedCorrectionPlotter::set_plotter_settings() {
	set_output_folder_name("cheated_correction");
}

std::vector<std::string> particle_names = {"light_quarks", "charm", "bottom"};

void CheatedCorrectionPlotter::define_plots(){
	for (int i=0; i<particle_names.size(); i++) {
		std::string particle_name = particle_names[i];
		add_new_TProfile( ("profile_s_t_E_"+particle_name).c_str(), new TProfile(("profile_detected_vs_true_E_" + particle_name).c_str(), "x: true - y: reco, cheated #nu correction; E_{true}^{jet} [GeV]; E_{reco}^{jet} [GeV]", 75, 0, 150) );
		add_new_TProfile( ("profile_s_t_JER_"+particle_name).c_str(), new TProfile(("profile_detected_vs_true_JER_" + particle_name).c_str(), "Jet Energy Resolution w/ TJ, cheated #nu correction; E_{j}^{true} [GeV]; (RMS(E_{j})/Mean(E_{j}))_{reco} [%]", 25, 0, 500) );
	}
}

void CheatedCorrectionPlotter::fill_plots(){
	float weight = get_current_weight();

	// This is the loop over all events
	while ( get_next_event() ) {


		int N_tj_jets = (evt_info->tj_jets).GetEntries();
		for (int i_jet = 0; i_jet<N_tj_jets; i_jet++ ) {
			TJJet *jet = (TJJet*)evt_info->tj_jets[i_jet];

			std::string particle_name;
			int abs_final_elementon_pdgID = fabs( jet->fe_pdgID );
		  if ( (abs_final_elementon_pdgID == 1) ||  (abs_final_elementon_pdgID == 2) || (abs_final_elementon_pdgID == 3) ) {
		          particle_name = "light_quarks";
		  }
		  else if ( abs_final_elementon_pdgID == 4 ) { particle_name = "charm"; }
		  else if ( abs_final_elementon_pdgID == 5 ) { particle_name = "bottom"; }
      else { particle_name = "other"; continue; }

			TLorentzVector tlv_jet_true = jet->tlv_true;
			TLorentzVector tlv_jet_seen_corrected = jet->tlv_seen;

			int N_pairs = (jet->lep_nu_pairs).GetEntries();

			// Cheated correction loop
			for (int i_pair = 0; i_pair<N_pairs; i_pair++ ) {
				LepNuPair *pair = (LepNuPair*)jet->lep_nu_pairs[i_pair];

				TLorentzVector tlv_nu = pair->get_total_nu_tlv();
				tlv_jet_seen_corrected += tlv_nu;
			}

			get_TProfile(("profile_s_t_E_"+particle_name).c_str())->Fill( tlv_jet_true.E(), tlv_jet_seen_corrected.E(), weight );
			get_TProfile(("profile_s_t_JER_"+particle_name).c_str())->Fill( tlv_jet_true.E(), tlv_jet_seen_corrected.E(), weight );

		}
	}
}

void CheatedCorrectionPlotter::get_resolution_projection( TProfile* plot, TH1D* error_clone ){
	plot->SetErrorOption("s");
	for (int i=1; i<plot->GetNbinsX()+2; i++) {
		if (plot->GetBinContent(i) > 0){
	    error_clone->SetBinContent( i, plot->GetBinError(i)/plot->GetBinContent(i)*100.0 );
		} else {
	    error_clone->SetBinContent(i, 0);
		}
		error_clone->SetBinError( i, 0.000001 );
	}
}



void CheatedCorrectionPlotter::draw_plots(){

	std::vector<std::array<float, 3>> colors {{27,158,119}, {217,95,2}, {117,112,179}, {231,41,138}};
  for (int j=0; j<colors.size(); j++) {
    TColor *h2_color = new TColor(9100+j, colors[j][0]/256.0, colors[j][1]/256.0, colors[j][2]/256.0);
  }

	TCanvas *canvas_profile_s_t = new TCanvas("can_profile_s_t_E", "", 0, 0, 600, 600);
	TLegend* legend_profile_s_t = new TLegend(0.25, 0.6, 0.45, 0.9);

	for (int i=0; i<particle_names.size(); i++) {
		std::string particle_name = particle_names[i];
		canvas_profile_s_t->cd();
		TProfile* profile_s_t = get_TProfile(("profile_s_t_E_" + particle_name).c_str());
		profile_s_t->SetLineColor(9100+i);
		profile_s_t->SetMarkerColor(9100+i);
		profile_s_t->SetMarkerSize(0.1);
		legend_profile_s_t->AddEntry(profile_s_t, particle_name.c_str(), "l");
		profile_s_t->Draw("same");
	}

	canvas_profile_s_t->cd();
	gPad->Update();
	double y_max = gPad->GetFrame()->GetY2();
	if ( y_max > 150 ) { y_max = 150; }
	TLine* profile_line = new TLine(0, 0, y_max, y_max);
	profile_line->SetLineWidth(1);
	profile_line->Draw("same");
	legend_profile_s_t->Draw();
	std::string plot_name_profile_s_t = get_output_directory() + "/profile_detected_w_cheated_nu_correction_vs_true_E.pdf";
	canvas_profile_s_t->Print(plot_name_profile_s_t.c_str());
	canvas_profile_s_t->Close();


	// Plot JER
	TCanvas *canvas_profile_s_t_JER = new TCanvas("can_profile_s_t_JER", "", 0, 0, 600, 600);
	TLegend* legend_profile_s_t_JER = new TLegend(0.25, 0.6, 0.45, 0.9);

	for (int i=0; i<particle_names.size(); i++) {
		std::string particle_name = particle_names[i];


		canvas_profile_s_t_JER->cd();
		TProfile* profile_s_t = get_TProfile(("profile_s_t_JER_" + particle_name).c_str());

		TH1D* resolution_plot =  (TH1D*)profile_s_t->ProjectionX(("resolution_E_" + particle_name).c_str());

		get_resolution_projection(profile_s_t, resolution_plot);

		resolution_plot->SetMinimum(0);
		resolution_plot->SetMaximum(100);
		resolution_plot->SetLineColor(9100+i);
		resolution_plot->SetLineWidth(5);
		resolution_plot->SetMarkerColor(9100+i);
		resolution_plot->SetMarkerSize(0.1);
		legend_profile_s_t_JER->AddEntry(resolution_plot, particle_name.c_str(), "l");
		resolution_plot->Draw("p same");

	}

	legend_profile_s_t_JER->Draw();
	std::string plot_name_profile_s_t_JER = get_output_directory() + "/JER_detected_w_cheated_nu_correction_vs_true_E.pdf";
	canvas_profile_s_t_JER->Print(plot_name_profile_s_t_JER.c_str());
	canvas_profile_s_t_JER->Close();


}
