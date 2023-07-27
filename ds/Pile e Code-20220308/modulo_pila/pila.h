/*******************************/
/* HEADER MODULO "pila" */
/*******************************/

struct elem {
       tipo_inf inf;
       elem* pun ;
};

typedef elem* pila;
	
pila push(pila, tipo_inf);
tipo_inf pop(pila&);
tipo_inf top(pila);
bool isEmpty(pila);
