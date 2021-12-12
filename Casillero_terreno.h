#ifndef CASILLEROTERRENO_H
#define CASILLEROTERRENO_H

#include "Casillero.h"

class CasilleroTerreno : public Casillero
{
    public:

    	// PRE:
        // POST: Crea un objeto CasilleroTerreno, guardando sus coordenadas del mapa
        CasilleroTerreno(unsigned int fila, unsigned int columna);

        // PRE: Se debe haber referenciado el edificio
        // POST: Coloca en el casillero el caracter del edificio, para que éste se muestre en el mapa
        void cambiar_caracter();

        // PRE:
        // POST: Devuelve el nombre del casillero, si esta libre o, en caso contrario, que objeto contiene (edificio/jugador)
        void mostrar_casillero();

        // PRE: Debe tener un edificio referenciado
        // POST: Desferencia el edificio, y coloca el caracter casillero 
        void limpiar_casillero();

};

#endif //CASILLEROTERRENO_H
