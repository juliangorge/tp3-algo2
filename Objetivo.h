#ifndef OBJETIVO__H
#define OBJETIVO__h

#include "Jugador.h"
#include <string>
using namespace std;

const int MINAS_METAL_OBJETIVO = 1;
const int MINAS_ORO_OBJETIVO = 1;
const int CANTIDAD_ANDYCOINS_OBJETIVO = 100000;
const int CANTIDAD_PIEDRA_OBJETIVO = 500;
const int BOMBAS_USADAS_OBJETIVO = 5;
const int CANTIDAD_CANSADO_OBJETIVO = 0;
const int CANTIDAD_ARMADO_OBJETIVO = 10;
const int CANTIDAD_EXTREMISTA_OBJETIVO = 500;


typedef enum {
    COMPRAR_ANDYPOLIS=1,
    EDAD_PIEDRA,
    BOMBARDERO,
    ENERGETICO,
    LETRADO,
    MINERO,
    CANSADO,
    CONSTRUCTOR,
    ARMADO,
    EXTREMISTA
    }objetivos;


#endif