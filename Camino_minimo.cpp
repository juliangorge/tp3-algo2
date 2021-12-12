#include "Camino_minimo.h"

Camino_minimo::Camino_minimo(Lista<Vertice> *vertices, int **matriz_adyacencia) {
    this -> vertices = vertices;
    this -> matriz_adyacencia = matriz_adyacencia;
    cantidadVertices = vertices -> obtener_cantidad_elementos();
}
