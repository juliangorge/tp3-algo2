#ifndef INTERACCION_USUARIO_H
#define INTERACCION_USUARIO_H

#include <iostream>
#include "Mensajes_de_error.h"
#include "Mapa.h"
#include "Constantes.h"

using namespace std;
int obtener_opcion_primer_menu();
int obtener_opcion_segundo_menu();
int obtener_numero_jugador();
estados_t obtener_valor_cantidad(unsigned int & cantidad);

bool es_numero(const string& s);

estados_t obtener_coordenadas(Mapa* mapa, unsigned int & fila, unsigned int & columna);

estados_t pedido_confirmacion();

string ingresar_nombre();

#endif //INTERACCION_USUARIO_H