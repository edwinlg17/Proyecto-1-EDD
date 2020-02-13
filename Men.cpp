#include <iostream>
#include <string>

#include "Men.hpp" 
#include "MatDis.hpp"
#include "LisDob.hpp"

void Men::ini(){
	menPri();
}
void Men::menPri(){
	int op = -1;
	
	while(op != 5){
		h.limCon();
		cout << "//////////////////// MENU ////////////////////" << endl;
		cout << " >> 1. Usurios. " << endl;
		cout << " >> 2. Imagenes. " << endl;
		cout << " >> 3. Reportes. " << endl;
		cout << " >> 4. Carga de Archivos. " << endl;
		cout << " << 5. Salir. " << endl;
		cout << endl <<" Escriba el numero de su opcion:" << endl;
		cout << endl << " #: ";
		
		string ent;
		cin >> ent;
		
		if(h.esNum(ent))  op = h.strInt(ent);
		else op = -1;
		
		switch(op){
			case 1:
				menUsu(); // menu usuarios
				break;
			case 2:
				break;
			case 3:
				menGra(); // menu graficos
				break;
			case 4:
				menCar(); // menu carga
				break;
		}
	}
}

void Men::menCar(){
	int op = -1;
	while(op != 4){ 
		h.limCon();
		cout << "//////////////////// CARGA DE ARCHIVOS ////////////////////" << endl;
		cout << " >> 1. Capas. " << endl;
		cout << " >> 2. Imagenes. " << endl;
		cout << " >> 3. Usuarios. " << endl;
		cout << " << 4. Regresar. " << endl;
		cout << endl <<" Escriba el numero de su opcion:" << endl;
		cout << endl << " #. ";
					
		string ent;
		cin >> ent;
					
		if(h.esNum(ent))  op = h.strInt(ent);
		else op = -1;
					
		switch(op){
			case 1:
				carCap(); 
				break;
			case 2:
				carIma();
				break;
			case 3:
				carUsu();
				break;
		}				
	}
}
void Men::carCap(){
	h.limCon();
	cout << "//////////////////// CARGA DE CAPAS ////////////////////" << endl;
	cout << endl <<" Escriba la Ruta del Archivo: " << endl;
	cout << endl << " #. ";
	string rut;
	cin >> rut;
	
	if(h.exiRut(rut)){
		string tex = h.leeArc(rut);
		Lis ls = h.anaLex(tex);
		
		ls.reiIte();
		string s, id, f, c, v;
		int i = 0;
		
		MatDis m;
		while(!ls.finIte()){
			s = ls.obtSig();
			
			if(s == "," || s == "{") continue;
			if(s == "}") {
				//m.imp();
				if(h.esNum(id)) a.agr(h.strInt(id), m);
				i = 0;
				continue;
			}
			if(s == ";") {
				i = 1;
				continue;
			}
			
			if(i == 0) {
				id = s;
				if(h.esNum(id)){
					MatDis t;
					m = t;
				} 
				i++;
			}else if(i == 1){
				f = s;
				i++;
			}else if(i == 2){
				c = s;
				i++;
			}else if(i == 3){
				v = s;
				i++;
			}
			if(i == 4 && h.esNum(f) && h.esNum(c)) m.agr(h.strInt(f), h.strInt(c), v);
		}	
		cout << endl <<" Archivo Cargado Exitosamente... " << endl;
	}else{
		cout << endl <<" Ruta Invalida... " << endl;
	}
	
	//a.rio();
	
	h.pauCon();
}
void Men::carIma(){
	h.limCon();
	cout << "//////////////////// CARGA DE IMAGENES ////////////////////" << endl;
	cout << endl <<" Escriba la Ruta del Archivo: " << endl;
	cout << endl << " #. ";
	string rut;
	cin >> rut;
	
	if(h.exiRut(rut)){
		string tex = h.leeArc(rut); // leo el archivo
		Lis ls = h.anaLex(tex);
		
		string s, id;
		int i = 0;
		LisDob ld;
		
		ls.reiIte();
		while(!ls.finIte()){
			s = ls.obtSig();
			if(s == "," || s == "{") continue;
			else if(s == "}") {
				if(h.esNum(id)) {
					//cout << endl << "////////////////// LISTA DOBLE " << id << endl;
					//ld.imp();
					lc.agr(h.strInt(id), ld);
				}
				i = 0;
				continue;
			}
			if(i == 0) {
				id = s;
				LisDob t;
				ld = t;
				i++;
			}
			else if(i == 1 && h.esNum(s)){
				NodArb *nt = a.obt(h.strInt(s)); 
				if(nt != NULL) ld.agr(h.strInt(s), nt);
			} 
		}	
		cout << endl <<" Archivo Cargado Exitosamente... " << endl;
	}else{
		cout << endl <<" Ruta Invalida... " << endl;
	}
	
	//cout << endl <<"////////////////// LISTA CIRCULAR " << endl;
	//lc.imp();
	
	
	h.pauCon();
	
}
void Men::carUsu(){
	h.limCon();
	cout << "//////////////////// CARGA DE USUARIOS ////////////////////" << endl;
	cout << endl <<" Escriba la Ruta del Archivo: " << endl;
	cout << endl << " #. ";
	string rut;
	cin >> rut;
	
	if(h.exiRut(rut)){
		string tex = h.leeArc(rut);
		Lis ls = h.anaLex(tex);
		
		ls.reiIte();
		string s, id;
		int i = 0;
		
		LisDob ld;
		while(!ls.finIte()){
			s = ls.obtSig();
			
			if(s == ":" || s == ",") continue;
			if(s == ";") {
				//cout << endl << "////////////////// LISTA DOBLE " << id << endl;
				//ld.imp();
				avl.agr(id, ld);
				i = 0;
				continue;
			}
			
			if(i == 0) {
				id = s;
				LisDob t;
				ld = t;
				i++;
			}else if(i == 1 && h.esNum(s)) ld.agr(h.strInt(s));
		}	
		cout << endl <<" Archivo Cargado Exitosamente... " << endl;
	}else{
		cout << endl <<" Ruta Invalida... " << endl;
	}
	
	//avl.rio();
	//avl.gra();
	
	h.pauCon();
}

