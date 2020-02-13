#include <iostream>

#include "LisDob.hpp"

using namespace std;

/////////////////////////////////////////// Clase Lista Doble
////////////// CONSTRUCTOR
LisDob::LisDob(){
	pri = NULL;
	ult = NULL;
}
		
////////////// METODOS
void LisDob::agr(int d){
	NodLisDob* nue = new NodLisDob(d);
	if(d >= 0){
		if(pri != NULL){
			ult->sig = nue;
			nue->ant = ult;
			ult = nue;
			
		}else{
			pri = nue;
			ult = nue;
		}
	}
}
void LisDob::agr(int d, NodArb* na){
	NodLisDob* nue = new NodLisDob(d, na);
	if(d >= 0){
		if(pri != NULL){
			ult->sig = nue;
			nue->ant = ult;
			ult = nue;
		}else{
			pri = nue;
			ult = nue;
		}
	}
}
string LisDob::obtCod(){
	MatDis m;
	NodLisDob *temp = pri;
	
	while(temp != NULL){
		MatDis t = temp->cap->md;
		m = t.matCom(m);
		temp = temp->sig;
	}
	
	return m.obtCod();
}
string LisDob::obtCod(string ini){
	string t = "", t2 = "";
	NodLisDob *temp = pri;
	
	while(temp != NULL){
		if(temp == pri) t += "img" + ini + " -> cap_" + ini + "_" + h.intStr(temp->dat);
		t += " cap_" + ini + "_" + h.intStr(temp->dat);
		t2 += "cap_" + ini + "_" + h.intStr(temp->dat) + "[ shape=box fillcolor=skyblue label=\"cap" + h.intStr(temp->dat) + "\"];\n";
		temp = temp->sig;
		if(temp != NULL) t += " -> ";
	}
	t += "\n";
	return t + t2;
}
string LisDob::obtCodArb(string ini){
	string con, atr = "", enl = "";
	con = "img" + ini + "[ label=\"ima: " + ini + "\" shape=ellipse color=royalblue ]\n";
	NodLisDob *temp = pri;
	while(temp != NULL){
		if(temp == pri) con += "img" + ini + " -> cap_" + ini + "_" + h.intStr(temp->dat);
		else con += " cap_" + ini + "_" + h.intStr(temp->dat);
		atr += "cap_" + ini + "_" + h.intStr(temp->dat) + "[ shape=box fillcolor=skyblue label=\"cap" + h.intStr(temp->dat) + "\" ];\n";
		enl += "cap_" + ini + "_" + h.intStr(temp->dat) + " -> cap" + h.intStr(temp->cap->dat) + ";\n";
		temp = temp->sig;
		if(temp != NULL) con += " -> ";
	}
	con += "\n";
	atr = "subgraph cluster_0 {\n" + atr + "\n}\n";
	
	return atr + con + enl;
}

bool LisDob::exiID(int d){
	NodLisDob *temp = pri;
	
	while(temp != NULL){
		if(temp->dat == d) return true;
		temp = temp->sig;
	}
	return false;
}
void LisDob::imp(){
	NodLisDob *temp = pri;
	
	while(temp != NULL){
		cout << "Dato:" << temp->dat << "  Nodos: " << temp->ant << " <- " << temp << " -> " << temp->sig << endl;
		temp = temp->sig;
	}
}

/////////////////////////////////////////// Clase Nodo Lista Doble
////////////// CONSTRUCTOR
NodLisDob::NodLisDob(int d){
	sig = NULL;
	ant = NULL;
	dat = d;
	cap = NULL;
}
NodLisDob::NodLisDob(int d, NodArb* na){
	sig = NULL;
	ant = NULL;
	dat = d;
	cap = na;
}
			
////////////// METODOS

