#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

#include "grafo.h"
#include "node.h" //viene dato

void leggi_riga(istream &is, char *riga){
    // consuma eventuali sequenze di newline, per evitare errori nella lettura di una riga che si sta per effettuare
    while (is.peek() == '\n') is.get();
    
    is.get(riga, 81) ; // legge una riga
    is.get() ; // consuma il newline che segue la riga appena letta
}

void add(graph& g, int u, int v, float w, bool d) {
    if (d) add_arc(g, u, v, w); // orientato
    else add_edge(g, u, v, w); // non orientato
}

graph gbuild(bool d, bool w) {
   ifstream file("graph"); // ifstream, ofstream, fstream
   if(!file) cout << "\nErrore nella lettura del file graph" << endl;
   int n; file >> n;
   graph G = new_graph(n); 
   
   int v1,v2;
    if (w) { 
        float w;
        while (file >> v1 >> v2 >> w){
            add(G, v1, v2, w, d); 
        }
    }else { 
        while (file >> v1 >> v2) {
            add(G, v1, v2, 1.0, d); 
        }
    }
    
    file.close();
    return G;
}



node* gnode(graph g){
    ifstream file("node");
    node* nd = new node[g.dim];
   
   
   // leggi_riga(file, nd[i].cont); ~= file.getline(nd[i].cont, 81, '\n'); 
   
    for(int i=0; i<g.dim; i++){
			file >> ws; // Senza questa riga, non funziona. Devo consumare il whitespace perche' quando file.getline vede davanti il whitespace lui emette fail().
			file.getline(nd[i].cont, 81, '\n'); //Consumo il contenuto e consumo il '\n' che segue.
			file >> nd[i].tipo; //Consumo il tipo e lascio (NON consumo) il whitespace che segue. 

    }

/* Alternativa al for di sopra.
	char tmp[2];  // 'CHAR' + '\0'
	for(int i=0; i<g.dim; i++){
	   file.getline(nd[i].cont, 81, '\n');
	   file.getline(tmp, 2);
	   nd[i].tipo = tmp[0];
	}
*/
	file.close();
	return nd;
}

/*
--------
U (tipo)  Nickname (cont)
--------
T (tipo)  Testo (>80 caratteri) (cont)
--------
U -> U  relazione follow  (U1 follow U2)
T -> U  relazione ownership (T owner U)
U -> T  relazione like (U like T)
*/

void stampa(graph g, node * nd) {
  for (int i = 0; i < g.dim; i++) {
			adj_node* l = get_adjlist(g, i + 1);
				while (l != NULL) {
				    int j = get_adjnode(l);
						if (nd[i].tipo == 'U') { // i e' il nodo ID di partenza
									cout << nd[i].cont;
									if (nd[j - 1].tipo == 'U') cout << " FOLLOW " << nd[j - 1].cont;
									else cout << " LIKE " << nd[j - 1].cont;
						} else {
							  cout << nd[i].cont;
								if (nd[j - 1].tipo == 'U') cout << " OWNER " << nd[j - 1].cont;
						}
						
				  cout << "\n";
					l = get_nextadj(l);
				}
				  //fine for
				  cout << "\n";
  }

}

int main() {
    graph g = gbuild(1, 0); //punto 1
    node* nd = gnode(g); // punto 2
    stampa(g, nd);
    
    return 0;
}
