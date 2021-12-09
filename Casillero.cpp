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

estados_t Casillero::verificar_condiciones_construccion(char caracter_jugador)
{
    if(!es_terreno) return ST_ERROR_CASILLERO_NO_CONSTRUIBLE; 
    if(!esta_libre()) return ST_ERROR_CASILLERO_OCUPADO;
    return ST_OK;
}

void Casillero:: cargar_edificio(Edificio* edificio, char caracter_jugador){
    
    this->edificio = edificio;
    this->caracter_jugador = caracter_jugador;
    cambiar_caracter();
    
}

estados_t Casillero::verificar_condiciones_demolicion(char caracter_jugador)
{
    if(!es_terreno) return ST_ERROR_CASILLERO_NO_CONSTRUIBLE; 
    if(esta_libre()) return ST_ERROR_CASILLERO_VACIO;
    if(this->caracter_jugador != caracter_jugador) return ST_ERROR_NO_ES_EDIFICIO_PROPIO;
    return ST_OK;
}

void Casillero:: cargar_material(Material* material){
    if(es_camino){
        this->material = material;
        cambiar_caracter();
    }
}

unsigned int Casillero:: obtener_costo_energia(char jugador){

    unsigned int costo = 0;
    if(jugador == 'J')
        costo = this->costo_energia_J;
    else if(jugador == 'U')
        costo = this->costo_energia_U;
    
    return costo;
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