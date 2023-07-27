

#include <iostream>

using namespace std ;


#include "tipo.h"
#include "pila.h"



/*******************************/
/* DEFINIZIONE MODULO "pila" */
/*******************************/
static elem* new_elem(tipo_inf inf){
	    elem* p = new elem ;
	    copy(p->inf,inf);
	    p->pun=NULL;
		return p;
	}

pila push(pila p, tipo_inf i){
	elem *e = new_elem(i);
	e->pun=p;
	return e;
}

tipo_inf pop(pila& p){
	tipo_inf ris;
	copy(ris,p->inf);
	elem* app=p;
	p=p->pun;	
	delete app;
	return ris;
};

tipo_inf top(pila p){
	return p->inf;
};

bool isEmpty(pila p){
	if(p==NULL) return true;
	return false;
}



