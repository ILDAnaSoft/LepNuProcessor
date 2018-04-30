#ifndef PLOTTERS_H
#define PLOTTERS_H 1

#include "plotter.h"

// Declase all plotter classes
class TestPlotter : public Plotter {
	virtual void set_plotter_settings();
	virtual void define_plots();
	virtual void fill_plots();
	virtual void draw_plots();
};

class LepNuPairPlotter : public Plotter {
	virtual void set_plotter_settings();
	virtual void define_plots();
	virtual void fill_plots();
	virtual void draw_plots();
};

class CheatedCorrectionPlotter : public Plotter {
	virtual void set_plotter_settings();
	virtual void define_plots();
	virtual void fill_plots();
	virtual void get_resolution_projection( TProfile* plot, TH1D* error_clone );
	virtual void draw_plots();
};

class NuCalculationPOPPlotter : public Plotter {
	virtual void set_plotter_settings();
	virtual void define_plots();
	virtual void fill_plots();
	virtual void draw_plots();
	virtual TLorentzVector get_nu_daughters_tlv( LepNuVertex* vertex );
	virtual TLorentzVector calculate_nus_from_MC( LepNuVertex* vertex );
	virtual bool isNeutrinoID( int pdgID );
};

#endif
