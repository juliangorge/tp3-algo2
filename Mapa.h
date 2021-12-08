#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include <string>

//#include "Casillero.h"
#include "Casillero.h"
#include "Casillero_camino.h"
#include "Casillero_betun.h"
#include "Casillero_lago.h"
#include "Casillero_muelle.h"
#include "Casillero_terreno.h"
#include "Jugador.h"

using namespace std;

const string ARCHIVO_MAPA = "mapa.txt";

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
        Casillero *** matriz_mapa;
        Material** materiales_mapa;
        unsigned int cantidad_de_materiales;

    public:
        // Constructor
        // PRE: debe existir un archivo con un mapa cargado en el camino especificado y con el formato correcto
        // POS: carga los atributos del objeto con lo que obtiene del archivo mapa
        Mapa();
        ~Mapa();
        void leer_mapa();
        void cargar_mapa(unsigned int cantidad_filas, unsigned int cantidad_columnas, char square_type);
        void mostrar_mapa_vacio();
        void mostrar_mapas();

        Casillero * obtener_casillero(unsigned int fila, unsigned int columna);

        // datos de consola
        bool chequear_coordenadas(unsigned int fila, unsigned int columna);

        void set_jugador_casillero(Jugador * jugador);

        void set_material_casillero(unsigned int fila, unsigned int columna, Material* material);

        estados_t verificar_condiciones_construccion(char caracter_jugador, unsigned int fila, unsigned int columna);

        estados_t verificar_condiciones_demolicion(char caracter_jugador, unsigned int fila, unsigned int columna);

        void set_edificio_casillero(char caracter_jugador, unsigned int fila, unsigned int columna, Edificio *edificio);

        void remover_edificio_casillero(unsigned int fila, unsigned int columna);

        bool es_construible(Casillero * casillero);

        void consultar_coordenadas(unsigned int fila, unsigned int columna);

        void cargar_materiales(Jugador* jugador);

        unsigned int set_cantidad_material(Material* material);

        Material* obtener_material(string nombre_material);
};



#endif
