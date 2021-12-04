#ifndef INTERACCION_USUARIO_H
#define INTERACCION_USUARIO_H

#include <iostream>
#include "Mensajes_de_error.h"
#include "Mapa.h"

const int PRIMER_CARACTER = 0;
const int SEGUNDO_CARACTER = 1;
const int TERCER_CARACTER = 2;

const unsigned int CANTIDAD_MINIMA = 0;
const unsigned int CANTIDAD_MAXIMA = 50000;

using namespace std;
int obtener_opcion_primer_menu();
int obtener_opcion_segundo_menu();
int obtener_numero_jugador();
estados_t obtener_valor_cantidad(unsigned int & cantidad);

bool es_numero(const string& s);

//bool consultar_coordenadas(Mapa* mapa, unsigned int & fila, unsigned int & columna);
estados_t consultar_coordenadas(Mapa* mapa, unsigned int & fila, unsigned int & columna);

#endif //INTERACCION_USUARIO_H