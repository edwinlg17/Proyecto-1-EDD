#ifndef HER_H
#define HER_H 

#include <iostream>
#include <stdlib.h>
#include "Lis.hpp"

using namespace std;

/////////////////////////////////////////// Clase Analizador Lexico
class Her{
	private:
		
	public:
		////////////// ATRIBUTOS
		
		////////////// CONSTRUCTOR
		Her();
		~Her();
		////////////// METODOS
		// entrada/salida
		void creArc(string, string);
		string leeArc(string);
		
		// analisis
		Lis anaLex(string);
		
		// comprobacion
		bool esLet(char);
		bool esDig(char);
		bool esNum(string);
		bool exiRut(string);
		
		// Convercion
		string intStr(int);
		int strInt(string);
		
		// consola
		void limCon();
		void pauCon();
		
		// otros
};

#endif // HER_H 

