#include <iostream>
#include <stdlib.h>
#include "grafo.h"
using namespace std;

graph new_graph(int n){
	graph G; // creo una struct graph
	G.dim = n;
    G.nodes = new struct adj_node* [n]; // [n] pointers of type struct adj_node.  	// struct adj_node ** K = new struct adj_node *;
	for (int i=0; i<n; i++) {
		G.nodes[i] = NULL;  //indicazione di lista vuota. 	// (*(G.nodes)+i)->next
	}
	return G;
}

/* Funzione che aggiunge l'arco orientato (u,v) alla lista di adiacenza del
 * nodo u (aggiunge in testa alla lista). L'arco ha peso w. */

void add_arc(graph& G, int u, int v, float w) {
  adj_node* t = new adj_node; //tmp variable
  t->node = v-1;
  t->weight = w;
  t->next = G.nodes[u-1]; // faccio punatre il nodo t al nodo puntato da G.nodes[u-1] in precedenza.
 
  G.nodes[u-1] = t; //faccio puntare G.nodes[u-1] al t
}


/* Funzione che aggiunge l'arco non orientato (u,v) alle liste
 * di adiacenza di u e v. L'arco ha peso w. */
void add_edge(graph& g, int u, int v, float w) {
  add_arc(g,u,v,w);
  add_arc(g,v,u,w);
}

int get_dim(graph g){
	return g.dim;
}

adj_list get_adjlist(graph g,int u){
	return g.nodes[u-1];
}

//returns "int node" or ID of struct adj_node
int get_adjnode(adj_node* l){
	return (l->node+1);
}

//returns "adj_node* next" of struct adj_node
adj_list get_nextadj(adj_list l){
	return l->next;
}
//returns weight of struct adj_node
float get_adjweight(adj_node* l){
	return (l->weight);
}