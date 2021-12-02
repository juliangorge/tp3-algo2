#include <iostream>
#include <fstream>
#include <string>

#include "casillero.h"
#include "casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable(char caracter)
{
    this->caracter = caracter;

    material = nullptr;

    this->transitable=true;
    this->construible=false;
    this->inaccesible=false;
    
}

void Casillero_transitable::agregar_material(Material * material)
{
    if(!this->material)
        this->material = material;
}

void Casillero_transitable::eliminar_material()
{   
    if(!this->material)
        delete (this->material);

    this->material = nullptr;
}

Material * Casillero_transitable::consultar_material()
{
    return this->material;
}

void Casillero_transitable::imprimir_estado()
{
    if(this->material)
    {
        cout << MSJE_CASILLERO_LLENO << this->material->obtener_cantidad() << " de " << this->material->obtener_nombre() << endl;
    }
    else
    {
        cout << MSJE_CASILLERO_VACIO << endl;
    }
}