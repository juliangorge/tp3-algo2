#ifndef INICIO_JUEGO_H
#define INICIO_JUEGO_H

#include <iostream>
#include "Primer_menu.h"
#include "Segundo_menu.h"
using namespace std;

void iniciar_juego();

void cargar_edificios(ABB<Edificio*> &arbol);
void agregar_edificio(ABB<Edificio*> &arbol, string nombre, Edificio* edificio);

void guardar_materiales(Jugador *jugador_uno, Jugador *jugador_dos, Mapa *mapa);

#endif //INICIO_JUEGO_H