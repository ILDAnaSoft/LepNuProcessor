#include "ILDStyle.h"

void set_ILD_style(){

  std::cout << "Loading ILD rootlogon for some stylish root standards." << std::endl;

  //ild TStyle
  TStyle* ildStyle = new  TStyle("ildStyle", "ILD Style");

  //set the background color to white
  ildStyle->SetFillColor(10);
  ildStyle->SetFrameFillColor(10);
  ildStyle->SetCanvasColor(10);
  ildStyle->SetPadColor(10);
  ildStyle->SetTitleFillColor(0);
  ildStyle->SetStatColor(10);

  //dont put a colored frame around the plots
  ildStyle->SetFrameBorderMode(0);
  ildStyle->SetCanvasBorderMode(0);
  ildStyle->SetPadBorderMode(0);
  ildStyle->SetLegendBorderSize(0);

  //use the primary color palette
  ildStyle->SetPalette(1,0);

  //set the default line color for a histogram to be black
  ildStyle->SetHistLineColor(kBlack);

  //set the default line color for a fit function to be red
  ildStyle->SetFuncColor(kRed);

  //make the axis labels black
  ildStyle->SetLabelColor(kBlack,"xyz");

  //set the default title color to be black
  ildStyle->SetTitleColor(kBlack);

  //set the margins
  ildStyle->SetPadBottomMargin(0.18);
  ildStyle->SetPadTopMargin(0.08);
  ildStyle->SetPadRightMargin(0.08);
  ildStyle->SetPadLeftMargin(0.17);

  //set axis label and title text sizes
  ildStyle->SetLabelFont(42,"xyz");
  ildStyle->SetLabelSize(0.06,"xyz");
  ildStyle->SetLabelOffset(0.015,"xyz");
  ildStyle->SetTitleFont(42,"xyz");
  ildStyle->SetTitleSize(0.07,"xyz");
  ildStyle->SetTitleOffset(1.1,"yz");
  ildStyle->SetTitleOffset(1.0,"x");
  ildStyle->SetStatFont(42);
  ildStyle->SetStatFontSize(0.07);
  ildStyle->SetTitleBorderSize(0);
  ildStyle->SetStatBorderSize(0);
  ildStyle->SetTextFont(42);

  //set line widths
  ildStyle->SetFrameLineWidth(2);
  ildStyle->SetFuncWidth(2);
  ildStyle->SetHistLineWidth(2);

  //set the number of divisions to show
  ildStyle->SetNdivisions(506, "xy");

  //turn off xy grids
  ildStyle->SetPadGridX(0);
  ildStyle->SetPadGridY(0);

  //set the tick mark style
  ildStyle->SetPadTickX(1);
  ildStyle->SetPadTickY(1);

  //turn off stats
  ildStyle->SetOptStat(0);
  ildStyle->SetOptFit(0);

  //marker settings
  ildStyle->SetMarkerStyle(20);
  ildStyle->SetMarkerSize(0.7);
  ildStyle->SetLineWidth(2);

  //done
  ildStyle->cd();
  gROOT->ForceStyle();
  gStyle->ls();

  std::vector<std::array<float, 3>> colors {{27,158,119}, {217,95,2}, {117,112,179}, {231,41,138}, {102,166,30}, {230,171,2}};
  for (int j=0; j<colors.size(); j++) {
    TColor *h2_color = new TColor(9100+j, colors[j][0]/256.0, colors[j][1]/256.0, colors[j][2]/256.0);
  }

}
