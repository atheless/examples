

#include <iostream>

using namespace std ;


#include "tipo.h"
#include "codap.h"

static elem* new_elem(tipo_inf inf, int w){
	    elem* p = new elem ;
	    copy(p->inf,inf);
	    p->w=w;
	    p->pun=NULL;
		return p;

	}

static codap tail(codap p){return p->pun;}

/*******************************/
/* DEFINIZIONE MODULO "codap" */
/*******************************/



codap enqueue(codap c, tipo_inf i, int w){
	elem *e=new_elem(i,w);
	if(c==NULL || e->w<c->w){
		e->pun=c;
		return e;
	}
	else{
		codap c1=c;
		while (tail(c1)!=NULL && tail(c1)->w<e->w)
			 c1=tail(c1);
		e->pun = c1->pun;
		c1->pun = e;
		return c;}
}

tipo_inf dequeue(codap& c){
	tipo_inf ris;
	copy(ris,c->inf);
	elem* app=c;
	c=c->pun;
	delete app;
	return ris;
};

tipo_inf minQueue(codap c){
	return c->inf;
};



bool isEmpty(codap c){
	if(c==NULL)
		return true;
	return false;
}

codap decreaseKey(codap c, tipo_inf i,int w){
	codap capp=c;
	if(compare(c->inf,i)==0){
			c->w-=w;
			return c;
	}
	while(tail(capp)!=NULL){
			if(compare(tail(capp)->inf,i)==0){
				tail(capp)->w-=w;
				if(capp->w>tail(capp)->w){
					elem* ele=tail(capp);
					capp->pun=tail(capp)->pun;
					c=enqueue(c,ele->inf,ele->w);
					delete ele;
					return c;
				}
				}
			capp=tail(capp);
			}

	return c;


}

