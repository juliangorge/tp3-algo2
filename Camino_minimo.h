#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS_CAMINOMINIMO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include <iostream>

const int INFINITO = 99999999;

class Camino_minimo
{

//Atributos
protected:
    unsigned int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    int cantidad_vertices;

//Métodos
public:
    // PRE:
    // POST: Crea un objeto Camino_minimo
    Camino_minimo(Lista<Vertice> * vertices, unsigned int** matriz_adyacencia);

    // POST: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual void camino_minimo(unsigned int origen, unsigned int destino) = 0;

    // PRE:
    // POST: Destruye un objeto Camino_minimo
    virtual ~Camino_minimo() = default;
};


#endif //GRAFOS_CAMINOMINIMO_H
