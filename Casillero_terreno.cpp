#include "Casillero_terreno.h"

CasilleroTerreno:: CasilleroTerreno(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = 'T';
    this->caracter = this->caracter_casillero;
    this->es_camino = false;
    this->es_terreno = true;
    this->nombre_casillero = "Casillero construible";
    this->costo_energia = 25;
}

void CasilleroTerreno:: cambiar_objeto(){
    this->caracter = this->edificio->obtener_caracter();
}