#include "Casillero_lago.h"

CasilleroLago:: CasilleroLago(){
    this->caracter = 'L';
    this->es_camino = false;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero intransitable";
    this->costo_energia = 2; // Jugador 1: 2 - Jugador 2: 5
}