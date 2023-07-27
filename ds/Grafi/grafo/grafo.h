#ifndef GRAFI_H_
#define GRAFI_H_


/* In programmazione 1

struct sondaggio {
    unsigned int indice;
    char domanda[MAXLUN];
    char r0[MAXLUN];
    char r1[MAXLUN];
    char r2[MAXLUN];
    unsigned int correct;//num della rispota corretta
};

struct T {
    struct sondaggio * pSondaggio;
    unsigned int dim; //N
};

*/


struct adj_node {
  int node; // ID
  float weight;
  struct adj_node* next;
};

//creo nuovo nome per il puntatore adj_list  che punta al tipo struct adj_node
typedef adj_node* adj_list; // adj_node** <=> adj_list* 

typedef struct { //il nuovo tipo graph
  adj_node** nodes; //adj_list* nodes;
  int dim;
} graph;

//CREA UN GRAFO NUOVO
graph new_graph(int);


void add_arc(graph&, int, int, float);
void add_edge(graph& g, int, int, float);

int get_dim(graph);
adj_list get_adjlist(graph,int);
int get_adjnode(adj_node*);
float get_adjweight(adj_node*);
adj_list get_nextadj(adj_list);



#endif /* GRAFI_H_ */
