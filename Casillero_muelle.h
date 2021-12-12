#ifndef CASILLEROMUELLE_H
#define CASILLEROMUELLE_H

#include "Casillero.h"

class CasilleroMuelle : public Casillero
{
    public:

    	// PRE:
        // POST: Crea un objeto CasilleroMuelle, guardando sus coordenadas del mapa
        CasilleroMuelle(unsigned int fila, unsigned int columna);

        // PRE: Se debe haber referenciado el material
        // POST: Coloca en el casillero el caracter del material, para que éste se muestre en el mapa
        void cambiar_caracter();

        // PRE:
        // POST: Devuelve el nombre del casillero, si esta libre o, en caso contrario, que objeto contiene (material/jugador)
        void mostrar_casillero();

        // PRE: Debe tener un material referenciado
        // POST: Desferencia el material, y coloca el caracter casillero 
        void limpiar_casillero();
};

#endif //CASILLEROMUELLE_H
