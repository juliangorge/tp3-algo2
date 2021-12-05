#ifndef CASILLEROMUELLE_H
#define CASILLEROMUELLE_H

#include "Casillero.h"

class CasilleroMuelle : public Casillero
{
    public:
        CasilleroMuelle(unsigned int fila, unsigned int columna);
        // ~CasilleroMuelle();
        bool esta_libre();
        void cambiar_objeto();
};

#endif //CASILLEROMUELLE_H
