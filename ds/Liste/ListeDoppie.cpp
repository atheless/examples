#include <iostream>
#include <cstring>

using namespace std;

struct elem {
    char inf[51];
    elem *pun;
    elem *prev;
};
typedef elem *lista;

/* --- Primitive --- */
char *head(lista p) { return p->inf; }
lista tail(lista p) { return p->pun; }
lista prev(lista p) { return p->prev; }

lista insert_elem(lista l, elem *e) {
    e->pun = l;
    if (l != NULL) l->prev = e;
    e->prev = NULL;
    return e;
}

// Inserimento alla fine. Contrario al lista insert_elem(lista l, elem *e)
lista insertAtEnd(lista testa, elem *node) {
  if (testa == NULL) {  // caso base
    testa = node;
    node->prev = testa;
    node->pun = NULL;
    return testa;
  }
  // caso non base
  elem *last = testa;
  while (last != NULL) {
    if (last->pun == NULL) {
      last->pun = node;
      node->prev = last;
      node->pun = NULL;
      return testa;
    }
    last = tail(last);
  }

  return testa;
}



lista delete_elem(lista l, elem *e) {
    if (l == e) l = e->pun; // e è la testa della lista
    else (e->prev)->pun = e->pun;// e non è la testa della lista

    if (e->pun != NULL) (e->pun)->prev = e->prev;
    delete e;
    return l;
}
//iterativa
elem *search(lista l, char *v) {
    while (l != NULL) {
        if (strcmp(head(l), v) == 0)
            return l;
        else
            l = tail(l);
    }
    return NULL;
}
//ricorsiva
elem *search2(lista l, char *v) {
    if (l == NULL) return NULL;
    if (strcmp(head(l), v) == 0) return l;
    return search2(tail(l), v);
}

/* --- Funzioni --- */
lista crealista(int n) {
    lista testa = NULL;
    for (int i = 1; i <= n; i++) {
        elem *p = new elem;
        cout << "URL " << i << ": ";
        cin >> p->inf;
        p->pun = p->prev = NULL;
        
        
        p->pun = testa;
        if (testa != NULL) testa->prev = p;
        p->prev = NULL;
        testa = p;
        //testa = insert_elem(testa, p);


        //testa = insertAtEnd(testa, p);
    }
    return testa;
}

void stampalista(lista p) {
    cout << "\n\n";
    while (p != NULL) {
        //cout << head(p) << " "; // stampa valore
        //cout << "(p: " << p << " succ:" << p->pun << " prev:" << p->prev << ")";
        cout << head(p) << " <--> ";
        p = tail(p); // spostamento sul prossimo elemento
    }
    cout << endl;
}

void stampalista2(lista p) {
    cout << head(p) << " "; // stampa valore
    cout << "(p: " << p << " succ:" << p->pun << " prev:" << p->prev << ")";
    if (tail(p) != NULL) stampalista2(tail(p));// spostamento sul prossimo elemento

}

lista cancella(lista l, char *v) {
    elem *e;
    while ((e = search(l, v)) != NULL) {
        cout << "Cancello un elemento con valore " << v << endl;
        l = delete_elem(l, e);
    }
    cout << "Fine cancellazione!!" << endl;
    return l;
}

void naviga(elem *e) {
    char scelta;
    cout << "Trovato!!";
    do {
        cout << "Cosa vuoi fare (B per backward,F per forward, S per stop)" << endl;
        cin >> scelta;
        if (scelta == 'F' && tail(e) != NULL) {
            cout << head(tail(e)) << endl;
            e = tail(e);
        } else if (scelta == 'B' && prev(e) != NULL) {
            cout << head(prev(e)) << endl;
            e = prev(e);
        } else cout << "Elemento non esistente!!" << endl;
    } while (scelta != 'S');
}

// Dato un elemento della lista, conta il numero di valori nella sequenza maggiori del valore dell'elemento in ingresso. L'algoritmo in un solo ciclo
int max(elem* e){
   int cont = 0;
   
   elem* left = e->prev;
   elem* right = e->pun;
   
   while (left != NULL || right != NULL){
   
    if(left != NULL) {
      if(left->inf > e->inf) { cont++; }
      left = left->prev;
    }
    
    if(right != NULL) {
      if(right->inf > e->inf) { cont++; }
      right = right->pun;
    }
    
    return cont;
   }

 return cont;
}



int main() {
    int n;
    char v[51];
    int scelta;
    lista testa = NULL;
    elem *ris;
    do {
        cout << "Cosa vuoi fare?" << endl;
        cout << "1: Creare una lista" << endl;
        cout << "2: Cancellare valori dalla lista" << endl;
        cout << "3: Stampare la lista" << endl;
        cout << "4: Cercare valori nella lista" << endl;
        cout << "5: Esci" << endl;
        cin >> scelta;
        switch (scelta) {
            case 1:
                cout << "Inserire il numero di elementi da inserire nella lista" << endl;
                cin >> n;
                testa = crealista(n);
                break;
            case 2:
                cout << "Inserire il valore da cancellare:" << endl;
                cin >> v;
                testa = cancella(testa, v);
                break;
            case 3:
                stampalista(testa);
                break;
            case 4:
                cout << "Valore da cercare" << endl;
                cin >> v;
                ris = search(testa, v);
                if (ris != NULL)
                    naviga(ris);
                else
                    cout << "Valore non presente" << endl;
                break;
            case 5:
                cout << "Ciao, ciao!!" << endl;
        }
    } while (scelta != 5);
    return 0;
}