void Men::menGra(){
	int op = -1;
	
	while(op != 14){
		h.limCon();
		cout << "//////////////////// MENU GRAFICAS ////////////////////" << endl;
		cout << " >> 1. Por Recorrido Limitado. " << endl;
		cout << " >> 2. Lista de imagen. " << endl;
		cout << " >> 3. Por Capa. " << endl;
		cout << " >> 4. Por Usuario. " << endl;
		cout << " >> 5. Lista Circular Imagenes. " << endl;
		cout << " >> 6. Arbol de Capas. " << endl;
		cout << " >> 7. Arbol de Capas Espejo. " << endl;
		cout << " >> 8. Ver Capa. " << endl;
		cout << " >> 9. Ver Imagen y Arbol de Capa. " << endl;
		cout << " >> 10. Graficar Arbol de Usuarios. " << endl;
		cout << " >> 11. Graficar Arbol de Usuarios Espejo. " << endl;
		cout << " >> 12. Listar Recorridos Arbol Capas. " << endl;
		cout << " >> 13. Listar Recorridos Arbol Usuario. " << endl;
		cout << " << 14. Regresar. " << endl;
		cout << endl <<" Escriba el numero de su opcion:" << endl;
		cout << endl << " #: ";
		
		string ent;
		cin >> ent;
		
		if(h.esNum(ent))  op = h.strInt(ent);
		else op = -1;
		
		switch(op){
			case 1:
				graRecPas();
				break;
			case 2:
				graLisIma();
				break;
			case 3:
				graPorCap();
				break;
			case 4:
				graPorUsu();
				break;
			case 5:
				graLisCir();
				break; 
			case 6:
				graArbCap();
				break;
			case 7:
				graArbCapI();
				break;
			case 8:
				graCap();
				break;
			case 9:
				graImaCap();
				break;
			case 10:
				graArbUsu();
				break;
			case 11:
				graArbUsuEsp();
				break;
			case 12:
				lisRecArbCap();
				break;
			case 13:
				lisRecArbUsu();
				break;
		}
	}
}
void Men::graRecPas(){
	h.limCon();
	
	string cad, ord;
	cout << "//////////////////// IMAGEN POR RECORRIDO LIMITADO ////////////////////" << endl;
	cout << endl <<" Ingrese el nuemro de capas a utilizar:" << endl;
	cout << endl << " #. ";
	
	cin >> cad;
	int c = 0;
	
	cout << endl <<" Escriba el orden a utilizar:" << endl;
	cout << " >> preorden >> inorden >> postorden" << endl;
	cout << endl << " #. ";
	
	cin >> ord; 
	
	if(h.esNum(cad)){
		 c = h.strInt(cad);
		 if(ord == "preorden"){
		 	a.rPre();
		 	Lis l = a.obtLisMat();
		 	genIma(h.strInt(cad), l);
		 }else if(ord == "inorden"){
		 	a.rio();
		 	Lis l = a.obtLisMat();
		 	genIma(h.strInt(cad), l);
		 }else if(ord == "postorden"){
		 	a.rPos();
		 	Lis l = a.obtLisMat();
		 	genIma(h.strInt(cad), l);
		 }else cout << endl <<" Orden Invalido." << endl;
	}else cout << endl <<" Numero Invalido." << endl;
	
	h.pauCon();
}
void Men::genIma(int c, Lis l){
	MatDis m;
	
	l.reiIte();
	while(!l.finIte() && c--){
		MatDis t = l.obtSigMat();
		m = t.matCom(m);
	}
	
	string cad = "digraph matrix {\n";
	cad +="HtmlTable [\n"; 
	cad +="shape = plaintext \n"; 
	cad +="label=< \n"; 
	cad +="<table  border=\"0\" cellspacing=\"0\" cellpadding=\"0\" > \n";
	cad += m.obtCod();
	cad +="</table> \n"; 
	cad +=">]; \n"; 
	cad +="} \n"; 
	
	h.creArc(cad, "C://Users//edwin//Desktop//cod.dot");
	
	system("dot C://Users//edwin//Desktop//cod.dot -o C://Users//edwin//Desktop//img.png -Tpng -Gcharset=utf8");
	system("C://Users//edwin//Desktop//img.png");
	
}
void Men::graLisIma(){
	h.limCon();
	
	string cad;
	cout << "//////////////////// LISTA DE IMAGEN ////////////////////" << endl;
	cout << endl <<" Ingrese el nuemro de imagen a utilizar:" << endl;
	cout << endl << " #. ";
	
	cin >> cad;
	
	if(h.esNum(cad)) {
		genIma(lc.obtCod(h.strInt(cad)));
	}
	h.pauCon();
}
void Men::genIma(string cod){
	string cad = "digraph matrix {\n";
	cad +="HtmlTable [\n"; 
	cad +="shape = plaintext \n"; 
	cad +="label=< \n"; 
	cad +="<table  border=\"0\" cellspacing=\"0\" cellpadding=\"0\" > \n"; //
	cad += cod;
	cad +="</table> \n"; 
	cad +=">]; \n"; 
	cad +="} \n"; 
	
	h.creArc(cad, "C://Users//edwin//Desktop//cod.dot");
	
	system("dot C://Users//edwin//Desktop//cod.dot -o C://Users//edwin//Desktop//img.png -Tpng -Gcharset=utf8");
	system("C://Users//edwin//Desktop//img.png");
}
void Men::graPorCap(){
	h.limCon();
	
	string cad;
	cout << "//////////////////// POR CAPA ////////////////////" << endl;
	cout << endl <<" Ingrese el ID de la Capa:" << endl;
	cout << endl << " #. ";
	
	cin >> cad;
	int id = 0;
	
	if(h.esNum(cad)) {
		NodArb *na = a.obt(h.strInt(cad));
		string cod = na->md.obtCod();
		genIma(cod);
	}
	h.pauCon();
}
void Men::graPorUsu(){
	h.limCon();
	
	string usu, ima;
	cout << "//////////////////// POR USUARIO ////////////////////" << endl;
	cout << endl <<" Ingrese el nombre del usuario" << endl;
	cout << endl << " #. ";
	
	cin >> usu;
	
	cout << endl <<" Ingrese el ID de la imagen" << endl;
	cout << endl << " #. ";
	
	cin >> ima;
	
	if(h.esNum(ima)) {
		if(avl.exiUsu(usu, h.strInt(ima))){
			genIma(lc.obtCod(h.strInt(ima)));
		}else cout << endl <<" ID o Imagen Invalido." << endl;
	}else cout << endl <<" ID o Imagen Invalido." << endl;
	
	h.pauCon();
}

