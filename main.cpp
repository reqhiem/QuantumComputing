#include <iostream>
#include <ctime>

#include "GeneticAlgorithm.h"

int main(int argc, char **argv)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	GeneticAlgorithm QGA(1200, 1500, 32, 0, 20); //Instancia de la clase GeneticAlgorithm
	QGA.run();
	
	return 0;
}
