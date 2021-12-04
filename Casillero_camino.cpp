#include "Casillero_camino.h"

CasilleroCamino:: CasilleroCamino(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter = 'C';
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero transitable";
    this->costo_energia = 4;
}

bool CasilleroCamino:: esta_libre(){
    return this->material == nullptr;
}

void CasilleroCamino:: cambiar_objeto(){
    if(esta_libre()){
        this->caracter = this->material->obtener_caracter();
    }else{
        this->caracter = 'C';
        this->material = nullptr;
    }
}