#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>

#include "ArbAVL.hpp"

using namespace std;
/////////////////////////////////////////// Clase Arbol
////////////// CONSTRUCTOR
ArbAVL::ArbAVL(){
	rai = NULL; 
}

////////////// METODOS
void ArbAVL::agr(string d){
	if(rai != NULL) agr(d, rai);
	else rai = new NodArbAVL(d);
}
void ArbAVL::agr(string d, NodArbAVL* &r){
	if(r->dat < d){
		if(r->der != NULL) agr(d, r->der);
		else r->der = new NodArbAVL(d);
	}else if(r->dat > d){
		if(r->izq != NULL) agr(d, r->izq);
		else r->izq = new NodArbAVL(d);
	}
	
	equ(r); 
}
void ArbAVL::agr(string d, LisDob l){
	if(rai != NULL) agr(d, l, rai);
	else rai = new NodArbAVL(d, l);
}
void ArbAVL::agr(string d, LisDob l, NodArbAVL* &r){
	if(r->dat < d){
		if(r->der != NULL) agr(d, l, r->der);
		else r->der = new NodArbAVL(d, l);
	}else if(r->dat > d){
		if(r->izq != NULL) agr(d, l, r->izq);
		else r->izq = new NodArbAVL(d, l);
	}
	
	equ(r); 
}
void ArbAVL::eli(string d){
	if(rai != NULL) eli(d, rai); 
}
void ArbAVL::eli(string d, NodArbAVL* &r){
	if(r->dat > d) eli(d, r->izq);
	else if(r->dat < d) eli(d, r->der);
	else{
		if(r->izq == NULL & r->der == NULL) r = NULL;
		else if(r->izq != NULL & r->der == NULL) r = r->izq;
		else if(r->izq == NULL & r->der != NULL) r = r->der;
		else {
			if(alt(r->der) - 1 != 0){
				NodArbAVL *iz = r->izq;
				NodArbAVL *de = r->der;
				r = sus(r->der);
				r->der = de;
				r->izq = iz;
			}else {
				r->der->izq = r->izq;
				r->der->der = NULL;
				r = r->der;
			}
		}
	}
	if(r != NULL) equ(r);
}

bool ArbAVL::exiUsu(string d, int i){
	if(rai != NULL) return exiUsu(d, i, rai); 
	return false;
}
bool ArbAVL::exiUsu(string d, int i, NodArbAVL* r){
	bool est = false;
	if(r != NULL){
		if(r->dat > d) est = exiUsu(d, i, r->izq);
		else if(r->dat < d) est = exiUsu(d, i, r->der);
		else return r->ld.exiID(i);
	}
	return est;
}

bool ArbAVL::exiUsu(string d){
	if(rai != NULL) return exiUsu(d, rai); 
	return false;
}
bool ArbAVL::exiUsu(string d, NodArbAVL* r){
	bool est = false;
	if(r != NULL){
		if(r->dat > d) est = exiUsu(d, r->izq);
		else if(r->dat < d) est = exiUsu(d, r->der);
		else return true;
	}
	return est;
}
LisDob ArbAVL::obtLisIma(string d){
	LisDob t;
	if(rai != NULL) return obtLisIma(d, rai); 
	return t;
}
LisDob ArbAVL::obtLisIma(string d, NodArbAVL* r){
	LisDob t;
	if(r != NULL){
		if(r->dat > d) t = obtLisIma(d, r->izq);
		else if(r->dat < d) t = obtLisIma(d, r->der);
		else return r->ld;
	}
	return t;
}

NodArbAVL* ArbAVL::sus(NodArbAVL* &r){
	NodArbAVL *t;
	if(alt(r->izq) - 1 != 0) t = sus(r->izq);
	else{
		t = r->izq;
		r->izq = NULL;
	}
	if(r != NULL) equ(r);
	return t;
}
void ArbAVL::equ(NodArbAVL* &r){
	r->alt = max(alt(r->der),alt(r->izq));
	r->val = alt(r->der)-alt(r->izq);
	
	if(r->val == 2){
		if(r->der->val == 1) r = rsi(r);
		else r = rdd(r);
		
	}else if(r->val == -2){
		if(r->izq->val == -1) r = rsd(r);
		else r = rdi(r);
	}
}
NodArbAVL* ArbAVL::rsd(NodArbAVL* &t1){
	NodArbAVL *t2 = t1->izq;
	t1->izq = t2->der;
	t2->der = t1;
	t1->alt = max(alt(t1->izq), alt(t1->der));
	t2->alt = max(alt(t2->izq), t1->alt);
	t1->val = alt(t1->der)-alt(t1->izq);
	t2->val = alt(t2->der)-alt(t2->izq);
	return t2;
}
NodArbAVL* ArbAVL::rsi(NodArbAVL* &t1){
	NodArbAVL *t2 = t1->der; 
	t1->der = t2->izq;
	t2->izq = t1;
	t1->alt = max(alt(t1->izq), alt(t1->der));
	t2->alt = max(alt(t2->der), t1->alt);
	t1->val = alt(t1->der)-alt(t1->izq);
	t2->val = alt(t2->der)-alt(t2->izq);
	return t2;
}
NodArbAVL* ArbAVL::rdd(NodArbAVL* &t1){
	t1->der = rsd(t1->der);
	return rsi(t1);
}
NodArbAVL* ArbAVL::rdi(NodArbAVL* &t1){
	t1->izq = rsi(t1->izq);
	return rsd(t1);
}
int ArbAVL::max(int a, int b){  
    if(a>b) return a;
	else return b;
}
int ArbAVL::alt(NodArbAVL* temp){
	if(temp != NULL) return temp->alt + 1;
	else return 0;
}

