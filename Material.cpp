#include "Material.h"

Material::Material(string nombre, unsigned int cantidad)
{
    this->nombre = nombre;
    this->cantidad = cantidad;
    this->establecer_caracter();
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

void Material::establecer_caracter()
{
    switch(nombre[0]){
        case 'm':
            if(nombre == NOMBRE_MADERA)
                this->caracter = CARACTER_MADERA;
            else
                this->caracter = CARACTER_METAL;
            break;
        case 'p':
            this->caracter = CARACTER_PIEDRA;
            break;
        case 'a':
            this->caracter = CARACTER_ANDYCOINS;
            break;
        default:
            this->caracter = CARACTER_NO_IDENTIFICADO;
            break;
    }
}

void Material::sumar_materiales(unsigned int sumar_cantidad)
{
    this->cantidad += sumar_cantidad;
}

void Material::restar_materiales(unsigned int restar_cantidad)
{
    this->cantidad -= restar_cantidad;
}