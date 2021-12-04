#include "Casillero_terreno.h"

CasilleroTerreno:: CasilleroTerreno(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter = 'T';
    this->es_camino = false;
    this->es_terreno = true;
    this->nombre_casillero = "Casillero construible";
    this->costo_energia = 25;
}