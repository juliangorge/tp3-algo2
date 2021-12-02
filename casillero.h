#ifndef CASILLERO_H
#define CASILLERO_H

#include <string>

using namespace std;

class Casillero
{
    protected:
        string nombre;
        char caracter;
        bool transitable;
        bool inaccesible;
        bool construible;
        bool casillero_ocupado;
        int jugador;

    public:
        // PRE: -
        // POS: devuelve el caracter identificatorio del casillero
        char obtener_caracter();

        // PRE: -
        // POS: retorna true si es transitable, false si no lo es
        bool es_transitable();

        // PRE: -
        // POS: retorna true si es inaccesible, false si no lo es
        bool es_inaccesible();

        // PRE: -
        // POS: retorna true si es construible, false si no lo es
        bool es_construible();

        // PRE: -
        // POS: Cambia el valor de un casillero según el objeto que lo ocupe
        void cambiar_objeto(string nombre, char tipo_objeto, int jugador);

};


#endif