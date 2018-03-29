#include "LepNuProcessor.h"

void LepNuProcessor::FindLowestLevelRecoParticles(
                ReconstructedParticle* reco, std::set<ReconstructedParticle*> &jet_recos_set ) {

        // Recursively search for lowest level of daughters and insert them in the set
        ReconstructedParticleVec daughters = reco->getParticles();
        if ( daughters.size() > 0 ) {
                for ( int idaughter=0; idaughter<daughters.size(); idaughter++ ) {
                        ReconstructedParticle* daughter = daughters[idaughter];

                        FindLowestLevelRecoParticles( daughter, jet_recos_set );
                }
        }
        else {
                jet_recos_set.insert(reco);
        }

}