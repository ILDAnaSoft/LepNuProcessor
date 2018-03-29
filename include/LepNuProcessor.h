#ifndef LepNuProcessor_h
#define LepNuProcessor_h 1

#include "marlin/Processor.h"
#include "StandardIncludes.h"

#include "EventInformation.h"

// TrueJet_Parser can link generator level color singlets (quarks,gluons)
// to the jet particles they produced, thereby allowing comparison of
// correct jet with own clustered one.
#include "Adjusted_TrueJet_Parser.h"


class LepNuProcessor : public Processor , public Adjusted_TrueJet_Parser {
 public:
  virtual Processor*  newProcessor() { return new LepNuProcessor ; }

  LepNuProcessor() ;

  /** Called at the begin of the job before anything is read.
   * Use to initialize the processor, e.g. book histograms.
   */
  virtual void init() ;

  virtual void makeNTuple() ;

  /** Called for every run.
   */
  virtual void processRunHeader( LCRunHeader* run ) ;

  /** Called for every event - the working horse.
   */
  virtual void processEvent( LCEvent * evt ) ;

  // Map one MCParticle to bunch of others
  // Here: Map one charged lepton to all its neutrinos
  typedef std::pair<MCParticle*, std::set<MCParticle*> > MCPMap;

    /** Subroutines
     */
    virtual void analyseEvent(LCCollection* colMC, LCCollection* colPFOs, LCRelationNavigator* relation_recoMCtruth, EventInfo &info);

	  virtual void SplitWeight( FloatVec &combined_weights, FloatVec &single_weights, std::string weight_name );
    virtual bool IsNeutrinoID( int pdgID );
    virtual void findNeutrinosToLepton( MCParticle* lep, std::set<MCParticle*> &nus );
    virtual void findLeptonNeutrinoPairs( std::set<ReconstructedParticle*> &jet_leptons_set, LCRelationNavigator* relation_recoMCtruth, std::set<MCPMap> &mc_lep_nu_pairs);

    virtual bool IsChargedLeptonID( int pdgID );
    virtual bool IdentifiedAsChargedLepton( ReconstructedParticle* PFO );
    virtual void FindChargedLeptons( std::set<ReconstructedParticle*> &jet_recos_set, std::set<ReconstructedParticle*> &jet_leptons_set );

    virtual void FindLowestLevelRecoParticles( ReconstructedParticle* reco, std::set<ReconstructedParticle*> &jet_recos_set );

    virtual int FindLeptonGeneration( int pdgID );

  /** For TrueJet_Parser -> see its documentation
  */
  std::string get_recoMCTruthLink(){ return _recoMCTruthLink  ; } ;

  virtual void check( LCEvent * evt ) ;


  /** Called after data processing for clean up.
   */
  virtual void end() ;


  /**
  General Helper Functions
  */

 protected:
  /** Input collection name.
   */
  std::string _colAllPFOs{};
  std::string _colMC{};

  std::string _mcpfoRelation{};

  // Input collections for TrueJet
  std::string _recoMCTruthLink{};

  // This are NOT declared here! They are already declared in TrueJet_Parser.h and repeated delaration will lead to error!
  //std::string _trueJetCollectionName;
  //std::string _finalColourNeutralCollectionName;
  //std::string _initialColourNeutralCollectionName;
  //std::string _trueJetPFOLink;
  //std::string _trueJetMCParticleLink;
  //std::string _initialElementonLink;
  //std::string _finalElementonLink;
  //std::string _finalColourNeutralLink;
  //std::string _initialColourNeutralLink;


  //std::string get_recoMCTruthLink(){ return _recoMCTruthLink  ; } ;

  /** Parameters during Marlin analysis
   */

  int _nRun {};
  int _nEvt {};

  EventInfo info{};

  /** Output File specifics
   */
  TFile* _otfile{};
  TTree* _datatrain{};
  //TTree* _TJRecoLeptonsInJets_tree;
  //TTree* _TJMCLeptonsInJets_tree;

  std::string _rootfilename{};
} ;

#endif