void Men::menUsu(){
	int op = -1;
	while(op != 4){ 
		h.limCon();
		cout << "//////////////////// USUARIOS ////////////////////" << endl;
		cout << " >> 1. Agregar. " << endl;
		cout << " >> 2. Editar. " << endl;
		cout << " >> 3. Eliminar. " << endl;
		cout << " << 4. Regresar. " << endl;
		cout << endl <<" Escriba el numero de su opcion:" << endl;
		cout << endl << " #. ";
					
		string ent;
		cin >> ent;
					
		if(h.esNum(ent))  op = h.strInt(ent);
		else op = -1;
					
		switch(op){
			case 1:
				agrUsu();
				break;
			case 2:
				ediUsu();
				break;
			case 3:
				eliUsu();
				break;
		}				
	}
}
void Men::agrUsu(){
	string usu;
	cout << "//////////////////// CREAR USUARIO ////////////////////" << endl;
	cout << endl <<" Ingrese el nombre del nuevo usuario" << endl;
	cout << endl << " #. ";
	
	cin >> usu;
	
	if(!avl.exiUsu(usu)){
		avl.agr(usu);
		cout << endl <<" Usuario Agregado." << endl;
	}else cout << endl <<" Usurio Existente." << endl;
	h.pauCon();
}
void Men::ediUsu(){
	string usu, nUsu;
	cout << "//////////////////// EDITAR USUARIO ////////////////////" << endl;
	cout << endl <<" Ingrese el nombre del usuario" << endl;
	cout << endl << " #. ";
	
	cin >> usu;
	
	cout << endl <<" Ingrese el nuevo nombre del usuario" << endl;
	cout << endl << " #. ";
	cin >> nUsu;
	
	if(avl.exiUsu(usu)){
		LisDob t = avl.obtLisIma(usu);
		avl.eli(usu);
		avl.agr(nUsu, t);
		cout << endl <<" Usuario Actualizado." << endl;
	} else cout << endl <<" Usurio Invalido." << endl;
	h.pauCon();
}
void Men::eliUsu(){
	string usu;
	cout << "//////////////////// ELIMINAR USUARIO ////////////////////" << endl;
	cout << endl <<" Ingrese el nombre del usuario" << endl;
	cout << endl << " #. ";
	
	cin >> usu;
	if(avl.exiUsu(usu)){
		 avl.eli(usu);
		 cout << endl <<" Usurio Eliminado." << endl;
	} else cout << endl <<" Usurio Invalido." << endl;
	h.pauCon();
}

