#include "Casillero.h"

Casillero:: Casillero(){
    this->edificio = nullptr;
    this->material = nullptr;
}

bool Casillero:: esta_libre(){
    if(this->es_camino) return this->material == nullptr;
    return this->edificio == nullptr;
}

Edificio* Casillero:: obtener_edificio(){
    return this->edificio;
}

Material* Casillero:: obtener_material(){
    return this->material;
}

string Casillero:: obtener_nombre_casillero(){
    return this->nombre_casillero;
}

char Casillero:: obtener_caracter(){
    return this->caracter;
}

void Casillero:: cargar(Edificio* edificio){
    if(es_terreno){
        this->edificio = edificio;
        cambiar_objeto();
    }
}
void Casillero:: cargar(Material* material){
    if(es_camino){
        this->material = material;
        cambiar_objeto();
    }
}

void Casillero:: limpiar_casillero(){
    this->edificio = nullptr;
    cambiar_objeto();
}

void Casillero:: cambiar_objeto(){
    if(esta_libre()){
        //this->caracter = this->caracter;
    }else{
        if(es_camino){
            this->caracter = this->material->obtener_caracter();
        }else{
            this->caracter = this->edificio->obtener_caracter();
        }
    }
}

unsigned int Casillero:: obtener_costo_de_energia(){
    return this->costo_energia;
}