#include "Casillero_camino.h"

CasilleroCamino:: CasilleroCamino(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter = 'C';
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero transitable";
    this->costo_energia = 4;
}