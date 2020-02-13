#ifndef LISCIR_H
#define LISCIR_H 

#include "LisDob.hpp"
#include "Her.hpp"

class NodLisCir;

/////////////////////////////////////////// Clase Lista Circular
class LisCir{
	private:
	public:
		NodLisCir *cab;
		Her h;
		
		////////////// CONSTRUCTOR
		LisCir();
		
		////////////// METODOS 
		void agr(int);
		void agr(int, LisDob);
		string obtCod();
		string obtCod(int);
		string obtCodIma(int);
		
		void imp();
};

/////////////////////////////////////////// Clase Nodo Lista Circular
class NodLisCir{
	private:
	public:
		////////////// ATRIBUTOS
		NodLisCir *sig, *ant;
		int dat;
		LisDob ld;
		
		////////////// CONSTRUCTOR
		NodLisCir(int);
		NodLisCir(int, LisDob);
		
		////////////// METODOS 
};

#endif // LISCIR_H 

