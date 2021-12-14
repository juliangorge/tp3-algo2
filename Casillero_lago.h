#ifndef CASILLEROLAGO_H
#define CASILLEROLAGO_H

#include "Casillero.h"

class CasilleroLago : public Casillero
{
    public:
        
        // PRE:
        // POST: Crea un objeto CasilleroLago, guardando sus coordenadas del mapa
        CasilleroLago(unsigned int fila, unsigned int columna);

        // PRE:
        // POST: Destruye un objeto CasilleroLago
        ~CasilleroLago();

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

#endif //CASILLEROLAGO_H
