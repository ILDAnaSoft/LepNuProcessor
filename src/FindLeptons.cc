#include "LepNuProcessor.h"

bool LepNuProcessor::IsChargedLeptonID( int pdgID ) {
  if( fabs(pdgID) == 11 ||
      fabs(pdgID) == 13 ||
      fabs(pdgID) == 15 ||
      fabs(pdgID) == 17 ){
      return true;
  } else {
    return false;
  }
}

bool LepNuProcessor::IdentifiedAsChargedLepton( ReconstructedParticle* PFO ) {
  int pdgID;
  if ( PFO->getParticleIDs().size() > 0 ) {
    pdgID = PFO->getParticleIDs()[0]->getPDG();
  } else if ( PFO->getParticleIDUsed() != 0 ) {
    pdgID = PFO->getParticleIDUsed()->getPDG();
  } else {
    pdgID = PFO->getType();
  }

  return IsChargedLeptonID( pdgID );
}

void LepNuProcessor::FindChargedLeptons(
  std::set<ReconstructedParticle*> &jet_recos_set, std::set<ReconstructedParticle*> &jet_leptons_set) {
    for ( std::set<ReconstructedParticle*>::iterator it=jet_recos_set.begin(); it!=jet_recos_set.end(); ++it) {
        if ( IdentifiedAsChargedLepton(*it) ) {
          jet_leptons_set.insert(*it);
        }
    }
}
