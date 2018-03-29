#include "LepNuProcessor.h"

void LepNuProcessor::SplitWeight(
                FloatVec &combined_weights, FloatVec &single_weights,
                std::string weight_name ) {
        for (int i=0; i<combined_weights.size(); i++) {
                if ( weight_name == "trck" ) {
                        single_weights.push_back(double((int(combined_weights[i])%10000)/1000.));
                }
                else if ( weight_name == "calo" ) {
                        single_weights.push_back(double((int(combined_weights[i])/10000)/1000.));
                }
        }
}

bool LepNuProcessor::IsNeutrinoID( int pdgID ) {
  if( fabs(pdgID) == 12 ||
      fabs(pdgID) == 14 ||
      fabs(pdgID) == 16 ||
      fabs(pdgID) == 18 ){
      return true;
  } else {
    return false;
  }
}


void LepNuProcessor::findNeutrinosToLepton( MCParticle* lep, std::set<MCParticle*> &nus ) {
    MCParticleVec parents = lep->getParents();
    for ( int i=0; i<parents.size(); i++ ){
      int parent_ID = parents[i]->getPDG();

      MCParticleVec daughters = parents[i]->getDaughters();

      std::set<MCParticle*> current_parent_nus;

      int N_lep_daughters = 0;

      for ( int j=0; j<daughters.size(); j++ ) {
        MCParticle* mc = daughters[j];
        int daughter_ID = mc->getPDG();

        if ( IsChargedLeptonID(daughter_ID) ) { N_lep_daughters++; }

        if ( IsNeutrinoID(daughter_ID) ) {
          nus.insert(mc);
        }
      }

      // If parent has more than one charged particle daughter ignore (likely neutral->l+l-)
      if ( N_lep_daughters == 1 ) {
        streamlog_out(DEBUG) << "Parent ID: " << parent_ID << std::endl;
        if ( IsChargedLeptonID(parent_ID) ) {
          streamlog_out(DEBUG) << "Second iteration!" << std::endl;
          findNeutrinosToLepton( parents[i], current_parent_nus );
        }

        nus.insert( current_parent_nus.begin(), current_parent_nus.end() );
      }
    }
}


void LepNuProcessor::findLeptonNeutrinoPairs( std::set<ReconstructedParticle*> &jet_leptons_set, LCRelationNavigator* relation_recoMCtruth, std::set<MCPMap> &mc_lep_nu_pairs) {
  std::set<MCParticle*> mc_leps_set;

  // Find all mc leptons associated with the reconstructed charged leptons
  for ( std::set<ReconstructedParticle*>::iterator reco_lep=jet_leptons_set.begin(); reco_lep!=jet_leptons_set.end(); ++reco_lep) {
    LCObjectVec mcs_to_reco_lep = relation_recoMCtruth->getRelatedToObjects( *reco_lep );
    FloatVec mc_weights_to_reco_lep = relation_recoMCtruth->getRelatedToWeights( *reco_lep );

    FloatVec mc_trck_weights_to_lep, mc_calo_weights_to_lep;
    SplitWeight( mc_weights_to_reco_lep, mc_trck_weights_to_lep, "trck");
    SplitWeight( mc_weights_to_reco_lep, mc_calo_weights_to_lep, "calo");

    for ( int i=0; i<mcs_to_reco_lep.size(); i++ ) {
      MCParticle* mc = dynamic_cast<MCParticle*>(mcs_to_reco_lep[i]);
      if ( ! IsChargedLeptonID(mc->getPDG()) ) { continue; }

      if ( mc_trck_weights_to_lep[i] > 0.9 || mc_calo_weights_to_lep[i] > 0.9 ) {
        mc_leps_set.insert(mc);
      }
    }
  }

  // Go through all parents and see if a neutrino is contained in their daughters
  for ( std::set<MCParticle*>::iterator mc_lep=mc_leps_set.begin(); mc_lep!=mc_leps_set.end(); ++mc_lep) {
    int lep_ID = (*mc_lep)->getPDG();

    // First check that lepton doesn't further decay into other charged lepton, if so ignore because correction will only applied to lowest level leptons
    MCParticleVec lep_daughters = (*mc_lep)->getDaughters();
    bool has_lep_daughters = false;
    for ( int i=0; i<lep_daughters.size(); i++) {
      if ( IsChargedLeptonID(lep_daughters[i]->getPDG()) ) { has_lep_daughters = true; }
    }
    if ( has_lep_daughters ) { continue; }

    std::set<MCParticle*> nus;
    LepNuProcessor::findNeutrinosToLepton( *mc_lep, nus );

    if ( nus.size() > 0 ) {
      mc_lep_nu_pairs.insert( std::make_pair( *mc_lep, nus ) );
    }
  }
}



		/*
    MCParticleVec parents = (*mc_lep)->getParents();
    std::set<MCParticle*> nus;
    for ( int i=0; i<parents.size(); i++ ){
      int parent_ID = parents[i]->getPDG();
      streamlog_out(DEBUG) << "Lepton Parent ID: " << parent_ID << std::endl;

      MCParticleVec daughters = parents[i]->getDaughters();

      for ( int j=0; j<daughters.size(); j++ ) {
        // The problem: decays like l- -> l'- nu' nu will have 2 nus in final state
        // -> If neutrino has same flavour (and CP) as parent: ignore it (comes from decay)
        // -> Only take neutrinos that are anti to the mc_lep and same flavour

        MCParticle* mc = daughters[j];
        int daughter_ID = mc->getPDG();
        if ( IsNeutrinoID(daughter_ID) ) {

          if (  ( fabs(daughter_ID) == fabs(parent_ID) + 1 ) &&
                ( daughter_ID * parent_ID > 0 ) ) {
            // Ignore because nu comes from decayed parent charged lepton
            continue;
          }
          else if ( ( fabs(daughter_ID) == fabs(lep_ID) + 1 ) &&
                    ( daughter_ID * lep_ID < 0 ) ) {
            // Nu fits profile of a nu-lep pair with current lep
            nus.insert(mc);
          }
        }
      }
    }

    if ( nus.size() > 1 ) {
      streamlog_out(DEBUG) << "WARNING in lep-nu pair finder: Ambiguous lepton, more than one nu. Skipping this lep." << std::endl;
      continue;
    }
    else if ( nus.size() == 1 ) {
      streamlog_out(DEBUG) << "In lep-nu pair finder: Found pair!" << std::endl;
      mc_lep_nu_pairs.insert( std::make_pair( *mc_lep, *(nus.begin()) ) );
    }
		*/
