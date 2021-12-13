#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H


#include "Camino_minimo.h"

class Dijkstra : public Camino_minimo{
//Atributos
private:
    bool *vertices_visitados;
    int *distancia;
    int *recorrido;

//Métodos
    //post: pone todos los valores del vector de vertices_visitados en "false" menos el origen
    void inicializar_visitados(int origen);

    //post: pone las distancias exactamente igual que la distanciaOrigen
    void inicializar_distancia(const int * distanciaOrigen);

    //post: llena el vector de recorrido con el origen
    void inicializar_recorrido(int origen);

    //post: devuelve el número de vértice con menor distancia al origen
    int vertice_minima_distancia();

    //post: actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
    void actualizar_distancia(int vertice);

    //pre: para que tenga sentido, debe ejecutarse un recorrido previamente
    //post: muestra por pantalla el resultado del recorrido.
    void mostrar_recorrido(int origen, int destino);

    //post: muestra el estado instantaneo del vector de recorrido, distancia y visitados.
    void mostrar_iteracion(int iteracion);
public:
    Dijkstra(Lista<Vertice> * vertices, int ** matriz_adyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void camino_minimo(int origen, int destino) override;

    ~Dijkstra() override;

};


#endif //GRAFOS_DIJKSTRA_H
