#ifndef INICIO_JUEGO_H
#define INICIO_JUEGO_H

#include <iostream>
#include "Interaccion_usuario.h"
#include "Primer_menu.h"
#include "Segundo_menu.h"
#include "mapa.h"
#include "Jugador.h"

using namespace std;

void iniciar_juego();

void cargar_edificios(ABB<Edificio*> &arbol);
void agregar_edificio(ABB<Edificio*> &arbol, string nombre, Edificio* edificio);

#endif //INICIO_JUEGO_H