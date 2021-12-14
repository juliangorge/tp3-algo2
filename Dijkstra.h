#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H


#include "Camino_minimo.h"

class Dijkstra : public Camino_minimo{
//Atributos
private:
    bool *vertices_visitados;
    unsigned int *distancia;
    unsigned int *recorrido;

//Métodos
    // POST: pone todos los valores del vector de vertices_visitados en "false" menos el origen
    void inicializar_visitados(unsigned int origen);

    // POST: pone las distancias exactamente igual que la distanciaOrigen
    void inicializar_distancia(const unsigned int * distanciaOrigen);

    // POST: llena el vector de recorrido con el origen
    void inicializar_recorrido(unsigned int origen);

    // POST: devuelve el número de vértice con menor distancia al origen
    unsigned int vertice_minima_distancia();

    // POST: actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
    void actualizar_distancia(unsigned int vertice);

    // PRE: para que tenga sentido, debe ejecutarse un recorrido previamente
    // POS: muestra por pantalla el resultado del recorrido.
    void mostrar_recorrido(unsigned int origen, unsigned int destino);

    // PRE: Recibe destino valido
    // POST: Retorna la posicion del vertice del destino
    unsigned int obtener_posicion_destino(unsigned int destino);

    //PRE: las coordenadas deben pertenecer al camino minimo encontrado
    //POST: devuelve el vertice adyacente de menor peso
    void obtener_casillero_recorrido(unsigned int *fila, unsigned int *columna, unsigned int origen, unsigned int destino);

    //post: muestra el estado instantaneo del vector de recorrido, distancia y visitados.
    //void mostrar_iteracion(int iteracion);


public:

    // PRE:
    // POST: Crea un objeto Dijkstra
    Dijkstra(Lista<Vertice> * vertices, unsigned int ** matriz_adyacencia);

    // POST: Retorna por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    unsigned int camino_minimo(unsigned int origen, unsigned int destino);

    // PRE: Recibe vertice valida
    // POST: Retorna la distancia entre el jugador y el origen
    unsigned int obtener_distancia(unsigned int vertice);

    // PRE:
    // POST: Destruye el objeto Dijkstra
    ~Dijkstra() override;

};


#endif //GRAFOS_DIJKSTRA_H
