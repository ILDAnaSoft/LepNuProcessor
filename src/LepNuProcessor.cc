#include "LepNuProcessor.h"

LepNuProcessor aLepNuProcessor ;


LepNuProcessor::LepNuProcessor() : Processor("LepNuProcessor") {
    _description = "LepNuProcessor: Search for VBS at the ILD detector" ;


    // Standard input collections
    registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
            "InputAllPFOsCollection",
            "Name of the PFOs collection",
            _colAllPFOs,
            std::string("PandoraPFOs")
    );

    registerInputCollection( LCIO::MCPARTICLE,
            "MCParticleCollection",
            "Name of the MC particle collection",
            _colMC,
            std::string("MCParticle")
    );


	// Inputs from TrueJet processor
	//WARNING Remove the "2"s when possible

	registerInputCollection( LCIO::LCRELATION,
    		"RecoMCTruthLink",
    		"Name of the RecoMCTruthLink input collection"  ,
			_recoMCTruthLink,
			std::string("RecoMCTruthLink") ) ;

	registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
			"TrueJets" ,
			"Name of the TrueJetCollection output collection"  ,
			_trueJetCollectionName ,
			std::string("TrueJets") ) ;

	registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
			"FinalColourNeutrals" ,
			"Name of the FinalColourNeutralCollection output collection"  ,
			_finalColourNeutralCollectionName ,
			std::string("FinalColourNeutrals") ) ;

	registerInputCollection( LCIO::RECONSTRUCTEDPARTICLE,
			"InitialColourNeutrals" ,
			"Name of the InitialColourNeutralCollection output collection"  ,
			_initialColourNeutralCollectionName ,
			std::string("InitialColourNeutrals") ) ;

	 registerInputCollection( LCIO::LCRELATION,
			"TrueJetPFOLink" ,
			"Name of the TrueJetPFOLink output collection"  ,
			_trueJetPFOLink,
			std::string("TrueJetPFOLink") ) ;

	registerInputCollection( LCIO::LCRELATION,
			"TrueJetMCParticleLink" ,
			"Name of the TrueJetMCParticleLink output collection"  ,
			_trueJetMCParticleLink,
			std::string("TrueJetMCParticleLink") ) ;

	registerInputCollection( LCIO::LCRELATION,
			"FinalElementonLink" ,
			"Name of the  FinalElementonLink output collection"  ,
			_finalElementonLink,
			std::string("FinalElementonLink") ) ;

	registerInputCollection( LCIO::LCRELATION,
			"InitialElementonLink" ,
			"Name of the  InitialElementonLink output collection"  ,
			_initialElementonLink,
			std::string("InitialElementonLink") ) ;

	registerInputCollection( LCIO::LCRELATION,
			"FinalColourNeutralLink" ,
			"Name of the  FinalColourNeutralLink output collection"  ,
			_finalColourNeutralLink,
			std::string("FinalColourNeutralLink") ) ;

	registerInputCollection( LCIO::LCRELATION,
			"InitialColourNeutralLink" ,
			"Name of the  InitialColourNeutralLink output collection"  ,
			_initialColourNeutralLink,
			std::string("InitialColourNeutralLink") ) ;



	// Technical
	// -> e.g. rootfile names

    registerProcessorParameter( "RootFileName",
            "Name of Root file (default: output.root)",
            _rootfilename,
            std::string("/nfs/dust/ilc/group/ild/beyerjac/VBS/nunu_hadrons/output/root_files/output.root")
    );
}



void LepNuProcessor::init() {
    streamlog_out(DEBUG) << "   init called  " << std::endl ;

    // usually a good idea to
    printParameters() ;

    makeNTuple() ;

    _nRun = 0 ;
    _nEvt = 0 ;
}


void LepNuProcessor::makeNTuple() {
    _otfile = new TFile( _rootfilename.c_str() , "RECREATE" );
    _datatrain = new TTree( "datatrain" , "events" );

    _datatrain->Branch("info", "EventInfo", &info);
}



void LepNuProcessor::processRunHeader( LCRunHeader* run) {
    _nRun++ ;
}




void LepNuProcessor::processEvent( LCEvent * evt ) {
    // this gets called for every event
    // usually the working horse ...

    // Clear memory
	info.Clear();
	info.evtN = _nEvt;

	// tj is a pointer to a Trujet_Parser, with the data of this processor object:
	Adjusted_TrueJet_Parser* tj= this ;
	// this method gets all the collections needed + initialises a few convienent variables.
	tj->getall(evt);

	// Relation between ReconstructedParticles and their corresponding MCParticles
	// -> tells you which MC Particles contribute to ReconstructedParticle 4momentum
	LCRelationNavigator* relation_recoMCtruth = new LCRelationNavigator( evt->getCollection( _recoMCTruthLink ) );


  // try to get lcio collection (exits if collection is not available which is good bc they definitely should exist!!!))
  LCCollection* colAllPFOs 			= evt->getCollection( _colAllPFOs 		) ;
  LCCollection* colMC 				= evt->getCollection( _colMC 			) ;


	/** Call analysis script on event
 	*/

    //-- note: this will not be printed if compiled w/o MARLINDEBUG=1 !

    streamlog_out(DEBUG) << "   processing event: " << evt->getEventNumber()
       << "   in run:  " << evt->getRunNumber() << std::endl ;


	analyseEvent(	colMC, colAllPFOs,
					relation_recoMCtruth,
					info);

    _datatrain->Fill();

    _nEvt ++ ;
}



void LepNuProcessor::check( LCEvent * evt ) {
    // nothing to check here - could be used to fill checkplots in reconstruction processor
}


void LepNuProcessor::end(){
    _otfile->cd();
    _datatrain->Write();
    _otfile->Close();
    delete _otfile;
}
