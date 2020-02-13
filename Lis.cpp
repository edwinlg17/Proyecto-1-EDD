#include <iostream>

#include "Lis.hpp"

/////////////////////////////////////////// Clase Lista
////////////// CONSTRUCTOR
Lis::Lis(){
	pri = NULL;
	ult = pri;
}
////////////// METODOS
void Lis::agr(string d){
	if(pri != NULL){
		ult->sig = new NodLis(d);
		ult = ult->sig;
	}else{
		pri = new NodLis(d);
		ult = pri;
	}
}
void Lis::agr(string d, MatDis m){
	if(pri != NULL){
		ult->sig = new NodLis(d, m);
		ult = ult->sig;
	}else{
		pri = new NodLis(d, m);
		ult = pri;
	}
}

void Lis::imp(){
	NodLis *temp = pri;
	while(temp != NULL){
		cout << temp->dat << endl;
		temp = temp->sig;
	}
}
bool Lis::finIte(){
	if(ite != NULL) return false;
	return true;
}
string Lis::obtSig(){
	if(ite != NULL){
		string t = ite->dat;
		ite = ite->sig;
		return t; 
	}
	return "";
}
MatDis Lis::obtSigMat(){
	MatDis t;
	if(ite != NULL){
		t = ite->md;
		ite = ite->sig;
		return t; 
	}
	return t;
}
void Lis::reiIte(){
	ite = pri;
}

/////////////////////////////////////////// Clase Nodo Lista
////////////// CONSTRUCTOR
NodLis::NodLis(string d){
	sig = NULL;
	dat = d;
}
NodLis::NodLis(string d, MatDis m){
	sig = NULL;
	dat = d;
	md = m;
}

////////////// METODOS



