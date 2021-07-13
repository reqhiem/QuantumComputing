#include "Individual.h"



// Estandar para numeros flotantes: IEEE - 754 

//Los Qubits de cada cromosoma son interpretados como numeros flotantes usando el estandar

float Individual::interpret_chromosome(size_t exponent_size, size_t mantissa_size) {
	float exponent = 0.f;
	float mantissa = 1.f;

	int sign = chromosome[m - 1].measure();

	for (int i = 0; i < exponent_size; ++i)
		exponent += (chromosome[mantissa_size + i].measure() * std::pow(2, i));
	exponent = std::pow(2, exponent - 127);

	for (int i = 1; i <= mantissa_size; ++i)
		mantissa += (chromosome[mantissa_size - i].measure() * std::pow(2, -i));

	latest_interpretation = std::pow(-1, sign) * exponent * mantissa;
	return latest_interpretation;
}

//Constructor copia de la clase individual

Individual::Individual(const Individual &o)
	: m(o.m), fitness(o.fitness), latest_interpretation(o.latest_interpretation) {
	chromosome = new Qubit[m];
	for (int i = 0; i < m; ++i)
		chromosome[i] = o.chromosome[i];
}

//Constructor de la clase individual

Individual::Individual(size_t size) {

	m = size;
	chromosome = new Qubit[m];
	latest_interpretation = 0.f;
	fitness = 0.f;
}

//destructor, elimina el array dinamico de cromosomas

Individual::~Individual() {
	delete[] chromosome;
}

//Funcion que obtiene el numero flotante

const float Individual::getLatestInterpretation() const {
	return latest_interpretation;
}
