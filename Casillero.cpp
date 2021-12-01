#include "Casillero.h"

Casillero:: Casillero(){
    this->edificio = nullptr;
    this->material = nullptr;
}

bool esta_libre(){
    if(this->es_camino) return this->material == nullptr;
    return this->edificio == nullptr;
}

Edificio* obtener_edificio(){
    return this->edificio;
}

Material* obtener_material(){
    return this->material;
}

string obtener_nombre_casillero(){
    return this->nombre_casillero;
}

char obtener_tipo_casillero(){
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

void limpiar_casillero(){
    this->edificio = nullptr;
    cambiarObjeto();
}

void cambiar_cbjeto(){
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

unsigned int obtener_costo_de_energia(){
    return this->costo_energia;
}