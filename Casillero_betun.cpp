#include "Casillero_betun.h"

CasilleroBetun:: CasilleroBetun(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = 'B';
    this->caracter = this->caracter_casillero;
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero transitable";
    this->costo_energia = 0;
}

void CasilleroBetun:: cambiar_objeto(){

}