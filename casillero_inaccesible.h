#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "casillero.h"


class Casillero_inaccesible: public Casillero
{
    
// Metodos
public:
    // Constructor
    // PRE: -
    // POS: construye el objeto del tipo casillero_inaccesible
    Casillero_inaccesible(char caracter);

    // // PRE: -
    // // POS: devuelve lo que hay alojado en él, o null si está vacío
    // Edificio * obtener_edificio();

    // PRE: el casillero debe estar vacío y debe haber materiales suficientes
    // POS: retorna true si pudo construir el edificio, false en caso contrario
    //bool constuir_edificio(Edificio * edificio);

    // PRE: -
    // POS: retorna true si había un edificio y lo destruyó, false si no había edificio
    //bool destruir_edificio()
};


#endif