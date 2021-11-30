#ifndef MAPA_H
#define MAPA_H

#include "Casillero.h"

#include "CasilleroBetun.h"
#include "CasilleroCamion.h"
#include "CasilleroLago.h"
#include "CasilleroMuelle.h"
#include "CasilleroTerreno.h"

#include <string>

using namespace std;

class Mapa
{
    private:
        unsigned int filas;
        unsigned int columnas;
        unsigned int path_square_quantity;
        Casillero*** casilleros;

    public:
        Mapa();
        void leerMapa();
        void cargarMapa(unsigned int filas, unsigned int columnas, char tipo_casillero);
        void agregarCoordenadas(unsigned int & pos_fila, unsigned int & pos_columna);
        bool verificarCoordenadas(unsigned int pos_fila, unsigned int pos_columna);

        void mostrarMapa();
        void mostrarCoordenadas(unsigned int pos_fila, unsigned int pos_columna);
        void limpiarCasillero(unsigned int pos_fila, unsigned int pos_columna);

};


#endif // MAP_H
