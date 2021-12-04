#include "Casillero_muelle.h"

CasilleroMuelle:: CasilleroMuelle(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter = 'M';
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero transitable";
    this->costo_energia = 5; // Jugador 1: 5 - Jugador 2: 2
}