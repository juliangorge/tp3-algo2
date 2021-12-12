#ifndef PRIMER_MENU_H
#define PRIMER_MENU_H

#include <iostream>
#include "Menu_consola.h"
#include "Interaccion_usuario.h"
#include "Mapa.h"
#include "Mensajes_de_error.h"
#include "Constantes.h"


#include "ABB.h"
#include "ABB_nodo.h"
#include "Edificio.h"
#include "Constantes.h"


using namespace std;
int trabajar_primer_menu(ABB<Edificio*> &arbol, Mapa* mapa);
void opciones_primer_menu(int opcion, ABB<Edificio*> &arbol, Mapa* mapa);

estados_t modificar_edificios(ABB<Edificio*> &arbol);
void listar_edificios(ABB<Edificio*> &arbol);

#endif //PRIMER_MENU_H
