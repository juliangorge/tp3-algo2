#include "Material.h"

Material::Material(string nombre, unsigned int cantidad)
{
    this->nombre = nombre;
    this->cantidad = cantidad;

    if(nombre == NOMBRE_MADERA)
        this->caracter = CARACTER_MADERA;
    else if(nombre == NOMBRE_PIEDRA)
        this->caracter = CARACTER_PIEDRA;
    else if(nombre == NOMBRE_METAL)
        this->caracter = CARACTER_METAL;
    else if(nombre == NOMBRE_ANDYCOINS)
        this->caracter = CARACTER_ANDYCOINS;
    else if(nombre == NOMBRE_BOMBAS)
        this->caracter = CARACTER_BOMBAS;
    else
        this->caracter = CARACTER_NO_IDENTIFICADO;
}

string Material::obtener_nombre()
{
    return this->nombre;
}

char Material::obtener_caracter()
{
    return this->caracter;
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