#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#include"carta.h"


int compare(tipo_inf a,tipo_inf b){
	if( (strcmp(a.nc, b.nc) == 0 && a.totalep == b.totalep) || strcmp(a.nc, b.nc) < 0 || strcmp(a.nc, b.nc) > 0) return strcmp(a.nc, b.nc);
	
	else  return a.totalep-b.totalep;
}

void copy(tipo_inf& a,tipo_inf b){
	strcpy(a.nc, b.nc);
	a.totalep = b.totalep;
}

void print(tipo_inf a){
	cout << a.nc << " " << a.totalep;
}
