#ifndef EVENT_INFORMATION_H
#define EVENT_INFORMATION_H 1

//#include "StandardIncludes.h"
#include "TObject.h"
#include "TLorentzVector.h"
#include "TObjArray.h"
#include <vector>

struct ParticleProperties : public TObject {
	// Properties of one particle level
	TLorentzVector tlv {};
	TVector3 vertex {};
	int pdg_ID {};

	ParticleProperties();

	ClassDef( ParticleProperties, 1 );
};

struct Particle : public TObject {
	// MC Particle, may have been reconstructed
	ParticleProperties MC {};
	bool was_reconstructed {};
	ParticleProperties Reco {};

	Particle();

	ClassDef( Particle, 1 );
};

struct LepNuVertex : public TObject {
	// Vertex (=parent-daughter relationship point) including >= 1 charged lep and >= nu in daughters
	TObjArray vertex_parents {};
	TObjArray vertex_daughters {};

	LepNuVertex();
	Particle* add_vertex_parent();
	Particle* add_vertex_daughter();
	void Clear( Option_t *option="" );

	ClassDef( LepNuVertex, 1 );
};

///////////////////// Objects containing several l-nu vertices /////////////////


struct TJJet : public TObject {
	// Information about one of the jets
	int fe_pdgID {};
	TLorentzVector tlv_true {};
	TLorentzVector tlv_seen {};
	TObjArray lep_nu_vertices {};

	TJJet();

	LepNuVertex* add_lep_nu_vertex();
	void Clear( Option_t *option="" );

	ClassDef( TJJet, 1 ); // Make class known to root
};

struct TotalEvent: public TObject {
	/* Class to hold non-jet-specific information */
	TObjArray lep_nu_vertices {};

	TotalEvent();

	LepNuVertex* add_lep_nu_vertex();
	void Clear( Option_t *option="" );

	ClassDef( TotalEvent, 1 );
};


///////////////////// All info about this event ////////////////////////////////

struct EventInfo : public TObject {
	/* General class that holds all information about the event
 	on all the levels of the generation */
	int evtN{};
	TotalEvent total_event {};
	TObjArray tj_jets {};

	EventInfo();

	TJJet* add_tj_jet();
	void Clear( Option_t *option="C" ); // Option C for recursive clearing

	ClassDef( EventInfo, 1 ); // Make class known to root
};


#endif
