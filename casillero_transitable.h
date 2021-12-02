#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "casillero.h"
#include "Material.h"

#include <string>

const string MSJE_CASILLERO_LLENO = "Soy un casillero transitable y tengo: ";
const string MSJE_CASILLERO_VACIO = "Soy un casillero transitable y me encueuntro vacío :(";

class Casillero_transitable: public Casillero
{
// Atributos
private:
    Material * material;
// Metodos
public:
    // Constructor
    // PRE: -
    // POS: construye el objeto del tipo casillero_transitable
    Casillero_transitable(char caracter);

    // PRE: el casillero no debe tener un material
    // POS: si el casillero no tenía material, agrega el material. Si no, ignora la petición.
    void agregar_material(Material * material);

    // PRE: -
    // POS: si existe material lo elimina y libera la memoria.
    void eliminar_material();

    // PRE: -
    // POS: devuelve el material alojado en él, o nullptr si no hay nada.
    Material * consultar_material();

    // PRE: -
    // POS: imprime por pantalla el estado del casillero
    void imprimir_estado();
};


#endif