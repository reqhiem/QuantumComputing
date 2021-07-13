#pragma once

#include <cmath>
class GeneticAlgorithm;

class Qubit {
	friend class GeneticAlgorithm; //La clase GeneticAlgorithm tendra acceso a los Qybits
private:
    //Amplitudes
	double alpha;
	double beta;
public:
	Qubit();

	bool check() const;
	int measure() const;
};

#include "Qubit.cpp"
