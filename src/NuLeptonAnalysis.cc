#include "LepNuProcessor.h"

void LepNuProcessor::analyseEvent(
		LCCollection* colMC, LCCollection* colPFOs,
		LCRelationNavigator* relation_recoMCtruth,
		EventInfo &info) {

		analyseTJJets( colMC, colPFOs, relation_recoMCtruth, info);
		analyseCompleteEvent( colMC, colPFOs, relation_recoMCtruth, info);
		
}
