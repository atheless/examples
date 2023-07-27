#ifndef CONTO_H_
#define CONTO_H_



typedef struct {
   char nome[100];
   int budget;
} tipo_inf;

/*
struct tipo_inf {
   char nome[100];
   int budget;
};

typedef struct tipo_inf tipo_inf; // Now you can write: tipo_inf w; instead of struct tipo_inf w;

*/



int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);





#endif /* CONTO_H_ */
