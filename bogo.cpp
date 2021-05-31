#include <iostream>
#include <stdlib.h>    
#include <time.h> 

class Individuo{
	int *arr;
	int n;
public:
	Individuo(int n, int rango){
		arr = new int[n];
		this -> n = n;
		srand (time(NULL));
		for(int i = 0 ; i < n; i++){
			arr[i] = rand() % rango + 1;
			if (rand() % 2 + 1 == 2 )
				arr[i] *= -1;

		}

	}

	void show(){
		for(int i = 0; i < n; i++)
			std::cout << arr[i] << " ";
		std::cout << "\n";
	}

	void swap(int &a, int &b){
		int c = a;
		a = b;
		b = c;
	}

	void shuffle(){
    	for (int i=0; i < n; i++)
        	swap(arr[i], arr[rand()%n]);
	}

	bool isSorted(){
		int i = n;
    	while ( --i > 1 )
    	    if (arr[i] < arr[i-1])
        	    return false;
    	return true;
	}

	void bogosort_itera(int a){
		for(int i = 0; i <a; i++)
			if ( !isSorted() )
				shuffle();
	}

	void bogosort_perpetuo(){
		while ( !isSorted() )
        	shuffle();
	}
	
	~Individuo(){
		delete[] arr;
	}
};


int main(){
	Individuo ind(30, 30);
	ind.show();
	ind.bogosort_itera(30);
	ind.show();
}

