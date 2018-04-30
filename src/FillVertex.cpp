#include "LepNuProcessor.h"

int LepNuProcessor::findHighestLikelihoodPIDOfReco( ReconstructedParticle* reco ){
  ParticleIDVec all_IDs = reco->getParticleIDs();

  float highest_likelihood = 0;
  int highest_likelihood_ID = 0;
  for ( int i=0; i<all_IDs.size(); i++ ){
    ParticleID* current_PID = all_IDs[i];
    if ( current_PID->getLikelihood() > highest_likelihood ) {
      highest_likelihood = current_PID->getLikelihood();
      highest_likelihood_ID = current_PID->getPDG();
    }
  }
  return highest_likelihood_ID;
}

void LepNuProcessor::fillRecoToMCParticle( MCParticle* mc, Particle* particle_info, LCRelationNavigator* relation_recoMCtruth ) {
  LCObjectVec recos_to_mc = relation_recoMCtruth->getRelatedFromObjects( mc );
  if ( recos_to_mc.size() > 0 ) {
    particle_info->was_reconstructed = true;
    ReconstructedParticle* reco = findHighestWeightRecoToMCParticle( mc, relation_recoMCtruth );

    (particle_info->MC).tlv = TLorentzVector( reco->getMomentum(), reco->getEnergy() );
    if ( reco->getStartVertex() != 0 ){
      (particle_info->MC).vertex = TVector3( reco->getStartVertex()->getPosition() );
    }
    (particle_info->MC).pdg_ID = findHighestLikelihoodPIDOfReco( reco );
  } else {
    particle_info->was_reconstructed = false;
  }
}

void LepNuProcessor::fillLepNuVertex( MCParticleVec vertex_parents, MCSet vertex_daughters, LepNuVertex* vertex, LCRelationNavigator* relation_recoMCtruth ) {
  for ( int i=0; i<vertex_parents.size(); i++ ){
    MCParticle* parent = vertex_parents[i];
    Particle* parent_info = vertex->add_vertex_parent();

    (parent_info->MC).tlv = TLorentzVector( parent->getMomentum(), parent->getEnergy() );
    (parent_info->MC).vertex = TVector3( parent->getVertex() );
    (parent_info->MC).pdg_ID = parent->getPDG();

    fillRecoToMCParticle( parent, parent_info, relation_recoMCtruth );
  }

  for ( MCSet::iterator daughter_it=vertex_daughters.begin(); daughter_it!=vertex_daughters.end(); ++daughter_it) {
    MCParticle* daughter = (*daughter_it);
    Particle* daughter_info = vertex->add_vertex_daughter();

    (daughter_info->MC).tlv = TLorentzVector( daughter->getMomentum(), daughter->getEnergy() );
    (daughter_info->MC).vertex = TVector3( daughter->getVertex() );
    (daughter_info->MC).pdg_ID = daughter->getPDG();

    fillRecoToMCParticle( daughter, daughter_info, relation_recoMCtruth );
  }
}
