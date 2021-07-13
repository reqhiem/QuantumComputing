#include "GeneticAlgorithm.h"

// Inicializacion de la poblacion
void GeneticAlgorithm::initialisePopulation() {
	// Generando individuos para la poblacion
	for (int i = 0; i < population_size; ++i)
		population.push_back(Individual(chromosomes_length));
}

// Evaluacion de los individuos
void GeneticAlgorithm::evaluateIndividuals() {
	for (int i = 0; i < population_size; ++i) {
		population[i].interpret_chromosome(); // Midiendo los qubits del cromosoma para interpretar un valor de un numero real
		population[i].evaluate_fitness(limit_a, limit_b); // Evaluando el fitness que se obtiene de la ultima interpretacion
	}
	std::sort(population.begin(), population.end()); // Ordenando la poblacion del individuo mas apto al menos apto
}


// Calculando el angulo de rotacion
float GeneticAlgorithm::calculate_rotation_angle(const Qubit x_i, const Qubit best_i, const bool x_best) {
	int x = x_i.measure();
	int best = best_i.measure();

	// Utilizando la estrategia de calibracion del angulo de rotacion
	const float pi = std::acosf(-1);
	float delta_th = 0.01f * pi;
	if (x == best)
		return 0.f;
	else if ((!x && x_best) || (x && !x_best)) {
		if (x_i.alpha * x_i.beta > 0)
			return -1 * delta_th;
		else if (x_i.alpha * x_i.beta < 0)
			return +1 * delta_th;
		else if (x_i.alpha == 0)
			return (rand() % 2) ? +1 * delta_th : -1 * delta_th;
		else
			return 0.f;
	}
	else {
		if (x_i.alpha * x_i.beta > 0)
			return +1 * delta_th;
		else if (x_i.alpha* x_i.beta < 0)
			return -1 * delta_th;
		else if (x_i.alpha == 0)
			return 0.f;
		else
			return (rand() % 2) ? +1 * delta_th : -1 * delta_th;
	}
}

// Aplicando la compuerta de rotacion cuantica
void GeneticAlgorithm::quantum_rotating_gate(Individual& x_individual, const Individual& best_individual) {
	bool x_best = x_individual.fitness > best_individual.fitness;
	for (int i = 0; i < chromosomes_length; ++i) {
		float rotation_angle = calculate_rotation_angle(x_individual[i], best_individual[i], x_best); // Calculando el angulo de rotacion para cada qubit

		// Aplicando la rotacion
		double _aplha = x_individual[i].alpha * std::cos(rotation_angle) - x_individual[i].beta * std::sin(rotation_angle); // Calculando la nueva amplitud 'alpha'
		double _beta = x_individual[i].alpha * std::sin(rotation_angle) + x_individual[i].beta * std::cos(rotation_angle); // Calculando la nueva amplitud 'beta'
		// Aplicando los cambios en el qubit
		x_individual[i].alpha = _aplha;
		x_individual[i].beta = _beta;
	}
}

// CONSTRUCTOR
GeneticAlgorithm::GeneticAlgorithm(size_t size, size_t _generations, size_t chrom_len, const float a, const float b)
	: population_size(size), generations(_generations), chromosomes_length(chrom_len), limit_a(a), limit_b(b) { // Inicializando parametros
	population.reserve(population_size); // Reservando memoria
}

// Ejecucion del Algoritmo Genetico
void GeneticAlgorithm::run() {
	initialisePopulation(); // Inicializacion de la poblacion
	evaluateIndividuals(); // Evaluacion de los individuos (valor y fitness)
	Individual best_individual = population[0]; // Fijando al mejor individuo como objetivo evolutivo de la generacion
	for (int i = 0; i < generations; ++i) {
		evaluateIndividuals(); // Evaluando cada individuo (valor y fitness)
		for (int i = 0; i < population_size; ++i)
			quantum_rotating_gate(population[i], best_individual); // Aplicando la compuerta de rotacion cuantica sobre cada individuo
		evaluateIndividuals(); // Evaluando los nuevos valores y fitness de cada individuo
		if (population[0] > best_individual) best_individual = population[0]; // Actualizando el mejor individuo
		std::cout << "Generacion " << i << ": x = " << best_individual.latest_interpretation << ", f(x) = " << best_individual.fitness << "\n";
	}
	std::cout << "ULTIMA GENERACION: x = " << best_individual.latest_interpretation << ", f(x) = " << best_individual.fitness << "\n";
}

