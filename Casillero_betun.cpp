#include "Casillero_betun.h"

CasilleroBetun:: CasilleroBetun(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter = 'B';
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero transitable";
    this->costo_energia = 0;
}

bool CasilleroBetun:: esta_libre(){
    return false;
}

void CasilleroBetun:: cambiar_objeto(){

}