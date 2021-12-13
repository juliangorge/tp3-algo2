#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include "Mapa.h"

using namespace std;

class Parser
{
private:
    string entrada;

public:

	// PRE: El archivo ubicaciones.txt debe estar cargado
	// POST: Crea el objeto Parser con cada linea del archivo ubicaciones.txt
    Parser(string valor_entrada);

    // PRE: El archivo ubicaciones.txt no debe estar vacío
	// POST: Devuelve el nombre del edificio o material, o bien el numero de jugador en string
    string nombre();

    // PRE: El archivo ubicaciones.txt no debe estar vacío
	// POST: Devuelve la primera coordenada, que es la fila en la que se encuentra el edificio/material/jugador
    unsigned int coordenada_fila();

    // PRE: El archivo ubicaciones.txt no debe estar vacío
	// POST: Devuelve la segunda coordenada, que es la columna en la que se encuentra el edificio/material/jugador
    unsigned int coordenada_columna();

    // PRE: El archivo ubicaciones.txt no debe estar vacío
	// POST: Devuelve el nombre o numero de un string dado, eliminando el delimitador que este string contiene
    string extraer_campo(string & entrada , string delimitador);
};

#endif