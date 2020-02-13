#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

#include "Her.hpp"
#include "Lis.hpp"

using namespace std;

/////////////////////////////////////////// Clase Herramientas
////////////// CONSTRUCTOR
Her::Her(){}
Her::~Her(){}

////////////// METODOS
// entrada/salida
void Her::creArc(string cad, string rut){
	ofstream file;
  	file.open(rut.c_str());
  	file << cad;
  	file.close();
}
string Her::leeArc(string rut){
	string cad = "", temp; 
	ifstream arc(rut.c_str());  
	string t;
	while (!arc.eof()) {
		t = "";
    	arc >> t;
    	cad += t;
  	}
  	arc.close();
  	return cad;
}
		
// analizador
Lis Her::anaLex(string cad){
	Lis ls;
	int i = 0, est = 0;
	string lex = "";
	char s;
	cad += "$";
	
	while(i < cad.size()){
		s = cad[i];
		switch(est){
			// estado inicial
			case 0:
				if(esLet(s)){
					lex += cad[i++];
					est = 1;
				} 
				else if(esDig(s)){
					lex += cad[i++];
					est = 2;
				} 
				else if(s == '#'){
					lex += cad[i++];
					est = 1;
				} 
				else if(s == '{' || s == '}' || s == ',' || s == ';'){
					lex += cad[i++];
					est = 3;
				} 
				else i++;
				break;
			case 1:
				if(esLet(s) || esDig(s) || s == '_'){
					lex += cad[i++];
				}else{
					ls.agr(lex);
					lex = "";
					est = 0;
				}
				break;
			case 2:
				if(esDig(s)){
					lex += cad[i++];
				}else{
					ls.agr(lex);
					lex = "";
					est = 0;
				}
				break;
			case 3:
				ls.agr(lex);
				lex = "";
				est = 0;
				break;
		}
	}
	return ls;
}

// comprobadores
bool Her::esLet(char s){
	int v = s;
	if((v >= 65 & v <= 90) || (v >= 97 & v <= 122)) return true;
	return false;
}
bool Her::esDig(char s){
	int v = s;
	if(v >= 48 & v <= 57) return true;
	return false;
}
bool Her::esNum(string cad){
	for(int i = 0; i < cad.size(); i++){
		if(!esDig(cad[i])) return false; 
	}
	return true;
}
bool Her::exiRut(string rut){
	
	bool est = false;
	ifstream arc(rut.c_str());
	if (arc.good()) est = true;
	arc.close();
	return est;
}

// convercion
string Her::intStr(int d){
	return static_cast<std::ostringstream*>(&(std::ostringstream() << d))->str();
}
int Her::strInt(string cad){
	int num = 0;
	int exp = 0;
	
	for(int i = cad.size() - 1; i >= 0; i--){
		int d = (int)cad[i] - 48;
		num += d * pow(10, exp++);
	}
	return num;
}

// consola
void Her::limCon(){
	system("cls");
}
void Her::pauCon(){
	system("pause>null");
}

// otros









