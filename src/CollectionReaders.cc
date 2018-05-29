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

bool LepNuProcessor::hasNonTrivialPartner( MCParticle* mc, LCRelationNavigator* relation_recoMCtruth ) {
	FloatVec mc_weights_to_recos = relation_recoMCtruth->getRelatedFromWeights( mc );

  FloatVec mc_trck_weights_to_recos, mc_calo_weights_to_recos;
  splitWeight( mc_weights_to_recos, mc_trck_weights_to_recos, "trck");
  splitWeight( mc_weights_to_recos, mc_calo_weights_to_recos, "calo");

	for ( int i=0; i<mc_trck_weights_to_recos.size(); i++) {
		if ( mc_trck_weights_to_recos[i] > 0 ) {return true;}
	}
	for ( int i=0; i<mc_calo_weights_to_recos.size(); i++) {
		if ( mc_calo_weights_to_recos[i] > 0 ) {return true;}
	}
	return false;
}
