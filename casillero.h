#ifndef CASILLERO_H
#define CASILLERO_H

#include <string>

using namespace std;

class Casillero
{
    protected:
        char caracter;
        bool transitable;
        bool inaccesible;
        bool construible;

    public:
        // PRE: -
        // POS: devuelve el caracter identificatorio del casillero
        char obtener_caracter();

        // PRE: -
        // POS: retorna true si es transitable, false si no lo es
        bool es_transitable() ;

        // PRE: -
        // POS: retorna true si es inaccesible, false si no lo es
        bool es_inaccesible() ;

        // PRE: -
        // POS: retorna true si es construible, false si no lo es
        bool es_construible() ;

        // PRE: -
        // POS: imprime por pantalla el estado del casillero
        virtual void imprimir_estado() = 0;

};


#endif