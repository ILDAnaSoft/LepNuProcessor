#include "LepNuProcessor.h"

void LepNuProcessor::splitWeight( FloatVec &combined_weights, FloatVec &single_weights, std::string weight_name ) {
  for (int i=0; i<combined_weights.size(); i++) {
    if ( weight_name == "trck" ) {
      single_weights.push_back(double((int(combined_weights[i])%10000)/1000.));
    }
    else if ( weight_name == "calo" ) {
      single_weights.push_back(double((int(combined_weights[i])/10000)/1000.));
    }
  }
}

bool LepNuProcessor::findRecoOfMCDaughters( MCParticle* mc, Particle* particle_info, LCRelationNavigator* relation_recoMCtruth) {
  MCParticleVec daughters = mc->getDaughters();
  bool daughters_have_reco = false;
  streamlog_out(DEBUG) << "\nMC is: " << mc->getPDG() << "\n";
  for ( int i_daughter = 0; i_daughter<daughters.size(); i_daughter++ ) {
    MCParticle* daughter = daughters[i_daughter];

    if ( this->hasNonTrivialPartner(daughter, relation_recoMCtruth) ) {
      LCObjectVec recos_to_daughter = relation_recoMCtruth->getRelatedFromObjects( daughter );
      streamlog_out(DEBUG) << "\nDaughter is: " << daughter->getPDG() << " E " << daughter->getEnergy() << "\n";
      ReconstructedParticle* reco = this->findHighestWeightRecoToMCParticle( daughter, relation_recoMCtruth );
      (particle_info->Reco).tlv += TLorentzVector( reco->getMomentum(), reco->getEnergy() );
      daughters_have_reco = true;
    } else {
      daughters_have_reco |= this->findRecoOfMCDaughters( daughter, particle_info, relation_recoMCtruth );
    }
  }
  return daughters_have_reco;
}

ReconstructedParticle* LepNuProcessor::findHighestWeightRecoToMCParticle( MCParticle* mc, LCRelationNavigator* relation_recoMCtruth ) {
  LCObjectVec recos_to_mc = relation_recoMCtruth->getRelatedFromObjects( mc );
  FloatVec mc_weights_to_recos = relation_recoMCtruth->getRelatedFromWeights( mc );

  FloatVec mc_trck_weights_to_recos, mc_calo_weights_to_recos;
  this->splitWeight( mc_weights_to_recos, mc_trck_weights_to_recos, "trck");
  this->splitWeight( mc_weights_to_recos, mc_calo_weights_to_recos, "calo");

  float highest_weight = 0;
  int highest_weight_index = -999;
  for ( int i=0; i<recos_to_mc.size(); i++ ) {
    ReconstructedParticle* reco = dynamic_cast<ReconstructedParticle*>(recos_to_mc[i]);
    streamlog_out(DEBUG) << " weight trck: " << mc_trck_weights_to_recos[i] << " weight calo: " << mc_calo_weights_to_recos[i] <<"\n";
    if ( mc_trck_weights_to_recos[i] > highest_weight ) {
      highest_weight = mc_trck_weights_to_recos[i];
      highest_weight_index = i;
    }
    if ( mc_calo_weights_to_recos[i] > highest_weight ) {
      highest_weight = mc_calo_weights_to_recos[i];
      highest_weight_index = i;
    }
  }
  
  ReconstructedParticle* highest_weight_reco = nullptr;
  if ( highest_weight > 0 ) {
    streamlog_out(DEBUG) << " highest i: " << highest_weight_index <<"\n";
    highest_weight_reco = dynamic_cast<ReconstructedParticle*>(recos_to_mc[highest_weight_index]);
  }
  return highest_weight_reco;
}
