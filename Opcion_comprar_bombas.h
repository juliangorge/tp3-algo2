#ifndef OPCION_COMPRAR_BOMBAS_H
#define OPCION_COMPRAR_BOMBAS_H

#include <string>
#include "Jugador.h"
#include "Interaccion_usuario.h"

using namespace std;

const unsigned int ENERGIA_COMPRAR_BOMBAS = 5;
const unsigned int PRECIO_BOMBA = 100;

estados_t comprar_bombas(Jugador* jugador);

void mostrar_compra_realizada(Jugador* jugador);

#endif //OPCION_COMPRAR_BOMBAS_H