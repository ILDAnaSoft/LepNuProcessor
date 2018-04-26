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

struct VerticesContainer : public TObject {
	TObjArray lep_nu_vertices {};
	LepNuVertex* add_lep_nu_vertex();

	VerticesContainer();
	void Clear( Option_t *option="" );

	ClassDef( VerticesContainer, 1 );
};

struct TJJet : public VerticesContainer {
	// Information about one of the jets
	int fe_pdgID {};
	TLorentzVector tlv_true {};
	TLorentzVector tlv_seen {};

	TJJet();

	ClassDef( TJJet, 1 ); // Make class known to root
};

///////////////////// All info about this event ////////////////////////////////

struct EventInfo : public TObject {
	/* General class that holds all information about the event
 	on all the levels of the generation */
	int evtN{};
	VerticesContainer total_event {};
	TObjArray tj_jets {};

	EventInfo();

	TJJet* add_tj_jet();
	void Clear( Option_t *option="C" ); // Option C for recursive clearing

	ClassDef( EventInfo, 1 ); // Make class known to root
};


#endif
