#ifndef DESPLAZAMIENTO_H
#define DESPLAZAMIENTO_H

#include <iostream>
#include "Jugador.h"

void moverse_coordenada(Jugador *jugador);

//PRE: recibe el jugador con su ubicación y el
//POST: devuelve lo que cuesta desplazarse al objetivo
//unsigned int calcular_energia_desplazamiento(Jugador *jugador);

void pedir_punto_final(int *x, int*y);

#endif //DEZPLAZAMIENTO_H