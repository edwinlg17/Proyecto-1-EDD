#include <iostream>
#include "Arb.hpp"

/////////////////////////////////////////// Clase Arbol
////////////// CONSTRUCTOR
Arb::Arb(){
	rai = NULL; 
}

////////////// METODOS

void Arb::agr(int d){
	if(rai != NULL) agr(d, rai);
	else rai = new NodArb(d);
}
void Arb::agr(int d, NodArb *r){
	if(r->dat < d){
		if(r->der != NULL) agr(d, r->der);
		else r->der = new NodArb(d);
	}else if(r->dat > d){
		if(r->izq != NULL) agr(d, r->izq);
		else r->izq = new NodArb(d);
	}
}
void Arb::agr(int d, MatDis m){
	if(rai != NULL) agr(d, m, rai);
	else rai = new NodArb(d, m);
}
void Arb::agr(int d, MatDis m, NodArb *r){
	if(r->dat < d){
		if(r->der != NULL) agr(d, m, r->der);
		else r->der = new NodArb(d, m);
	}else if(r->dat > d){
		if(r->izq != NULL) agr(d, m, r->izq);
		else r->izq = new NodArb(d, m);
	}
}

string Arb::obtCod(){
	string cad = "node [ style=filled color=royalblue];\n";
	if(rai != NULL) cad += obtCod(rai);
	return cad;
}
string Arb::obtCod(NodArb* r){
	string t = "";
	if(r != NULL){
		if(r->izq != NULL){
			t += "cap" + h.intStr(r->dat) + " -> cap" + h.intStr(r->izq->dat) + " ";
			t += obtCod(r->izq);
		} else if(r->der != NULL) t += "cap" + h.intStr(r->dat) + " -> NULL" + h.intStr(r->dat) + " ";
		if(r->der != NULL){
			t += "cap" + h.intStr(r->dat) + " -> cap" + h.intStr(r->der->dat) + " ";
			t += obtCod(r->der);
		}else if(r->izq != NULL) t += "cap" + h.intStr(r->dat) + " -> NULL" + h.intStr(r->dat) + " ";
	}
	
	return t;
}
string Arb::obtCodI(){
	string cad = "node [ style=filled color=royalblue];\n";
	if(rai != NULL) cad += obtCodI(rai);
	return cad;
}
string Arb::obtCodI(NodArb* r){
	string t = "";
	if(r != NULL){
		if(r->der != NULL){
			t += "cap" + h.intStr(r->dat) + " -> cap" + h.intStr(r->der->dat) + " ";
			t += obtCodI(r->der);
		}else if(r->izq != NULL) t += "cap" + h.intStr(r->dat) + " -> NULL" + h.intStr(r->dat) + " ";
		if(r->izq != NULL){
			t += "cap" + h.intStr(r->dat) + " -> cap" + h.intStr(r->izq->dat) + " ";
			t += obtCodI(r->izq);
		} else if(r->der != NULL) t += "cap" + h.intStr(r->dat) + " -> NULL" + h.intStr(r->dat) + " ";
	}
	return t;
}
string Arb::obtCodM(int i){
	NodArb *nt = obt(i);
	if(nt != NULL) return nt->md.obtCodM();
	return "";  
}

NodArb* Arb::obt(int d){
	if(rai != NULL) return obt(d, rai);
	return NULL;
}
NodArb* Arb::obt(int d, NodArb *r){
	if(r != NULL){
		if(r->dat > d) obt(d, r->izq);
		else if(r->dat < d) obt(d, r->der);
		else return r;
	}else return NULL;
}
void Arb::rio(){
	if(rai != NULL){
		Lis t;
		lm = t;
		rio(rai);
	}
}
void Arb::rio(NodArb* t){
	if(t->izq != NULL) rio(t->izq);
	lm.agr(h.intStr(t->dat), t->md);
	cout << t->dat << endl;
	if(t->der != NULL) rio(t->der);
}
void Arb::rPre(){
	if(rai != NULL){
		Lis t;
		lm = t;
		rPre(rai);
	} 
}
void Arb::rPre(NodArb* t){
	lm.agr(h.intStr(t->dat), t->md);
	cout << t->dat << endl;
	if(t->izq != NULL) rPre(t->izq);
	if(t->der != NULL) rPre(t->der);
}
void Arb::rPos(){
	if(rai != NULL){
		Lis t;
		lm = t;
		rPos(rai);
	} 
}
void Arb::rPos(NodArb* t){
	if(t->izq != NULL) rPos(t->izq);
	if(t->der != NULL) rPos(t->der);
	lm.agr(h.intStr(t->dat), t->md);
	cout << t->dat << endl;
}
Lis Arb::obtLisMat(){
	return lm;
}

/////////////////////////////////////////// Clase Nodo Arbol
////////////// CONSTRUCTOR
NodArb::NodArb(int d){
	izq = NULL;
	der = NULL;
	dat = d;
}
NodArb::NodArb(int d, MatDis m){
	izq = NULL;
	der = NULL;
	dat = d;
	md = m;
}

////////////// METODOS






