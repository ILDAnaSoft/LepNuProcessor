#ifndef EVENT_INFORMATION_H
#define EVENT_INFORMATION_H 1

//#include "StandardIncludes.h"
#include "TObject.h"
#include "TLorentzVector.h"
#include "TObjArray.h"


///////////////////// Objects contained in one l-nu-pair ///////////////////////

struct VertexDaughter : public TObject {
	int v_daughter_ID {} ;
	TLorentzVector tlv_v_daughter {};

	VertexDaughter();

	ClassDef( VertexDaughter, 1 );
};


struct ParentVertex : public TObject {
	int v_parent_ID {};
	TLorentzVector tlv_v_parent {};
	TVector3 v_position {};
	TObjArray v_daughters {};

	ParentVertex();

	VertexDaughter* add_v_daughter();
	void Clear( Option_t *option="" );
	TLorentzVector get_total_v_daughter_tlv();

	ClassDef( ParentVertex, 1 );
};

struct Nu : public TObject {
	int nu_ID {};
	TLorentzVector tlv_nu {};

	Nu();

	ClassDef( Nu, 1 ); // Make class known to root
};


///////////////////// Lepton + (multiple) neutrino(s) pair /////////////////////

struct LepNuPair : public TObject {
	int lep_ID {};
	TLorentzVector tlv_lep {};
	TObjArray nus {};

	LepNuPair();

	Nu* add_nu();
	void Clear( Option_t *option="" );
	TLorentzVector get_total_nu_tlv();

	ClassDef( LepNuPair, 1 ); // Make class known to root
};

///////////////////// Objects containing several l-nu-pairs ////////////////////

struct TJJet : public TObject {
	// Information about one of the jets
	int fe_pdgID {};
	TLorentzVector tlv_true {};
	TLorentzVector tlv_seen {};
	TObjArray lep_nu_pairs {};

	TJJet();

	LepNuPair* add_lep_nu_pair();
	void Clear( Option_t *option="" );

	ClassDef( TJJet, 1 ); // Make class known to root
};

struct TotalEvent: public TObject {
	/* Class to hold non-jet-specific information */
	TObjArray lep_nu_pairs {};

	TotalEvent();

	LepNuPair* add_lep_nu_pair();
	void Clear( Option_t *option="" );

	ClassDef( TotalEvent, 1 );
};


///////////////////// All info about this event ////////////////////////////////

struct EventInfo : public TObject {
	/* General class that holds all information about the event
 	on all the levels of the generation */
	int evtN{};
	TObjArray tj_jets {};

	EventInfo();

	TJJet* add_tj_jet();
	void Clear( Option_t *option="C" ); // Option C for recursive clearing

	ClassDef( EventInfo, 1 ); // Make class known to root
};


#endif
