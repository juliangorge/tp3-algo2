#ifndef PRIMER_MENU_H
#define PRIMER_MENU_H

#include <iostream>

#include "Menu_consola.h"
#include "Interaccion_usuario.h"
#include "Mapa.h"

using namespace std;

// PRE:
// POST:
int trabajar_primer_menu(ABB<Edificio*> &arbol, Mapa* mapa);

// PRE:
// POST:
void opciones_primer_menu(int opcion, ABB<Edificio*> &arbol, Mapa* mapa);

// PRE: Se debe tener creado el ABB que contenga los edificios
// POST: Modifica los materiales requeridos del edificio ingresado por nombre. Devuelve error si el edificio ingresado no exite o si la cantidad ingresada no es válida
estados_t modificar_edificios(ABB<Edificio*> &arbol);

// PRE: Se debe tener creado el ABB que contenga los edificios
// POST: Devuelve todos los edificios que contiene el ABB con sus materiales requeridos, y su cantidad maximo posible de construicción
void listar_edificios(ABB<Edificio*> &arbol);

// PRE: Se deben tener creados los dos Jugadores, materiales.txt debe existir
// POST: Se trabaja con materiales.txt y se crea una lista de materiales en base a los nombres y cantidades de los mismos
void cargar_materiales_jugadores(Jugador* jugador_uno, Jugador* jugador_dos); 

#endif //PRIMER_MENU_H
