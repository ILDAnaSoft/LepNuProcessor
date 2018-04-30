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

void LepNuProcessor::findMCLepsToRecoLeps( RecoSet &reco_leps_set, MCSet &mc_leps_set, LCRelationNavigator* relation_recoMCtruth) {
  // Find all mc leptons associated with the reconstructed charged leptons
  for ( RecoSet::iterator reco_lep=reco_leps_set.begin(); reco_lep!=reco_leps_set.end(); ++reco_lep) {
    LCObjectVec mcs_to_reco_lep = relation_recoMCtruth->getRelatedToObjects( *reco_lep );
    FloatVec mc_weights_to_reco_lep = relation_recoMCtruth->getRelatedToWeights( *reco_lep );

    FloatVec mc_trck_weights_to_lep, mc_calo_weights_to_lep;
    splitWeight( mc_weights_to_reco_lep, mc_trck_weights_to_lep, "trck");
    splitWeight( mc_weights_to_reco_lep, mc_calo_weights_to_lep, "calo");

    for ( int i=0; i<mcs_to_reco_lep.size(); i++ ) {
      MCParticle* mc = dynamic_cast<MCParticle*>(mcs_to_reco_lep[i]);
      if ( ! isChargedLeptonID(mc->getPDG()) ) { continue; }

      if ( mc_trck_weights_to_lep[i] > 0.9 || mc_calo_weights_to_lep[i] > 0.9 ) {
        mc_leps_set.insert(mc);
      }
    }
  }
}


void LepNuProcessor::findLeptonNeutrinoVertices( RecoSet &reco_leps_set, LCRelationNavigator* relation_recoMCtruth, VerticesContainer* vertices_info ) {

  MCSet mc_leps_set;
  findMCLepsToRecoLeps( reco_leps_set, mc_leps_set, relation_recoMCtruth );

  MCSet treated_MC_daughters; // Set to keep track of MC particles already contained in a vertex as daughter

  // Go through all parents and see if a neutrino is contained in their daughters
  for ( MCSet::iterator mc_lep=mc_leps_set.begin(); mc_lep!=mc_leps_set.end(); ++mc_lep) {
    bool already_treated_as_daughter = ( treated_MC_daughters.find(*mc_lep) != treated_MC_daughters.end() );
    if (already_treated_as_daughter) { continue; }

    MCParticleVec vertex_parents = (*mc_lep)->getParents();
    MCSet vertex_daughters;
    bool has_nu_sibling = false;
    bool is_detector_effect = false; // If any parent is stable (gen_status=1) then neutrino must have come form detector effect

    for ( int i=0; i<vertex_parents.size(); i++ ){
      if ( vertex_parents[i]->getGeneratorStatus() == 1 ){
        is_detector_effect = true;
        break;
      }

      MCParticleVec daughters = vertex_parents[i]->getDaughters();

      // Can I find a neutrino sibling to the lepton?
      for ( int j=0; j<daughters.size(); j++ ) {
        MCParticle* mc = daughters[j];
        int daughter_ID = mc->getPDG();
        if ( isNeutrinoID(daughter_ID) ) { has_nu_sibling=true; }
      }

      vertex_daughters.insert( daughters.begin(), daughters.end() );
    }

    if ( has_nu_sibling && ! is_detector_effect ) {
      LepNuVertex* new_vertex = vertices_info->add_lep_nu_vertex();
      fillLepNuVertex( vertex_parents, vertex_daughters, new_vertex );
    }
  }
}
