#include "Casillero_terreno.h"

CasilleroTerreno:: CasilleroTerreno(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter = 'T';
    this->es_camino = false;
    this->es_terreno = true;
    this->nombre_casillero = "Casillero construible";
    this->costo_energia = 25;
}

bool CasilleroTerreno:: esta_libre(){
    return this->edificio == nullptr;
}

void CasilleroTerreno:: cambiar_objeto(){
    if(esta_libre()){
        this->caracter = this->edificio->obtener_caracter();
    }else{
        this->caracter = 'T';
        this->edificio = nullptr;
    }
}