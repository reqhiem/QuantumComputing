#include <iostream>

#include "bogoSort.h"
#include "tools.h"

using namespace std;

int main(int argc, char** argv){
    Individuo ind(30,30);
	ind.show();
	ind.bogosort_itera(100);
    ind.show();
    cout << ind.fitness1() << "% sorted" << endl;
    cout << ind.fitness2() << "% sorted" << endl;
    if(ind.isSorted())
        cout << "Sorted\n";
    else
        cout << "Not Sorted\n";

    return 0;
}