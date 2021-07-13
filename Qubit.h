#pragma once

#include <cmath>
class GeneticAlgorithm;

class Qubit {
	friend class GeneticAlgorithm;
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
