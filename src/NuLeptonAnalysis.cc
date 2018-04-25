#include "LepNuProcessor.h"

void LepNuProcessor::analyseEvent(
		LCCollection* colMC, LCCollection* colPFOs,
		LCRelationNavigator* relation_recoMCtruth,
		EventInfo &info) {
	for (int i=0; i<njets(); i++) {
		if ( ! ( type_jet(i) == 1 || type_jet(i) == 3 || int(type_jet(i)%100) == 1 || int(type_jet(i)%100) == 3 )  ) { continue; }

		TJJet* jet_info = info.add_tj_jet();

		jet_info->fe_pdgID = final_elementon(i)->getPDG();
		jet_info->tlv_true = TLorentzVector( p4true(i)[1], p4true(i)[2], p4true(i)[3], p4true(i)[0]);
		jet_info->tlv_seen = TLorentzVector( p4seen(i)[1], p4seen(i)[2], p4seen(i)[3], p4seen(i)[0]);

		std::set<ReconstructedParticle*> jet_recos_set;

		// Search for all (lowest level) reco-particles in the jet
		if (  seen_partics(i).size() > 0 ) {
			// seen_partics(...) is function of TrueJet_Parser, see header
			ReconstructedParticleVec ijet_PFOs = seen_partics(i);

			for ( int ijetPFO = 0; ijetPFO<ijet_PFOs.size(); ijetPFO++ ) {
				ReconstructedParticle* jetPFO_i = ijet_PFOs[ijetPFO];

				FindLowestLevelRecoParticles(jetPFO_i, jet_recos_set);
			}
		}

		// Find leptons
		std::set<ReconstructedParticle*> jet_leptons_set;
		FindChargedLeptons( jet_recos_set, jet_leptons_set );

		std::set<MCPMap> mc_lep_nu_pairs;
		findLeptonNeutrinoPairs( jet_leptons_set, relation_recoMCtruth, mc_lep_nu_pairs);
		streamlog_out(DEBUG) << "Jet " <<  i << ": found " << mc_lep_nu_pairs.size() << " lep-nu pairs." << std::endl;


	for ( std::set<MCPMap>::iterator lep_nu_pair_it=mc_lep_nu_pairs.begin(); lep_nu_pair_it!=mc_lep_nu_pairs.end(); ++lep_nu_pair_it) {
			LepNuPair *lep_nu_pair_info = jet_info->add_lep_nu_pair();

			MCPMap lep_nu_pair = (*lep_nu_pair_it);

			MCParticle* lep = lep_nu_pair.first;
			std::set<MCParticle*> nus = lep_nu_pair.second;

			lep_nu_pair_info->lep_ID = lep->getPDG();
			lep_nu_pair_info->tlv_lep = TLorentzVector( lep->getMomentum(), lep->getEnergy() );

			for ( std::set<MCParticle*>::iterator nu_it=nus.begin(); nu_it!=nus.end(); ++nu_it) {
				Nu *nu_info = lep_nu_pair_info->add_nu();
				MCParticle* nu = (*nu_it);

				nu_info->nu_ID = nu->getPDG();
				nu_info->tlv_nu = TLorentzVector( nu->getMomentum(), nu->getEnergy() );
			}
		}
	}
}
