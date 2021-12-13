#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS_CAMINOMINIMO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include <iostream>

const int INFINITO = 99999999;

class Camino_minimo {
//Atributos
protected:
    int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    int cantidad_vertices;

//Métodos
public:
    Camino_minimo(Lista<Vertice> * vertices, int** matriz_adyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual void camino_minimo(int origen, int destino) = 0;

    virtual ~Camino_minimo() = default;
};


#endif //GRAFOS_CAMINOMINIMO_H
