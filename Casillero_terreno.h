#ifndef CASILLEROTERRENO_H
#define CASILLEROTERRENO_H

#include "Casillero.h"

class CasilleroTerreno : public Casillero
{
    public:
        CasilleroTerreno(unsigned int fila, unsigned int columna);
        //~CasilleroTerreno();
        void cambiar_objeto();
        void mostrar_casillero();

};

#endif //CASILLEROTERRENO_H
