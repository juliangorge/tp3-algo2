#include <iostream>
#include <fstream>
#include <string>

#include "casillero.h"
#include "casillero_construible.h"

using namespace std;

Casillero_construible::Casillero_construible(char caracter)
{
    this->caracter = caracter;

    this->edificio = nullptr;

    this->transitable=false;
    this->construible=true;
    this->inaccesible=false;
}

void Casillero_construible::agregar_edificio(Edificio * edificio)
{
    if(!this->edificio)
        this->edificio = edificio;
}

void Casillero_construible::eliminar_edificio()
{   
    if(!this->edificio)
        delete (this->edificio);

    this->edificio = nullptr;
}

Edificio * Casillero_construible::consultar_edificio()
{
    return this->edificio;
}


void Casillero_construible::imprimir_estado()
{
    if(edificio)
        cout << MSJE_CASILLERO_CONSTRUIBLE_OCUPADO << this->edificio->obtener_nombre();
    else
        cout << MSJE_CASILLERO_CONSTRUIBLE_VACIO << endl;
    
}
