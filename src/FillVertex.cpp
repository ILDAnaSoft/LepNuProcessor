#include "LepNuProcessor.h"

void LepNuProcessor::fillLepNuVertex( MCParticleVec vertex_parents, MCSet vertex_daughters, LepNuVertex* vertex ) {
  for ( int i=0; i<vertex_parents.size(); i++ ){
    MCParticle* parent = vertex_parents[i];
    Particle* parent_info = vertex->add_vertex_parent();

    (parent_info->MC).tlv = TLorentzVector( parent->getMomentum(), parent->getEnergy() );
    (parent_info->MC).vertex = TVector3( parent->getVertex() );
    (parent_info->MC).pdg_ID = parent->getPDG();
  }

  for ( MCSet::iterator daughter_it=vertex_daughters.begin(); daughter_it!=vertex_daughters.end(); ++daughter_it) {
    MCParticle* daughter = (*daughter_it);
    Particle* daughter_info = vertex->add_vertex_daughter();

    (daughter_info->MC).tlv = TLorentzVector( daughter->getMomentum(), daughter->getEnergy() );
    (daughter_info->MC).vertex = TVector3( daughter->getVertex() );
    (daughter_info->MC).pdg_ID = daughter->getPDG();
  }
}
