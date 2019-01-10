#include "configuration.h"

#include "plotters.h"

void set_plotters(std::vector<Plotter*> &plotters) {
	/* ---------------------------------------------------------------------*/
	// INSERT THE PLOTTER MODULES HERE

	// plotters.push_back( new TestPlotter );
	// plotters.push_back( new LepNuPairPlotter);
	// plotters.push_back( new CheatedCorrectionPlotter );
	// plotters.push_back( new NuCalculationPOPPlotter );
	// plotters.push_back( new NuCalculationCheatedSignPOPPlotter );
	// plotters.push_back( new NuCalculationPOPGuessedGammaPlotter );
    // plotters.push_back( new CheatedNuCalculationReco4MomentaPlotter );
	//plotters.push_back( new RoughNuCorrectionFitPlotter );
	// plotters.push_back( new RoughNuCorrectionPOPPlotter );
	plotters.push_back( new RoughNuCorrectionOnTJjetsPlotter );

	/* ---------------------------------------------------------------------*/
}
