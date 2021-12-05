#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include "Vertice.h"
#include "Caminos.h"

using namespace std;

class Grafo
{
private:
	//vertices;

public:

	// PRE: 
	// POST: crea un objeto Grafo.
	Grafo();

	// PRE: 
	// POST: destruye un objeto Grafo.
	~Grafo();

	// PRE: Recibe string
	// POST: Agrega un vértice con dicho string si no existe
	void agregar_vertice(string valor);

	// PRE: Recibe string
	// POST: Retorna TRUE si existe un vértice del grafo con ese string
	bool hay_vertice(string valor);

	// PRE: Recibe string
	// POST: Retorna un puntero a dicho vértice, si pertenece
	Vertice * obtener_vertice(string valor);

	// PRE: Recibe string de un vértice de llegada y salida.
	// POST: Retorna un puntero cargado con el camino mas barato, si existe.
	//		 Debe liberarse la memoria del puntero luego de usarlo.
	Tipo * camino_mas_barato(string llegada, string salida);

	// PRE: Recibe string de un vértice de llegada y salida.
	// POST: Retorna un puntero cargado con el camino mas corto, si existe.
	//		 Debe liberarse la memoria del puntero luego de usarlo.
	Tipo * camino_mas_corto(string llegada, string salida);

private:
	// PRE: Recibe string de un vértice de llegada y salida.
	// POST: Retorna un puntero cargado
	Tipo * menor_camino(string llegada, string salida, char tipo_dato);

	// PRE: Recibe string de dos vertices, 2 vectores ya creados con tamaño = vertices.tam + 1, una lista vacia, y el tipo_dato para buscar por costo de energía u distancia.
	// POST: Retorna un puntero a una lista de los predecesores cargada segun las posiciones en la lista de vertices.
	Tipo<Dato * > * dijkstra(string llegada, string salida, float * costo, bool * visitado, Tipo<Dato * > * predecesores, char tipo_dato);
};

#endif /* GRAFO_H_ */
