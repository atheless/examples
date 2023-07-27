#include<iostream>
#include<cstring>
using namespace std;
#include"tipo.h"


int compare(tipo_inf a,tipo_inf b){
 	return a.id - b.id;	
}
void copy(tipo_inf& dest, tipo_inf source){
	dest.id = source.id;
	strcpy(dest.nome, source.nome);
	dest.tipo = source.tipo;
}
void print(tipo_inf a){
	cout << a.id << " " << a.nome << " " << a.tipo;
}

