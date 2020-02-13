#ifndef ARBAVL_H
#define ARBAVL_H 

#include <iostream>
#include "Her.hpp"
#include "LisDob.hpp"

using namespace std;

class NodArbAVL;

/////////////////////////////////////////// Clase Arbol
class ArbAVL{
	private:
		////////////// ATRIBUTOS
		NodArbAVL *rai;		
		Her h;
		
		////////////// METODOS
		void agr(string, NodArbAVL* &);
		void agr(string, LisDob, NodArbAVL* &);
		void eli(string, NodArbAVL* &);
		bool exiUsu(string, int, NodArbAVL*);
		bool exiUsu(string, NodArbAVL*);
		LisDob obtLisIma(string, NodArbAVL*);
		
		NodArbAVL* sus(NodArbAVL* &);
		void equ(NodArbAVL* &);
		NodArbAVL* rsd(NodArbAVL* &);
		NodArbAVL* rsi(NodArbAVL* &);
		NodArbAVL* rdd(NodArbAVL* &);
		NodArbAVL* rdi(NodArbAVL* &);
		int max(int, int);  
		int alt(NodArbAVL*);
		
		void rio(NodArbAVL*);
		void rPre(NodArbAVL*);
		void rPos(NodArbAVL*);
		
		string gra(NodArbAVL*);
		string obtCod(NodArbAVL*);
		string obtCodI(NodArbAVL*);
		
	public:
		////////////// CONSTRUCTOR
		ArbAVL();
		
		////////////// METODOS
		void agr(string);
		void agr(string, LisDob);
		void eli(string);
		bool exiUsu(string, int);
		bool exiUsu(string);
		LisDob obtLisIma(string);
		
		void rio();
		void rPre();
		void rPos();
		
		void gra();
		string obtCod();
		string obtCodI();
		
};

/////////////////////////////////////////// Clase Nodo Arbol
class NodArbAVL{
	private:
		
	public:
		////////////// ATRIBUTOS
		NodArbAVL *izq, *der;
		int alt, val;
		string dat;
		LisDob ld;
		
		////////////// CONSTRUCTOR
		NodArbAVL(string);
		NodArbAVL(string, LisDob);
		////////////// METODOS
};

#endif // ARBAVL_H 

