#include "plotters.h"

void CheatedCorrectionPlotter::set_plotter_settings() {
	set_output_folder_name("cheated_correction");
}

std::vector<std::string> particle_names = {"light_quarks", "charm", "bottom"};

void CheatedCorrectionPlotter::define_plots(){
	for (int i=0; i<particle_names.size(); i++) {
		std::string particle_name = particle_names[i];
		add_new_TProfile( ("profile_s_t_E_"+particle_name).c_str(), new TProfile(("profile_detected_vs_true_E_" + particle_name).c_str(), "x: true - y: reco, cheated #nu correction; E_{true}^{jet} [GeV]; E_{reco}^{jet} [GeV]", 75, 0, 150) );
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
		  if ( (jet->fe_pdgID == 1) ||  (jet->fe_pdgID == 2) || (jet->fe_pdgID == 3) ) {
		          particle_name = "light_quarks";
		  }
		  else if ( jet->fe_pdgID == 4 ) { particle_name = "charm"; }
		  else if ( jet->fe_pdgID == 5 ) { particle_name = "bottom"; }
      else { particle_name = "other"; continue; }

			TLorentzVector tlv_jet_true = jet->tlv_true;
			TLorentzVector tlv_jet_seen_corrected = jet->tlv_seen;

			int N_pairs = (jet->lep_nu_pairs).GetEntries();

			// Cheated correction loop
			for (int i_pair = 0; i_pair<N_pairs; i_pair++ ) {
				LepNuPair *pair = (LepNuPair*)jet->lep_nu_pairs[i_pair];

				int N_nus = (pair->nus).GetEntries();
				for (int i_nu = 0; i_nu<N_nus; i_nu++ ) {
					Nu* nu = (Nu*)pair->nus[i_nu];

					TLorentzVector tlv_nu = pair->get_total_nu_tlv();
					tlv_jet_seen_corrected += tlv_nu;
				}
			}

			get_TProfile(("profile_s_t_E_"+particle_name).c_str())->Fill( tlv_jet_true.E(), tlv_jet_seen_corrected.E(), weight );

		}
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

}
