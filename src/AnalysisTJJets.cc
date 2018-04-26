#include "LepNuProcessor.h"

void LepNuProcessor::analyseTJJets(
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

				findLowestLevelRecoParticles(jetPFO_i, jet_recos_set);
			}
		}

		// Find leptons
		std::set<ReconstructedParticle*> jet_leptons_set;
		findChargedLeptons( jet_recos_set, jet_leptons_set );

		findLeptonNeutrinoVertices( jet_leptons_set, relation_recoMCtruth, jet_info );

	}
}
