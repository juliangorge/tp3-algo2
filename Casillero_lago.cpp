#include "Casillero_lago.h"

CasilleroLago:: CasilleroLago(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = 'L';
    this->caracter = this->caracter_casillero;
    this->es_camino = false;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero intransitable";
    this->costo_energia = 2; // Jugador 1: 2 - Jugador 2: 5
}

void CasilleroLago:: cambiar_objeto(){

}