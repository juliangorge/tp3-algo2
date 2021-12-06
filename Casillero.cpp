#include "Casillero.h"

Casillero:: Casillero(unsigned int fila, unsigned int columna){
    this->edificio = nullptr;
    this->material = nullptr;
    

    this->fila = fila;
    this->columna = columna;
}

bool Casillero::esta_libre()
{
    return this->caracter == this->caracter_casillero;
}

unsigned int Casillero:: obtener_fila(){
    return this->fila;
}
unsigned int Casillero:: obtener_columna(){
    return this->columna;
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

char Casillero:: obtener_caracter_casillero(){
    return this->caracter_casillero;
}

estados_t Casillero:: cargar(Edificio* edificio, char caracter_jugador){
    estados_t st = ST_OK;
    if(!es_terreno) return ST_ERROR_CASILLERO_NO_CONSTRUIBLE; 
    else if(!esta_libre()) return ST_ERROR_CASILLERO_OCUPADO;
    this->edificio = edificio;
    this->caracter_jugador = caracter_jugador;
    cambiar_objeto();
    return st;
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

/*void Casillero:: cambiar_objeto(){
    if(esta_libre()){
        //this->caracter = this->tipo_casillero;
    }else{
        if(es_camino){
            this->caracter = this->material->obtener_caracter();
        }else{
            this->caracter = this->edificio->obtener_caracter();
        }
    }
}*/

unsigned int Casillero:: obtener_costo_de_energia(){
    return this->costo_energia;
}

bool Casillero:: es_construible(){
    return (this->es_terreno && this->edificio == nullptr);
}

void Casillero:: mostrar_edificios(){
    cout << this->obtener_edificio()->obtener_nombre() << endl;
    cout << "Coordenadas: (" << this->fila << ", " << this->columna << ") " << endl;
    cout << "Necesita reparación?: (" << (this->necesita_reparacion ? "Sí" : "No") << ")" << endl;
}

void Casillero::ocupar_casillero(char caracter)
{
    this->caracter = caracter;
}