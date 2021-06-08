#include "Individuo.h"

#include <iostream>
#include <stdlib.h>    
#include <time.h>

#include "tools.h"

Individuo::Individuo(){
	int n = 0;
	arr = new int[n];
}
Individuo::Individuo(int n, int rango){
	arr = new int[n];
	this -> n = n;
	srand (time(NULL));
	for(int i = 0 ; i < n; i++){
		arr[i] = rand() % rango + 1;
		if (rand() % 2 + 1 == 2 )
			arr[i] *= -1;

	}
}

//constructor copia
Individuo::Individuo(const Individuo& obj){
	arr = new int [obj.n];
	this->n = obj.n;
	for(int i = 0 ; i < obj.n; i++){
		arr[i] = obj.arr[i];
	}
}

void Individuo::show(){
	for(int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void Individuo::swap(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}

void Individuo::shuffle(){
	for (int i=0; i < n; i++)
		swap(arr[i], arr[rand()%n]);
}

bool Individuo::isSorted(){
	int i = n;
	while ( --i > 1 )
		if (arr[i] < arr[i-1])
			return false;
	return true;
}

void Individuo::bogosort_itera(int a){
	for(int i = 0; i <a; i++)
		if ( !isSorted() )
			shuffle();
}

void Individuo::bogosort_perpetuo(){
	while ( !isSorted() )
		shuffle();
}

Individuo::~Individuo(){
	delete[] arr;
}

float Individuo::fitness1(){
	float fit = 0; 
	for (int i = 0; i < n - 1; ++i)
		if (arr[i] > arr[i + 1])
			++fit;
	return fit/(n) * 100.f;
}

float Individuo::fitness2(int p=0, int q=-1){
	if(q == -1) q = n;
	float fit = 0;
	for (int i = p; i <= q; ++i)
		for (int j = i + 1; j <=q; ++j)
			if (arr[i] > arr[j])
				++fit; // C(n, 2)
	return 100 - (fit/choose(n,2) * 100.f);
}

int& Individuo::operator [] (unsigned int i) {
	return arr[i];
}

const int& Individuo::operator [] (unsigned int i) const {
	return arr[i];
}