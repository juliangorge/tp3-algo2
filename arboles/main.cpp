#include <iostream>
#include "ABB.h"
#include "ABB_nodo.h"


using namespace std;

int main()
{
    ABB<int>* abb = new ABB<int>();
    int datos[] = {23, 12, 31, 3, 7, 15, 29, 88, 53};
    for(int i=0; i<9; i++)
        abb->insertar(datos[i]);

    abb->imprimir_en_orden();

    delete abb;


}