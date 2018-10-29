#include "LepNuProcessor.h"

void LepNuProcessor::analyseCompleteEvent(
		LCCollection* colMC, LCCollection* colPFOs,
		LCRelationNavigator* relation_recoMCtruth,
		EventInfo &info) {

	// // Search for all (lowest level) reco-particles
	// ReconstructedParticleVec PFOs = readRecoColToVector( colPFOs );
	// RecoSet recos_set;
  // 
	// for ( int iPFO = 0; iPFO<PFOs.size(); iPFO++ ) {
	// 	ReconstructedParticle* PFO_i = PFOs[iPFO];
	// 	findLowestLevelRecoParticles(PFO_i, recos_set);
	// }
  // 
	// // Find leptons
	// RecoSet reco_leptons_set;
	// findChargedLeptons( recos_set, reco_leptons_set );

  MCParticleVec mc_particles = this->readMCColToVector( colMC );

	findLeptonNeutrinoVertices( mc_particles, relation_recoMCtruth, &(info.total_event) );

}
