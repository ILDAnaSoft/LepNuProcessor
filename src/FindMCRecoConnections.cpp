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


ReconstructedParticle* LepNuProcessor::findHighestWeightRecoToMCParticle( MCParticle* mc, LCRelationNavigator* relation_recoMCtruth ) {
  LCObjectVec recos_to_mc = relation_recoMCtruth->getRelatedFromObjects( mc );
  FloatVec mc_weights_to_recos = relation_recoMCtruth->getRelatedFromWeights( mc );

  FloatVec mc_trck_weights_to_recos, mc_calo_weights_to_recos;
  splitWeight( mc_weights_to_recos, mc_trck_weights_to_recos, "trck");
  splitWeight( mc_weights_to_recos, mc_calo_weights_to_recos, "calo");

  float highest_weight = 0;
  int highest_weight_index = -999;
  for ( int i=0; i<recos_to_mc.size(); i++ ) {
    ReconstructedParticle* reco = dynamic_cast<ReconstructedParticle*>(recos_to_mc[i]);
    if ( mc_trck_weights_to_recos[i] > highest_weight ) {
      highest_weight = mc_trck_weights_to_recos[i];
      highest_weight_index = i;
    }
    if ( mc_calo_weights_to_recos[i] > highest_weight ) {
      highest_weight = mc_calo_weights_to_recos[i];
      highest_weight_index = i;
    }
  }
  ReconstructedParticle* highest_weight_reco = dynamic_cast<ReconstructedParticle*>(recos_to_mc[highest_weight_index]);
  return highest_weight_reco;
}
