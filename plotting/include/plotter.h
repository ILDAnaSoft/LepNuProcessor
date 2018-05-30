#ifndef PLOTTER_h
#define PLOTTER_h
#include "InfoStorage.h"
#include "EventInformation.h"
#include "cpp_mkdir.h"

struct Plotter {
	/* Superclass for all Plotters, contains basic functionalities,
 	details must then be specified in implementation of subclass.
	-> Looping etc. provided, but what, how and where to plot custom
	*/

	// File and directory information
	InfoStorage info_storage;

	std::string output_folder_name;

	std::string get_output_folder_name() { return output_folder_name; }

	std::string get_output_directory() {
		// Return the plotter specific output directory
		return info_storage.get_output_directory() + "/" + get_output_folder_name() ;
	}

	void set_output_folder_name(std::string _output_folder_name) {
		// Set the name of the folder in the output directory for this specific plotter
		output_folder_name = _output_folder_name;
		cpp_mkdir( get_output_directory() );
	}

	// Vectors for the possible diagrams (if new type needed: add it)
	std::vector<TH1D*> TH1D_vector;
	std::vector<TH2D*> TH2D_vector;
	std::vector<TProfile*> TProfile_vector;
	std::vector<TProfile2D*> TProfile2D_vector;
	std::vector<TH3D*> TH3D_vector;

	// Maps for comprehensive storage of the diagrams by a name
	// -> connects index of histogram in vector with its name
	std::map<std::string, int> TH1D_map;
	std::map<std::string, int> TH2D_map;
	std::map<std::string, int> TProfile_map;
	std::map<std::string, int> TProfile2D_map;
	std::map<std::string, int> TH3D_map;

	// Functions to store and get the histograms by name (copy-paste for new types)
	void add_new_TH1D (std::string name, TH1D* hist) {
		TH1D_vector.push_back(hist);										// push histo into vector
		int hist_index = TH1D_vector.size() - 1;							// get its index
		TH1D_map.insert( std::pair<std::string,int>( name.c_str(), hist_index ) );	// connect index with name
	}

	void add_new_TH2D (std::string name, TH2D* hist) {
		TH2D_vector.push_back(hist);										// push histo into vector
		int hist_index = TH2D_vector.size() - 1;							// get its index
		TH2D_map.insert( std::pair<std::string,int>( name.c_str(), hist_index ) );	// connect index with name
	}

	void add_new_TProfile (std::string name, TProfile* hist) {
		TProfile_vector.push_back(hist);										// push histo into vector
		int hist_index = TProfile_vector.size() - 1;							// get its index
		TProfile_map.insert( std::pair<std::string,int>( name.c_str(), hist_index ) );	// connect index with name
	}

	void add_new_TProfile2D (std::string name, TProfile2D* hist) {
		TProfile2D_vector.push_back(hist);										// push histo into vector
		int hist_index = TProfile2D_vector.size() - 1;							// get its index
		TProfile2D_map.insert( std::pair<std::string,int>( name.c_str(), hist_index ) );	// connect index with name
	}

	void add_new_TH3D (std::string name, TH3D* hist) {
		TH3D_vector.push_back(hist);										// push histo into vector
		int hist_index = TH3D_vector.size() - 1;							// get its index
		TH3D_map.insert( std::pair<std::string,int>( name.c_str(), hist_index ) );	// connect index with name
	}


	TH1D* get_TH1D (std::string name) {
		int hist_index = TH1D_map.find(name.c_str())->second;	// Get the index of hist called name
		return TH1D_vector[hist_index];
	}

	TH2D* get_TH2D (std::string name) {
		int hist_index = TH2D_map.find(name.c_str())->second;	// Get the index of hist called name
		return TH2D_vector[hist_index];
	}

	TProfile* get_TProfile (std::string name) {
		int hist_index = TProfile_map.find(name.c_str())->second;	// Get the index of hist called name
		return TProfile_vector[hist_index];
	}

	TProfile2D* get_TProfile2D (std::string name) {
		int hist_index = TProfile2D_map.find(name.c_str())->second;	// Get the index of hist called name
		return TProfile2D_vector[hist_index];
	}

	TH3D* get_TH3D (std::string name) {
		int hist_index = TH3D_map.find(name.c_str())->second;	// Get the index of hist called name
		return TH3D_vector[hist_index];
	}


