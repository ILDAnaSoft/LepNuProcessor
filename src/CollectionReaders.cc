#include "LepNuProcessor.h"

/* Functions that read in LCCollections and return
   vector containing the Particles in their corresponding
	LCIO format */

MCParticleVec LepNuProcessor::readMCColToVector(LCCollection* mcs) {
	MCParticleVec mc_vec;
	int N_mc = mcs->getNumberOfElements();
	for( int i = 0; i < N_mc; i++ ){
		MCParticle* mc = dynamic_cast< MCParticle* >( mcs->getElementAt(i) );
		mc_vec.push_back(mc);
	}
	return(mc_vec);
}


ReconstructedParticleVec LepNuProcessor::readRecoColToVector(LCCollection* recos) {
	ReconstructedParticleVec revo_vec;
	int N_reco;
	try{
		N_reco = recos->getNumberOfElements();
	} catch(...) {
		N_reco = 0;
	}
	if ( N_reco != 0 ){
		for( int i = 0; i < N_reco; i++ ){
			ReconstructedParticle* reco= dynamic_cast< ReconstructedParticle* >( recos->getElementAt(i) );
			revo_vec.push_back(reco);
		}
	}
	return(revo_vec);
}
