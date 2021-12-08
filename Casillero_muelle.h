#ifndef CASILLEROMUELLE_H
#define CASILLEROMUELLE_H

#include "Casillero.h"

class CasilleroMuelle : public Casillero
{
    public:
        CasilleroMuelle(unsigned int fila, unsigned int columna);
        // ~CasilleroMuelle();
        void cambiar_caracter();
        void mostrar_casillero();
        void limpiar_casillero();
};

#endif //CASILLEROMUELLE_H
