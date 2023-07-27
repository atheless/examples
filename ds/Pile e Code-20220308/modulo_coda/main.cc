/*
 * main.cc
 *
 *  Created on: 10 mag 2018
 *      Author: federica
 */



#include <iostream>
using namespace std;

#include "tipo.h"
#include "coda.h"
int main(){
	coda c;
	c = newQueue();
	c = enqueue(c,2);
	c = enqueue(c,3);
	c = enqueue(c,10);
	c = enqueue(c,130);

	while(!isEmpty(c))
		cout<<"deQueue: "<< dequeue(c) << endl;

	if(isEmpty(c)) cout << "coda e' vuota" << endl;
	
	return 0;
}

