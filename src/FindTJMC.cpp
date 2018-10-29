#include "LepNuProcessor.h"

MCParticleVec LepNuProcessor::findMCsInTJjet( ReconstructedParticle* jet ) {
  MCParticleVec jet_mc {};
  if ( nullptr == jet ) {
    streamlog_out(WARNING) << "In findMCsInTJjet: Jet does not exist!" << std::endl;
    return jet_mc;
  }
  
  LCObjectVec jet_mc_objects = reltjmcp->getRelatedToObjects( jet );
  
  for ( auto & mc_object: jet_mc_objects ) {
    MCParticle* mc = dynamic_cast<MCParticle*>( mc_object );
    jet_mc.push_back(mc);
  }
  
  return jet_mc;
}