#ifndef CASILLEROBETUN_H
#define CASILLEROBETUN_H

#include "Casillero.h"

class CasilleroBetun : public Casillero
{
    public:
        CasilleroBetun(unsigned int fila, unsigned int columna);
        //~CasilleroBetun();
        void cambiar_caracter();
        void mostrar_casillero();
        void limpiar_casillero();
};

#endif //CASILLEROBETUN_H
