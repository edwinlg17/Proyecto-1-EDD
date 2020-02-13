#ifndef LIS_H
#define LIS_H 

#include <iostream>
#include "MatDis.hpp"

using namespace std;

class NodLis;

/////////////////////////////////////////// Clase Lista
class Lis{
	private:
		
	public:
		////////////// ATRIBUTOS
		NodLis *pri, *ult, *ite;
		
		////////////// CONSTRUCTOR
		Lis();
		
		////////////// METODOS
		
		void agr(string);
		void agr(string, MatDis);
		bool finIte();
		string obtSig();
		MatDis obtSigMat();
		void reiIte();
		
		void imp();
};

/////////////////////////////////////////// Clase Nodo Lista
class NodLis{
	private:
		
	public:
		////////////// ATRIBUTOS
		NodLis *sig;
		string dat;
		MatDis md;
		
		////////////// CONSTRUCTOR
		NodLis(string);
		NodLis(string, MatDis);
		
		////////////// METODOS
};

#endif // LIS_H 

