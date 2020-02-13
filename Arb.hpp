#ifndef ARB_H
#define ARB_H

#include "MatDis.hpp"
#include "Lis.hpp"
#include "Her.hpp"

using namespace std;

class NodArb;

/////////////////////////////////////////// Clase Arbol
class Arb{
	private:
		////////////// ATRIBUTOS
		NodArb *rai;
		Lis lm;
		Her h;
		
		////////////// METODOS
		void agr(int, NodArb*);
		void agr(int, MatDis, NodArb*);
		string obtCod(NodArb*);
		string obtCodI(NodArb*);
		NodArb* obt(int, NodArb*);
		
		void rio(NodArb*);
		void rPre(NodArb*);
		void rPos(NodArb*);
		
	public:
		////////////// CONSTRUCTOR
		Arb();

		////////////// METODOS
		void agr(int);
		void agr(int, MatDis);
		string obtCod();
		string obtCodI();
		string obtCodM(int);
		NodArb* obt(int);
		
		void rio();
		void rPre();
		void rPos();
		Lis obtLisMat();
};
/////////////////////////////////////////// Clase Nodo Arbol
class NodArb{
	private:

	public:
		////////////// ATRIBUTOS
		NodArb *izq, *der;
		int dat;
		MatDis md;
		////////////// CONSTRUCTOR
		NodArb(int);
		NodArb(int, MatDis);
		////////////// METODOS
};

#endif // ARB_H

