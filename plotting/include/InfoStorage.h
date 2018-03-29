#ifndef INFOSTORAGE_h
#define INFOSTORAGE_h 1

#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TF2.h"
#include "TF3.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TLegend.h"
#include "THStack.h"
#include "TLine.h"
#include "TPad.h"
#include "TVirtualPad.h"
#include "TMath.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
//#include <pair>

class InfoStorage {
	/* Class to store all information about the files which
 	are used for plotting */

	// Infos regarding computational environment
	std::string input_directory;
	std::string output_directory;
	std::string tree_name;

	// Infos regarding the setup
	float luminosity;
	float e_beam_polarization;
	float p_beam_polarization;

	// Infos regarding files
	std::vector<std::string> 	filenames;
	std::vector<std::string> 	class_names;
	std::vector<std::string> 	final_states;
	std::vector<std::string> 	polarizations;
	std::vector<float>	xsections;

	std::vector<float>	file_weights;

	void calculate_weight_i (int i) {
		/* Calculate and set the weight for file i*/
		TFile *file = TFile::Open((input_directory + "/" + filenames[i]).c_str());
		TTree *tree = (TTree*)file->Get(tree_name.c_str());

		int nEntries = tree->GetEntries();

		// Calculate weight for this input sample
		float pol_weight = 	( 1 + get_e_polarization_sign_i(i) * e_beam_polarization )/2
							* ( 1 + get_p_polarization_sign_i(i) * p_beam_polarization )/2;
		file_weights[i] = ( xsections[i] * luminosity / nEntries ) * pol_weight;
	}

	public:

		void set_environment(std::string _input_directory, std::string _output_directory, std::string _tree_name) {
			/* Set the computing environment */
			input_directory = _input_directory;
			output_directory = _output_directory;
			tree_name = _tree_name;
		}

		void set_setup (float _luminosity, float _e_beam_polarization, float _p_beam_polarization) {
			/* Set the experimental setup */
			luminosity = _luminosity;
			e_beam_polarization = _e_beam_polarization;
			p_beam_polarization = _p_beam_polarization;
		}

		void add_file_info(std::string filename, std::string class_name, std::string final_state, std::string polarization, float xsection) {
			/* Add a new file with its information */
			filenames.push_back(filename);
			class_names.push_back(class_name);
			final_states.push_back(final_state);
			polarizations.push_back(polarization);
			xsections.push_back(xsection);

			// Adjust length of weights vector and calculate new weight
			file_weights.resize(get_number_of_files());
			calculate_weight_i(get_number_of_files()-1);
		}

		// Get functions

		int get_number_of_files () {
			return filenames.size();
		}

		std::string get_file_name_i (int i) {
			return filenames[i];
		}

		std::string get_file_path_i (int i) {
			return input_directory + "/" + filenames[i];
		}

		std::string get_tree_name () {
			return tree_name;
		}

		std::string get_output_directory() {
			return output_directory;
		}

		std::string get_class_name_i (int i) {
			return class_names[i];
		}

		std::string get_final_state_i (int i) {
			return final_states[i];
		}

		std::string get_polarization_string_i (int i) {
			return polarizations[i];
		}

		float get_xsection_i (int i) {
			return xsections[i];
		}

		float get_file_weight_i (int i) {
			return file_weights[i];
		}

		int get_e_polarization_sign_i (int i) {
			// Extract the electron helicity in process i from the std::string version
			std::string polarization_string = polarizations[i];
			if ( (polarization_string == "rr") || (polarization_string == "rl") ) {
				return 1;
			} else if ( (polarization_string == "ll") || (polarization_string == "lr") ) {
				return -1;
			} else {
				return 0;
			}
		}

		int get_p_polarization_sign_i (int i) {
			// Extract the positron helicity in process i from the std::str version
			std::string polarization_string = polarizations[i];
			if ( (polarization_string == "rr") || (polarization_string == "lr") ) {
				return 1;
			} else if ( (polarization_string == "ll") || (polarization_string == "rl") ) {
				return -1;
			} else {
				return 0;
			}
		}




} ;

#endif