	// For looping also allow access by index (bc it's generic)
	int get_number_TH1Ds() { return TH1D_vector.size(); }
	int get_number_TH2Ds() { return TH2D_vector.size(); }
	int get_number_TProfiles() { return TProfile_vector.size(); }
	int get_number_TProfile2Ds() { return TProfile2D_vector.size(); }
	int get_number_TH3Ds() { return TH3D_vector.size(); }

	TH1D* get_TH1D_i (int i) { return TH1D_vector[i]; }
	TH2D* get_TH2D_i (int i) { return TH2D_vector[i]; }
	TProfile* get_TProfile_i (int i) { return TProfile_vector[i]; }
	TProfile2D* get_TProfile2D_i (int i) { return TProfile2D_vector[i]; }
	TH3D* get_TH3D_i (int i) { return TH3D_vector[i]; }

	// Functions to automatically save all histograms to a rootfile in the output directory
	void save_all_TH1Ds_in_rootfile() {
		if ( get_number_TH1Ds() == 0 ) { return; }	// Do only if histograms available

		TFile* TH1D_file = new TFile( (get_output_directory() + "/_all_TH1Ds.root").c_str() ,"RECREATE");
		for ( int i=0; i<get_number_TH1Ds(); i++ ) {
			TH1D* th1d_clone = (TH1D*)get_TH1D_i(i)->Clone();
			th1d_clone->Draw();
		}
		TH1D_file->Write();
		TH1D_file->Close();
	}

	void save_all_TH2Ds_in_rootfile() {
		if ( get_number_TH2Ds() == 0 ) { return; }	// Do only if histograms available

		TFile* TH2D_file = new TFile( (get_output_directory() + "/_all_TH2Ds.root").c_str() ,"RECREATE");
		for ( int i=0; i<get_number_TH2Ds(); i++ ) {
			TH2D* th2d_clone = (TH2D*)get_TH2D_i(i)->Clone();
			th2d_clone->Draw();
		}
		TH2D_file->Write();
		TH2D_file->Close();
	}

	void save_all_TProfiles_in_rootfile() {
		if ( get_number_TProfiles() == 0 ) { return; }	// Do only if histograms available

		TFile* TProfile_file = new TFile( (get_output_directory() + "/_all_TProfiles.root").c_str() ,"RECREATE");
		for ( int i=0; i<get_number_TProfiles(); i++ ) {
			TProfile* tprofile_clone = (TProfile*)get_TProfile_i(i)->Clone();
			tprofile_clone->Draw();
		}
		TProfile_file->Write();
		TProfile_file->Close();
	}

	void save_all_TProfile2Ds_in_rootfile() {
		if ( get_number_TProfile2Ds() == 0 ) { return; }	// Do only if histograms available

		TFile* TProfile2D_file = new TFile( (get_output_directory() + "/_all_TProfile2Ds.root").c_str() ,"RECREATE");
		for ( int i=0; i<get_number_TProfile2Ds(); i++ ) {
			TProfile2D* tprofile_clone = (TProfile2D*)get_TProfile2D_i(i)->Clone();
			tprofile_clone->Draw();
		}
		TProfile2D_file->Write();
		TProfile2D_file->Close();
	}

	void save_all_TH3Ds_in_rootfile() {
		if ( get_number_TH3Ds() == 0 ) { return; }	// Do only if histograms available

		TFile* TH3D_file = new TFile( (get_output_directory() + "/_all_TH3Ds.root").c_str() ,"RECREATE");
		for ( int i=0; i<get_number_TH3Ds(); i++ ) {
			TH3D* th3d_clone = (TH3D*)get_TH3D_i(i)->Clone();
			th3d_clone->Draw();
		}
		TH3D_file->Write();
		TH3D_file->Close();
	}



	void save_all_histograms_in_rootfiles() {
		// Execute all histograms to rootfile functions
		save_all_TH1Ds_in_rootfile();
		save_all_TH2Ds_in_rootfile();
		save_all_TProfiles_in_rootfile();
		save_all_TProfile2Ds_in_rootfile();
		save_all_TH3Ds_in_rootfile();
	}

	// Specifics for current file
	float current_weight;
	float get_current_weight() { return current_weight; }

	TTree* current_tree;
	// For looping over tree:
	int current_event_number;

