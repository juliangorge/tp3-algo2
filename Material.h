#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string NOMBRE_MADERA = "madera";
const string NOMBRE_PIEDRA = "piedra";
const string NOMBRE_METAL = "metal";
const string NOMBRE_BOMBAS = "bombas";
const string NOMBRE_ANDYCOINS = "andycoins";
const char CARACTER_MADERA = 'W';
const char CARACTER_PIEDRA = 'S';
const char CARACTER_METAL = 'I';
const char CARACTER_ANDYCOINS = 'C';
const char CARACTER_BOMBAS = '#';
const char CARACTER_NO_IDENTIFICADO = '#';

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
        // PRE: -
        // POS: crea un objeto del tipo material con nombre, cantidad y letra identificatoria especificados.
         Material(string nombre, unsigned int cantidad);

        // PRE: -
        // POS: devuelve el nombre
        string obtener_nombre();

        // PRE: -
        // POS: devuelve el caracter identificatorio
        char obtener_caracter();

        // PRE: -
        // POS: devuelve la cantidad
        unsigned obtener_cantidad();

        // PRE: -
        // POS: suma la cantidad de materiales espècificada al atributo
        void sumar_materiales(unsigned int sumar_cantidad);

        // PRE: debe haber la cantidad de materiales especificada o más
        // POS: resta la cantidad de materiales especificada al atributo
        void restar_materiales(unsigned int restar_cantidad);
};


#endif