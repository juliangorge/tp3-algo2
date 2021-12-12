#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include <string>

#include "Casillero.h"
#include "Casillero_camino.h"
#include "Casillero_betun.h"
#include "Casillero_lago.h"
#include "Casillero_muelle.h"
#include "Casillero_terreno.h"
#include "Jugador.h"
#include "Constantes.h"

using namespace std;

class Mapa
{
    private:
        unsigned int cantidad_filas;
        unsigned int cantidad_columnas;
        Casillero *** matriz_mapa;
        Material** materiales_mapa;
        unsigned int cantidad_de_materiales;

    public:

        // PRE: debe existir un archivo con un mapa cargado en el camino especificado y con el formato correcto
        // POST: carga los atributos del objeto con lo que obtiene del archivo mapa
        Mapa();
        ~Mapa();
        void leer_mapa();
        void cargar_mapa(unsigned int cantidad_filas, unsigned int cantidad_columnas, char square_type);
        void mostrar_mapa_vacio();
        void mostrar_mapas();

        Casillero * obtener_casillero(unsigned int fila, unsigned int columna);

        void set_jugador_casillero(Jugador * jugador);

        void set_material_casillero(unsigned int fila, unsigned int columna, Material* material);

        estados_t verificar_condiciones_construccion(char caracter_jugador, unsigned int fila, unsigned int columna);

        estados_t verificar_condiciones_demolicion(char caracter_jugador, unsigned int fila, unsigned int columna);

        estados_t verificar_condiciones_ataque(char caracter_jugador, unsigned int fila, unsigned int columna);

        void set_edificio_casillero(char caracter_jugador, unsigned int fila, unsigned int columna, Edificio *edificio);

        void demoler_edificio_casillero(unsigned int fila, unsigned int columna);

        void atacar_edificio_casillero(unsigned int fila, unsigned int columna);

        void consultar_coordenadas(unsigned int fila, unsigned int columna);

        void cargar_materiales(Jugador* jugador);

        unsigned int set_cantidad_material(Material* material);

        Material* obtener_material(string nombre_material);

        unsigned int obtener_cantidad_filas();

        unsigned int obtener_cantidad_columnas();


};

#endif //MAPA_H
