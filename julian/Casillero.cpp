#include "Casillero.h"

Casillero:: Casillero(){
    this->edificio = nullptr;
    this->material = nullptr;
}

bool estaLibre(){
    if(this->es_camino) return this->material == nullptr;
    return this->edificio == nullptr;
}

Edificio* obtenerEdificio(){
    return this->edificio;
}

Material* obtenerMaterial(){
    return this->material;
}

string obtenerNombreCasillero(){
    return this->nombre_casillero;
}

char obtenerTipoCasillero(){
    return this->tipo_casillero;
}

void cargar(Edificio* edificio){
    if(es_terreno){
        this->edificio = edificio;
        cambiarObjeto();
    }
}
void cargar(Material* material){
    if(es_camino){
        this->material = material;
        cambiarObjeto();
    }
}

void limpiarCasillero(){
    this->edificio = nullptr;
    cambiarObjeto();
}

void cambiarObjeto(){
    if(estaLibre()){
        this->type_square = this->tipo_casillero;
    }else{
        if(es_camino){
            this->type_square = this->material->obtenerChar();
        }else{
            this->type_square = this->edificio->obtenerChar();
        }
    }
}

unsigned int obtenerCostoDeEnergia(){
    return this->costo_energia;
}