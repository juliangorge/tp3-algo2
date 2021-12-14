#ifndef INTERACCION_USUARIO_H
#define INTERACCION_USUARIO_H

#include <iostream>
#include "Mensajes_de_error.h"
#include "Mapa.h"
#include "Constantes.h"

using namespace std;

// PRE: Los valores mínimo y máximo deben ser valores positivos
// POST: Devuelve un número contemplado entre las cotas minimas y maximas dadas por parámetro
unsigned int obtener_numero_por_consola(unsigned int valor_minimo, unsigned int valor_maximo);

// PRE: Los valores mínimo y máximo deben ser valores positivos
// POST: Devuelve OK si se genera un número contemplado entre las cotas minimas y maximas dadas por parámetro, caso contrario da error
estados_t obtener_valor_cantidad(unsigned int & cantidad, unsigned int cantidad_minima, unsigned int cantidad_maxima);

// PRE: Se debe haber ingresado un valor por consola
// POST: Verifica si el valor ingresado por consola es un número
bool es_numero(const string& valor);

// PRE: Se debe tener cargado el Mapa
// POST: Devuelve OK si las coordenadas ingresadas son numeros y son menores a la cantidad y filas y columnas del mapa
estados_t obtener_coordenadas(Mapa* mapa, unsigned int & fila, unsigned int & columna);

// PRE: 
// POST: Se le pide al usuario que ingrese el caracter 'Y' o 'y' para confirmar. Caso contrario se cancela la acción
estados_t pedido_confirmacion();

// PRE: 
// POST: Devuelve el nombre de edificio a trabajar
string ingresar_nombre();

#endif //INTERACCION_USUARIO_H