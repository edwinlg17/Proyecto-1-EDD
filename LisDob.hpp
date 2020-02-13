#ifndef LISDOB_H
#define LISDOB_H 

#include "Arb.hpp"
#include "Her.hpp"

class NodLisDob;

/////////////////////////////////////////// Clase Lista Doble
class LisDob{
	private:
		NodLisDob *pri, *ult;
		Her h;
		
	public:
		////////////// CONSTRUCTOR
		LisDob();
		
		////////////// METODOS
		void agr(int);
		void agr(int, NodArb*);
		bool exiID(int);
		string obtCod();
		string obtCod(string);
		string obtCodArb(string);
		void imp();
};

/////////////////////////////////////////// Clase Nodo Lista Loble
class NodLisDob{
		private:
			
		public:
			NodLisDob *sig, *ant;
			int dat;
			NodArb *cap;
			
			////////////// CONSTRUCTOR
			NodLisDob(int);
			NodLisDob(int, NodArb*);
			
			////////////// METODOS
			
};

#endif // LISDOB_H 

