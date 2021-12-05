#ifndef CASILLEROLAGO_H
#define CASILLEROLAGO_H

#include "Casillero.h"

class CasilleroLago : public Casillero
{
    public:
        CasilleroLago(unsigned int fila, unsigned int columna);
        //~CasilleroLago();
        bool esta_libre();
        void cambiar_objeto();
};

#endif //CASILLEROLAGO_H
