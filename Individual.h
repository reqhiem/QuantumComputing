#pragma once 

#include "Qubit"

class Individual {
	friend class GeneticAlgorithm; //permitimos a la clase GeneticAlgorithm acceder al cromosoma y fitness
private:
	Qubit* chromosome; //cromosoma representado mediante quibits
	size_t m; //tamanio del individuo

	float fitness; 
	float latest_interpretation; // guardar el ultimo resultado de los individuos

private:
	//simular un float mediante qubits
	float interpret_chromosome(size_t exponent_size = 8, size_t mantissa_size = 23);

public:
	//inicializar el individuo
	Individual() : chromosome(nullptr), m(0), latest_interpretation(0.f), fitness(0.f) {}
	Individual(const Individual& o);
	Individual(size_t size);
	~Individual();

	//retornar el mejor resultado del individuo
	const float getLatestInterpretation() const;
	
	
	//declarar nuestra funcion fitness y lo evaluamos.
	void evaluate_fitness(const float a, const float b);


	//sobrecarga de operadores para facilitar el manejo del cromosoma y fitness
	Qubit& operator [] (size_t index);
	const Qubit& operator[] (size_t index) const;

	bool operator < (const Individual& o) const;
	bool operator > (const Individual& o) const;
	Individual& operator = (const Individual& o);
};


