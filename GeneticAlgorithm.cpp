#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>

#include "Individuo.h"

bool pertenece(int x,int* arr,int size){
	for (int i = 0; i < size;i++){
		if(arr[i]==x)
			return true;	
	}
	return false;
}

Individuo operacion1(Individuo father, Individuo mother, int n){
	Individuo hijo=father;
	int p = rand() % n;
	int *auxsegment = new int[n - p];
	for (int i=p; i<n;i++){
		auxsegment[i-p]=father[i];
	}
	int index = 0;
	for (int j = 0;j<n;j++){
		if(!pertenece(mother[j],auxsegment,n-p)){
			hijo[index] = mother.arr[j];
			index++;
		}			
	}
	delete[] auxsegment;
	return hijo;
}

Individuo operacion2(Individuo father, Individuo mother, int tam){
    
    Individuo child(father); //o mother
    int division1=rand() % tam;
    int division2=rand() % tam;
    int index=0;


    //SEGMENTO MEDIO CON MOTHER
    for (int i=0; i<division1 ; i++){
        for(division1;division1<division2;division1++){
            if(mother[i] != father[division1])
            {
                child[index] = mother[i];
                index++;
            }
        }
    return child;
    

    //SEGMENTO MEDIO -> CHILD
    for (division1;division1<division2;division1++){
        child[index] = father[division1];
        index++;        
    }


    //TODO

    
    
    }


}


class GeneticAlgorithm {
private:
	unsigned int tamano_poblacion;
	Individuo (*operaciones[2])(Individuo, Individuo, int) = { operacion1, operacion2 };
    std::vector<Individuo> poblacion;
    unsigned int epocas;

// Utility Functions
private:
	void generaPoblacion(std::vector<Individuo> &_poblacion, int n, int rango);
    bool fun_prob() {
        return rand()%2;
    }

public:
	GeneticAlgorithm(unsigned int tamano, unsigned int _epocas) : tamano_poblacion(tamano), epocas(_epocas) {
		poblacion.resize(tamano);
	}
	~GeneticAlgorithm();

	void run() {
		generaPoblacion(poblacion, 5, 100); // 1. Generar Poblacion Inicial - Nice
		sort(poblacion.begin(), poblacion.end(), fitness); // 2. Evaluacion inicial
		for (int i = 0; i < epocas; ++i) { // 3. Condicion de termino (nro iteraciones)
			for (int j = 0; j < tamano_poblacion - 1; j += 2) {
				// 3.1. Recombinacion
				// Falta testeo (constructor copia)
				Individuo aux_1 = poblacion[j];
				Individuo aux_2 = poblacion[j + 1];

				Individuo hijo = (*operaciones[rand() % 2])(aux_1, aux_2, poblacion[0].n);
				poblacion.push_back(hijo);

				// poblacion.push_back(operaciones[rand() % 2](poblacion[j], poblacion[j + 1]));
				// poblacion.push_back(operaciones[rand() % nro_operaciones].aplica(poblacion[j], poblacion[j + 1]));

				// 3.2. Mutacion
				bool prob_mut = fun_prob();
				if (prob_mut) {
					mutar(hijo);
					poblacion.push_back(hijo);
				}

				// double prob = aleatorio(); - Atencius
				//if()
				//poblacion.push_back(aplicamutacion(poblacion[i]));
				//poblacion.push_back(operaciones[0].aplica(poblacion[i])); -
			}
			// 3.3. Seleccion
			sort(poblacion.begin(), poblacion.end(), fitness);
			// seleccionNatural(tamano_poblacion);
			dividir_poblacion(tamano_poblacion);
		}
	}

    void mutar(Individuo hijo){
        //hijo.n == tamaño del arreglo del individuo
        int tamanio_seg = 0.2f * hijo.n; //rango del segmento a mutar
        int begin_seg  = rand() % hijo.n;  //el segemento comienza en cualquier punto del arreglo

        std::stack<int> aux_hijo;
        int j = begin_seg; //indice del arreglo
        int i = 0;         //rango del segmento

        //guardamos el segmento en una pila
        while( i < tamanio_seg){
	        if(j > (hijo.n)-1)
		        j = 0;
	        aux_hijo.push(hijo.arr[j]);
	        j++;
	        i++;
        }                

        j= begin_seg;
        i = 0;
        
        //colocamos los valores invertidos al hijo
        while( i < tamanio_seg){
	        if(j > (hijo.n)-1)
		        j = 0;
	        hijo.arr[j] = aux_hijo.top();
            aux_hijo.pop();
	        j++;
	        i++;
        }
    }

	void dividir_poblacion(int tamano){
		for (int i = 0; i < tamano; i++){
			poblacion.pop_back();
		}
	}

};



GeneticAlgorithm::~GeneticAlgorithm()
{
}

void GeneticAlgorithm::generaPoblacion(std::vector<Individuo> &_poblacion, int n, int rango) {
	Individuo individuo(n, rango);
	for (int i = 0; i < tamano_poblacion; ++i) {
		individuo.shuffle();
		poblacion.push_back(individuo);
	}
}


//https://jamboard.google.com/d/1pu7omhSo7UbcmUQGWEeirwdJvi155OIdXnkiJZwFaFA/edit?usp=sharing
