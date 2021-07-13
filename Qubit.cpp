#include "Qubit.h"

Qubit::Qubit() {
	alpha = beta = 1 / std::sqrt(2);
}

bool Qubit::check() const {
	double error = 10e-6;
	return std::abs(alpha - beta) < error;
	//return (std::pow(alpha, 2) + std::pow(beta, 2) == 1);
}

int Qubit::measure() const {
	double probability = (double)rand() / (double)RAND_MAX;
	return (probability < beta * beta);
}

