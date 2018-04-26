#include "EventInformation.h"

////////////////////////////////// ParticleProperties

ParticleProperties::ParticleProperties() : TObject() {}

////////////////////////////////// Particle

Particle::Particle() : TObject() {}

////////////////////////////////// LepNuVertex

LepNuVertex::LepNuVertex() : TObject() {
	vertex_parents.SetOwner(kTRUE);
	vertex_daughters.SetOwner(kTRUE);
}

Particle* LepNuVertex::add_vertex_parent(){
	Particle *new_particle = new Particle();
	vertex_parents.Add( new_particle );
	return new_particle;
}

Particle* LepNuVertex::add_vertex_daughter(){
	Particle *new_particle = new Particle();
	vertex_daughters.Add( new_particle );
	return new_particle;
}

void LepNuVertex::Clear( Option_t *option ){
	vertex_parents.Clear(option);
	vertex_daughters.Clear(option);
}

////////////////////////////////// TJJet

TJJet::TJJet() : TObject() {
	lep_nu_vertices.SetOwner(kTRUE);
}

LepNuVertex* TJJet::add_lep_nu_vertex(){
	LepNuVertex *new_vertex = new LepNuVertex();
	lep_nu_vertices.Add( new_vertex );
	return new_vertex;
}

void TJJet::Clear( Option_t *option ) {
  lep_nu_vertices.Clear(option);
}

////////////////////////////////// TotalEvent

TotalEvent::TotalEvent() : TObject() {
	lep_nu_vertices.SetOwner(kTRUE);
}

LepNuVertex* TotalEvent::add_lep_nu_vertex(){
	LepNuVertex *new_vertex = new LepNuVertex();
	lep_nu_vertices.Add( new_vertex );
	return new_vertex;
}

void TotalEvent::Clear( Option_t *option ) {
  lep_nu_vertices.Clear(option);
}

////////////////////////////////// EventInfo

EventInfo::EventInfo() : TObject() {
	evtN = -1;

	tj_jets.SetOwner(kTRUE);
}

TJJet* EventInfo::add_tj_jet() {
	TJJet *new_jet = new TJJet();
	tj_jets.Add( new_jet );
	return new_jet;
}

void EventInfo::Clear( Option_t *option ) {
  tj_jets.Clear(option);
}

// Make classes known to ROOT
#if !defined(__CINT__)
	ClassImp(ParticleProperties)
	ClassImp(Particle)
	ClassImp(LepNuVertex)
	ClassImp(TJJet)
	ClassImp(TotalEvent)
	ClassImp(EventInfo)
#endif
