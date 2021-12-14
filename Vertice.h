#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H
#include "Casillero.h"
#include <string>

using namespace std;

class Vertice {

/*ATRIBUTOS*/
private:
    Casillero *casillero;

/*MÉTODOS*/
public:
    // PRE:
    // POST: Construye el objeto Vertice
    Vertice(Casillero *casillero);

    // POST: obtiene el casillero del vertice
    Casillero *obtener_casillero();
    
    // PRE:
    // POST: Destruye el objeto Vertice
    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
