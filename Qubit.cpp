#include "Qubit.h"

Qubit::Qubit() {
    //Constructor de Qubit
	alpha = beta = 1 / std::sqrt(2);
}

bool Qubit::check() const {
    //Verificamos que el Qubit no se sobrecarge
	double error = 10e-6;
	return std::abs(alpha - beta) < error;
}

int Qubit::measure() const {
    //Retorna la medida del Qubit
	double probability = (double)rand() / (double)RAND_MAX;
	return (probability < beta * beta);
}
