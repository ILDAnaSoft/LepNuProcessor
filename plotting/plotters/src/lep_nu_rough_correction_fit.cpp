#include "plotters.h"

// Very simple example

void RoughNuCorrectionFitPlotter::set_plotter_settings() {
	set_output_folder_name("rough_nu_correction_fit");
}

void RoughNuCorrectionFitPlotter::define_plots(){

	add_new_TH1D("x_parameter_all", new TH1D("x_parameter_all", "x parameter distribution, all parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_Cparents", new TH1D("x_parameter_Cparents", "x parameter distribution, C parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_Bparents", new TH1D("x_parameter_Bparents", "x parameter distribution, B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_CandBparents", new TH1D("x_parameter_CandBparents", "x parameter distribution, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TProfile("x_parameter_VS_Elep_CandBparents", new TProfile("x_parameter_VS_Elep_CandBparents", "x parameter : E_{lep} (Profile), C and B parents; E_{lep}; < ( E_{lep}/(E_{lep} + E_{#nu}) ) >", 5, 0, 100));


	add_new_TH1D("x_parameter_all_Elepmin1", new TH1D("x_parameter_all_Elepmin1", "x parameter distribution, E_{lep} > 1GeV, all parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_Cparents_Elepmin1", new TH1D("x_parameter_Cparents_Elepmin1", "x parameter distribution, E_{lep} > 1GeV, C parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_Bparents_Elepmin1", new TH1D("x_parameter_Bparents_Elepmin1", "x parameter distribution, E_{lep} > 1GeV, B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_CandBparents_Elepmin1", new TH1D("x_parameter_CandBparents_Elepmin1", "x parameter distribution, E_{lep} > 1GeV, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TProfile("x_parameter_VS_Elep_CandBparents_Elepmin1", new TProfile("x_parameter_VS_Elep_CandBparents_Elepmin1", "x parameter : E_{lep} (Profile), E_{lep} > 1GeV, C and B parents; E_{lep}; < ( E_{lep}/(E_{lep} + E_{#nu}) ) >", 25, 0, 100));

	add_new_TH1D("x_parameter_all_Elepmin3", new TH1D("x_parameter_all_Elepmin3", "x parameter distribution, E_{lep} > 3GeV, all parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_Cparents_Elepmin3", new TH1D("x_parameter_Cparents_Elepmin3", "x parameter distribution, E_{lep} > 3GeV, C parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_Bparents_Elepmin3", new TH1D("x_parameter_Bparents_Elepmin3", "x parameter distribution, E_{lep} > 3GeV, B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_CandBparents_Elepmin3", new TH1D("x_parameter_CandBparents_Elepmin3", "x parameter distribution, E_{lep} > 3GeV, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TProfile("x_parameter_VS_Elep_CandBparents_Elepmin3", new TProfile("x_parameter_VS_Elep_CandBparents_Elepmin3", "x parameter : E_{lep} (Profile), E_{lep} > 3GeV, C and B parents; E_{lep}; < ( E_{lep}/(E_{lep} + E_{#nu}) ) >", 25, 0, 100));

	add_new_TH1D("x_parameter_all_Elepmin5", new TH1D("x_parameter_all_Elepmin5", "x parameter distribution, E_{lep} > 5GeV, all parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_Cparents_Elepmin5", new TH1D("x_parameter_Cparents_Elepmin5", "x parameter distribution, E_{lep} > 5GeV, C parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_Bparents_Elepmin5", new TH1D("x_parameter_Bparents_Elepmin5", "x parameter distribution, E_{lep} > 5GeV, B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TH1D("x_parameter_CandBparents_Elepmin5", new TH1D("x_parameter_CandBparents_Elepmin5", "x parameter distribution, E_{lep} > 5GeV, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 20, 0, 1.001));
	add_new_TProfile("x_parameter_VS_Elep_CandBparents_Elepmin5", new TProfile("x_parameter_VS_Elep_CandBparents_Elepmin5", "x parameter : E_{lep} (Profile), E_{lep} > 5GeV, C and B parents; E_{lep}; < ( E_{lep}/(E_{lep} + E_{#nu}) ) >", 25, 0, 100));


	add_new_TH1D("x_parameter_CandBparents_Elep0to20", new TH1D("x_parameter_CandBparents_Elepmin0to20", "x parameter distribution, E_{lep} #in (0,20)GeV, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 5, 0, 1.001));
	add_new_TH1D("x_parameter_CandBparents_Elep20to40", new TH1D("x_parameter_CandBparents_Elep20to40", "x parameter distribution, E_{lep} #in (20,40)GeV, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 5, 0, 1.001));
	add_new_TH1D("x_parameter_CandBparents_Elep40to60", new TH1D("x_parameter_CandBparents_Elep40to60", "x parameter distribution, E_{lep} #in (40,60)GeV, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 5, 0, 1.001));
	add_new_TH1D("x_parameter_CandBparents_Elep60to80", new TH1D("x_parameter_CandBparents_Elep60to80", "x parameter distribution, E_{lep} #in (60,80)GeV, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 5, 0, 1.001));
	add_new_TH1D("x_parameter_CandBparents_Elep80to100", new TH1D("x_parameter_CandBparents_Elep80to100", "x parameter distribution, E_{lep} #in (80,100)GeV, C and B parents; E_{lep}/(E_{lep} + E_{#nu}); vertices", 5, 0, 1.001));

}

bool RoughNuCorrectionFitPlotter::is_neutrino_ID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

bool RoughNuCorrectionFitPlotter::is_Bmeson_ID( int pdgID ) {
  if ( fabs(pdgID) == 511 || fabs(pdgID) == 521 || fabs(pdgID) == 531 ){
      return true;
  } else {
    return false;
  }
}

bool RoughNuCorrectionFitPlotter::is_Cmeson_ID( int pdgID ) {
  if ( fabs(pdgID) == 411 || fabs(pdgID) == 421 || fabs(pdgID) == 431 ){
      return true;
  } else {
    return false;
  }
}

// TLorentzVector RoughNuCorrectionFitPlotter::get_parents_tlv( LepNuVertex *vertex ) {
// 	TLorentzVector parents_tlv {};
// 	int N_parents = (vertex->vertex_parents).GetEntries();
// 	for (int i_parent = 0; i_parent<N_parents; i_parent++) {
// 		Particle* parent = (Particle*)(vertex->vertex_parents)[i_parent];
// 		if ( ! isNeutrinoID(parent->MC.pdg_ID) ) { parents_tlv += parent->MC.tlv; }
// 	}
// 	return parents_tlv;
// }
//
// TLorentzVector RoughNuCorrectionFitPlotter::get_vis_tlv( LepNuVertex* vertex ){
// 	// Get non-nu daughter tlvs ( = "visible part of vertex")
// 	TLorentzVector vis_tlv {};
// 	int N_daughters = (vertex->vertex_daughters).GetEntries();
// 	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
// 		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
// 		if ( ! isNeutrinoID(daughter->MC.pdg_ID) ) { vis_tlv += daughter->MC.tlv; }
// 	}
// 	return vis_tlv;
// }

TLorentzVector RoughNuCorrectionFitPlotter::get_charged_lepton_daughters_tlv( LepNuVertex *vertex ) {
	TLorentzVector charged_lep_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! is_neutrino_ID(daughter->MC.pdg_ID) ) { charged_lep_tlv += daughter->MC.tlv; }
	}
	return charged_lep_tlv;
}

TLorentzVector RoughNuCorrectionFitPlotter::get_nu_daughters_tlv( LepNuVertex *vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( is_neutrino_ID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

void RoughNuCorrectionFitPlotter::fill_plots(){
	float weight = get_current_weight();

	// This is the loop over all events
	while ( get_next_event() ) {

		int N_vertices = (evt_info->total_event.lep_nu_vertices).GetEntries();
		for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
			LepNuVertex* vertex = (LepNuVertex*)evt_info->total_event.lep_nu_vertices[i_vertex];

			//TLorentzVector parents_tlv = get_parents_tlv( vertex );
			TLorentzVector charged_leps_tlv = get_charged_lepton_daughters_tlv( vertex );
			TLorentzVector nus_tlv = get_nu_daughters_tlv( vertex );

			double x = charged_leps_tlv.E() / (charged_leps_tlv.E() + nus_tlv.E());


			int first_parent_pdg = ((Particle*)((vertex->vertex_parents)[0]))->MC.pdg_ID;

			get_TH1D("x_parameter_all")->Fill(x, weight);
			if ( is_Cmeson_ID(first_parent_pdg) ) {
				get_TH1D("x_parameter_Cparents")->Fill(x, weight);
			}
			else if ( is_Bmeson_ID(first_parent_pdg) ) {
				get_TH1D("x_parameter_Bparents")->Fill(x, weight);
			}

			if ( is_Cmeson_ID(first_parent_pdg) || is_Bmeson_ID(first_parent_pdg) ) {
				get_TH1D("x_parameter_CandBparents")->Fill(x, weight);
				get_TProfile("x_parameter_VS_Elep_CandBparents")->Fill(charged_leps_tlv.E(), x, weight);
			}

			if ( charged_leps_tlv.E() > 1 ) {
				get_TH1D("x_parameter_all_Elepmin1")->Fill(x, weight);
				if ( is_Cmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_Cparents_Elepmin1")->Fill(x, weight);
				}
				else if ( is_Bmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_Bparents_Elepmin1")->Fill(x, weight);
				}

				if ( is_Cmeson_ID(first_parent_pdg) || is_Bmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_CandBparents_Elepmin1")->Fill(x, weight);
					get_TProfile("x_parameter_VS_Elep_CandBparents_Elepmin1")->Fill(charged_leps_tlv.E(), x, weight);
				}
			}

			if ( charged_leps_tlv.E() > 3 ) {
				get_TH1D("x_parameter_all_Elepmin3")->Fill(x, weight);
				if ( is_Cmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_Cparents_Elepmin3")->Fill(x, weight);
				}
				else if ( is_Bmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_Bparents_Elepmin3")->Fill(x, weight);
				}

				if ( is_Cmeson_ID(first_parent_pdg) || is_Bmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_CandBparents_Elepmin3")->Fill(x, weight);
					get_TProfile("x_parameter_VS_Elep_CandBparents_Elepmin3")->Fill(charged_leps_tlv.E(), x, weight);
				}
			}

			if ( charged_leps_tlv.E() > 5 ) {
				get_TH1D("x_parameter_all_Elepmin5")->Fill(x, weight);
				if ( is_Cmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_Cparents_Elepmin5")->Fill(x, weight);
				}
				else if ( is_Bmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_Bparents_Elepmin5")->Fill(x, weight);
				}

				if ( is_Cmeson_ID(first_parent_pdg) || is_Bmeson_ID(first_parent_pdg) ) {
					get_TH1D("x_parameter_CandBparents_Elepmin5")->Fill(x, weight);
					get_TProfile("x_parameter_VS_Elep_CandBparents_Elepmin5")->Fill(charged_leps_tlv.E(), x, weight);
				}
			}

			if ( is_Cmeson_ID(first_parent_pdg) || is_Bmeson_ID(first_parent_pdg) ) {
				if ( charged_leps_tlv.E() > 0 && charged_leps_tlv.E() < 20) {
					get_TH1D("x_parameter_CandBparents_Elep0to20")->Fill(x, weight);
				}
				if ( charged_leps_tlv.E() > 20 && charged_leps_tlv.E() < 40) {
					get_TH1D("x_parameter_CandBparents_Elep20to40")->Fill(x, weight);
				}
				if ( charged_leps_tlv.E() > 40 && charged_leps_tlv.E() < 60) {
					get_TH1D("x_parameter_CandBparents_Elep40to60")->Fill(x, weight);
				}
				if ( charged_leps_tlv.E() > 60 && charged_leps_tlv.E() < 80) {
					get_TH1D("x_parameter_CandBparents_Elep60to80")->Fill(x, weight);
				}
				if ( charged_leps_tlv.E() > 80 && charged_leps_tlv.E() < 100) {
					get_TH1D("x_parameter_CandBparents_Elep80to100")->Fill(x, weight);
				}
			}

		}
	}
}

void RoughNuCorrectionFitPlotter::get_resolution_projection ( TProfile* plot, TH1D* error_clone ){
	for (int i=1; i<plot->GetNbinsX()+2; i++) {
		if (plot->GetBinContent(i) != 0){
			std::cout << "\n" << plot->GetBinError(i)/plot->GetBinContent(i)*100.0;
			error_clone->SetBinContent( i, plot->GetBinError(i)/plot->GetBinContent(i)*100.0 );
		} else {
			error_clone->SetBinContent(i, 0);
		}
		error_clone->SetBinError( i, 0.000001 );
	}
}


void RoughNuCorrectionFitPlotter::draw_plots(){
	std::string output_dir = get_output_directory();

	TH1D *x_resolution_VS_Elep_CandBparents = (TH1D*)(get_TProfile("x_parameter_VS_Elep_CandBparents"))->ProjectionX("x_resolution_projection_VS_Elep_CandBparents");
	get_resolution_projection(get_TProfile("x_parameter_VS_Elep_CandBparents"), x_resolution_VS_Elep_CandBparents);
	x_resolution_VS_Elep_CandBparents->SetTitle("x resolution : E_{lep} (Profile), C and B parents; E_{lep}; #Delta <x>");
	add_new_TH1D("x_resolution_VS_Elep_CandBparents", x_resolution_VS_Elep_CandBparents);


	TCanvas* c_x = new TCanvas("c_x", "", 0, 0, 800, 800);
	TLegend* leg_x = new TLegend(0.6, 0.7, 0.9, 0.9);
	get_TH1D("x_parameter_CandBparents")->SetLineColor(9101);
	get_TH1D("x_parameter_CandBparents")->SetMarkerColor(9101);
	get_TH1D("x_parameter_CandBparents")->SetMarkerSize(2);
	get_TH1D("x_parameter_CandBparents")->Draw();
	leg_x->AddEntry(get_TH1D("x_parameter_CandBparents"), "E_{lep,min} = 0");
	get_TH1D("x_parameter_CandBparents_Elepmin1")->SetLineColor(9102);
	get_TH1D("x_parameter_CandBparents_Elepmin1")->SetMarkerColor(9102);
	get_TH1D("x_parameter_CandBparents_Elepmin1")->SetMarkerSize(2);
	get_TH1D("x_parameter_CandBparents_Elepmin1")->Draw("same");
	leg_x->AddEntry(get_TH1D("x_parameter_CandBparents_Elepmin1"), "E_{lep,min} = 1");
	get_TH1D("x_parameter_CandBparents_Elepmin3")->SetLineColor(9103);
	get_TH1D("x_parameter_CandBparents_Elepmin3")->SetMarkerColor(9103);
	get_TH1D("x_parameter_CandBparents_Elepmin3")->SetMarkerSize(2);
	get_TH1D("x_parameter_CandBparents_Elepmin3")->Draw("same");
	leg_x->AddEntry(get_TH1D("x_parameter_CandBparents_Elepmin3"), "E_{lep,min} = 3");
	get_TH1D("x_parameter_CandBparents_Elepmin5")->SetLineColor(9104);
	get_TH1D("x_parameter_CandBparents_Elepmin5")->SetMarkerColor(9104);
	get_TH1D("x_parameter_CandBparents_Elepmin5")->SetMarkerSize(2);
	get_TH1D("x_parameter_CandBparents_Elepmin5")->Draw("same");
	leg_x->AddEntry(get_TH1D("x_parameter_CandBparents_Elepmin5"), "E_{lep,min} = 5");
	leg_x->Draw();
	c_x->Print((output_dir + "/x_distributions.pdf").c_str());

	TCanvas* c_x_0to20 = new TCanvas("c_x_0to20", "", 0, 0, 800, 800);
	get_TH1D("x_parameter_CandBparents_Elep0to20")->Draw();
	c_x_0to20->SetTopMargin(0.1);
	c_x_0to20->Print((output_dir + "/x_distribution_Elep0to20.pdf").c_str());

	TCanvas* c_x_20to40 = new TCanvas("c_x_20to40", "", 0, 0, 800, 800);
	get_TH1D("x_parameter_CandBparents_Elep20to40")->Draw();
	c_x_20to40->SetTopMargin(0.1);
	c_x_20to40->Print((output_dir + "/x_distribution_Elep20to40.pdf").c_str());

	TCanvas* c_x_40to60 = new TCanvas("c_x_40to60", "", 0, 0, 800, 800);
	get_TH1D("x_parameter_CandBparents_Elep40to60")->Draw();
	c_x_40to60->SetTopMargin(0.1);
	c_x_40to60->Print((output_dir + "/x_distribution_Elep40to60.pdf").c_str());

	TCanvas* c_x_60to80 = new TCanvas("c_x_60to80", "", 0, 0, 800, 800);
	get_TH1D("x_parameter_CandBparents_Elep60to80")->Draw();
	c_x_60to80->SetTopMargin(0.1);
	c_x_60to80->Print((output_dir + "/x_distribution_Elep60to80.pdf").c_str());

	TCanvas* c_x_80to100 = new TCanvas("c_x_80to100", "", 0, 0, 800, 800);
	get_TH1D("x_parameter_CandBparents_Elep80to100")->Draw();
	c_x_80to100->SetTopMargin(0.1);
	c_x_80to100->Print((output_dir + "/x_distribution_Elep80to100.pdf").c_str());



	TF1 *fit_x = new TF1("fit_x", " [0]*x / ([1] + x) ", 0, 100 );
	TCanvas* c_x_profile = new TCanvas("c_x_profile", "", 0, 0, 800, 800);
	TLegend* leg_x_profile = new TLegend(0.5, 0.3, 0.87, 0.5);
	get_TProfile("x_parameter_VS_Elep_CandBparents")->Draw();
	get_TProfile("x_parameter_VS_Elep_CandBparents")->Fit("fit_x");
	leg_x_profile->AddEntry(fit_x, "a E_{lep} / (b + E_{lep})", "l");
	leg_x_profile->Draw();
	c_x_profile->SetTopMargin(0.1);
	c_x_profile->Print((output_dir + "/x_profile.pdf").c_str());


	TF1 *fit_dx = new TF1("fit_dx", " [0]+[1]*x ", 0, 100 );
	TCanvas* c_dx = new TCanvas("c_dx_profile", "", 0, 0, 800, 800);
	TLegend* leg_dx = new TLegend(0.5, 0.3, 0.87, 0.5);
	x_resolution_VS_Elep_CandBparents->Draw();
	x_resolution_VS_Elep_CandBparents->Fit("fit_dx");
	leg_dx->AddEntry(fit_x, "a + b E_{lep}", "l");
	leg_dx->Draw();
	c_dx->SetTopMargin(0.1);
	c_dx->Print((output_dir + "/dx_distribution.pdf").c_str());


	//TF1 *f1 = new TF1("f1", "[0]*x+[1]", 0, 100 )

	//new TH1D("x_resolution_VS_Elep_CandBparents", "x resolution : E_{lep} (Profile), C and B parents; E_{lep}; #Delta <x>", 25, 0, 100));

	//TCanvas* c1 = new TCanvas("c1", "", 0, 0, 800, 800);
	//get_TH1D("test")->Draw();
	//c1->Print((output_dir + "/test.pdf").c_str());
}
