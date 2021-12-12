#ifndef CASILLEROLAGO_H
#define CASILLEROLAGO_H

#include "Casillero.h"

class CasilleroLago : public Casillero
{
    public:
        CasilleroLago(unsigned int fila, unsigned int columna);

        // PRE: 
        // POST:        
        void cambiar_caracter();

        // PRE:
        // POST: Devuelve el nombre del casillero, si esta libre o, en caso contrario, que objeto contiene (jugador)
        void mostrar_casillero();

        // PRE:
        // POST:
        void limpiar_casillero();
};

#endif //CASILLEROLAGO_H
