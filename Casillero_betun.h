#ifndef CASILLEROBETUN_H
#define CASILLEROBETUN_H

#include "Casillero.h"

class CasilleroBetun : public Casillero
{
    public:
        CasilleroBetun(unsigned int fila, unsigned int columna);
        //~CasilleroBetun();
        void cambiar_objeto();
};

#endif //CASILLEROBETUN_H
