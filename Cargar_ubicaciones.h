#ifndef UBICACIONES_H
#define UBICACIONES_H

#include <iostream>
#include <string>
#include "Mapa.h"
#include "Jugador.h"
#include "ABB.h"
#include "Parser.h"
#include "Constantes.h"

void cargar_ubicaciones (Jugador*& jugador_uno, Jugador*& jugador_dos, ABB<Edificio*>& arbol, Mapa*& mapa);

int validar_linea(char *aux);

#endif