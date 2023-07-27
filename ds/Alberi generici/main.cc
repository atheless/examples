#include <iostream>
using namespace std;

//ordine di #include e' importante
#include "tipo.h"
#include "tree.h"
#include "coda-bfs.h"
#include <cmath>

// puntatore -> [inf][parent][firstChild][nextSubling]
//ricorsiva
void serialize(tree t){
	cout << "(";
	print(get_info(t));
	tree t1 = get_firstChild(t);
	while (t1 != NULL){
		serialize(t1);
		t1 = get_nextSibling(t1);
	}
	cout << ")";
}


int alt(tree T){
 if(T == NULL) return -1;
 else return (1 + max( alt(T->firstChild), alt(T->nextSibling) )  );
}



// node* puntatore -> [inf][parent][firstChild][nextSubling]
int altezza(tree t){
	if (get_firstChild(t) == NULL) return 0;
	int max = 0, max_loc;
	tree t1 = get_firstChild(t);
	while (t1 != NULL){
		max_loc = altezza(t1);
		if (max_loc > max)
			max = max_loc;
		t1 = get_nextSibling(t1);
	}
	return max + 1;
}

//La dimensione di un albero corrisponde al numero di nodi contenuti nell’albero.
//La funzione deve calcolare la dimensione implementando la visita BFS iterattiva
int dimensioneBFS(tree t){
	int count = 0;
	codaBFS c = newQueue();
	c = enqueue(c, t);
	while (!isEmpty(c)){
		node *n = dequeue(c);
		count++;
		tree t1 = get_firstChild(n);
		while (t1 != NULL){
			c = enqueue(c, t1);
			t1 = get_nextSibling(t1);
		}
	}
return count;
}

//La funzione deve calcolare la dimensione usando visita DFS ricorsiva
int dimensioneDFS(tree t){
	int dim=0,dim1;
	tree t1 = get_firstChild(t);
	while(t1!=NULL){
		dim1 = dimensioneDFS(t1); //chiamata ricursiva!
		dim = dim + dim1;
		t1 = get_nextSibling(t1);
	}
	return dim+1;
}

//Visita DFS ricorsiva in preorder
void DFS(tree T){
    if (T == NULL) return;
	cout << get_info(T) << endl;
    T = get_firstChild(T);
	while(T != NULL){
		DFS(T);
		T = get_nextSibling(T);
	}
}
//ricorsiva presa dai esercizi di tuttorato
void DFS2Easy(tree T){
	if(T != NULL){
	cout << get_info(T) << endl;
	DFS2Easy(get_firstChild(T));
	DFS2Easy(get_nextSibling(T));
	}
}


//ricorsiva presa dai esercizi di tuttorato
int DFS2ContaFoglie(tree T){
 int ris = 0;
 if(T != NULL){
	 if(get_firstChild(T) == NULL) ris++;
	 ris += DFS2ContaFoglie(get_firstChild(T));
	 ris += DFS2ContaFoglie(get_nextSibling(T));
	}
 return ris;
}


// Esercizio 1 -- Soluzione (DFS vista a lezione)
unsigned int count_leaves(tree root){
	int ret = 0;

	if(root != NULL)
	{	// Se il nodo non è nullo e non ha figli è una foglia
		if(get_firstChild(root) == NULL){
			ret = 1;
		}
		else{ // Altrimenti si continua a cercare tra i figli
			node* child = get_firstChild(root);
			while(child != NULL)
			{
				ret += count_leaves(child);
				child = get_nextSibling(child);
			}
		}
	}
	return ret;
}

// Esercizio 2.1 -- Soluzione (DFS vista a lezione)
node* search_node(tree root, tipo_inf inf){
	node* ret = NULL;

	if(root != NULL){
		if(compare(get_info(root), inf) == 0)
			ret = root;
		else{
			node* child = get_firstChild(root);

			while(child != NULL && ret == NULL)
			{
				ret = search_node(child, inf);
				child = get_nextSibling(child);
			}
		}
	}
	return ret;
}



// https://www.geeksforgeeks.org/creating-tree-left-child-right-sibling-representation/
// DFS preorder methodo 2
void traverseTree(tree T){
    if (T == NULL) return;
    while (T != NULL){
        cout << get_info(T) << endl;
        if (get_firstChild(T)) traverseTree(get_firstChild(T));
		T = get_nextSibling(T);
    }
}




int main()
{
	tree t = new_node("Luca");
	
	node *n = new_node("Paolo");
	insert_child(t, n);

	n = new_node("Elena");
	insert_child(t->firstChild, n);

    n = new_node("Sofia");
	insert_sibling(t->firstChild->firstChild, n);

	n = new_node("Marco");
	insert_sibling(t->firstChild, n);

	n = new_node("Lucia");
	insert_child(t->firstChild->nextSibling, n);

	node *m = new_node("Anna");
	insert_sibling(n->parent, m);
	

	//serialize(t);
    cout<<"Altezza dell'albero: "<<altezza(t) << ". MIA VERSIONE: " << alt(t) <<endl;
	traverseTree(t);
	cout << endl;
	DFS(t);
	cout << "-----------" << endl;
	//traverseTree(t);
	DFS2Easy(t);
	
	cout << "Total amount of leaves: " << count_leaves(t) << endl;



	char input = 'N';
	do{
		tipo_inf inf_to_search;
		cout << "Enter an info to search in the tree: ";
		cin >> inf_to_search;

		node* node_found = search_node(t, inf_to_search);

		if(node_found != NULL) {
			cout << "Node found!" << endl;
			cout << "Enter a new value for the node: ";
			cin >> node_found->inf;
		}
		else{
			cout << "Node not found!" << endl;
		}

		cout << "Do you want to modify another node? (y/n): ";
		cin >> input;
		cout << endl;

	}while(input == 'y' || input == 'Y');
}
