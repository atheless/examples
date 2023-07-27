#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "grafo.h"
#include "coda-bfs.h"

// arco e' quando diretto o l'arco orientato
// edge e' quando indiretto o l'arco non orientato
// (u,v) u - nodo partenza  v - nodo di destinazione
void add(graph& g, int u, int v, float w, bool d) {
    if (d) add_arc(g, u, v, w); // orientato
    else add_edge(g, u, v, w); // non orientato
}

graph g_build(ifstream &g, bool d, bool w) {
  int n;
  g >> n; //numero di nodi. La prima riga del filename
  graph G = new_graph(n); //crea grafo vuoto
  int v1,v2;

  if (w) { //grafo pesato
    float w;
    while (g >> v1 >> v2 >> w){
      add(G, v1, v2, w, d); // directed - 1 non directed 0
    }
  } else { //grafo non e' pesato
    while (g >> v1 >> v2) {
      add(G, v1, v2, 1.0, d); // directed - 1 non directed 0
    }
  }
  return G;
}

//Consideriamo grafi non orientati. Usa l'algoritmo BFS per verificare se il grafo è connesso
//Si assuma che i grafi acquisiti da file siano sempre non orientati.
bool connected(graph g, int s){
  bool *raggiunto = new bool[get_dim(g)];

  int i;
  for (int i = 0; i < get_dim(g); i++)
    raggiunto[i] = false;

  codaBFS C = newQueue();
  raggiunto[s - 1] = true;

  C = enqueue(C, s);
  while (!isEmpty(C)){
    int w = dequeue(C);

    for (adj_node *n = get_adjlist(g, w); n != NULL; n = n->next ){ // n = get_nextadj(n)
      i = get_adjnode(n); //node ID

      if (!raggiunto[i - 1]){ // is i visited? If not then mark visited and add to the queue.
        raggiunto[i - 1] = true;
        C = enqueue(C, i);
      }
    
    }

  }
  //check if grafo connesso
  for (int i = 0; i < get_dim(g); i++){
    if (!raggiunto[i]) return false; // grafo non connesso
  }

  return true; // grafo connesso
}


void simpleBFS(graph g, int s){
  bool* raggiunto = new bool[get_dim(g)];

  for (int i = 0; i < get_dim(g); i++){
    raggiunto[i] = false;
  }

  codaBFS C = newQueue();
  raggiunto[s-1] = true;
  C = enqueue(C, s);
  

  while (!isEmpty(C)){
    int w = dequeue(C);
    for (adj_node *n = get_adjlist(g, w); n != NULL; n = n->next ){ // n = get_nextadj(n)
     int u = get_adjnode(n); //u has node ID of potential non visited new node.
      
      if (!raggiunto[u-1]){ // is i visited? If not then mark visited and add to the queue.
        cout << "new node " << u << " is visited" << endl; //analisi nodo u.
        raggiunto[u-1] = true;
        C = enqueue(C, u);
      }
    
    }

  }

}

// Versione avanzata del SimpleBFS che puo' evitare i nodi e ha mantiene il vettore di distanza e parent.
int* BFSEvitaDist(graph g, int s){
  bool* raggiunto = new bool[get_dim(g)];
  int * dest  = new int[g.dim]; // distanza dal s ad un vertice u.
  int * parent = new int[g.dim]; // padre del nodo u.

  for (int i = 0; i < get_dim(g); i++){
    raggiunto[i] = false;
    parent[i] = 0;
    dest[i] = 9999; 
  }
  dest[s-1] = 0; // distanza nodo partenza = 0

  codaBFS C = newQueue();
  raggiunto[s-1] = true;
  C = enqueue(C, s);
  

  while (!isEmpty(C)){
    int w = dequeue(C);
    for (adj_node *n = get_adjlist(g, w); n != NULL; n = n->next ){ // n = get_nextadj(n)
     int u = get_adjnode(n); //u has node ID of potential non visited new node.
      
      if(u == 7) continue; //EVITA IL NODO 7

      if (!raggiunto[u-1]){ // is i visited? If not then mark visited and add to the queue.
        cout << "new node " << u << " is visited" << endl; //analisi nodo u.
        raggiunto[u-1] = true;
        
        dest[u-1] = dest[w-1] + 1;
        parent[u-1] = w;

        C = enqueue(C, u);
      }
    
    }

  }

  for (int i = 0; i < get_dim(g); i++){
    cout << "Nodo \t Distanza" << endl;
    cout << i+1 << "\t " << dest[i] << endl; 
  }

  cout << "\n\n";
    for (int i = 0; i < get_dim(g); i++){
    cout << "Nodo \t Parent" << endl;
    cout << i+1 << "\t " << parent[i] << endl; 
  }

  return dest;
}


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


int main(int argc, char *argv[]){
  /* Se il numero di parametri con cui e' stato chiamato il client e'
    inferiore a tre - si ricordi che il primo parametro c'e' sempre, ed e' il
    nome del file eseguibile - si ricorda all'utente che deve inserire
    anche il nome del file che descrive il grafo e il flag  weighted*/

  if (argc < 3){
    cout << "Usage: " << argv[0] << " filename directed weighted\n";
    exit(0);
  };

  ifstream g;
  g.open(argv[1]); //prendo in input filename
  cout << argv[1] << " " << argv[2] << " " << argv[2] << endl;
  int directed = atoi(argv[2]); // directed - 1 non directed 0
  int weighted = atoi(argv[3]);
  //https://www.cplusplus.com/reference/cstdlib/strtol/



  /*Chiamata a g_build che costruisce un grafo*/
  graph G = g_build(g, directed, weighted);
  cout << get_dim(G) << endl;


 // typedef adj_node* adj_list; //adj_list <=> adj_node*
 // Stampa dell'array di liste
 // adj_list tmp;
 
  for (int i = 1; i <= get_dim(G); i++){
        adj_node* tmp = get_adjlist(G, i);
        cout << i;
        while (tmp){
          cout << " --> " << get_adjnode(tmp);
          tmp = get_nextadj(tmp);
        }
        cout << endl;

        //inside is same as stampaNodiAdj(G,i);
  }


  cout << "\n\n";
  
  for (int i = 1; i <= get_dim(G); i++){
        adj_node* tmp = get_adjlist(G, i);
        cout << i;
        while (tmp){
          cout << " --> " << get_adjnode(tmp) << " (" << get_adjweight(tmp) << ") "; // OR cout << " --> " << tmp->node << " (" << tmp->weight << ") ";
          tmp = get_nextadj(tmp);
        }
        cout << endl;

        //inside is same as stampaNodiAdj(G,i);
  }



  cout << "-------------------" << endl;
  stampaNodiAdj(G,2);
  cout << "-------------------" << endl;
  //simpleBFS(G, 3);
  
  cout << "\n\n";
  BFSEvitaDist(G,1);

  //if (connected(G, 6)) cout << "Grafo connesso!!" << endl;
  //else cout << "Grafo non connesso!!" << endl;


}
