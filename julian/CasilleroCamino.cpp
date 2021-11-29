#include "CasilleroCamino.h"

CasilleroCamino:: CasilleroCamino(){
    this->tipo_casillero = 'C';
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = 'Casillero transitable';
    this->costo_energia = 4;
}