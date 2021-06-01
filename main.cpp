#include <iostream>

#include "bogoSort.h"

using namespace std;

int main(int argc, char** argv){
    Individuo ind(30, 30);
	ind.show();
	ind.bogosort_itera(30);
	ind.show();
    return 0;
}