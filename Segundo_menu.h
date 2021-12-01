#ifndef SEGUNDO_MENU_H
#define SEGUNDO_MENU_H

#include <iostream>
#include "Menu_consola.h"
#include "Interaccion_usuario.h"
//#include "Mapa.h"
#include "Jugador.h"

const int OPCION_CONSTRUIR_EDIFICIO = 1;
const int OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int OPCION_DEMOLER_COORDENADA = 3;
const int OPCION_ATACAR_EDIFICIO = 4;
const int OPCION_REPARAR_EDIFICIO = 5;
const int OPCION_COMPRAR_BOMBAS = 6;
const int OPCION_CONSULTAR_COORDENADA = 7;
const int OPCION_MOSTRAR_INVENTARIO = 8;
const int OPCION_MOSTRAR_OBJETIVOS = 9;
const int OPCION_RECOLECTAR_RECURSOS = 10;
const int OPCION_MOVERSE_A_COORDENADA = 11;
const int OPCION_FINALIZAR_TURNO = 12;
const int OPCION_SALIR_SEGUNDO_MENU = 13;

using namespace std;
void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos);
void opciones_segundo_menu(int opcion, Jugador* jugador);

#endif //SEGUNDO_MENU_H
