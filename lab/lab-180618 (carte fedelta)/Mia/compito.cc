#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
#include "carta.h"
#include "bst.h"



/**
 * Funzione per calcolare il totale punti.
 * Controlla se il nodo è null, dopo controlla se la key del nodo è valida per il controllo.
 * Infine controlla se è necessario richiamare la funzione su destra e sinistra (se la key corrente è uguale o maggiore/inferiore di uno
 * degli estremi allora procedendo in quella direzione troveremo solo altre chiavi che non coincidono con il criterio)
 *
 */
int totalepunti(bst t, int inf, int sup){
	int tot = 0;
	if(t != NULL){
		if(get_key(t) >= inf && get_key(t) <= sup) tot += get_value(t).totalep;
		if(get_key(t) > inf) tot += totalepunti(get_left(t), inf, sup);
		if(get_key(t) < sup) tot += totalepunti(get_right(t), inf, sup);
	}
	return tot;
}


int main(){

	bst btree = NULL; // MAIN POINTER

	int num_c;
	cout << "Quante carte vuoi inserire?" << endl;
	cin >> num_c;
	
	tipo_inf k;
	int key = 0;	
	for(int i=0; i<num_c; i++){
		cout << "Inserisci il codice della carta: " << endl;
		cin >> key; // int 'CODICE' + '\n'
		
		cout << "Inserisci il nome e cognome: " << endl;
		cin >> ws; // Cancello '\n' prima di fare cin.getline().
		cin.getline(k.nc, 50, '\n');
		
		cout << "Inserisci il # totale punti: " << endl;
		cin >> k.totalep;
		bst_insert(btree, bst_newNode(key, k));	
		
	}
	cout << "\n";
	
	//Punto 2
	cout << "# Carta \t Nome Cognome \t # Punti" << endl;
	stampa(btree);
	cout << "\n";
	
	//Punto 2.b:
	cout << "Inserisci il inf per # carte: ";
	int inf; cin >> inf;
	cout << "Inserisci il sup per # carte: ";
	int sup; cin >> sup;
	cout << "totalePunti: " << totalepunti(btree, inf, sup) << endl;




// cin >> ws; Senza questo cin.getline() non funziona. ws Extracts as many whitespace characters as possible from the current position in the input sequence.
return 0;
}
