
#ifndef _BOGOSORT_
#define _BOGOSORT_

class Individuo{
	int *arr;
	int n;
public:

    //Constructors
    Individuo();
	Individuo(int n, int rango);
    ~Individuo();

	//Memebers methods
	void show();
	void swap(int &a, int &b);
	void shuffle();
	bool isSorted();
	void bogosort_itera(int a);
	void bogosort_perpetuo();

	//Funciones fitness
    float fitness1();
	float fitness2(int p, int q);
};


#include "bogoSort.cpp"
#endif