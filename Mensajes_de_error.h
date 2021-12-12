#ifndef MENSAJES_DE_MSJ_ERROR_H
#define MENSAJES_DE_MSJ_ERROR_H

#include <iostream>
#include <string>

using namespace std;

const string MSJ_ERROR_OPCION_INVALIDA = "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
const string MSJ_ERROR_CANTIDAD_INVALIDA = "La cantidad ingresada no es valida, debe ser un valor entre 0 y 50000";
const string MSJ_ERROR_NOMBRE_INVALIDO = "El nombre del edificio ingresado no es valido";
const string MSJ_ERROR_COORDENADAS_INVALIDAS = "Las coordenadas ingresadas no son validas";
const string MSJ_ERROR_MAXIMO_SUPERADO = "Se tiene construida la máxima cantidad del edificio seleccionado";
const string MSJ_ERROR_CASILLERO_NO_CONSTRUIBLE = "El casillero seleccionado no es un casillero construible";
const string MSJ_ERROR_CASILLERO_OCUPADO = "El casillero construible seleccionado se encuentra ocupado";
const string MSJ_ERROR_MATERIALES_INSUFICIENTES = "No se tienen materiales suficientes para realizar la construcción de edificio seleccionado";
const string MSJ_ERROR_CASILLERO_VACIO = "El casillero construible seleccionado se encuentra vacío";
const string MSJ_ERROR_NO_ES_EDIFICIO_PROPIO = "El edificio seleccionado no es un edificio del jugador";
const string MSJ_ERROR_ES_EDIFICIO_PROPIO = "El edificio seleccionado es un edificio del jugador";
const string MSJ_ERROR_CASILLERO_ES_JUGADOR = "El casillero seleccionado contiene a un jugador";
const string MSJ_ERROR_BOMBAS_INSUFICIENTES = "No se tienen bombas en el inventario para atacar";
const string MSJ_ERROR_NO_REQUIERE_REPARACION = "El edificio seleccionado no requiere reparación";
const string MSJ_ERROR_ANDYCOINS_INSUFICIENTES = "No se tienen Andycoins suficientes para comprar la cantidad de bombas seleccionada";
const string MSJ_ERROR_RECOLECCION_REPETIDA = "No se puede recolectar recursos de los edificios 2 veces en un mismo turno";
const string MSJ_ERROR_ENERGIA_INSUFICIENTE = "No se tiene energía suficiente para realizar esta acción";
const string MSJ_ERROR_MODIFICANDO_OBELISCO = "No se pueden modificar los valores de obelisco";
const string MSJ_ERROR_EDIFICIO_MAXIMO_ALCANZADO = "Ya no se pueden construir más edificios de este tipo";
const string MSJ_ERROR_DEMOLER_EDIFICIO = "No se pudo demoler el edificio";
const string MSJ_ERROR_NO_ES_NUMERO = "El valor ingresado no es un numero";
const string MSJ_SALIR = "Accion cancelada";

typedef enum 
{
	ST_OK,
 	ST_ERROR_OPCION_INVALIDA, 
 	ST_ERROR_CANTIDAD_INVALIDA,
 	ST_ERROR_NOMBRE_INVALIDO,
 	ST_ERROR_COORDENADAS_INVALIDAS,  
 	ST_ERROR_MAXIMO_SUPERADO,  
 	ST_ERROR_CASILLERO_NO_CONSTRUIBLE,  
 	ST_ERROR_CASILLERO_OCUPADO, 
 	ST_ERROR_MATERIALES_INSUFICIENTES, 
 	ST_ERROR_CASILLERO_VACIO,  
 	ST_ERROR_NO_ES_EDIFICIO_PROPIO, 
 	ST_ERROR_ES_EDIFICIO_PROPIO, 
 	ST_ERROR_CASILLERO_ES_JUGADOR, 
 	ST_ERROR_BOMBAS_INSUFICIENTES, 
 	ST_ERROR_NO_REQUIERE_REPARACION, 
 	ST_ERROR_ANDYCOINS_INSUFICIENTES, 
 	ST_ERROR_RECOLECCION_REPETIDA,
 	ST_ERROR_ENERGIA_INSUFICIENTE,
 	ST_ERROR_MODIFICANDO_OBELISCO,
 	ST_ERROR_EDIFICIO_MAXIMO_ALCANZADO,
 	ST_ERROR_DEMOLER_EDIFICIO,
 	ST_ERROR_NO_ES_NUMERO,
 	ST_MSJ_SALIR
}estados_t;

void imprimir_error(estados_t st);

#endif //MENSAJES_DE_MSJ_ERROR_H

