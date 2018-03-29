#include "plotters.h"

// Very simple example

void LepNuPairPlotter::set_plotter_settings() {
	set_output_folder_name("lep_nu_pairs");
}

void LepNuPairPlotter::define_plots(){
	add_new_TH2D("lep_nu_E",
		new TH2D(	"lep_nu_E", "lep-#nu-pair energies; E_{l} [GeV]; E_{#nu} [GeV]; Pairs",
					40, 0, 20, 40, 0, 20 ) );

	add_new_TH2D("lep_nu_theta",
		new TH2D(	"lep_nu_theta", "lep-#nu-pair thetas; #theta_{l} [GeV]; #theta_{#nu} [GeV]; Pairs",
					100, 0, 3.2, 100, 0, 3.2 ) );

	add_new_TH2D("lep_nu_phi",
		new TH2D(	"lep_nu_phi", "lep-#nu-pair phis; #phi_{l} [GeV]; #phi_{#nu} [GeV]; Pairs",
					100, 0, 3.2, 100, 0, 3.2 ) );

	add_new_TH2D("lep_nu_E_bjets",
		new TH2D(	"lep_nu_E_bjets", "lep-#nu-pair energies, b jets; E_{l} [GeV]; E_{#nu} [GeV]; Pairs",
					40, 0, 20, 40, 0, 20 ) );

	add_new_TH2D("lep_nu_theta_bjets",
		new TH2D(	"lep_nu_theta_bjets", "lep-#nu-pair thetas, b jets; #theta_{l} [GeV]; #theta_{#nu} [GeV]; Pairs",
					100, 0, 3.2, 100, 0, 3.2 ) );

	add_new_TH2D("lep_nu_phi_bjets",
		new TH2D(	"lep_nu_phi_bjets", "lep-#nu-pair phis, b jets; #phi_{l} [GeV]; #phi_{#nu} [GeV]; Pairs",
					100, 0, 3.2, 100, 0, 3.2 ) );



	add_new_TH2D("lep_nu_E_electrons",
		new TH2D(	"lep_nu_E_electrons", "lep-#nu-pair energies, electrons; E_{l} [GeV]; E_{#nu} [GeV]; Pairs",
					40, 0, 20, 40, 0, 20 ) );

	add_new_TH2D("lep_nu_theta_electrons",
		new TH2D(	"lep_nu_theta_electrons", "lep-#nu-pair thetas, electrons; #theta_{l} [GeV]; #theta_{#nu} [GeV]; Pairs",
					100, 0, 3.2, 100, 0, 3.2 ) );

	add_new_TH2D("lep_nu_phi_electrons",
		new TH2D(	"lep_nu_phi_electrons", "lep-#nu-pair phis, electrons; #phi_{l} [GeV]; #phi_{#nu} [GeV]; Pairs",
					100, 0, 3.2, 100, 0, 3.2 ) );

	add_new_TH2D("lep_nu_E_muons",
		new TH2D(	"lep_nu_E_muons", "lep-#nu-pair energies, muons; E_{l} [GeV]; E_{#nu} [GeV]; Pairs",
					40, 0, 20, 40, 0, 20 ) );

	add_new_TH2D("lep_nu_theta_muons",
		new TH2D(	"lep_nu_theta_muons", "lep-#nu-pair thetas, muons; #theta_{l} [GeV]; #theta_{#nu} [GeV]; Pairs",
					100, 0, 3.2, 100, 0, 3.2 ) );

	add_new_TH2D("lep_nu_phi_muons",
		new TH2D(	"lep_nu_phi_muons", "lep-#nu-pair phis, muons; #phi_{l} [GeV]; #phi_{#nu} [GeV]; Pairs",
					100, 0, 3.2, 100, 0, 3.2 ) );
}

void LepNuPairPlotter::fill_plots(){
	float weight = get_current_weight();

	// This is the loop over all events
	while ( get_next_event() ) {
		//get_TH1D("test")->Fill(evt_info->evtN, weight);


		int N_tj_jets = (evt_info->tj_jets).GetEntries();
		for (int i_jet = 0; i_jet<N_tj_jets; i_jet++ ) {
			TJJet *jet = (TJJet*)evt_info->tj_jets[i_jet];
			int N_pairs = (jet->lep_nu_pairs).GetEntries();

			for (int i_pair = 0; i_pair<N_pairs; i_pair++ ) {
				LepNuPair *pair = (LepNuPair*)jet->lep_nu_pairs[i_pair];
				TLorentzVector tlv_l = pair->tlv_lep;
				TLorentzVector tlv_n = pair->get_total_nu_tlv();

				get_TH2D("lep_nu_E")->Fill(tlv_l.E(), tlv_n.E(), weight);
				get_TH2D("lep_nu_theta")->Fill(tlv_l.Theta(), tlv_n.Theta(), weight);
				get_TH2D("lep_nu_phi")->Fill(tlv_l.Phi(), tlv_n.Phi(), weight);

				if ( fabs(jet->fe_pdgID) == 5 ) {
					get_TH2D("lep_nu_E_bjets")->Fill(tlv_l.E(), tlv_n.E(), weight);
					get_TH2D("lep_nu_theta_bjets")->Fill(tlv_l.Theta(), tlv_n.Theta(), weight);
					get_TH2D("lep_nu_phi_bjets")->Fill(tlv_l.Phi(), tlv_n.Phi(), weight);
				}


				if ( fabs(pair->lep_ID) == 11 ) {
					get_TH2D("lep_nu_E_electrons")->Fill(tlv_l.E(), tlv_n.E(), weight);
					get_TH2D("lep_nu_theta_electrons")->Fill(tlv_l.Theta(), tlv_n.Theta(), weight);
					get_TH2D("lep_nu_phi_electrons")->Fill(tlv_l.Phi(), tlv_n.Phi(), weight);
				}


				if ( fabs(pair->lep_ID) == 13 ) {
					get_TH2D("lep_nu_E_muons")->Fill(tlv_l.E(), tlv_n.E(), weight);
					get_TH2D("lep_nu_theta_muons")->Fill(tlv_l.Theta(), tlv_n.Theta(), weight);
					get_TH2D("lep_nu_phi_muons")->Fill(tlv_l.Phi(), tlv_n.Phi(), weight);
				}
			}
		}
	}
}

void LepNuPairPlotter::draw_plots(){
	//std::string output_dir = get_output_directory();

	//TCanvas* c1 = new TCanvas("c1", "", 0, 0, 800, 800);
	//get_TH1D("test")->Draw();
	//c1->Print((output_dir + "/test.pdf").c_str());
}
