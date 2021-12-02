#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include <string>

//#include "Casillero.h"
#include "CasilleroCamino.h"
#include "CasilleroBetun.h"
#include "CasilleroLago.h"
#include "CasilleroMuelle.h"
#include "CasilleroTerreno.h"

using namespace std;

const string CAMINO_ARCHIVO_MAPA = "mapa.txt";

// Casilleros transitables
const char CARACTER_CAMINO = 'C';
const char CARACTER_BETUN = 'B';
const char CARACTER_MUELLE = 'M';

// Casilleros inaccesibles
const char CARACTER_LAGO = 'L';

// Casilleros construibles
const char CARACTER_TERRENO = 'T';

// ArregloS con los tipos de casilleros
const char ARREGLO_CHAR_TRANSITABLES [] = {CARACTER_CAMINO, CARACTER_BETUN, CARACTER_MUELLE};
const char ARREGLO_CHAR_INACCESIBLES [] = {CARACTER_LAGO};
const char ARREGLO_CHAR_CONSTRUIBLES [] = {CARACTER_TERRENO};

class Mapa
{
    private:
        unsigned int cantidad_filas;
        unsigned int cantidad_columnas;
        Casillero ** matriz_mapa;

    public:
        // Constructor
        // PRE: debe existir un archivo con un mapa cargado en el camino especificado y con el formato correcto
        // POS: carga los atributos del objeto con lo que obtiene del archivo mapa
        Mapa(string CAMINO_ARCHIVO_MAPA);

        unsigned int obtener_cantidad_filas();

        unsigned int obtener_cantidad_columnas();

        Casillero * consultar_coordenada (unsigned int fila, unsigned int columna);

        void imprimir_mapa();

};




#endif