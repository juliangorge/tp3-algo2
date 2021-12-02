#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "casillero.h"
#include "Edificio.h"

#include <string>

const string MSJE_CASILLERO_CONSTRUIBLE_VACIO = "Soy un casillero construible y me encuentro vacio :(";
const string MSJE_CASILLERO_CONSTRUIBLE_OCUPADO = "Soy un casillero construible y estoy ocupado por: ";

class Casillero_construible: public Casillero
{
// Atributos
private:
    Edificio * edificio;

// Metodos
public:
    // Constructor
    // PRE: -
    // POS: construye el objeto del tipo casillero_construible
    Casillero_construible(char caracter);

    // PRE: -
    // POS: imprime por pantalla el estado del casillero
    void imprimir_estado();

    // PRE: el casillero debe estar vacío
    // POS: si el casillero está vacío, agrega el edificio. Si no, ingora la petición
    void agregar_edificio(Edificio * edificio);

    // PRE: debe existir un edificio en el casillero
    // POS: elimina el edificio y libera memoria
    void eliminar_edificio();

    // PRE: -
    // POS: retorna el puntero al edificio, o null si no hay nada.
    Edificio * consultar_edificio();


};


#endif