#include "CasilleroLago.h"

CasilleroLago:: CasilleroLago(){
    this->tipo_casillero = 'L';
    this->es_camino = false;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero con agua";
    this->costo_energia = 2; // Jugador 1: 2 - Jugador 2: 5
}
