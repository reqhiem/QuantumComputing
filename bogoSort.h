
#ifndef _BOGOSORT_
#define _BOGOSORT_

#include <iostream>
#include <stdlib.h>    
#include <time.h> 

class Individuo{
	int *arr;
	int n;
public:
    Individuo();
	Individuo(int n, int rango);
    ~Individuo();

	void show();

	void swap(int &a, int &b);

	void shuffle();

	bool isSorted();

	void bogosort_itera(int a);

	void bogosort_perpetuo();
	
	
};


#include "bogoSort.cpp"
#endif