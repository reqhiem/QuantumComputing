
#ifndef _BOGOSORT_
#define _BOGOSORT_

class Individuo {
	int *arr;
	int n; 
public:

    //Constructors
    Individuo();
	Individuo(int n, int rango); 
	Individuo(const Individuo& obj);
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
	
	friend class GeneticAlgorithm;
	friend Individuo operacion1(Individuo father, Individuo mother, int n);

	int& operator [] (unsigned int i);
	const int& operator [] (unsigned int i) const;
};

//Utility functions
bool fitness(Individuo &i1, Individuo &i2){
	if(i1.fitness2() < i2.fitness2())
		return true;
	return false;
}

#include "Individuo.cpp"
#endif