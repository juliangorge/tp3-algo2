#include "Casillero_terreno.h"

CasilleroTerreno:: CasilleroTerreno(){
    this->caracter = 'T';
    this->es_camino = false;
    this->es_terreno = true;
    this->nombre_casillero = "Casillero construible";
    this->costo_energia = 25;
}