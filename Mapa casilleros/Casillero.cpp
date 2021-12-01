#include "Casillero.h"

Casillero:: Casillero(){
    this->edificio = nullptr;
    this->material = nullptr;
}

bool Casillero::esta_libre(){
    if(this->es_camino) return this->material == nullptr;
    return this->edificio == nullptr;
}

Edificio* Casillero::obtener_edificio(){
    return this->edificio;
}

Material* Casillero::obtener_material(){
    return this->material;
}

string Casillero::obtener_nombre_casillero(){
    return this->nombre_casillero;
}

char Casillero::obtener_tipo_casillero(){
    return this->tipo_casillero;
}

void Casillero::cargar(Edificio* edificio){
    if(es_terreno){
        this->edificio = edificio;
        cambiar_objeto();
    }
}
void Casillero::cargar(Material* material){
    if(es_camino){
        this->material = material;
        cambiar_objeto();
    }
}

void Casillero::limpiar_casillero(){
    this->edificio = nullptr;
    this->cambiar_objeto();
}

void Casillero::cambiar_objeto(){
    if(esta_libre()){
        this->caracter_elemento = this->tipo_casillero;
    }else{
        if(es_camino){
            //this->caracter_elemento = this->material->obtenerChar();
        }else{
            //this->caracter_elemento = this->edificio->obtenerChar();
        }
    }
}

unsigned int Casillero::obtener_costo_de_energia(){
    return this->costo_energia;
}