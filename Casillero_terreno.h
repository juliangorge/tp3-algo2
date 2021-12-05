#ifndef CASILLEROTERRENO_H
#define CASILLEROTERRENO_H

#include "Casillero.h"

class CasilleroTerreno : public Casillero
{
    public:
        CasilleroTerreno(unsigned int fila, unsigned int columna);
        //~CasilleroTerreno();
        bool esta_libre();
        void cambiar_objeto();
};

#endif //CASILLEROTERRENO_H
