#ifndef CASILLEROLAGO_H
#define CASILLEROLAGO_H

#include "Casillero.h"

class CasilleroLago : public Casillero
{
    public:
        CasilleroLago(unsigned int fila, unsigned int columna);
        //~CasilleroLago();
        void cambiar_caracter();
        void mostrar_casillero();
        void limpiar_casillero();
};

#endif //CASILLEROLAGO_H
