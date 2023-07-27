#include <iostream>

using namespace std;

struct elem {
  int inf;
  elem *pun;
};

typedef elem* lista;// alias: elem* <=> lista

int head(lista p) { return p->inf; }    // alias: info
lista tail(lista p) { return p->pun; }  // alias: next

// Inserimento in testa. Devi prima creare elem* e. Guarda lista crealista(int)
lista insert_elem(lista l, elem *e) {
  e->pun = l;
  return e;
}

// Inserimento alla fine. Contrario al lista insert_elem(lista l, elem *e)
lista insertAtEnd(lista testa, elem *node) {
  if (testa == NULL) {  // caso base
    testa = node;
    node->pun = NULL;
    return testa;
  }
  // caso non base
  elem *last = testa;
  while (last != NULL) {
    if (last->pun == NULL) {
      last->pun = node;
      node->pun = NULL;
      return testa;
    }
    last = tail(last);
  }
  
  return testa;
}

void somma_elemento(lista l, int pos, int sizeL){
 lista l1=l;
  while(l1 != NULL){
   if (pos == 0) break; //arrivato
    pos--;
    l1 = tail(l1);
  }

  while(l != NULL){
    cout << (l->inf + l1->inf) << " ";
    l = tail(l);
  }
  cout << endl;

}


lista find_last_elem(lista l){
 elem * tmp= NULL;
 
 while (l != NULL) {
    if(l->pun = NULL) tmp = l; 
    l = tail(l);
  }

  return tmp;
}


bool palindroma(lista l){
 elem* last = find_last_elem(l);

 while(l != NULL && last != NULL){

  //last = l.prev;
   l = tail(l);
 }
return true;
}


//iterativa
void stampalista(lista p) {
  while (p != NULL) {
    cout << head(p) << " ";
    p = tail(p);
  }
  cout << endl;
}

//ricorsiva
void r_stampalista(lista p) {
  if (p == NULL) return;
  cout << head(p) << " ";
  r_stampalista(tail(p));
  cout << endl;
}

//Ritorna indirizzio dell'elem con inf pari a v
elem *search(lista l, int v) {
  while (l != NULL){
    if (head(l) == v) return l;
    else l = tail(l);
  }
  return NULL;
}

// Cancella dalla lista il elem *e. Attenzione funzione assume che il elem *e esiste all'interno della lista!
// In caso contrario comportamento e' indefinito!
lista delete_elem(lista l, elem *e) {
  if (l == e) l = tail(l);
  else {
    lista l1 = l;
    while (tail(l1) != e) {
      l1 = tail(l1);
    }

    l1->pun = tail(e);
  }
  delete e;
  return l;
}

void eliminalista(lista &testa) {
  while (testa != NULL) testa = delete_elem(testa, testa);
}

int conta(lista l, int v) {
  int occorenza = 0;
  while ((l = search(l, v)) != NULL){
    l = tail(l);
    occorenza++;
  }
  return occorenza;
}

// ristituisce la lista priva di elementi v. Soluzione non efficiente perche scorre la lista due volte. Riscrivere la funzione affinche scorra una sola volta uttili. head() e tail()
//iteratvia
lista cancella(lista l, int v) {
  elem *e;
  while ((e = search(l, v)) != NULL) {
    l = delete_elem(l, e);
  }
  return l;
}


// crea una coppia di lista, identica che passo
lista copy(lista l1) {
  lista l = NULL;
  elem *curr;
  elem *prev = NULL;
  while (l1 != NULL) {
    curr = new elem;
    curr->inf = head(l1);
    curr->pun = NULL;

    if (prev == NULL) l = curr;
    else prev->pun = curr;
    
    prev = curr;
    l1 = tail(l1);
  }
  return l;
}



lista crealista(int n) {
  lista testa = NULL;
  for (int i = 1; i <= n; i++) {
    elem *p = new struct elem;
    cout << "Valore elemento " << i << ": ";
    cin >> p->inf;

    p->pun = testa;
    testa = p; 
    //testa = insert_elem(testa, p);

    //testa = insertAtEnd(testa, p);
  }
  return testa;
}


//La funzione restituisce la lista inversa che passo.
// Lista1 -> 1 -> 2 -> 3 -> 4
// Lista2 -> 4 -> 3 -> 2 -> 1

lista invert_lista(lista testa, int sizeTesta){
  lista t1 = NULL;

  while (testa != NULL) {
     elem *p = new elem;
     p->inf = testa->inf;
     
     p->pun = t1;     
     t1 = p;  
     //OR  t1 = insert_elem(t1, p);
    
    testa = tail(testa);
  }
  cout << endl;

  return t1;
}




int main() {
  int n;
  cout << "Inserire il numero di elementi da inserire nella lista: " << endl;
  cin >> n; //Size of Lista
  lista testa = crealista(n);
  
  cout << "\n\n--- stampalista(testa);" << endl;
  stampalista(testa);
  
  //cout << "\n\n--- somma_elemento(testa, 2);" << endl;
  //somma_elemento(testa, 2, n);
  

  lista t1 = invert_lista(testa, n);
  stampalista(t1);
  
  return 0;
}