void Men::genGra(string cod, string nom, string rut){
	string cad = "digraph G { \n" + cod + "} \n";
	
	h.creArc(cad, rut + nom + ".dot");
	
	string dot = "dot " + rut + nom + ".dot -o " + rut + nom + ".png -Tpng -Gcharset=utf8";
	string abr = rut + nom + ".png";
	system(dot.c_str());
	system(abr.c_str());
}
void Men::graLisCir(){
	genGra(lc.obtCod(), "img", "C://Users//edwin//Desktop//");
	h.pauCon();
}
void Men::graArbCap(){
	genGra(a.obtCod(), "img", "C://Users//edwin//Desktop//");
	h.pauCon();
}
void Men::graArbCapI(){
	genGra(a.obtCodI(), "img", "C://Users//edwin//Desktop//");
	h.pauCon();
}
void Men::graCap(){
	string num;
	cout << "//////////////////// VER CAPA ////////////////////" << endl;
	cout << endl <<" Ingrese el nuemro de la capa a graficar" << endl;
	cout << endl << " #. ";
	
	cin >> num;
	
	if(h.esNum(num)) genGra(a.obtCodM(h.strInt(num)), "img", "C://Users//edwin//Desktop//");
	else cout << endl <<" Numero Invalido." << endl;
	h.pauCon();
}
void Men::graImaCap(){
	string num;
	cout << "//////////////////// Ver Imagen y Arbol de Capas ////////////////////" << endl;
	cout << endl <<" Ingrese el nuemro de la imagen a graficar" << endl;
	cout << endl << " #. ";
	
	cin >> num;
	
	if(h.esNum(num)){
		string t = "newrank=true\n" + lc.obtCodIma(h.strInt(num)) + "subgraph cluster_1 {\n" + a.obtCod() + "}\n";
		genGra(t, "img", "C://Users//edwin//Desktop//");
	}
	
	else cout << endl <<" Numero Invalido." << endl;
	h.pauCon();
}
void Men::graArbUsu(){
	genGra(avl.obtCod(), "img", "C://Users//edwin//Desktop//");
	h.pauCon();
}
void Men::graArbUsuEsp(){
	genGra(avl.obtCodI(), "img", "C://Users//edwin//Desktop//");
	h.pauCon();
}
void Men::lisRecArbCap(){
	cout << "//////////////////// RECORRIDOS ARBOL CAPAS ////////////////////" << endl;
	cout << endl <<" PREORDEN" << endl;
	a.rPre();
	cout << endl <<" INORDEN" << endl;
	a.rio();
	cout << endl <<" POSTORDEN" << endl;
	a.rPos();
	h.pauCon();
}
void Men::lisRecArbUsu(){
	cout << "//////////////////// RECORRIDOS ARBOL USUARIOS ////////////////////" << endl;
	cout << endl <<" PREORDEN" << endl;
	avl.rPre();
	cout << endl <<" INORDEN" << endl;
	avl.rio();
	cout << endl <<" POSTORDEN" << endl;
	avl.rPos();
	h.pauCon();
}



