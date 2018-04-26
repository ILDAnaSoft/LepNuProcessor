#include "LepNuProcessor.h"

int LepNuProcessor::findLeptonGeneration( int pdgID ) {
  int abs_pdgID = fabs(pdgID);
  if (abs_pdgID > 10 && abs_pdgID < 13) {
    return 1;
  }
  else if (abs_pdgID > 12 && abs_pdgID < 15) {
    return 2;
  }
  else if (abs_pdgID > 14 && abs_pdgID < 19) {
    return 3;
  }
  else {
    streamlog_out(DEBUG) << " WARNING: weird pdgID: " <<  pdgID << std::endl;
    return 0;
  }
}
