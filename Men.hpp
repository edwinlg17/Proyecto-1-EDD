#ifndef MEN_H
#define MEN_H 

#include <iostream>
#include "Her.hpp"
#include "Arb.hpp"
#include "LisCir.hpp"
#include "ArbAVL.hpp"

/////////////////////////////////////////// Clase Nodo Lista
class Men{
	private:
		////////////// ATRIBUTOS
		Her h;
		Arb a;
		LisCir lc;
		ArbAVL avl;
		
		////////////// METODOS
		void menPri();
		
		void menCar();
		void carCap();
		void carIma();
		void carUsu();
		
		void menGra();
		void graRecPas();
		void genIma(int, Lis);
		void graLisIma();
		void genIma(string);
		void graPorCap();
		void graPorUsu();
		
		void menUsu();
		void agrUsu();
		void ediUsu();
		void eliUsu();
		
		void genGra(string, string, string);
		void graLisCir();
		void graArbCap();
		void graArbCapI();
		void graCap();
		void graImaCap();
		void graArbUsu();
		void graArbUsuEsp();
		void lisRecArbCap();
		void lisRecArbUsu();
		
	public:
		////////////// ATRIBUTOS
		
		////////////// CONSTRUCTOR
		
		////////////// METODOS
		void ini();
};

#endif // MEN_H 

