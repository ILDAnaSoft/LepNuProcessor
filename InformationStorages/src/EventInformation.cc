#include "EventInformation.h"

VertexDaughter::VertexDaughter() : TObject() {}

ParentVertex::ParentVertex() : TObject() {
	v_daughters.SetOwner(kTRUE);
}

void ParentVertex::Clear( Option_t *option ){
	v_daughters.Clear(option);
}

TLorentzVector ParentVertex::get_total_v_daughter_tlv() {
	TLorentzVector total_v_daughter_tlv {};
	for ( int i=0; i<v_daughters.GetEntries(); i++ ) {
		total_v_daughter_tlv += ((VertexDaughter*)v_daughters[i])->tlv_v_daughter;
	}
	return total_v_daughter_tlv;
}


Nu::Nu() : TObject() {
}

LepNuPair::LepNuPair() : TObject() {
	nus.SetOwner(kTRUE);
}

Nu* LepNuPair::add_nu(){
	Nu *new_nu = new Nu();
	nus.Add( new_nu );
	return new_nu;
}

void LepNuPair::Clear( Option_t *option ) {
	nus.Clear(option);
}

TLorentzVector LepNuPair::get_total_nu_tlv() {
		TLorentzVector total_nu_tlv {};
		for ( int i=0; i<nus.GetEntries(); i++ ) {
			total_nu_tlv += ((Nu*)nus[i])->tlv_nu;
		}
		return total_nu_tlv;
}

TJJet::TJJet() : TObject() {
	lep_nu_pairs.SetOwner(kTRUE);
}

LepNuPair* TJJet::add_lep_nu_pair(){
	LepNuPair *new_pair = new LepNuPair();
	lep_nu_pairs.Add( new_pair );
	return new_pair;
}

void TJJet::Clear( Option_t *option ) {
  lep_nu_pairs.Clear(option);
}


TotalEvent::TotalEvent() : TObject() {
	lep_nu_pairs.SetOwner(kTRUE);
}

LepNuPair* TotalEvent::add_lep_nu_pair(){
	LepNuPair *new_pair = new LepNuPair();
	lep_nu_pairs.Add( new_pair );
	return new_pair;
}

void TotalEvent::Clear( Option_t *option ) {
  lep_nu_pairs.Clear(option);
}


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
	ClassImp(VertexDaughter)
	ClassImp(ParentVertex)
	ClassImp(Nu)
	ClassImp(LepNuPair)
	ClassImp(TJJet)
	ClassImp(TotalEvent)
	ClassImp(EventInfo)
#endif
