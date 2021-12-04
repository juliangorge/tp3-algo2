#include "Casillero.h"

Casillero:: Casillero(){
    this->edificio = nullptr;
    this->material = nullptr;
}

unsigned int Casillero:: obtener_fila(){
    return this->fila;
}
unsigned int Casillero:: obtener_columna(){
    return this->columna;
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
        //this->caracter = this->tipo_casillero;
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

bool Casillero:: es_construible(){
    return (this->esta_libre() && this->es_terreno && this->edificio == nullptr);
}

/*
Listar mis edificios construidos
Se deberán listar todos los edificios construidos por el jugador que lo solicite, es decir,
que haya por lo menos un edificio de este tipo indicando cuántos hay construidos de cada uno, las coordenadas en las que se encuentran y si necesitan o no reparación.
Energía necesaria: 0
*/

void Casillero:: mostrar_coordenadas_de_edificio_por_jugador(char caracter_jugador){
    if(caracter_jugador != this->caracter_jugador || this->obtener_edificio() == NULL) return;

    cout << this->obtener_edificio()->obtener_nombre() << " Coordenadas: (" << this->fila << ", " << this->columna << ") " << endl;

    /// Acá va la impresión del edificio
}