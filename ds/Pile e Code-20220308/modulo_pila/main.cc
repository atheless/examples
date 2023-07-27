
#include <iostream>
using namespace std;

#include "tipo.h"
#include "pila.h"
int main(){
	pila p = NULL;

	p = push(p,2);
	p = push(p,3);
	cout<<"Pop: "<< pop(p) <<endl;
	p=push(p,10);
	cout<<"Pop: "<< pop(p) <<endl;
	cout<<"Pop: "<< pop(p) <<endl;
	if(!isEmpty(p))
		cout<< "Pop: "<< pop(p) <<endl;
	else
		cout<< "Lista vuota!!;";
	return 0;
}