void ArbAVL::rio(){
	if(rai != NULL) rio(rai);
}
void ArbAVL::rio(NodArbAVL* t){
	if(t->izq != NULL) rio(t->izq);
	cout << t->dat << endl;
	if(t->der != NULL) rio(t->der);
}
void ArbAVL::rPre(){
	if(rai != NULL){
		rPre(rai);
	} 
}
void ArbAVL::rPre(NodArbAVL* t){
	cout << t->dat << endl;
	if(t->izq != NULL) rPre(t->izq);
	if(t->der != NULL) rPre(t->der);
}
void ArbAVL::rPos(){
	if(rai != NULL){
		rPos(rai);
	} 
}
void ArbAVL::rPos(NodArbAVL* t){
	if(t->izq != NULL) rPos(t->izq);
	if(t->der != NULL) rPos(t->der);
	cout << t->dat << endl;
}

void ArbAVL::gra(){
	/////// Creacion del Archivo dot
	ofstream file;
    file.open("C:/Users/edwin/Desktop/EDD/arbol.dot");

    file << "digraph G {" << endl;
    file << "graph [ordering=\"out\"];" << endl;
    
    if(rai != NULL) file << gra(rai);
    
    file << "}";

    file.close();
	
	/////// Generacion Grafico
	system("dot C://Users//edwin//Desktop//EDD//arbol.dot -o C://Users//edwin//Desktop//EDD//arbol.png -Tpng -Gcharset=utf8");
	system("C://Users//edwin//Desktop//EDD//arbol.png");
}
string ArbAVL::gra(NodArbAVL* temp){
	string t = "";
	
	if(temp == rai & temp->izq == NULL & temp->der == NULL) t += temp->dat + ";\n";
	
	t += temp->dat + "[label=\"D:"+ temp->dat +" - A:" + h.intStr(temp->alt) + " - V:" + h.intStr(temp->val) + "\"]; \n";
	
	if(temp->izq != NULL){
		t += temp->dat + "->" + temp->izq->dat + ";\n";
		t += gra(temp->izq);
	}
	
	if(temp->der != NULL | temp->izq != NULL) if(temp->izq == NULL) t += temp->dat + "->NULL" + temp->dat + "\n";
	
	if(temp->der != NULL){
		t += temp->dat + "->" + temp->der->dat + ";\n";
		t += gra(temp->der);
	} 
	
	if(temp->der != NULL | temp->izq != NULL) if(temp->der == NULL) t += temp->dat + "->NULL" + temp->dat + "\n";
	
	return t;
}

string ArbAVL::obtCod(){
	string cad = "";
	if(rai != NULL) cad += "node [ style=filled color=royalblue];\n" + obtCod(rai);
	return cad;
}
string ArbAVL::obtCod(NodArbAVL* r){
	string t = "";
	if(r != NULL){
		if(r->izq != NULL){
			t += r->dat + " -> " + r->izq->dat + "\n";
			t += obtCod(r->izq);
		}else if(r->der != NULL) t += r->dat + " -> NULL" + r->dat + "\n";
		if(r->der != NULL){
			t += r->dat + " -> " + r->der->dat + "\n";
			t += obtCod(r->der);
		}else if(r->izq != NULL) t += r->dat + " -> NULL" + r->dat + "\n";
	}
	
	return t;
}
string ArbAVL::obtCodI(){
	string cad = "";
	if(rai != NULL) cad += "node [ style=filled color=royalblue];\n" + obtCodI(rai);
	return cad;
}
string ArbAVL::obtCodI(NodArbAVL* r){
	string t = "";
	if(r != NULL){
		if(r->der != NULL){
			t += r->dat + " -> " + r->der->dat + "\n";
			t += obtCodI(r->der);
		}else if(r->izq != NULL) t += r->dat + " -> NULL" + r->dat + "\n";
		if(r->izq != NULL){
			t += r->dat + " -> " + r->izq->dat + "\n";
			t += obtCodI(r->izq);
		}else if(r->der != NULL) t += r->dat + " -> NULL" + r->dat + "\n";
	}
	return t;
}

/////////////////////////////////////////// Clase Nodo Arbol
////////////// CONSTRUCTOR
NodArbAVL::NodArbAVL(string d){
	izq = NULL;
	der = NULL;
	dat = d;
	alt = 0;
	val = 0;
}
NodArbAVL::NodArbAVL(string d, LisDob l){
	izq = NULL;
	der = NULL;
	dat = d;
	ld = l;
	alt = 0;
	val = 0;
}

////////////// METODOS

