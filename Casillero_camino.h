#ifndef CASILLEROCAMINO_H
#define CASILLEROCAMINO_H

#include "Casillero.h"

class CasilleroCamino : public Casillero
{
    public:
        CasilleroCamino(unsigned int fila, unsigned int columna);
        //~CasilleroCamino();
        void cambiar_caracter();
        void mostrar_casillero();
        void limpiar_casillero();
};

#endif //CASILLEROCAMINO_H
