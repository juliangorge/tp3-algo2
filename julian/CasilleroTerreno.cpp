#include "CasilleroTerreno.h"

CasilleroTerreno:: CasilleroTerreno(){
    this->tipo_casillero = 'T';
    this->es_camino = false;
    this->es_terreno = true;
    this->nombre_casillero = 'Casillero construible';
    this->costo_energia = 25;
}