/**
 *  @descripcion: Archivo de cabecera para la declaracion de la clase GeneticAlgorithm para manipular
 * 				  datos y funciones miembro de un QGA (Quantum Genetic Algorithm)
*/

#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

#include "Individual.h"

class GeneticAlgorithm {
private:
	std::vector<Individual> population; //arreglo de individuos (poblacion)
	size_t chromosomes_length; //tamaño del cromosoma
	size_t population_size; //tamaño de la poblacion
	size_t generations; //generaciones (total de mutaciones)

	float limit_a; //limite inferior de busqueda
	float limit_b; //limite superior de busqueda

private:
	void initialisePopulation();
	void evaluateIndividuals();

	float calculate_rotation_angle(const Qubit x_i, const Qubit best_i, const bool x_best); 
	void quantum_rotating_gate(Individual& x_individual, const Individual& best_individual); //compuerta cuántica de rotacion (crossover)

public:
	GeneticAlgorithm(size_t size, size_t _generations, size_t chrom_len, const float a, const float b); //constructor de inicializacion

	void run(); //metodo para ejecutar el algoritmo genetico

};

#include "GeneticAlgorithm.cpp"