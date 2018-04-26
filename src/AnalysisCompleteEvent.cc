#include "LepNuProcessor.h"

void LepNuProcessor::analyseCompleteEvent(
		LCCollection* colMC, LCCollection* colPFOs,
		LCRelationNavigator* relation_recoMCtruth,
		EventInfo &info) {

	// 	std::set<ReconstructedParticle*> recos_set;
	//
	// 	int N_recos = colPFOs->getNumberOfElements();
	// 	for ( int iPFO = 0; iPFO<N_recos; iPFO++ ) {
	// 		ReconstructedParticle* PFO_i = dynamic_cast<ReconstructedParticle*>( colPFOs->getElementAt(iPFO) );
	//
	// 		FindLowestLevelRecoParticles( PFO_i, recos_set);
	// 	}
	//
	// 	// Find leptons
	// 	std::set<ReconstructedParticle*> reco_leptons_set;
	// 	FindChargedLeptons( recos_set, reco_leptons_set );
	//
	// 	std::set<MCPMap> mc_lep_nu_pairs;
	// 	findLeptonNeutrinoPairs( reco_leptons_set, relation_recoMCtruth, mc_lep_nu_pairs);
	// // 	streamlog_out(DEBUG) << "Jet " <<  i << ": found " << mc_lep_nu_pairs.size() << " lep-nu pairs." << std::endl;
	//
	//  	for ( std::set<MCPMap>::iterator lep_nu_pair_it=mc_lep_nu_pairs.begin(); lep_nu_pair_it!=mc_lep_nu_pairs.end(); ++lep_nu_pair_it) {
	//  		LepNuPair *lep_nu_pair_info = info.total_event.add_lep_nu_pair();
	//
	// 		MCPMap lep_nu_pair = (*lep_nu_pair_it);
	//
	// 		MCParticle* lep = lep_nu_pair.first;
	// 		std::set<MCParticle*> nus = lep_nu_pair.second;
	//
	// 		lep_nu_pair_info->lep_ID = lep->getPDG();
	// 		lep_nu_pair_info->tlv_lep = TLorentzVector( lep->getMomentum(), lep->getEnergy() );
	//
	// 		for ( std::set<MCParticle*>::iterator nu_it=nus.begin(); nu_it!=nus.end(); ++nu_it) {
	// 			Nu *nu_info = lep_nu_pair_info->add_nu();
	// 			MCParticle* nu = (*nu_it);
	//
	// 			nu_info->nu_ID = nu->getPDG();
	// 			nu_info->tlv_nu = TLorentzVector( nu->getMomentum(), nu->getEnergy() );
	// 		}
	//  }
}
