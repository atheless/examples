#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "tipo.h"
#include "liste.h"
#include "grafo.h"

int caricaOLD(lista& pi){
	fstream file("PI.txt");
	if(!file) cout << "\nErrore nella lettura del file PI.txt" << endl;
	int count = 0;
	tipo_inf i;
	while(file >> i.id){
		count++;
		file >> ws;
		file.getline(i.nome, 21);
		file >> i.tipo;
		file >> ws;
		pi = ord_insert_elem(pi, new_elem(i));
	}
	return count;
}

//stampa di debug
void stampa(lista l){
	while(l != NULL) {
		cout << l->inf.id  << " | " << l->inf.nome  << " | " << l->inf.tipo  << endl;
		l = tail(l);
	}

}

int carica(lista& pi){
	fstream file("PI.txt");
	if(!file) cout << "\nErrore nella lettura del file PI.txt" << endl;
	elem* e = new elem;
	int count = 0;
	while(file >> e->inf.id){
		count++;
		file >> ws;
		file.getline(e->inf.nome, 21);
		file >> e->inf.tipo;
		file >> ws;
		pi = ord_insert_elem(pi, e);
		e = new elem;
	}
	file.close();
	return count;
}

tipo_inf search_pi(lista pi, int id){
	tipo_inf i;
	i.id = id;
	pi = ord_search(pi, i);
	if(pi == NULL) {
		i.id = -999;
		strcpy(i.nome, "NON TROVATO");
		i.tipo = 'X';
		return i;	
	}	
	copy(i, pi->inf);
	return i;
}



graph mappa(int n){
	fstream file("G.txt");
	if(!file) cout << "\nErrore nella lettura del file GI.txt" << endl;
	graph G = new_graph(n); 
	
	int v1,v2;
	 while (file >> v1 >> v2) {
            add_edge(G, v1, v2, 1.0);
        }
        
        file.close();
        return G;
}

void stampa_mappa(graph g, lista pi){
  for (int i = 1; i <= get_dim(g); i++){
    adj_node* tmp = get_adjlist(g, i);
    tipo_inf k = search_pi(pi, i);
    
    cout << k.nome << " connesso a: ";
    while (tmp){
      k = search_pi(pi, get_adjnode(tmp));
      cout << k.nome << ", ";
      tmp = get_nextadj(tmp);
    }
    cout << endl;
    cout << endl;
  }
}



void trip(graph g, int node, lista pi){
    adj_node* tmp = get_adjlist(g, node);
    tipo_inf s = search_pi(pi, node);
    tipo_inf d;
    while (tmp){
        d = search_pi(pi, get_adjnode(tmp));
				if(s.tipo == d.tipo){
					cout << d.id << " ";
				}      
       tmp = get_nextadj(tmp);
    }
    cout << endl;
    cout << endl;
}

int main(){
	lista pi = NULL;
	int numpi = carica(pi);
	//stampa(pi);
	char c = 'y';
	while(c == 'y' || c == 'Y'){
		int pif;
		cout << "Inserisci il numero di pi:";
		cin >> pif;
		print(search_pi(pi, pif)); cout << "\n";
		cout << "Vuoi cercare un altro pi? (y) yes: ";
		cin >> c;
	}
	
	cout << "\n \n \n";
	//Punto 2.a
	graph g = mappa(numpi);
	stampa_mappa(g, pi);
	
	//Punto 3.a
	cout << endl;
	cout << endl;
	
	trip(g, 1, pi);
	trip(g, 6, pi);
	
	return 0;
}
