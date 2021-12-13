#include "Casillero.h"

Casillero:: Casillero(unsigned int fila, unsigned int columna){
    this->edificio = nullptr;
    this->material = nullptr;
    this->fila = fila;
    this->columna = columna;
}

Casillero::~Casillero(){
    this->edificio = nullptr;
    this->material = nullptr;
}
    

unsigned int Casillero::obtener_fila(){
    return this->fila;
}
unsigned int Casillero::obtener_columna(){
    return this->columna;
}

bool Casillero::esta_libre()
{
    return this->caracter == this->caracter_casillero;
}

bool Casillero::no_tiene_jugador()
{
    return this->caracter_jugador != CARACTER_JUGADOR_UNO || this->caracter_jugador != CARACTER_JUGADOR_DOS;
}

bool Casillero::es_transitable()
{
    return this->es_camino;
}

Edificio* Casillero:: obtener_edificio(){
    return this->edificio;
}

Material* Casillero:: obtener_material(){
    return this->material;
}

char Casillero:: obtener_caracter(){
    return this->caracter;
}

char Casillero::obtener_caracter_casillero(){
    return this->caracter_casillero;
}

string Casillero::obtener_nombre_casillero(){
    return this->nombre_casillero;
}


void Casillero::cargar_edificio(Edificio* edificio, char caracter_jugador){
    
    this->edificio = edificio;
    this->caracter_jugador = caracter_jugador;
    cambiar_caracter();
    
}

void Casillero::cargar_material(Material* material){
    if(es_camino){
        this->material = material;
        cambiar_caracter();
    }
}

void Casillero::atacar_edificio(){
    
    if(this->edificio->obtener_contiene_escudo()){
        if(this->edificio->obtener_fue_atacado())
            limpiar_casillero();
        else
            this->edificio->cambio_estado_edificio();
    }
    else
        limpiar_casillero();
}

unsigned int Casillero::obtener_costo_energia(char jugador){

    unsigned int costo = 0;
    if(jugador == 'J')
        costo = this->costo_energia_J;
    else if(jugador == 'U')
        costo = this->costo_energia_U;
    
    return costo;
}

void Casillero::mostrar_edificio(){
    cout << this->obtener_edificio()->obtener_nombre() << endl;
    cout << "Coordenadas: (" << this->fila << ", " << this->columna << ") " << endl;
    cout << "Necesita reparación?: (" << (this->obtener_edificio()->obtener_fue_atacado() ? "Sí" : "No") << ")" << endl;
}

void Casillero::ocupar_casillero(char caracter)
{
    this->caracter = caracter;
    this->caracter_jugador = caracter;
}

estados_t Casillero::verificar_condiciones_construccion(char caracter_jugador)
{
    if(!es_terreno) return ST_ERROR_CASILLERO_NO_CONSTRUIBLE; 
    if(!esta_libre()) return ST_ERROR_CASILLERO_OCUPADO;
    return ST_OK;
}

estados_t Casillero::verificar_condiciones_demolicion(char caracter_jugador)
{
    if(!es_terreno) return ST_ERROR_CASILLERO_NO_CONSTRUIBLE; 
    if(esta_libre()) return ST_ERROR_CASILLERO_VACIO;
    if(this->caracter_jugador != caracter_jugador) return ST_ERROR_NO_ES_EDIFICIO_PROPIO;
    if(this->caracter == caracter_jugador) return ST_ERROR_CASILLERO_ES_JUGADOR;
    return ST_OK;
}

estados_t Casillero::verificar_condiciones_ataque(char caracter_jugador)
{
    if(!es_terreno) return ST_ERROR_CASILLERO_NO_CONSTRUIBLE; 
    if(esta_libre()) return ST_ERROR_CASILLERO_VACIO;
    if(this->caracter_jugador == caracter_jugador) return ST_ERROR_ES_EDIFICIO_PROPIO;
    if(this->caracter == this->caracter_jugador) return ST_ERROR_CASILLERO_ES_JUGADOR;
    return ST_OK;
}
