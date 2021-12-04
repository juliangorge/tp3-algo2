#ifndef CASILLEROCAMINO_H
#define CASILLEROCAMINO_H

#include "Casillero.h"

class CasilleroCamino : public Casillero
{
    public:
        CasilleroCamino(unsigned int fila, unsigned int columna);
        //~CasilleroCamino();
        bool esta_libre();
        void cambiar_objeto();
};

#endif //CASILLEROCAMINO_H
