#include <iostream>
#include <string>
#include <sstream>
#include "MatDis.hpp"

using namespace std;

/////////////////////////////////////////// Clase MatDis
// CONSTRUCTOR
MatDis::MatDis(){
	fil = NULL;
	col = NULL;
} // constructor

// METODOS
MDNodInd* MatDis::enlInd(MDNodInd* &p, int i){
	MDNodInd *nNue = new MDNodInd(i);
	MDNodInd *ntemp;
	

	if(!vac()){
		ntemp = p;
	
		while(ntemp!=NULL && ntemp->sig != NULL){
			if(ntemp->sig->ind > i || ntemp->ind == i) break;
			ntemp = ntemp->sig;
		}
		
		if(ntemp->ind < i){
			MDNodInd *tAnt = ntemp;
			MDNodInd *tSig = ntemp->sig;
		
			tAnt->sig = nNue;
			
			if(tSig != NULL) tSig->ant = nNue;
				
			nNue->sig = tSig;
			nNue->ant = tAnt;
		}else if(ntemp->ind > i){
			p->ant = nNue;
			nNue->sig = p;
			p = nNue;
		}else return ntemp;
	}else p = nNue;
	
	return nNue;
} 
void MatDis::enlConFil(MDNodInd* &p, MDNodCon* &n, int i){
	MDNodCon *ntemp;
	
	if(p->con != NULL){
		ntemp = p->con;
		
		while(ntemp != NULL && ntemp->der != NULL){
			if(ntemp->der->indC > i || ntemp->indC == i) break;
			ntemp = ntemp->der;
		}
		
		if(ntemp->indC < i){
			MDNodCon *tAnt = ntemp;
			MDNodCon *tSig = ntemp->der;
		
			tAnt->der = n;
			
			if(tSig != NULL) tSig->izq = n;
				
			n->der = tSig;
			n->izq = tAnt;
		}else if(ntemp->indC > i){
			p->con->izq = n;
			p->con->fil = NULL;
			
			n->der = p->con;
			n->fil = p;
			
			p->con = n;
		}else ntemp->dat = n->dat;
	}else{
		p->con = n;
		n->fil = p;
	}
} // enlaza los nodos contenido
void MatDis::enlConCol(MDNodInd* &p, MDNodCon* &n, int i){
	MDNodCon *ntemp;
	
	if(p->con != NULL){
		ntemp = p->con;
		
		while(ntemp != NULL && ntemp->aba != NULL){
			if(ntemp->aba->indF > i || ntemp->indF == i) break;
			ntemp = ntemp->aba;
		}
		
		if(ntemp->indF < i){
			MDNodCon *tAnt = ntemp;
			MDNodCon *tSig = ntemp->aba;
		
			tAnt->aba = n;
			
			if(tSig != NULL) tSig->arr = n;
				
			n->aba = tSig;
			n->arr = tAnt;
		}else if(ntemp->indF > i){
			p->con->arr = n;
			p->con->col = NULL;
			
			n->aba = p->con;
			n->col = p;
			
			p->con = n;
		}else ntemp->dat = n->dat;
	}else{
		p->con = n;
		n->col = p;
	}
} // enlaza los nodos contenido columna

