#ifndef NODE_H_
#define NODE_H_

struct node{
	char cont[81];
	char tipo;
};

void leggi_riga(istream &is, char *riga);

graph gbuild();


graph g_build2(graph &G);

void stampa(graph &G);

void stampa(graph g, node* nd);

node* getnodes();

void follow(graph g, node* nd, int v);

int* totallike(graph g, node* nd);


#endif /* GRAFI_H_ */