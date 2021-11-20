#include <iostream>
#include <fstream>
#include <string>

#include "material.h"

using namespace std;

Material::Material(string nombre, unsigned cantidad)
{
    this->nombre = nombre;
    this->cantidad = cantidad;

    if(nombre == STRING_MADERA)
        this->letra_identificatoria = CARACTER_MADERA;
    else if(nombre == STRING_PIEDRA)
        this->letra_identificatoria = CARACTER_PIEDRA;
    else if(nombre == STRING_METAL)
        this->letra_identificatoria = CARACTER_METAL;
    else if(nombre == STRING_ANDYCOINS)
        this->letra_identificatoria = CARACTER_ANDYCOINS;
    else if(nombre == STRING_BOMBAS)
        this->letra_identificatoria = CARACTER_BOMBAS;
    else
        this->letra_identificatoria = CARACTER_NO_IDENTIFICADO;
}

string Material::obtener_nombre()
{
    return nombre;
}

char Material::obtener_letra_identificatoria()
{
    return letra_identificatoria;
}

unsigned Material::obtener_cantidad()
{
    return cantidad;
}

void Material::sumar_materiales(unsigned sumar_cantidad)
{
    cantidad += sumar_cantidad;
}

void Material::restar_materiales(unsigned restar_cantidad)
{
    cantidad -= restar_cantidad;
}