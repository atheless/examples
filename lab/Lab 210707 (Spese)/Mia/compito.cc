#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "grafi.h"
#include "conto.h"

/**
 * @brief aggiunge gli archi al grafo
 *          
 * @param graph G
 * @param int u
 * @param int v
 * @param flaot w
 * @param bool d
 */

void add(graph& g, int u, int v, float w, bool d) {
    if (d) add_arc(g, u, v, w); // orientato
    else add_edge(g, u, v, w); // non orientato
}

/**
 * @brief Carica grafo dal file soldi.txt
 *          
 * @param G
 * @param tipo_inf
 * 
 */

void carica(graph &G, tipo_inf*& ni){
   ifstream file("soldi.txt");  if(!file) cerr << "\nErrore nella lettura del file soldi.txt" << endl;
   int n_nodi = 0;
   int n_archi = 0; 
   file >> n_nodi;  file >> n_archi;

   G = new_graph(n_nodi); 
   ni = new tipo_inf[n_nodi];
   
   for(int i=0; i<G.dim; i++){
   		file >> ni[i].nome;
   		file >> ni[i].budget; 
   }
   
   int v1,v2;
   float w;
   while (file >> v1 >> v2 >> w){
      add(G, v1, v2, w, 1);  // add(G, v1, v2, w, d);
   }
    
   file.close();
}


/**
 * @brief Stampa
 *          
 * @param G
 * @param tipo_inf
 * 
 */

void stampa(graph G, tipo_inf* ni){
	  for (int i = 0; i< G.dim; i++){
        adj_node* tmp = get_adjlist(G, i+1);
        cout << "Persona " << ni[i].nome << " budget " << ni[i].budget << ", pagamenti: ";
        while (tmp){
          cout << ni[tmp->node].nome << " (" << tmp->weight << ") ";
          tmp = get_nextadj(tmp);
        }
        cout << endl;
  }
}



/**
 * @brief Crea l'arco da i a j con peso indcato come ultimo parametro, se l'arco non esiste, ed invece lo aggoirna se esiste
 *          
 * @param graph
 * @param char*
 * @param char*
 * @param int
 * 
 */


void update(graph G, char* i, char* j, int somma, tipo_inf* ni){
				int ipos = -1;
			  int jpos = -1;
			  adj_node* tmp = NULL;
				bool trovato = false;
				

				 for (int k = 0; k<G.dim; k++){
						if(strcmp(ni[k].nome, i) == 0) ipos = k;
   					if(strcmp(ni[k].nome, j) == 0) jpos = k;
				 }
	

				if(ipos == -1 && jpos == -1){
							cerr << "\nErrore i o j non esiste!" << endl;
				}
				
				tmp = G.nodes[ipos];
				while (tmp){
					 if( strcmp(ni[tmp->node].nome, j) == 0){
									tmp->weight += somma;
									trovato = true;
						}
						tmp = get_nextadj(tmp); //next node
				}
				
				if(trovato == false){
						add(G, ipos+1, jpos+1, somma, 1);  // add(G, v1, v2, w, d);
				}
					
}


int main(){
	graph G;
  tipo_inf* ni = NULL;
  
  carica(G, ni);
  
  stampa(G, ni);
  
  
  char i[100];
  char j[100];
  int somma = -1;
  cout << "Inserisci il nome i: "; cin >> i;
  cout << "Inserisci il nome j: "; cin >> j;
  cout << "Inserisci la somma: "; cin >> somma;
  cout << "\n";
  
  update(G, i, j, somma, ni);
  stampa(G, ni);
  
return 0;
}
