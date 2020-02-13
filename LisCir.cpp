#include <iostream>
#include "LisCir.hpp"

using namespace std;

/////////////////////////////////////////// Clase Lista Circular
////////////// CONSTRUCTOR
LisCir::LisCir(){
	cab = NULL;
}

////////////// METODOS
void LisCir::agr(int d){
	if(d >= 0){
		NodLisCir *nue = new NodLisCir(d);
		
		if(cab != NULL){
			NodLisCir *temp = cab; 
			
			do{
				if(temp->sig->dat >= d || temp->sig == cab) break;
				temp = temp->sig;
			}while(true);
			
			if(temp->dat < d){
				NodLisCir *tsig = temp->sig;
				NodLisCir *tant = temp;
				
				nue->sig = tsig;
				nue->ant = tant;
				tsig->ant = nue;
				tant->sig = nue;
			}else if(temp->dat > d){
				NodLisCir *tant = cab->ant;
				
				nue->sig = cab;
				nue->ant = tant;
				cab->ant = nue;
				tant->sig = nue;
				
				cab = nue;
			}else{
				cout << "el valor ya existe" << endl;
			}
			
		}else{
			cab = nue;
			cab->sig = nue;
			cab->ant = nue;
		}
	}
}
void LisCir::agr(int d, LisDob l){
	if(d >= 0){
		NodLisCir *nue = new NodLisCir(d, l);
		
		if(cab != NULL){
			NodLisCir *temp = cab; 
			
			do{
				if(temp->sig->dat >= d || temp->sig == cab) break;
				temp = temp->sig;
			}while(true);
			
			if(temp->dat < d){
				NodLisCir *tsig = temp->sig;
				NodLisCir *tant = temp;
				
				nue->sig = tsig;
				nue->ant = tant;
				tsig->ant = nue;
				tant->sig = nue;
			}else if(temp->dat > d){
				NodLisCir *tant = cab->ant;
				
				nue->sig = cab;
				nue->ant = tant;
				cab->ant = nue;
				tant->sig = nue;
				
				cab = nue;
			}else{
				cout << "el valor ya existe" << endl;
			}
			
		}else{
			cab = nue;
			cab->sig = nue;
			cab->ant = nue;
		}
	}
}

string LisCir::obtCod(){
	string t = "", t2 = "node [shape=ellipse style=filled color=royalblue]; { rank=same", t3 = "";
	
	NodLisCir *temp = cab;
	if(temp != NULL){
		do{
			t += "img" + h.intStr(temp->dat);
			t2 += " img" + h.intStr(temp->dat);
			t3 += temp->ld.obtCod(h.intStr(temp->dat));
			temp = temp->sig;
			if(temp != cab) t += " -> ";
			else t += " -> img" + h.intStr(temp->dat) + ";\n";
		}while(temp != cab);
	}
	t2 += " } \n";
	
	temp = cab;
	if(temp != NULL){
		do{
			t += "img" + h.intStr(temp->dat);
			temp = temp->ant;
			if(temp != cab) t += " -> ";
			else t += " -> img" + h.intStr(temp->dat) + ";\n";
		}while(temp != cab);
	}
	
	return t2 + t + t3;
}
string LisCir::obtCod(int d){
	string t = "";
	
	NodLisCir *temp = cab;
	if(temp != NULL){
		do{
			if(d == temp->dat){
				t = temp->ld.obtCod();
				break;
			}
			temp = temp->sig;
		}while(temp != cab);
	}
	return t;
}
string LisCir::obtCodIma(int i){
	string t = "node [ style=filled ];\n";
	
	NodLisCir *nl = cab;
	if(nl != NULL){
		do{
			if(i == nl->dat){
				t += nl->ld.obtCodArb(h.intStr(nl->dat));
				break; 
			} 
			nl = nl->sig;
		}while(nl != cab);
	}
	return t;
}

void LisCir::imp(){
	NodLisCir *temp = cab;
	if(temp != NULL){
		do{
			cout << "Dato: " << temp->dat << " Nodos: " << temp->ant << " <- " << temp << " -> " << temp->sig << endl;
			temp = temp->sig;
		}while(temp != cab);
	}
}

/////////////////////////////////////////// Clase Nodo Lista Circular
////////////// CONSTRUCTOR
NodLisCir::NodLisCir(int d){
	sig = NULL;
	ant = NULL;
	dat = d;
}
NodLisCir::NodLisCir(int d, LisDob l){
	sig = NULL;
	ant = NULL;
	dat = d;
	ld = l;
}

////////////// METODOS




