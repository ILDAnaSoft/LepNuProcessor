#include "plotters.h"

// Very simple example

void TestPlotter::set_plotter_settings() {
	set_output_folder_name("test");
}

void TestPlotter::define_plots(){
	add_new_TH1D("test", new TH1D("test", "test", 5, 0, 5) );
}

void TestPlotter::fill_plots(){
	float weight = get_current_weight();

	// This is the loop over all events
	while ( get_next_event() ) {
		get_TH1D("test")->Fill(evt_info->evtN, weight);
	}
}

void TestPlotter::draw_plots(){
	std::string output_dir = get_output_directory();

	TCanvas* c1 = new TCanvas("c1", "", 0, 0, 800, 800);
	get_TH1D("test")->Draw();
	c1->Print((output_dir + "/test.pdf").c_str());
}