	bool get_next_event() {
		/* Allows running over all events of the file using a simple while loop */
		// If counter within size of tree -> get next event
		// Otherwise return false -> stop
		if ( current_event_number < current_tree->GetEntries() ) {
			current_tree->GetEntry(current_event_number);
			current_event_number++; // Increment to next event
			return true;
		} else {
			return false;
		}
	}

	TTree* get_current_tree(){
		return current_tree;
	}

	/* --------------------------------------------------------*/
	// Read EventInformation class from tree
	EventInfo *evt_info = nullptr ;

	void set_tree_adresses () {
		/* Link the variables used in the plotting to the current tree */
		current_tree->SetBranchAddress( "info" , &evt_info );
	}

	/* --------------------------------------------------------*/

	/* --------------------------------------------------------*/
	// Physical constants
	float mW_DBD = 80.419000;
	float mZ_DBD = 91.188200;
	/* --------------------------------------------------------*/

	/* --------------------------------------------------------*/
	// Functions that need to be specified in the subclass
	virtual void set_plotter_settings() = 0;
	virtual void define_plots() = 0;
	virtual void fill_plots() = 0;
	virtual void draw_plots() = 0;
	/* --------------------------------------------------------*/


	void loop_over_files() {
		/* Perfom standard loop over all files in info_storage */
		int N_files = info_storage.get_number_of_files();
		for (int file_i=0; file_i<N_files; file_i++) {
			current_weight=info_storage.get_file_weight_i(file_i);

			// Open the tree of the new file
			std::string current_file_path = info_storage.get_file_path_i(file_i);
			TFile *file = TFile::Open( current_file_path.c_str() );
			current_tree = (TTree*)file->Get( ( info_storage.get_tree_name() ).c_str() );
			current_event_number=0; // Reset counter for event loops

			// Link the variables to the current tree
			set_tree_adresses();
			fill_plots();
			file->Close();
		}
	}


	/* --------------------------------------------------------*/
	// Functions to help with plotting.
	//
	void draw_mass_line ( std::string particle, std::string measurement_version, std::string direction ) {
		// In the current histogram draw a line in the given direction at the point of
		// the particles mass.
		// CAREFUL: Can only be called AFTER other histos are already drawn!

		float mass = -9999999;
		int line_color = 0;

		if ( particle == "W" ) {
			line_color = 9;
			if ( measurement_version == "DBD" ) { mass = mW_DBD; }
		}
		else if ( particle == "Z" ) {
			line_color = 46;
			if ( measurement_version == "DBD" ) { mass = mZ_DBD; }
		}

		if ( mass<0 ) { return; }

		if ( direction == "x" ) {
			gPad->Update(); // Some weird ROOT thing. First need to update the current Pad before able to read axis range.

			// Get Minimum and Maximum of axis from current TPad
			float x_min = gPad->GetFrame()->GetX1();
			float x_max = gPad->GetFrame()->GetX2();

			TLine* mass_line = new TLine(x_min, mass, x_max, mass);
			mass_line->SetLineColorAlpha(line_color, 0.5);
			mass_line->Draw("same");
		}
		else if ( direction == "y" ) {
			gPad->Update(); // Some weird ROOT thing. First need to update the current Pad before able to read axis range.

			// Get Minimum and Maximum of axis from current TPad
			float y_min = gPad->GetFrame()->GetY1();
			float y_max = gPad->GetFrame()->GetY2();

			TLine* mass_line = new TLine(mass, y_min, mass, y_max);
			mass_line->SetLineColorAlpha(line_color, 0.5);
			mass_line->Draw("same");
		}
	}

	/* --------------------------------------------------------*/


	/* --------------------------------------------------------*/
	//Functions to be called on instance (additional to virtuals).
	//
	void init ( InfoStorage _info_storage ) {
		info_storage = _info_storage;
		gROOT->Reset();
		gStyle->SetOptStat(0);
		TH1D::SetDefaultSumw2();
		TH2D::SetDefaultSumw2();
		TProfile::SetDefaultSumw2();
		TProfile2D::SetDefaultSumw2();
		TH3D::SetDefaultSumw2();
	}

	void run() {
		set_plotter_settings();
		define_plots();
		loop_over_files();
		draw_plots();
		save_all_histograms_in_rootfiles();
	}
	/* --------------------------------------------------------*/
};

#endif
