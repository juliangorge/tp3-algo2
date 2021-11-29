#ifndef MENUS_H
#define MENUS_H

//#include <iostream>
#include "Andypolis.h"

const int EXIT_OPTION = 10;

/*const int FIRST_POS = 0;
const int SECOND_POS = 1;
const int THIRD_POS = 2;*/

using namespace std;

// PRE:
// POST: Ejecuta el menu
void ejecutarMenu();

// PRE:
// POST: Muestra las opciones de menu
void mostrarOpciones();

// PRE:
// POST: Se solicita el ingreso de la opcion
int obtenerOpcion();

// PRE: Recibe city y la respuesta
// POST: Se ejecuta la opcion seleccionada
void opcionSeleccionada(Andypolis& city, int answer);

#endif //MENU_H