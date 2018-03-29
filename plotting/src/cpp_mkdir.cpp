#include "cpp_mkdir.h"

void cpp_mkdir( std::string dir_name ) {
	const int dir_err = mkdir( dir_name.c_str() , S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	// Check if making of directory threw error and ignore if it complains about directory
	// already existing (using special variable errno)
	if (-1 == dir_err && errno != EEXIST)
	{
	    printf(("Error creating directory: " + dir_name + "\n" + "Exiting.\n").c_str());
	    exit(1);
	}
}
