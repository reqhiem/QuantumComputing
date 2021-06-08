#include "bogoSort.h"

class operacion
{
private:
    /* data */
public:  
    operacion(/* args */);
    ~operacion();
    Individuo generaPoblacion();
}; 

operacion::operacion(/* args */)
{
    
}

operacion::~operacion()
{
}


class ag

{
private:
    /* data */
    operacion[] operaciones;
    int tam_pob;
     
public:
    ag(/* args */);
    ~ag();

    void run(){
        vector<Individuo> poblacion = generaPoblacion();
        for(i=0; i<epocas; ++i){
            for (int j = poblacion[i]; j < tamanioPoblacion; j++)
            {
                double prop = aleatorio();
                if()
                poblacion.push_back(aplicamutacion(poblacio[i]));
                poblacion.push_back(operaciones[0].aplica(poblacio[i]));
            }
            sort(poblacion.begin(), poblacion.end(), fitness);
            poblacion = poblacion[:tamanioPoblacion]    
        }
        

    }

};

ag::ag(/* args */)
{
}

ag::~ag()
{
}

