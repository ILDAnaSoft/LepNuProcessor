#include "LepNuProcessor.h"


bool LepNuProcessor::isNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 ||
      fabs(pdgID) == 14 ||
      fabs(pdgID) == 16 ||
      fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}


bool LepNuProcessor::isChargedLeptonID( int pdgID ) {
  if( fabs(pdgID) == 11 ||
      fabs(pdgID) == 13 ||
      fabs(pdgID) == 15 ||
      fabs(pdgID) == 17 ){
      return true;
  } else {
    return false;
  }
}

bool LepNuProcessor::identifiedAsChargedLepton( ReconstructedParticle* PFO ) {
  int pdgID;
  if ( PFO->getParticleIDs().size() > 0 ) {
    pdgID = PFO->getParticleIDs()[0]->getPDG();
  } else if ( PFO->getParticleIDUsed() != 0 ) {
    pdgID = PFO->getParticleIDUsed()->getPDG();
  } else {
    pdgID = PFO->getType();
  }

  return isChargedLeptonID( pdgID );
}

void LepNuProcessor::findChargedLeptons( RecoSet &recos_set, RecoSet &leptons_set) {
    for ( RecoSet::iterator it=recos_set.begin(); it!=recos_set.end(); ++it) {
        if ( identifiedAsChargedLepton(*it) ) {
          leptons_set.insert(*it);
        }
    }
}
