#include "plotters.h"

void RoughNuCorrectionPOPPlotter::set_plotter_settings() {
	set_output_folder_name("rough_nu_correction_pop");
}

void RoughNuCorrectionPOPPlotter::define_plots(){
	add_new_TH2D("nu_E", new TH2D("nu_E", "E_{#nu}^{calc from MC lep} : E_{#nu}^{lep}; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );

	add_new_TH2D("nu_E_CandBparents_only", new TH2D("nu_E_CandBparents_only", "E_{#nu}^{calc from MC lep} : E_{#nu}^{lep}, C and B parents; E_{#nu}^{MC} [GeV]; E_{#nu}^{calcx} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_CandBparents_only_0vertex", new TH2D("nu_E_CandBparents_only_0vertex", "E_{#nu}^{calc from MC lep} : E_{#nu}^{lep}, C and B parents starting at 0; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_CandBparents_only_0vertex_visEgr5", new TH2D("nu_E_CandBparents_only_0vertex_visEgr5", "E_{#nu}^{calc from MC lep} : E_{#nu}^{lep}, C and B parents starting at 0, E_{vis}>5; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_CandBparents_only_0vertex_lepEgr5", new TH2D("nu_E_CandBparents_only_0vertex_lepEgr5", "E_{#nu}^{calc from MC lep} : E_{#nu}^{lep}, C and B parents starting at 0, E_{lep}>5; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );

	const int N_profile_bins = 12;
	double profile_binning[N_profile_bins+1] = {0, 1, 2, 3, 5, 7, 10, 15, 20, 30, 50, 70, 100};

	add_new_TProfile("nu_E_profile_CandBparents_only", new TProfile("nu_E_profile_CandBparents_only", "<E_{#nu}^{calc from MC lep}> : E_{#nu}^{lep}, C and B parents; E_{#nu}^{MC} [GeV], C and B parents; E_{#nu}^{calc} [GeV]; #nu's", N_profile_bins, profile_binning) );
	add_new_TProfile("nu_E_correction_pull_VS_Elep_CandBparents_only", new TProfile("nu_E_correction_pull_VS_Elep_CandBparents_only", "<E_{#nu}^{calc from MC lep} - E_{#nu}^{MC}> : E_{lep}, C and B parents; E_{lep}; <E_{#nu}^{calc from MC lep} - E_{#nu}^{MC}>", N_profile_bins, profile_binning));

	get_TProfile("nu_E_profile_CandBparents_only")->SetErrorOption("s");
	get_TProfile("nu_E_correction_pull_VS_Elep_CandBparents_only")->SetErrorOption("s");
}

bool RoughNuCorrectionPOPPlotter::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

TLorentzVector RoughNuCorrectionPOPPlotter::get_nu_daughters_tlv( LepNuVertex* vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( isNeutrinoID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

TLorentzVector RoughNuCorrectionPOPPlotter::get_vis_tlv( LepNuVertex* vertex ){
	// Get non-nu daughter tlvs ( = "visible part of vertex")
	TLorentzVector vis_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( ! isNeutrinoID(daughter->MC.pdg_ID) ) { vis_tlv += daughter->MC.tlv; }
	}
	return vis_tlv;
}

TLorentzVector RoughNuCorrectionPOPPlotter::get_charged_leptons_tlv( LepNuVertex* vertex ){
	TLorentzVector charged_lep_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { charged_lep_tlv += daughter->MC.tlv; }
	}
	return charged_lep_tlv;
}

bool  RoughNuCorrectionPOPPlotter::is_Bmeson_ID( int pdgID ) {
  if ( ( fabs(pdgID) >= 500 && fabs(pdgID) < 600 ) || ( fabs(pdgID) >= 5000 && fabs(pdgID) < 6000 ) ) { 
      return true;
  } else {
    return false;
  }
}

bool  RoughNuCorrectionPOPPlotter::is_Cmeson_ID( int pdgID ) {
  if ( ( fabs(pdgID) >= 400 && fabs(pdgID) < 500 ) || ( fabs(pdgID) >= 4000 && fabs(pdgID) < 5000 ) ) {
      return true;
  } else {
    return false;
  }
}

double RoughNuCorrectionPOPPlotter::fitted_mean_x( double E_lep ){
	double a = 0.76;
	double b = 2.4;
	return a*E_lep / ( b + E_lep );
}

double RoughNuCorrectionPOPPlotter::fitted_delta_mean_x( double E_lep ){
	double a = 0.24;
	double b = -0.0012;
	return a + b*E_lep;
}

double RoughNuCorrectionPOPPlotter::nu_energy_error_estimate( double E_lep ) {
	double mean_x = fitted_mean_x(E_lep);
	double d_mean_x = fitted_delta_mean_x(E_lep);
	return d_mean_x/mean_x * E_lep;
}

double RoughNuCorrectionPOPPlotter::nu_energy_correction( double E_lep ){
	if ( E_lep > 0 ) {
		double mean_x = fitted_mean_x(E_lep);
		return (1.0/mean_x - 1) * E_lep;
	} else {
		return 0;
	}
}

void RoughNuCorrectionPOPPlotter::fill_plots(){
	float weight = get_current_weight();

	// int i=1;
	// This is the loop over all events
	while ( get_next_event() ) {
		int N_vertices = (evt_info->total_event.lep_nu_vertices).GetEntries();
		// std::cout << i++ << "\n";
		for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
			LepNuVertex* vertex = (LepNuVertex*)evt_info->total_event.lep_nu_vertices[i_vertex];

			TLorentzVector vis_tlv = get_vis_tlv(vertex);
			float vis_E = vis_tlv.E();
			TLorentzVector nu_tlv_true = get_nu_daughters_tlv( vertex );
			int first_parent_pdg = ((Particle*)((vertex->vertex_parents)[0]))->MC.pdg_ID;

			float E_lep = (get_charged_leptons_tlv(vertex)).E();
			double nu_E = nu_energy_correction( E_lep );

			get_TH2D("nu_E")->Fill(nu_tlv_true.E(), nu_E, 1);

			if ( is_Cmeson_ID(first_parent_pdg) || is_Bmeson_ID(first_parent_pdg) ) {
				get_TH2D("nu_E_CandBparents_only")->Fill(nu_tlv_true.E(), nu_E, 1);
				get_TProfile("nu_E_profile_CandBparents_only")->Fill(nu_tlv_true.E(), nu_E, 1);
				get_TProfile("nu_E_correction_pull_VS_Elep_CandBparents_only")->Fill(E_lep, (nu_E - nu_tlv_true.E()), 1);
				float parent_init_pos = ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(); // TODO Adjust to non-zero init vertex
				if ( parent_init_pos == 0.0 ) {
					get_TH2D("nu_E_CandBparents_only_0vertex")->Fill(nu_tlv_true.E(), nu_E, 1);
					if ( vis_E > 5.0) {
						get_TH2D("nu_E_CandBparents_only_0vertex_visEgr5")->Fill(nu_tlv_true.E(), nu_E, 1);
					}

					if ( E_lep > 5.0) {
						get_TH2D("nu_E_CandBparents_only_0vertex_lepEgr5")->Fill(nu_tlv_true.E(), nu_E, 1);
					}
				}
			}
		}
	}
}

void RoughNuCorrectionPOPPlotter::draw_plots(){
	std::string output_dir = get_output_directory();

	const int N_profile_bins = 12;

	TGraph* pull_error_estimate = new TGraph(14);
	//double E_lep_array[5], pull_plus_delta_array[5], pull_minus_delta_array[5];
	for (int i=0; i<N_profile_bins; i++) {
		double E_lep = get_TProfile("nu_E_correction_pull_VS_Elep_CandBparents_only")->GetBinCenter(i+1);
		double pull = get_TProfile("nu_E_correction_pull_VS_Elep_CandBparents_only")->GetBinContent(i+1);
		double delta_estimation = nu_energy_error_estimate(E_lep);
		// std::cout << "\n" << delta_estimation;
		// E_lep_array[i] = E_lep;
		// pull_plus_delta_array[i] = pull + delta_estimation;
		// pull_minus_delta_array[i] = pull - delta_estimation;
		pull_error_estimate->SetPoint(2*i, E_lep, pull + delta_estimation);
		pull_error_estimate->SetPoint(2*i+1, E_lep, pull - delta_estimation);
	}
	pull_error_estimate->SetMarkerColor(2);
	pull_error_estimate->SetMarkerSize(2);
	pull_error_estimate->SetLineStyle(0);

	TCanvas* c_pull_profile = new TCanvas("c_pull_profile", "", 0, 0, 800, 800);
	TLegend* leg_pull_profile = new TLegend(0.25, 0.7, 0.55, 0.85);
	get_TProfile("nu_E_correction_pull_VS_Elep_CandBparents_only")->Draw();
	pull_error_estimate->Draw("same *");
	leg_pull_profile->AddEntry(pull_error_estimate, "error estimate", "p");
	leg_pull_profile->Draw("same");
	TLine* pull_profile_line = new TLine(0, 0, 100, 0);
	pull_profile_line->Draw("same");
	c_pull_profile->SetTopMargin(0.1);
	c_pull_profile->Modified();
	c_pull_profile->Update();
	c_pull_profile->Print((output_dir + "/pull_profile.pdf").c_str());




	// for (int i=0; i<get_number_TH2Ds(); i++) {
	// 	TH2D* current_h2 = get_TH2D_i(i);
	// 	TCanvas* current_canvas = new TCanvas(( std::string() + current_h2->GetName() + "_can").c_str(), "", 0, 0, 800, 800);
	// 	current_h2->Draw("colz");
	// 	current_canvas->SetRightMargin(0.2);
	// 	current_canvas->Print(( output_dir + "/h2_" + current_h2->GetName() + ".pdf").c_str());
	// 	// delete current_canvas;
	// }

}