bool MatDis::vac(){
	if(fil==NULL | col==NULL) return true;
	else return false;
} // matriz vacia?
void MatDis::agr(int f, int c, string d){
	MDNodInd* nftemp = enlInd(fil, f);
	MDNodInd* nctemp = enlInd(col, c);
	
	MDNodCon *n = new MDNodCon(f, c, d);
	
	enlConFil(nftemp, n, c);
	enlConCol(nctemp, n, f);
} // agrega fila - columna
void MatDis::imp(){
	MDNodInd *ntemp = fil;
	if(!vac()){
		cout << "////////////////// MATRIZ " << endl;
		do{
			MDNodCon* t = ntemp->con;
			while(t != NULL){
				cout  << " F:" << t->indF << " C:" << t->indC <<  " D:" << t->dat << endl;
				t = t->der;
			}
			ntemp = ntemp->sig;
		}while(ntemp != NULL);
	}
	
	
	/*if(!vac()){
		cout << "////////////////// PUNTEROS MATRIZ " << dat << endl;
		MDNodInd *ntemp = fil;
		cout << "////////////////// Filas" << endl;
		do{
			cout << "fila:" << ntemp->ind << " Nodos " << ntemp->ant << " - " << ntemp << " - " << ntemp->sig << endl;
			
			MDNodCon* t = ntemp->con;
			cout << "///////////// enlaces filas" << endl;
			while(t != NULL){
				cout << "dato:" << t->dat << " Nodos " << t->izq << " - " << t << " - " << t->der << " Nodo Fila:" << t->fil << " Nodo Columna:" << t->col << endl;
				t = t->der;
			}
			cout << "//////////////////////////" << endl;
			ntemp = ntemp->sig;
		}while(ntemp != NULL);	
		
		ntemp = col;
		cout << "////////////////// Columnas" << endl;
		do{
			cout << ntemp->ind << " - " << ntemp->ant << " - " << ntemp << " - " << ntemp->sig << endl;
			
			MDNodCon* t = ntemp->con;
			cout << "///////////// enlaces columna" << endl;
			while(t != NULL){
				cout << "dato:" << t->dat << " Nodos " << t->arr << " - " << t << " - " << t->aba << " Nodo Fila:" << t->fil << " Nodo Columna:" << t->col << endl;
				t = t->aba;
			}
			cout << "//////////////////////////" << endl;
			
			ntemp = ntemp->sig;
		}while(ntemp != NULL);
	}
	*/
}

