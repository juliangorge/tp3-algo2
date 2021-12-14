#ifndef INICIO_JUEGO_H
#define INICIO_JUEGO_H

#include <iostream>
#include "Primer_menu.h"
#include "Segundo_menu.h"
using namespace std;

// PRE: Se deben cargar correctarmente los archivos mapa.txt edificios.txt y materiales.txt
// POST: Carga el mapa, arbol, y jugadores y empieza con el juego
void iniciar_juego();

// PRE: Se debe cargar correctamente el  edificios.txt
// POST: Crea un objeto edificio a partir del archivo
void cargar_edificios(ABB<Edificio*> &arbol);

// PRE: Se debe cargar correctamente el  edificios.txt
// POST: Agrega al ABB un edificio
void agregar_edificio(ABB<Edificio*> &arbol, string nombre, Edificio* edificio);

// PRE: 
// POST: Guarda materiales.txt los materiales de ambos jugadores
void guardar_materiales(Jugador *jugador_uno, Jugador *jugador_dos);

// PRE: 
// POST: Guarda en ubicaciones.txt los materiales del mapa y los edificios construidos por los jugadores
void guardar_ubicaciones(Mapa* & mapa, Jugador* jugador_uno, Jugador* jugador_dos);

// PRE:
// POST: Se verifica si algun jugador cumplio con los objetivos dados
void analizar_ganador(Jugador*& jugador_uno, Jugador*& jugador_dos);

#endif //INICIO_JUEGO_H