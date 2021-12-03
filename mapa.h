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

class Mapa
{
    private:
        unsigned int filas;
        unsigned int columnas;
        Casillero*** casilleros;

    public:
        Mapa();
        ~Mapa();
        void leer();
        void cargar(unsigned int filas, unsigned int columnas, char casillero_caracter);
        void mostrar();
        bool consultar_coordenada(unsigned int fila_pos, unsigned int columna_pos);
        bool es_construible(unsigned int fila_pos, unsigned int columna_pos);
        Casillero * obtener_casillero(unsigned int fila_pos, unsigned int columna_pos);
};

#endif