#ifndef PRIMER_MENU_H
#define PRIMER_MENU_H

#include <iostream>
#include "menu_consola.h"
#include "interaccion_usuario.h"
#include "mapa.h"

const int OPCION_MODIFICAR_EDIFICIOS = 1;
const int OPCION_LISTAR_EDIFICIOS = 2;
const int OPCION_MOSTRAR_MAPA = 3;
const int OPCION_COMENZAR_PARTIDA = 4;
const int OPCION_SALIR_PRIMER_MENU = 5;

using namespace std;
int trabajar_primer_menu();
void opciones_primer_menu(int opcion,Mapa* mapa);

#endif //PRIMER_MENU_H
