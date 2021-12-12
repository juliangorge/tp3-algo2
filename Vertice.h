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
    Vertice(Casillero *casillero);

    //post: obtiene el casillero del vertice
    Casillero *obtener_casillero();

    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
