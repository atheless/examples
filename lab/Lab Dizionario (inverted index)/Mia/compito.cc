#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "tipo.h"
#include "liste.h"
#include "parola.h"

void stampa(parola* p, int dim) {
  for(int i=0; i<dim; i++){
  cout << p[i].p  << endl;  
  lista tmp = p[i].l;
  cout << p[i].n_doc << " documenti" << endl;
    while (tmp != NULL) {
				cout << tmp->inf << " ";
        tmp = tail(tmp); 
    }
    cout << endl;
    cout << endl;
    }
    
    
}

void update(parola* &II, char* fileName, int& dim){
	ifstream file(fileName);
	if(!file) cout << "Errore nella lettura doc" << endl;
	int idDoc = 0;
	file >> idDoc;

	
	char* newWord = new char[80];
	while(file >> newWord){

		bool found = false;
		for(int i=0; i<dim; i++){
		  if ( strcmp( II[i].p , newWord) == 0 ){
		  	elem* e = new elem; 
		  	e->inf = idDoc;
		    e->pun = e->prev = NULL;
		  	
		  	II[i].l = ord_insert_elem(II[i].l, e);
		  	II[i].n_doc++;
		    found = true;
		  }
		}
		
		if(found == false){
		
				struct parola* IIold = II; 
				dim++;
			  II = new parola[dim]; // parola* II = new parola[dim]; <-- Problem: THIS WILL OVERSHADOW II. Why? Because you use parola* II in a diferent SCOPE!!!
				
				for (int i = 0; i<dim-1; i++){ // copy
		       strcpy(II[i].p, IIold[i].p);
		       II[i].n_doc = IIold[i].n_doc;
		       II[i].l = IIold[i].l; 
		  	}

		  	   strcpy(II[dim-1].p, newWord);
		       II[dim-1].n_doc = 1;
		       elem* e = new elem; 
					 e->inf = idDoc;
				   e->pun = e->prev = NULL;
		       II[dim-1].l = ord_insert_elem(II[dim-1].l, e);
		  	   delete [] IIold;
    		 
		}
		

}

		file.close();
}

/*
//In questa versione elimino nuovo array allocato
bool resize_array(struct sondaggio &s){
    struct persona* pTemp = s.pPersona;
    s.dim_array++;
    s.pPersona = new struct persona[s.dim_array];

    for (int i = 0; i<s.num_persone; i++){
        strncpy(s.pPersona[i].nome, pTemp[i].nome, max_nome);
        strncpy(s.pPersona[i].giorni, pTemp[i].giorni, max_giorni);
    }
    delete [] pTemp;
    return 0;
}
*/

parola* load(){
 ifstream file("inverted");
 if(!file) cout << "Errore nella lettura del file: inverted" << endl;
 int n = 0;
 file >> n;
 parola* p = new parola[n];
 
 for(int i=0; i<n; i++){
  file >> p[i].p;
  file >> p[i].n_doc;
  p[i].l = NULL;
  for(int j=0; j<p[i].n_doc; j++){
  	elem* e = new elem;
  	file >> e->inf; e->pun = e->prev = NULL;
  	p[i].l = ord_insert_elem(p[i].l, e);
  }
 } 
 
 file.close();
 return p;
}


int main(){
 ifstream file("inverted");
 if(!file) cout << "Errore nella lettura del file: inverted" << endl;
 int n = 0;
 file >> n;
 file.close();
 
 //Punto 1
 parola* p = load();
 stampa(p, n);

 //Punto 2
  cout << "\n\n Dopo: " << endl;
  cout << endl;
  cout << endl;
  
  update(p, "doc", n);
  stampa(p, n);
 
return 0;

}