MatDis MatDis::matCom(MatDis m){
	MDNodInd *ntemp = fil;
	if(!vac()){
		do{
			MDNodCon* t = ntemp->con;
			while(t != NULL){
				//cout  << " F:" << t->indF << " C:" << t->indC <<  " D:" << t->dat << endl;
				m.agr(t->indF, t->indC, t->dat);
				t = t->der;
			}
			ntemp = ntemp->sig;
		}while(ntemp != NULL);
	}
	return m;
}
string MatDis::obtCod(){
	string cad = "";
	MDNodInd *ntemp = fil;
	if(!vac()){
		do{
			MDNodCon* t = ntemp->con;
			int ca = 0, ul = 0, ta = 0;
			ta = tamCol() + 1;
			
			cad += "<tr>\n"; 
			
			while(t != NULL){
				
				for(int i = ca; i < t->indC; i++){
					cad += "<td bgcolor = \"#FFFFFF\" width=\"25\" height=\"25\"> </td>\n";
					//cout << "x";
				}
				cad += "<td bgcolor = \"" + t->dat + "\" width=\"25\" height=\"25\"> </td>\n";
				//cout << "o";
				ca = t->indC + 1;
				t = t->der;
			}
			for(int i = ca; i < ta; i++){
				cad += "<td bgcolor = \"#FFFFFF\" width=\"25\" height=\"25\"> </td>\n";
				//cout << "x";
			}
			cad += "</tr>\n"; 
			//cout << endl;
			ntemp = ntemp->sig;
		}while(ntemp != NULL);
	}
	return cad;
}
int MatDis::tamCol(){
	int t = 0;
	MDNodInd *ntemp = col;
	if(!vac()){
		do{
			t = ntemp->ind;
			ntemp = ntemp->sig;
		}while(ntemp != NULL);
	}
	return t;
}
string MatDis::obtCodM(){
	string cod = "node [shape=box style=filled color=skyblue2];";
	
	if(!vac()){
		string con = "MatDis -> ", coni = "", ran = "{ rank=same MatDis ", atr = "MatDis[ label=\"MatDis\" color=royalblue group=F ];\n";
		string c = "", ci = "", cit = "", a = "";
        //recorro columnas 
        MDNodInd *nc = col;
		do{
			ran += "col" + intStr(nc->ind) + " ";
			atr += "col" + intStr(nc->ind) + "[ label=\"col: " + intStr(nc->ind) + "\" color=skyblue1 group=" + intStr(nc->ind) + " ];\n";
			con += "col" + intStr(nc->ind);
			coni = "col" + intStr(nc->ind) + coni;
						
            // recorro filas
			MDNodCon* nf = nc->con;
			c += "col" + intStr(nc->ind) + " -> ";
			cit = "";
			
			while(nf != NULL){
				a += "con" + intStr(nf->indF) + "_" + intStr(nf->indC) + "[ label=\"" + nf->dat + "\" color=grey group=" + intStr(nc->ind) + " ];\n";
				c += "con" + intStr(nf->indF) + "_" + intStr(nf->indC);
				cit = "con" + intStr(nf->indF) + "_" + intStr(nf->indC) + cit;
				
				nf = nf->aba;
				
				if(nf != NULL){
					c += " -> ";
					cit = " -> " + cit;
				}
			}
			c += ";\n";
			ci += cit + " -> col" + intStr(nc->ind) + ";\n";
			
			nc = nc->sig;
			if(nc != NULL){
				con += " -> ";
				coni = " -> " + coni;
			}
			
		}while(nc != NULL);
		ran += "}\n";
        con += ";\n";
        coni += " -> MatDis;\n";
        
        //cout << ran << atr << con << coni << a << c << ci;
        cod += ran + atr + con + coni + a + c + ci;
	}
	
	if(!vac()){
		string con = "MatDis -> ", coni = "", atr = "";
		string c = "", ci = "", cit = "", r = "";
		
		// recorro filas
		MDNodInd *nf = fil;

		do{
			atr += "fil" + intStr(nf->ind) + "[ label=\"fil: " + intStr(nf->ind) + "\" color=skyblue1 group=F ];\n";
			con += "fil" + intStr(nf->ind);	
			coni = "fil" + intStr(nf->ind) + coni;
			
			//recorro columnas 
			MDNodCon* nc = nf->con;
			r += "{ rank=same fil" + intStr(nf->ind) + " ";
			c += "fil" + intStr(nf->ind) + " -> ";
			cit = "";
			
			while(nc != NULL){
				r += "con" + intStr(nc->indF) + "_" + intStr(nc->indC) + " ";
				c += "con" + intStr(nc->indF) + "_" + intStr(nc->indC);
				cit = "con" + intStr(nc->indF) + "_" + intStr(nc->indC) + cit;
				
				nc = nc->der;
				if(nc != NULL){
					c += " -> "; 
					cit = " -> " + cit;
				}
			}
			r += "}\n";
			c += ";\n";
			ci += cit +" -> fil" + intStr(nf->ind) + ";\n";
			
			nf = nf->sig;
			if(nf != NULL){
				con += " -> ";
				coni = " -> " + coni;
			}
		}while(nf != NULL);
		con += ";\n";
		coni += " -> MatDis;\n";
		
		//cout << atr << con << coni << r << c << ci;
		cod += atr + con + coni + r + c + ci;
	}

	return cod;
}

string MatDis::intStr(int d){
	return static_cast<std::ostringstream*>(&(std::ostringstream() << d))->str();
}

/////////////////////////////////////////// Clase MDNodInd
// CONSTRUCTOR
MDNodInd::MDNodInd(int i){
	ind = i;
	
	sig = NULL;
	ant = NULL;
	con = NULL;
} // constructor

////////////// METODOS

/////////////////////////////////////////// Clase MDNodCon
// CONSTRUCTOR
MDNodCon::MDNodCon(int f, int c, string d){
	izq = NULL;
	der = NULL;
	arr = NULL;
	aba = NULL;
	fil= NULL;
	col=NULL;
	indF = f;
	indC = c;
	dat = d;
} // constructor

////////////// METODOS




