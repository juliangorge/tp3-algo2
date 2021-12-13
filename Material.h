#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <fstream>
#include <string>

#include "Constantes.h"

using namespace std;

class Material
{
    // Atributos
    private:
        string nombre;
        char caracter;
        unsigned int cantidad;

    // Metodos
    public:
        // Constructor
        // PRE: Debe haber al menos un material en el archivo materiales.txt
        // POS: Crea un objeto del tipo Material con nombre, cantidad y letra identificatoria especificados
         Material(string nombre, unsigned int cantidad);

        // PRE: -
        // POS: Devuelve el nombre
        string obtener_nombre();

        // PRE: -
        // POS: Devuelve el caracter identificatorio
        char obtener_caracter();

        // PRE: -
        // POS: Devuelve la cantidad
        unsigned obtener_cantidad();

        // PRE: -
        // POS: Establece el caracter del material en base a su nombre.
        void establecer_caracter();

        // PRE: -
        // POS: Suma la cantidad de materiales espècificada al atributo
        void sumar_materiales(unsigned int sumar_cantidad);

        // PRE: Debe haber la cantidad de materiales especificada o más
        // POS: Resta la cantidad de materiales especificada al atributo
        void restar_materiales(unsigned int restar_cantidad);
};

#endif