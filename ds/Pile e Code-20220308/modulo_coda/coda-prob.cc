

#include <iostream>

using namespace std ;


#include "tipo.h"
#include "coda.h"

static elem* new_elem(tipo_inf inf){
	    elem* p = new elem ;
	    copy(p->inf,inf);
	    p->pun=NULL;
		return p;

	}

/*******************************/
/* DEFINIZIONE MODULO "coda" */
/*******************************/

coda enqueue(coda c, tipo_inf i){
	/*** da completare **/
}

tipo_inf dequeue(coda& c){
	/** da completare **/
};

tipo_inf first(coda c){
	return (c.head)->inf;
};



bool isEmpty(coda c){
	if(c.head==NULL)
		return true;
	return false;
}

coda newQueue(){
	coda c={NULL, NULL};
	return c;
}


