#ifndef EVENT_INFORMATION_H
#define EVENT_INFORMATION_H 1

//#include "StandardIncludes.h"
#include "TObject.h"
#include "TLorentzVector.h"
#include "TObjArray.h"

struct Nu : public TObject {
	int nu_ID {};

	TLorentzVector tlv_nu {};

	Nu();

	ClassDef( Nu, 1 ); // Make class known to root
};

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
