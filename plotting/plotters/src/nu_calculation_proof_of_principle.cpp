#include "plotters.h"

void NuCalculationPOPPlotter::set_plotter_settings() {
	set_output_folder_name("nu_calculation_pop");
}

void NuCalculationPOPPlotter::define_plots(){
	add_new_TH1D("N_vertices", new TH1D("N_vertices", "Number of ch. lep. + #nu vertices in event; N_{l-#nu vertices}; Event", 7, -0.5, 6.5));

	add_new_TH2D("nu_E_plus", new TH2D("nu_E_plus", "#nu calculation from MC info; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_p_plus", new TH2D("nu_p_plus", "#nu calculation from MC info; p_{#nu}^{MC} [GeV]; p_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_theta_plus", new TH2D("nu_theta_plus", "#nu calculation from MC info; #theta_{#nu}^{MC}; #theta_{#nu}^{calc from MC vertex}; #nu's", 32, 0, 3.2, 32, 0, 3.2) );
	add_new_TH2D("nu_phi_plus", new TH2D("nu_phi_plus", "#nu calculation from MC info; #phi_{#nu}^{MC}; #phi_{#nu}^{calc from MC vertex}; #nu's", 32, -3.2, 3.2, 32, -3.2, 3.2) );

	add_new_TH1D("non-reconstructed_nu_parent_init_vertex_plus", new TH1D("non_plus-reconstructed_nu_parent_init_vertex", "Init. vertex radius of first parent of non-reconstructed #nu's; r_{parent}^{MC} [mm]; #nu's", 100, 0, 3000));
	add_new_TH1D("non-reconstructed_nu_E_plus", new TH1D("non_plus-reconstructed_nu_E", "E of non-reconstructed #nu's; E_{#nu}^{MC} [GeV]; #nu's", 30, 0, 30));
	add_new_TH1D("non-reconstructed_nu_theta_plus", new TH1D("non_plus-reconstructed_nu_theta", "#theta of non-reconstructed #nu's; #theta_{#nu}^{MC}; #nu's", 32, 0, 3.2) );
	add_new_TH1D("non-reconstructed_nu_phi_plus", new TH1D("non_plus-reconstructed_nu_phi", "#phi of non-reconstructed #nu's; #phi_{#nu}^{MC}; #nu's", 32, -3.2, 3.2) );

	add_new_TH1D("reconstructed_nu_parent_init_vertex_plus", new TH1D("reconstructed_nu_parent_init_vertex_plus", "Init. vertex radius of first parent of reconstructed #nu's; r_{parent}^{MC} [mm]; #nu's", 100, 0, 3000));
	add_new_TH2D("reconstructed_nu_E_plus", new TH2D("reconstructed_nu_E_plus", "#nu calculation from MC info, only reconstructed #nu's; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("reconstructed_nu_theta_plus", new TH2D("reconstructed_nu_theta_plus", "#nu calculation from MC info, only reconstructed #nu's; #theta_{#nu}^{MC}; #theta_{#nu}^{calc from MC vertex}; #nu's", 32, 0, 3.2, 32, 0, 3.2) );
	add_new_TH2D("reconstructed_nu_phi_plus", new TH2D("reconstructed_nu_phi_plus", "#nu calculation from MC info, only reconstructed #nu's; #phi_{#nu}^{MC}; #phi_{#nu}^{calc from MC vertex}; #nu's", 32, -3.2, 3.2, 32, -3.2, 3.2) );


	add_new_TH2D("nu_E_Bparents_only_plus", new TH2D("nu_E_Bparents_only_plus", "#nu calculation from MC info, only B parents; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_plus", new TH2D("nu_E_Bparents_only_0vertex_plus", "#nu calculation from MC info, only B parents starting at 0; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr5_plus", new TH2D("nu_E_Bparents_only_0vertex_visEgr5_plus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>5; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr10_plus", new TH2D("nu_E_Bparents_only_0vertex_visEgr10_plus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>10; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr15_plus", new TH2D("nu_E_Bparents_only_0vertex_visEgr15_plus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>15; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr20_plus", new TH2D("nu_E_Bparents_only_0vertex_visEgr20_plus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>20; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr30_plus", new TH2D("nu_E_Bparents_only_0vertex_visEgr30_plus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>30; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr50_plus", new TH2D("nu_E_Bparents_only_0vertex_visEgr50_plus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>50; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );

	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr5_plus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr5_plus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>5; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr10_plus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr10_plus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>10; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr15_plus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr15_plus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>15; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr20_plus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr20_plus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>20; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr30_plus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr30_plus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>30; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr50_plus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr50_plus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>50; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );


	add_new_TH2D("E_deviations_plus", new TH2D("E_deviations_plus", "Mis-calculation VS difference of calc. E from vis. E (B only, 0 vertex); (E_{#nu}^{calc} - E_{vis})/E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 150, -1.50, 1.50, 220, -20, 200) );
	add_new_TH2D("E_deviations_lepE5cut_plus", new TH2D("E_deviations_lepE5cut_plus", "Mis-calculation VS difference of calc. E from vis. E (B only, 0 vertex, E_{lep}>5); (E_{#nu}^{calc} - E_{vis})/E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 150, -1.50, 1.50, 220, -20, 200) );
	add_new_TH2D("E_deviations_visE_plus", new TH2D("E_deviations_visE_plus", "Mis-calculation VS vis. E (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 110, 0, 110, 220, -20, 200) );
	add_new_TH2D("E_deviations_lepE_plus", new TH2D("E_deviations_lepE_plus", "Mis-calculation VS ch. lep. E (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 110, 0, 110, 220, -20, 200) );
	add_new_TH2D("E_deviations_lepEpercentage_plus", new TH2D("E_deviations_lepEpercentage_plus", "Mis-calculation VS ch. lep. E percentage (B only, 0 vertex); E_{lep} / E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 100, 0, 1.0, 220, -20, 200) );
	add_new_TH2D("E_deviations_lepPDG_plus", new TH2D("E_deviations_lepPDG_plus", "Mis-calculation VS ch. lep. PDG (abs) (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 8, 10.5, 18.5, 220, -20, 200) );
	add_new_TH2D("E_deviations_nuTheta_plus", new TH2D("E_deviations_nuTheta_plus", "Mis-calculation VS #theta_{#nu}^{calc} (B only, 0 vertex); #theta_{#nu}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 32, 0, 3.2, 220, -20, 200) );
	add_new_TH2D("E_deviations_correctedE_plus", new TH2D("E_deviations_correctedE_plus", "Mis-calculation VS E_{corrected} (B only, 0 vertex); E_{corrected}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 250, 0, 250, 220, -20, 200) );
	add_new_TH2D("E_deviations_Ndaughters_plus", new TH2D("E_deviations_Ndaughters_plus", "Mis-calculation VS N_{daughters} (B only, 0 vertex); N_{daughters}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 5, 0.5, 5.5, 220, -20, 200) );
	add_new_TH2D("E_deviations_Bboost_plus", new TH2D("E_deviations_Bboost_plus", "Mis-calculation VS B boost (B only, 0 vertex); #gamma_{B}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 64, 1, 65, 220, -20, 200) );
	add_new_TH2D("E_deviations_Bmagnitude_plus", new TH2D("E_deviations_Bmagnitude_plus", "Mis-calculation VS B magnitude (B only, 0 vertex); |l_{B}^{MC}| [mm]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 20, 0, 20, 220, -20, 200) );

	add_new_TH2D("p_nu_parallel_vs_Bboost_plus", new TH2D("p_nu_parallel_vs_Bboost_plus", "#nu mom. parallel B VS B boost, (B only, 0 vertex); #gamma_{B}; p_{#nu}^{parallel} [GeV]; #nu's", 30, 1, 60, 150,-50, 250) );

	add_new_TH1D("B_magnitude_plus", new TH1D("B_magnitude_plus", "magnitude of B endpoint; |l_{B}| [mm]; Event", 100, 0, 10));
	add_new_TH2D("B_E_vs_B_magnitude_plus", new TH2D("B_E_vs_B_magnitude_plus", "B energy VS magnitude of B endpoint; |l_{B}^{MC}| [mm]; E_{B}^{MC}; Event", 40, 0, 4, 200, 0, 200));

	add_new_TH2D("E_deviations_visPperp_plus", new TH2D("E_deviations_visPperp_plus", "Mis-calculation VS ch. visible perp. mom. (B only, 0 vertex); p_{vis}^{perp} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 30, 0, 3, 220, -20, 200) );
	add_new_TH2D("E_deviations_visPratio_plus", new TH2D("E_deviations_visPratio_plus", "Mis-calculation VS ch. visible mom. perp./par. ratio (B only, 0 vertex); p_{vis}^{perp}/ p_{vis}^{par}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 50, 0, 0.5, 220, -20, 200) );
	add_new_TH2D("Bboost_visPratio_plus", new TH2D("Bboost_visPratio_plus", "B boost VS ch. visible mom. perp./par. ratio (B only, 0 vertex); p_{vis}^{perp}/ p_{vis}^{par}; #gamma_{B}; #nu's", 50, 0, 0.5, 20, 0, 20) );

	add_new_TH2D("Bbeta_visPparOVERvisE_plus", new TH2D("Bbeta_visPparOVERvisE_plus", "B boost VS ch. visible mom. perp./par. ratio (B only, 0 vertex); 1-p_{vis}^{par}/E_{vis}; 1-#beta_{B}; #nu's", 40, 0, 0.2, 40, 0, 0.2) );






	add_new_TH2D("nu_E_minus", new TH2D("nu_E_minus", "#nu calculation from MC info; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_p_minus", new TH2D("nu_p_minus", "#nu calculation from MC info; p_{#nu}^{MC} [GeV]; p_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_theta_minus", new TH2D("nu_theta_minus", "#nu calculation from MC info; #theta_{#nu}^{MC}; #theta_{#nu}^{calc from MC vertex}; #nu's", 32, 0, 3.2, 32, 0, 3.2) );
	add_new_TH2D("nu_phi_minus", new TH2D("nu_phi_minus", "#nu calculation from MC info; #phi_{#nu}^{MC}; #phi_{#nu}^{calc from MC vertex}; #nu's", 32, -3.2, 3.2, 32, -3.2, 3.2) );

	add_new_TH1D("non-reconstructed_nu_parent_init_vertex_minus", new TH1D("non_minus-reconstructed_nu_parent_init_vertex", "Init. vertex radius of first parent of non-reconstructed #nu's; r_{parent}^{MC} [mm]; #nu's", 100, 0, 3000));
	add_new_TH1D("non-reconstructed_nu_E_minus", new TH1D("non_minus-reconstructed_nu_E", "E of non-reconstructed #nu's; E_{#nu}^{MC} [GeV]; #nu's", 30, 0, 30));
	add_new_TH1D("non-reconstructed_nu_theta_minus", new TH1D("non_minus-reconstructed_nu_theta", "#theta of non-reconstructed #nu's; #theta_{#nu}^{MC}; #nu's", 32, 0, 3.2) );
	add_new_TH1D("non-reconstructed_nu_phi_minus", new TH1D("non_minus-reconstructed_nu_phi", "#phi of non-reconstructed #nu's; #phi_{#nu}^{MC}; #nu's", 32, -3.2, 3.2) );

	add_new_TH1D("reconstructed_nu_parent_init_vertex_minus", new TH1D("reconstructed_nu_parent_init_vertex_minus", "Init. vertex radius of first parent of reconstructed #nu's; r_{parent}^{MC} [mm]; #nu's", 100, 0, 3000));
	add_new_TH2D("reconstructed_nu_E_minus", new TH2D("reconstructed_nu_E_minus", "#nu calculation from MC info, only reconstructed #nu's; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("reconstructed_nu_theta_minus", new TH2D("reconstructed_nu_theta_minus", "#nu calculation from MC info, only reconstructed #nu's; #theta_{#nu}^{MC}; #theta_{#nu}^{calc from MC vertex}; #nu's", 32, 0, 3.2, 32, 0, 3.2) );
	add_new_TH2D("reconstructed_nu_phi_minus", new TH2D("reconstructed_nu_phi_minus", "#nu calculation from MC info, only reconstructed #nu's; #phi_{#nu}^{MC}; #phi_{#nu}^{calc from MC vertex}; #nu's", 32, -3.2, 3.2, 32, -3.2, 3.2) );


	add_new_TH2D("nu_E_Bparents_only_minus", new TH2D("nu_E_Bparents_only_minus", "#nu calculation from MC info, only B parents; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_minus", new TH2D("nu_E_Bparents_only_0vertex_minus", "#nu calculation from MC info, only B parents starting at 0; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr5_minus", new TH2D("nu_E_Bparents_only_0vertex_visEgr5_minus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>5; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr10_minus", new TH2D("nu_E_Bparents_only_0vertex_visEgr10_minus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>10; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr15_minus", new TH2D("nu_E_Bparents_only_0vertex_visEgr15_minus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>15; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr20_minus", new TH2D("nu_E_Bparents_only_0vertex_visEgr20_minus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>20; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr30_minus", new TH2D("nu_E_Bparents_only_0vertex_visEgr30_minus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>30; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_visEgr50_minus", new TH2D("nu_E_Bparents_only_0vertex_visEgr50_minus", "#nu calculation from MC info, only B parents starting at 0, E_{vis}>50; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );

	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr5_minus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr5_minus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>5; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr10_minus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr10_minus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>10; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr15_minus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr15_minus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>15; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr20_minus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr20_minus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>20; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr30_minus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr30_minus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>30; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );
	add_new_TH2D("nu_E_Bparents_only_0vertex_lepEgr50_minus", new TH2D("nu_E_Bparents_only_0vertex_lepEgr50_minus", "#nu calculation from MC info, only B parents starting at 0, E_{lep}>50; E_{#nu}^{MC} [GeV]; E_{#nu}^{calc from MC vertex} [GeV]; #nu's", 110, 0, 110, 110, 0, 110) );


	add_new_TH2D("E_deviations_minus", new TH2D("E_deviations_minus", "Mis-calculation VS difference of calc. E from vis. E (B only, 0 vertex); (E_{#nu}^{calc} - E_{vis})/E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 150, -1.50, 1.50, 220, -20, 200) );
	add_new_TH2D("E_deviations_lepE5cut_minus", new TH2D("E_deviations_lepE5cut_minus", "Mis-calculation VS difference of calc. E from vis. E (B only, 0 vertex, E_{lep}>5); (E_{#nu}^{calc} - E_{vis})/E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 150, -1.50, 1.50, 220, -20, 200) );
	add_new_TH2D("E_deviations_visE_minus", new TH2D("E_deviations_visE_minus", "Mis-calculation VS vis. E (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 110, 0, 110, 220, -20, 200) );
	add_new_TH2D("E_deviations_lepE_minus", new TH2D("E_deviations_lepE_minus", "Mis-calculation VS ch. lep. E (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 110, 0, 110, 220, -20, 200) );
	add_new_TH2D("E_deviations_lepEpercentage_minus", new TH2D("E_deviations_lepEpercentage_minus", "Mis-calculation VS ch. lep. E percentage (B only, 0 vertex); E_{lep} / E_{vis} ; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 100, 0, 1.0, 220, -20, 200) );
	add_new_TH2D("E_deviations_lepPDG_minus", new TH2D("E_deviations_lepPDG_minus", "Mis-calculation VS ch. lep. PDG (abs) (B only, 0 vertex); E_{vis} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 8, 10.5, 18.5, 220, -20, 200) );
	add_new_TH2D("E_deviations_nuTheta_minus", new TH2D("E_deviations_nuTheta_minus", "Mis-calculation VS #theta_{#nu}^{calc} (B only, 0 vertex); #theta_{#nu}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 32, 0, 3.2, 220, -20, 200) );
	add_new_TH2D("E_deviations_correctedE_minus", new TH2D("E_deviations_correctedE_minus", "Mis-calculation VS E_{corrected} (B only, 0 vertex); E_{corrected}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 250, 0, 250, 220, -20, 200) );
	add_new_TH2D("E_deviations_Ndaughters_minus", new TH2D("E_deviations_Ndaughters_minus", "Mis-calculation VS N_{daughters} (B only, 0 vertex); N_{daughters}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 5, 0.5, 5.5, 220, -20, 200) );
	add_new_TH2D("E_deviations_Bboost_minus", new TH2D("E_deviations_Bboost_minus", "Mis-calculation VS B boost (B only, 0 vertex); #gamma_{B}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 64, 1, 65, 220, -20, 200) );
	add_new_TH2D("E_deviations_Bmagnitude_minus", new TH2D("E_deviations_Bmagnitude_minus", "Mis-calculation VS B magnitude (B only, 0 vertex); |l_{B}^{MC}| [mm]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 20, 0, 20, 220, -20, 200) );

	add_new_TH2D("p_nu_parallel_vs_Bboost_minus", new TH2D("p_nu_parallel_vs_Bboost_minus", "#nu mom. parallel B VS B boost, (B only, 0 vertex); #gamma_{B}; p_{#nu}^{parallel} [GeV]; #nu's", 30, 1, 60, 150,-50, 250) );

	add_new_TH1D("B_magnitude_minus", new TH1D("B_magnitude_minus", "magnitude of B endpoint; |l_{B}| [mm]; Event", 100, 0, 10));
	add_new_TH2D("B_E_vs_B_magnitude_minus", new TH2D("B_E_vs_B_magnitude_minus", "B energy VS magnitude of B endpoint; |l_{B}^{MC}| [mm]; E_{B}^{MC}; Event", 40, 0, 4, 200, 0, 200));

	add_new_TH2D("E_deviations_visPperp_minus", new TH2D("E_deviations_visPperp_minus", "Mis-calculation VS ch. visible perp. mom. (B only, 0 vertex); p_{vis}^{perp} [GeV]; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 30, 0, 3, 220, -20, 200) );
	add_new_TH2D("E_deviations_visPratio_minus", new TH2D("E_deviations_visPratio_minus", "Mis-calculation VS ch. visible mom. perp./par. ratio (B only, 0 vertex); p_{vis}^{perp}/ p_{vis}^{par}; E_{#nu}^{calc} - E_{#nu}^{MC} [GeV]; #nu's", 50, 0, 0.5, 220, -20, 200) );
	add_new_TH2D("Bboost_visPratio_minus", new TH2D("Bboost_visPratio_minus", "B boost VS ch. visible mom. perp./par. ratio (B only, 0 vertex); p_{vis}^{perp}/ p_{vis}^{par}; #gamma_{B}; #nu's", 50, 0, 0.5, 20, 0, 20) );

	add_new_TH2D("Bbeta_visPparOVERvisE_minus", new TH2D("Bbeta_visPparOVERvisE_minus", "B boost VS ch. visible mom. perp./par. ratio (B only, 0 vertex); 1-p_{vis}^{par}/E_{vis}; 1-#beta_{B}; #nu's", 40, 0, 0.2, 40, 0, 0.2) );


}

bool NuCalculationPOPPlotter::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 || fabs(pdgID) == 14 || fabs(pdgID) == 16 || fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}

TLorentzVector NuCalculationPOPPlotter::get_nu_daughters_tlv( LepNuVertex* vertex ){
	TLorentzVector nu_tlv {};

	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( isNeutrinoID(daughter->MC.pdg_ID) ) { nu_tlv += daughter->MC.tlv; }
	}

	return nu_tlv;
}

TLorentzVector NuCalculationPOPPlotter::get_vis_tlv( LepNuVertex* vertex ){
	// Get non-nu daughter tlvs ( = "visible part of vertex")
	TLorentzVector vis_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( ! isNeutrinoID(daughter->MC.pdg_ID) ) { vis_tlv += daughter->MC.tlv; }
	}
	return vis_tlv;
}

TLorentzVector NuCalculationPOPPlotter::get_charged_leptons_tlv( LepNuVertex* vertex ){
	TLorentzVector charged_lep_tlv {};
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { charged_lep_tlv += daughter->MC.tlv; }
	}
	return charged_lep_tlv;
}

int NuCalculationPOPPlotter::get_first_charged_lepton_pdg( LepNuVertex* vertex ){
	int N_daughters = (vertex->vertex_daughters).GetEntries();
	for (int i_daughter = 0; i_daughter<N_daughters; i_daughter++) {
		Particle* daughter = (Particle*)(vertex->vertex_daughters)[i_daughter];
		if ( fabs(daughter->MC.pdg_ID) > 10 && fabs(daughter->MC.pdg_ID) < 18 && ! isNeutrinoID(daughter->MC.pdg_ID) ) { return daughter->MC.pdg_ID; }
	}
}

TLorentzVector NuCalculationPOPPlotter::calculate_nus_from_MC( LepNuVertex* vertex, std::string solution_mode ){
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


		// long double guess_gamma_B = 946 / std::pow(vis_p_perp/vis_p_parallel, 0.00293) - 948;
		// if (guess_gamma_B < 0) { guess_gamma_B = 0; }
		//
		// if ( fabs(guess_gamma_B - tlv_total_plus.Gamma()) < fabs(guess_gamma_B - tlv_total_minus.Gamma()) ) {
		// 	nu_tlv = nu_tlv_plus;
		// } else {
		// 	nu_tlv = nu_tlv_minus;
		// }

		if ( solution_mode == "plus" ){
			nu_tlv = nu_tlv_plus;
		}
		else if ( solution_mode == "minus" ){
			nu_tlv = nu_tlv_minus;
		}


	}

	return nu_tlv;
}

void NuCalculationPOPPlotter::fill_plots(){
	float weight = get_current_weight();

	// int i=1;
	// This is the loop over all events
	while ( get_next_event() ) {
		int N_vertices = (evt_info->total_event.lep_nu_vertices).GetEntries();
		// std::cout << i++ << "\n";
		get_TH1D("N_vertices")->Fill(N_vertices, weight);
		for (int i_vertex = 0; i_vertex<N_vertices; i_vertex++ ) {
			LepNuVertex* vertex = (LepNuVertex*)evt_info->total_event.lep_nu_vertices[i_vertex];

			TLorentzVector vis_tlv = get_vis_tlv(vertex);
			float vis_vertex_E = vis_tlv.E();
			TLorentzVector nu_tlv_true = get_nu_daughters_tlv( vertex );
			int first_parent_pdg = ((Particle*)((vertex->vertex_parents)[0]))->MC.pdg_ID;


			TLorentzVector nu_tlv_calculated_plus = calculate_nus_from_MC( vertex, "plus" );
			//std::cout << "nu: true: " << nu_tlv_true.E() << " calc: " << nu_tlv_calculated_plus.E() << " Init_vertex position:" << ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag() << " \n\n";
			get_TH2D("nu_E_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
			get_TH2D("nu_p_plus")->Fill(nu_tlv_true.P(), nu_tlv_calculated_plus.P(), weight);
			get_TH2D("nu_theta_plus")->Fill(nu_tlv_true.Theta(), nu_tlv_calculated_plus.Theta(), weight);
			get_TH2D("nu_phi_plus")->Fill(nu_tlv_true.Phi(), nu_tlv_calculated_plus.Phi(), weight);

			if ( nu_tlv_calculated_plus.E() == 0 ) {
				get_TH1D("non-reconstructed_nu_parent_init_vertex_plus")->Fill(((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(), weight);
				get_TH1D("non-reconstructed_nu_E_plus")->Fill(nu_tlv_true.E(), weight);
				get_TH1D("non-reconstructed_nu_theta_plus")->Fill(nu_tlv_true.Theta(), weight);
				get_TH1D("non-reconstructed_nu_phi_plus")->Fill(nu_tlv_true.Phi(), weight);
			} else {
				get_TH1D("reconstructed_nu_parent_init_vertex_plus")->Fill(((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(), weight);
				get_TH2D("reconstructed_nu_E_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
				get_TH2D("reconstructed_nu_theta_plus")->Fill(nu_tlv_true.Theta(), nu_tlv_calculated_plus.Theta(), weight);
				get_TH2D("reconstructed_nu_phi_plus")->Fill(nu_tlv_true.Phi(), nu_tlv_calculated_plus.Phi(), weight);
			}


			if ( fabs(first_parent_pdg) == 511 || fabs(first_parent_pdg) == 521 || fabs(first_parent_pdg) == 531 ) {
				get_TH2D("nu_E_Bparents_only_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
				float parent_init_pos = ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(); // TODO Adjust to non-zero init vertex
				if ( parent_init_pos < 1.0 ) {
					get_TH2D("nu_E_Bparents_only_0vertex_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					if ( vis_vertex_E > 5.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr5_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( vis_vertex_E > 10.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr10_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( vis_vertex_E > 15.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr15_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( vis_vertex_E > 20.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr20_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( vis_vertex_E > 30.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr30_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( vis_vertex_E > 50.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr50_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}

					float charged_leps_vertex_E = (get_charged_leptons_tlv(vertex)).E();
					if ( charged_leps_vertex_E > 5.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr5_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
						get_TH2D("E_deviations_lepE5cut_plus")->Fill((nu_tlv_calculated_plus.E()-vis_vertex_E)/vis_vertex_E, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);
					}
					if ( charged_leps_vertex_E > 10.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr10_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( charged_leps_vertex_E > 15.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr15_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( charged_leps_vertex_E > 20.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr20_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( charged_leps_vertex_E > 30.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr30_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					if ( charged_leps_vertex_E > 50.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr50_plus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_plus.E(), weight);
					}
					get_TH2D("E_deviations_plus")->Fill((nu_tlv_calculated_plus.E()-vis_vertex_E)/vis_vertex_E, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_visE_plus")->Fill(vis_vertex_E, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_lepE_plus")->Fill(charged_leps_vertex_E, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_lepEpercentage_plus")->Fill(charged_leps_vertex_E/vis_vertex_E, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_nuTheta_plus")->Fill(nu_tlv_calculated_plus.Theta(), nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_correctedE_plus")->Fill( nu_tlv_calculated_plus.E()+vis_vertex_E, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);

					int first_lep_pdg = get_first_charged_lepton_pdg(vertex);
					get_TH2D("E_deviations_lepPDG_plus")->Fill(fabs(first_lep_pdg), nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);

					int N_daughters = (vertex->vertex_daughters).GetEntries();
					get_TH2D("E_deviations_Ndaughters_plus")->Fill( N_daughters, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);

					get_TH2D("E_deviations_Bboost_plus")->Fill( ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);
					get_TH2D("p_nu_parallel_vs_Bboost_plus")->Fill( ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), (nu_tlv_calculated_plus.Vect()).Dot(((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Unit()), weight);

					get_TH1D("B_magnitude_plus")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), weight );
					get_TH2D("B_E_vs_B_magnitude_plus")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.E(), weight );

					get_TH2D("E_deviations_Bmagnitude_plus")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight);

					{
						TVector3 init_direction = ((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Unit();
						float vis_p_parallel = vis_tlv.Vect().Dot(init_direction);
						TVector3 perp_to_init = ( vis_tlv.Vect() - vis_p_parallel*init_direction ).Unit();
						long double vis_p_perp = vis_tlv.Vect().Dot( perp_to_init );
						get_TH2D("E_deviations_visPperp_plus")->Fill( vis_p_perp, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight );
						get_TH2D("E_deviations_visPratio_plus")->Fill( vis_p_perp/vis_p_parallel, nu_tlv_calculated_plus.E()-nu_tlv_true.E(), weight );
						get_TH2D("Bboost_visPratio_plus")->Fill( vis_p_perp/vis_p_parallel, ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), weight );

						get_TH2D("Bbeta_visPparOVERvisE_plus")->Fill(1.0-vis_p_parallel/vis_vertex_E, 1.0-((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Beta(), weight);
					}
				}
			}

			TLorentzVector nu_tlv_calculated_minus = calculate_nus_from_MC( vertex, "minus" );
			//std::cout << "nu: true: " << nu_tlv_true.E() << " calc: " << nu_tlv_calculated_minus.E() << " Init_vertex position:" << ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag() << " \n\n";
			get_TH2D("nu_E_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
			get_TH2D("nu_p_minus")->Fill(nu_tlv_true.P(), nu_tlv_calculated_minus.P(), weight);
			get_TH2D("nu_theta_minus")->Fill(nu_tlv_true.Theta(), nu_tlv_calculated_minus.Theta(), weight);
			get_TH2D("nu_phi_minus")->Fill(nu_tlv_true.Phi(), nu_tlv_calculated_minus.Phi(), weight);

			if ( nu_tlv_calculated_minus.E() == 0 ) {
				get_TH1D("non-reconstructed_nu_parent_init_vertex_minus")->Fill(((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(), weight);
				get_TH1D("non-reconstructed_nu_E_minus")->Fill(nu_tlv_true.E(), weight);
				get_TH1D("non-reconstructed_nu_theta_minus")->Fill(nu_tlv_true.Theta(), weight);
				get_TH1D("non-reconstructed_nu_phi_minus")->Fill(nu_tlv_true.Phi(), weight);
			} else {
				get_TH1D("reconstructed_nu_parent_init_vertex_minus")->Fill(((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(), weight);
				get_TH2D("reconstructed_nu_E_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
				get_TH2D("reconstructed_nu_theta_minus")->Fill(nu_tlv_true.Theta(), nu_tlv_calculated_minus.Theta(), weight);
				get_TH2D("reconstructed_nu_phi_minus")->Fill(nu_tlv_true.Phi(), nu_tlv_calculated_minus.Phi(), weight);
			}


			if ( fabs(first_parent_pdg) == 511 || fabs(first_parent_pdg) == 521 || fabs(first_parent_pdg) == 531 ) {
				get_TH2D("nu_E_Bparents_only_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
				float parent_init_pos = ((Particle*)(vertex->vertex_parents[0]))->MC.vertex.Mag(); // TODO Adjust to non-zero init vertex
				if ( parent_init_pos < 1.0 ) {
					get_TH2D("nu_E_Bparents_only_0vertex_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					if ( vis_vertex_E > 5.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr5_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( vis_vertex_E > 10.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr10_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( vis_vertex_E > 15.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr15_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( vis_vertex_E > 20.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr20_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( vis_vertex_E > 30.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr30_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( vis_vertex_E > 50.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_visEgr50_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}

					float charged_leps_vertex_E = (get_charged_leptons_tlv(vertex)).E();
					if ( charged_leps_vertex_E > 5.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr5_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
						get_TH2D("E_deviations_lepE5cut_minus")->Fill((nu_tlv_calculated_minus.E()-vis_vertex_E)/vis_vertex_E, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);
					}
					if ( charged_leps_vertex_E > 10.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr10_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( charged_leps_vertex_E > 15.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr15_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( charged_leps_vertex_E > 20.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr20_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( charged_leps_vertex_E > 30.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr30_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					if ( charged_leps_vertex_E > 50.0) {
						get_TH2D("nu_E_Bparents_only_0vertex_lepEgr50_minus")->Fill(nu_tlv_true.E(), nu_tlv_calculated_minus.E(), weight);
					}
					get_TH2D("E_deviations_minus")->Fill((nu_tlv_calculated_minus.E()-vis_vertex_E)/vis_vertex_E, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_visE_minus")->Fill(vis_vertex_E, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_lepE_minus")->Fill(charged_leps_vertex_E, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_lepEpercentage_minus")->Fill(charged_leps_vertex_E/vis_vertex_E, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_nuTheta_minus")->Fill(nu_tlv_calculated_minus.Theta(), nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);
					get_TH2D("E_deviations_correctedE_minus")->Fill( nu_tlv_calculated_minus.E()+vis_vertex_E, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);

					int first_lep_pdg = get_first_charged_lepton_pdg(vertex);
					get_TH2D("E_deviations_lepPDG_minus")->Fill(fabs(first_lep_pdg), nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);

					int N_daughters = (vertex->vertex_daughters).GetEntries();
					get_TH2D("E_deviations_Ndaughters_minus")->Fill( N_daughters, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);

					get_TH2D("E_deviations_Bboost_minus")->Fill( ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);
					get_TH2D("p_nu_parallel_vs_Bboost_minus")->Fill( ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), (nu_tlv_calculated_minus.Vect()).Dot(((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Unit()), weight);

					get_TH1D("B_magnitude_minus")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), weight );
					get_TH2D("B_E_vs_B_magnitude_minus")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.E(), weight );

					get_TH2D("E_deviations_Bmagnitude_minus")->Fill( ((Particle*)((vertex->vertex_daughters)[0]))->MC.vertex.Mag(), nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight);

					{
						TVector3 init_direction = ((Particle*)(vertex->vertex_daughters[0]))->MC.vertex.Unit();
						float vis_p_parallel = vis_tlv.Vect().Dot(init_direction);
						TVector3 perp_to_init = ( vis_tlv.Vect() - vis_p_parallel*init_direction ).Unit();
						long double vis_p_perp = vis_tlv.Vect().Dot( perp_to_init );
						get_TH2D("E_deviations_visPperp_minus")->Fill( vis_p_perp, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight );
						get_TH2D("E_deviations_visPratio_minus")->Fill( vis_p_perp/vis_p_parallel, nu_tlv_calculated_minus.E()-nu_tlv_true.E(), weight );
						get_TH2D("Bboost_visPratio_minus")->Fill( vis_p_perp/vis_p_parallel, ((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Gamma(), weight );

						get_TH2D("Bbeta_visPparOVERvisE_minus")->Fill(1.0-vis_p_parallel/vis_vertex_E, 1.0-((Particle*)((vertex->vertex_parents)[0]))->MC.tlv.Beta(), weight);
					}
				}
			}
		}
	}
}

void NuCalculationPOPPlotter::draw_plots(){
	std::string output_dir = get_output_directory();

	TCanvas* c_parent_init_vertices = new TCanvas("parent_init_vertices", "", 0, 0, 800, 900);
	TLegend* vertices_leg = new TLegend(0.35, 0.7, 0.9, 0.9);
	TH1D* non_reco_nu_parent_vertices = get_TH1D("non-reconstructed_nu_parent_init_vertex_plus");
	TH1D* reco_nu_parent_vertices = get_TH1D("reconstructed_nu_parent_init_vertex_plus");
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
	TH1D* nonreco_nu_E = get_TH1D("non-reconstructed_nu_E_plus");
	nonreco_nu_E->Draw("hist");
	nonreco_nu_E->GetYaxis()->SetTitleOffset(1.4);
	c_nonreco_nu_E->SetLeftMargin(0.2);
	c_nonreco_nu_E->Print((output_dir + "/h1_nonreco_nu_E.pdf").c_str());
	// delete c_nonreco_nu_E;

	TCanvas* c_nonreco_nu_theta = new TCanvas("can_nonreco_nu_theta", "", 0, 0, 800, 900);
	TH1D* nonreco_nu_theta = get_TH1D("non-reconstructed_nu_theta_plus");
	nonreco_nu_theta->Draw("hist");
	c_nonreco_nu_theta->Print((output_dir + "/h1_nonreco_nu_theta.pdf").c_str());
	// delete c_nonreco_nu_theta;

	TCanvas* c_nonreco_nu_phi = new TCanvas("can_nonreco_nu_phi", "", 0, 0, 800, 900);
	TH1D* nonreco_nu_phi = get_TH1D("non-reconstructed_nu_phi_plus");
	nonreco_nu_phi->Draw("hist");
	c_nonreco_nu_phi->Print((output_dir + "/h1_nonreco_nu_phi.pdf").c_str());
	// delete c_nonreco_nu_phi;

}
