#include <boost/algorithm/string/classification.hpp> // Include boost::for is_any_of
#include <boost/algorithm/string/split.hpp> // Include for boost::split

// Own header and source files
#include "ILDStyle.h"
#include "plotter.h"
#include "configuration.h"


std::vector<std::vector<std::string>> fileinfo_input_splitting (std::string fileinfo_input) {
	/* Takes the long input string from the sqlite readout and separates it into
 	the individual elements -> vector for each file containing all infos as strings
	 */

	// delimiters between two files and between the infos for one file
	std::string inter_file_delimiter=",";
	std::string intra_file_delimiter="|";

	// Split up the infos so that there is one long string for each file
	std::vector<std::string> split_file_infos;
	split(split_file_infos, fileinfo_input, boost::is_any_of(inter_file_delimiter.c_str()), boost::token_compress_on);

	// For each file split up the long string into the individual elements
	// and push the results into a vector per file
	std::vector<std::vector<std::string>> result;
	for (int i=0; i<split_file_infos.size(); i++) {
		std::vector<std::string> single_file_info;
		split(single_file_info, split_file_infos[i], boost::is_any_of(intra_file_delimiter.c_str()), boost::token_compress_on);

		result.push_back(single_file_info);
	}

	return result;
}

void fill_info_storage (std::string &_luminosity, std::string &_e_beam_polarization, std::string &_p_beam_polarization,
						std::string &fileinfo_input, std::string &input_directory, std::string &output_directory, std::string tree_name,
						InfoStorage &info_storage) {
	/* Fill the InfoStorage with the file information encoded in the long
 	string fileinfo_input */

	// Transfer the computing environment to the info_storage
	info_storage.set_environment(input_directory, output_directory, tree_name);

	// Transfer the setup to the info_storage
	float luminosity = stof(_luminosity);
	float e_beam_polarization = stof(_e_beam_polarization);
	float p_beam_polarization = stof(_p_beam_polarization);

	info_storage.set_setup(luminosity, e_beam_polarization, p_beam_polarization);

	// Get the splitted input
	std::vector<std::vector<std::string>> split_fileinfo_input = fileinfo_input_splitting(fileinfo_input);

	// For each file information:
	// Convert the string information into the appropriate format and add
	// the entry in the info_storage
	for (int i=0; i<split_fileinfo_input.size(); i++) {
		std::vector<std::string> single_file_info = split_fileinfo_input[i];

		std::string filename = single_file_info[0];
		std::string class_name = single_file_info[1];
		std::string final_state = single_file_info[2];
		std::string polarization = single_file_info[3];
		float xsection = stof(single_file_info[4]);

		info_storage.add_file_info(filename, class_name, final_state, polarization, xsection);
	}
}


void run_plotting_framework(std::string &luminosity, std::string &e_beam_polarization, std::string &p_beam_polarization,
							std::string &fileinfo_input, std::string &input_directory, std::string &output_directory,
							std::string &tree_name) {
	/* Creates central info_storage and passes it to the individual plotters to run */

	// Create central info_storage object storing infos for all plotters
	InfoStorage info_storage;
	fill_info_storage(	luminosity, e_beam_polarization, p_beam_polarization,
						fileinfo_input, input_directory, output_directory, tree_name,
						info_storage);

	// Store all plotters in this vector
	// -> Possible with pointers despite being different subclasses
	std::vector<Plotter*> plotters;

	set_plotters(plotters);

	// Execute common functionality of all Plotters
	for (int i=0; i<plotters.size(); i++) {
		plotters[i]->init(info_storage);
		plotters[i]->run();
	}
}


int main( int argc, char *argv[] ) {
	/* This function gets called when using the executable in the build directory.*/

	if ( ! (argc == 8) ) {
		std::cout << "ERROR in run_plotting_framework: Number of input arguments not correct! " << std::endl;
		std::cout << "Exiting." << std::endl;
		return 0;
	}

	std::string luminosity 			= argv[1];
	std::string e_beam_polarization 	= argv[2];
	std::string p_beam_polarization 	= argv[3];
	std::string fileinfo_input 		= argv[4];
	std::string input_directory 		= argv[5];
	std::string output_directory 	= argv[6];
	std::string tree_name 			= argv[7];

	set_ILD_style();

	run_plotting_framework( luminosity, e_beam_polarization, p_beam_polarization,
							fileinfo_input, input_directory, output_directory,
							tree_name);

	return 1;
}
