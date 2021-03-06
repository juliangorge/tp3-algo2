#ifndef CASILLEROCAMINO_H
#define CASILLEROCAMINO_H

#include "Casillero.h"

class CasilleroCamino : public Casillero
{
    public:

    	// PRE:
        // POST: Crea un objeto CasilleroCamino, guardando sus coordenadas del mapa
        CasilleroCamino(unsigned int fila, unsigned int columna);

        // PRE:
        // POST: Destruye un objeto CasilleroCamino
        ~CasilleroCamino();

        // PRE: Se debe haber referenciado el material
        // POST: Coloca en el casillero el caracter del material, para que éste se muestre en el mapa
        void cambiar_caracter();

        // PRE:
        // POST: Retornar el nombre del casillero, si esta libre o, en caso contrario, que objeto contiene (material/jugador)
        void mostrar_casillero();

        // PRE: Debe tener un material referenciado
        // POST: Desferencia el material, y coloca el caracter casillero 
        void limpiar_casillero();
};

#endif //CASILLEROCAMINO_H
