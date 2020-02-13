#ifndef MATDIS_H
#define MATDIS_H 

#include <iostream>
#include <string>

using namespace std;

class MDNodInd;
class MDNodCon;

/////////////////////////////////////////// Clase MatDis
class MatDis{
	private:
		MDNodInd* enlInd(MDNodInd*&, int); // enlaza los nodo indice
		void enlConFil(MDNodInd*&, MDNodCon*&, int); // enlaza los nodos contenido fila
		void enlConCol(MDNodInd*&, MDNodCon*&, int); // enlaza los nodos contenido columna
		
	public:
		MDNodInd *fil, *col;
		
		////////////// CONSTRUCTOR
		MatDis();
		
		////////////// METODOS
		bool vac(); // matriz vacia?
		void agr(int, int, string); // agrega fila - columna
		MatDis matCom(MatDis);
		string obtCod();
		int tamCol();
		void imp();
		string obtCodM();
		string intStr(int);
};

/////////////////////////////////////////// Clase MDNodInd
class MDNodInd{
	private:
		
	public:
		int ind;
		
		MDNodInd *sig, *ant;
		MDNodCon *con;
		
		////////////// CONSTRUCTOR
		MDNodInd(int); // constructor
		
		////////////// METODOS
};

/////////////////////////////////////////// Clase MDNodCon
class MDNodCon{
	private:
		
	public:
		int indF, indC;
		string dat;
		
		MDNodCon *izq, *der, *arr, *aba;
		MDNodInd *fil, *col;
		
		////////////// CONSTRUCTOR
		MDNodCon(int, int, string); // constructor
		
		////////////// METODOS
};

#endif // MATDIS_H 

