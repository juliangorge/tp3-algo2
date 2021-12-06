#ifndef CASILLEROCAMINO_H
#define CASILLEROCAMINO_H

#include "Casillero.h"

class CasilleroCamino : public Casillero
{
    public:
        CasilleroCamino(unsigned int fila, unsigned int columna);
        //~CasilleroCamino();
        void cambiar_objeto();
};

#endif //CASILLEROCAMINO_H
