#ifndef INICIO_JUEGO_H
#define INICIO_JUEGO_H

#include <iostream>
#include "Interaccion_usuario.h"
#include "Primer_menu.h"
#include "Segundo_menu.h"
#include "Mapa.h"
#include "Jugador.h"
#include "ABB.h"
#include "ABB_nodo.h"
#include "Edificio.h"
#include "Objetivo.h"
using namespace std;

void iniciar_juego();

void cargar_edificios(ABB<Edificio*> &arbol);
void agregar_edificio(ABB<Edificio*> &arbol, string nombre, Edificio* edificio);

#endif //INICIO_JUEGO_H