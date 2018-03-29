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

#endif
