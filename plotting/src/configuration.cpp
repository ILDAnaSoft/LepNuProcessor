#include "configuration.h"

#include "plotters.h"

void set_plotters(std::vector<Plotter*> &plotters) {
	/* ---------------------------------------------------------------------*/
	// INSERT THE PLOTTER MODULES HERE

	//plotters.push_back( new TestPlotter );
	//plotters.push_back( new LepNuPairPlotter);
	plotters.push_back( new CheatedCorrectionPlotter );
	/* ---------------------------------------------------------------------*/
}
