#include <iostream>
#include <fstream>
#include <string>

#include "Material.h"

using namespace std;

Material::Material(string nombre, unsigned int cantidad)
{
    this->nombre = nombre;
    this->cantidad = cantidad;

    if(nombre == NOMBRE_MADERA)
        this->letra_identificatoria = CARACTER_MADERA;
    else if(nombre == NOMBRE_PIEDRA)
        this->letra_identificatoria = CARACTER_PIEDRA;
    else if(nombre == NOMBRE_METAL)
        this->letra_identificatoria = CARACTER_METAL;
    else if(nombre == NOMBRE_ANDYCOINS)
        this->letra_identificatoria = CARACTER_ANDYCOINS;
    else if(nombre == NOMBRE_BOMBAS)
        this->letra_identificatoria = CARACTER_BOMBAS;
    else
        this->letra_identificatoria = CARACTER_NO_IDENTIFICADO;
}

string Material::obtener_nombre()
{
    return this->nombre;
}

char Material::obtener_letra_identificatoria()
{
    return this->letra_identificatoria;
}

unsigned Material::obtener_cantidad()
{
    return this->cantidad;
}

void Material::sumar_materiales(unsigned int sumar_cantidad)
{
    this->cantidad += sumar_cantidad;
}

void Material::restar_materiales(unsigned int restar_cantidad)
{
    this->cantidad -= restar_cantidad;
}