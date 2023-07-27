#include <iostream>
using namespace std;
#include "tipo.h"
#include "tree.h"

// node* puntatore -> [inf][parent][firstChild][nextSubling]

// Crea un nuovo nodo con valore informativo i
node* new_node(tipo_inf i){
	node *n = new node;
	copy(n->inf, i);
	n->nextSibling = n->firstChild = n->parent = NULL;
	return n;
}
// Aggiorna p: [parent] inserendo, il sottoalbero nuovo radicato in c, come primo figlio di p: [parent]
// ALGORITMO: 1. Aggiorno c->nextSibling 2. Aggiorno c->parent 3. Aggiorno p->firstChild
void insert_child(tree p, tree c){
	c->nextSibling = p->firstChild;
	c->parent = p;
	p->firstChild = c;
}
// Aggiorna di n: [nextSubling] inserendo, il sottoalbero nuovo radicato in t, come fratello successivo di n: [nextSubling]
// Inserimento in testa 2. Aggiorno t->parent
//ALGORITMO: 1. Aggiorno t->nextSibling 3. Aggiorno n->nextSibling
void insert_sibling(node *n, tree t){
	t->nextSibling = n->nextSibling;
	t->parent = n->parent;
	n->nextSibling = t;
}

tipo_inf get_info(node *n) {
	return n->inf;
}

node *get_parent(node *n) {
	return n->parent;
}

node *get_firstChild(node *n) {
	return n->firstChild;
}

node *get_nextSibling(node *n){
	return n->nextSibling;
}

//Perché il primo parametro di insert_child e insert_sibling non viene passato per riferimento?
// R: Perché dobbiamo modificato il contenuto a cui il puntatore punta, cioe' questo puntatore -> [inf][parent][firstChild][nextSubling]
//Quando è necessario il passaggio per riferimento in questi casi?
// R: Quando dobbiamo modificare il valore del puntatore