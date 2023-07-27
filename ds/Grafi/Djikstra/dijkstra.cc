#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "grafo.h"
#include "codap.h"
#include <float.h>


void add(graph &g, int u, int v, float w, bool d) {
	if (d)
		add_arc(g, u, v, w);
	else
		add_edge(g, u, v, w);
}

graph g_build(ifstream &g, bool d, bool w) {
	int n;
	g >> n;
	graph G = new_graph(n);
	int v1, v2;
	if (w) {
		float w;
		while (g >> v1 >> v2 >> w) {
			add(G, v1, v2, w, d);
		}
	} else {
		while (g >> v1 >> v2) {
			add(G, v1, v2, 1.0, d);
		}
	}
	return G;
}




float *dest; //GLOBAL
int *parent; //GLOBAL




bool CheckIfNodoRaggiunto(int n){
	if(parent[n] != NULL) {
		cout << "NODO" << n << "e' raggiungibe" << endl;
		return true;
	}
	else return false;
}

void StampaCammino(int* parent, int x){
	if (x != NULL){
		StampaCammino(parent, parent[x-1]); //s -> x
		cout << x << " ";
	}
}


/*
void inizialize(graph G, int s) {
	for (int i = 0; i < G.dim; i++) {
		dest[i] = FLT_MAX;
		parent[i] = NULL;
	}
	dest[s-1] = 0;
}

void relax(int u, int v, int w) {
	if (dest[v] > dest[u] + w) {
		dest[v] = dest[u] + w;
		parent[v] = u + 1;
	}
}

void Dijkstra(graph G, int s){
	dest = new float[G.dim]; // distanza dal s ad un vertice u.  		Uso: dest[u]
    parent = new int[G.dim]; // padre del nodo u. 						Uso: parent[u]

	cout << "[Dijkstra] Nodo di partenza: " << s << endl;

	inizialize(G, s);
	codap queue = NULL;
	for (int i = 0; i < G.dim; i++) {
		queue = enqueue(queue, i, dest[i]);
	}

	while (!isEmpty(queue)) {
		int u = dequeue(queue);
		adj_node* vicini = get_adjlist(G, u + 1);
		while (vicini != NULL) {
			int v = get_adjnode(vicini);
			float w_u_v = get_adjweight(vicini);
			relax(u, v-1, w_u_v);
			queue = Decrease_Priority(queue, v - 1, dest[v - 1]);
			vicini = get_nextadj(vicini);
		}
	}

	cout << "Nodo\t Peso \t Padre" << endl;
	for (int i = 0; i < G.dim; i++) {
		cout << i + 1 << " \t " << dest[i] << " \t " << parent[i] << endl;
	}

	StampaCammino(parent, 7);
}


*/

//Stampa soli nodi adj di u
void stampaNodiAdj(graph G, int u){
    adj_node* tmp = get_adjlist(G, u);
    cout << u;
    while (tmp){
      cout << " --> " << get_adjnode(tmp);
      tmp = get_nextadj(tmp);
    }
    cout << endl;
}

void Lrelax(float* dest, int* parent, int u, int v, int w) {
	if (dest[v] > dest[u] + w) {
		dest[v] = dest[u] + w;
		parent[v] = u + 1;
	}
}

void LDijkstra(graph G, int s){
	float * dest  = new float[G.dim]; // distanza dal s ad un vertice u.  		Uso: dest[u]
    int * parent = new int[G.dim]; // padre del nodo u. 						Uso: parent[u]
    cout << "[Dijkstra] Nodo di partenza: " << s << endl;

	for (int i = 0; i < G.dim; i++) {
		dest[i] = FLT_MAX;
		parent[i] = NULL;
	}
	dest[s-1] = 0;


	codap queue = NULL;
	for (int i = 0; i < G.dim; i++) {
		queue = enqueue(queue, i, dest[i]);
	}

	while (!isEmpty(queue)) {
		int u = dequeue(queue);
		adj_node* vicini = get_adjlist(G, u + 1);
		while (vicini != NULL) {
			int v = get_adjnode(vicini);
			float w_u_v = get_adjweight(vicini);
			Lrelax(dest, parent, u, v-1, w_u_v);
			queue = Decrease_Priority(queue, v - 1, dest[v - 1]);
			vicini = get_nextadj(vicini); // il prossimo vicino
		}
	}

	cout << "Nodo\t Peso \t Padre" << endl;
	for (int i = 0; i < G.dim; i++) {
		cout << i + 1 << " \t " << dest[i] << " \t " << parent[i] << endl;
	}

	StampaCammino(parent, 7);
}







int main(int argc, char *argv[]) {
	/* Se il numero di parametri con cui e' stato chiamato il client e'
	 inferiore a tre - si ricordi che il primo parametro c'e' sempre, ed e' il
	 nome del file eseguibile - si ricorda all'utente che deve inserire
	 anche il nome del file che descrive il grafo e il flag  weighted*/

	if (argc < 3) {
		cout << "Usage: " << argv[0] << " filename directed weighted\n";
		exit(0);
	};

	ifstream g;
	g.open(argv[1]);
	cout << argv[1] << " " << argv[2] << " " << argv[2] << endl;
	int directed = atoi(argv[2]);
	int weighted = atoi(argv[3]);

	/* Chiamata a g_build che costruisce un grafo*/
    graph G = g_build(g, directed, weighted);

	cout << get_dim(G) << endl;

	//Stampa dell'array di liste
  	for (int i = 1; i <= get_dim(G); i++){
		stampaNodiAdj(G, i);
    }
	
	
	cout << endl;
    cout << endl;
	// Dijkstra
	LDijkstra(G, 2);

}
