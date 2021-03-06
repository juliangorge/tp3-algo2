#ifndef SEGUNDO_MENU_H
#define SEGUNDO_MENU_H

#include "Op_menu_dos.h"
#include "Parser.h"

using namespace std;

// Se contiene todo el espacio del segundo menu, las funciones de inicialización de jugadores, cambio de turno y verificacion de energía.

// PRE: Se deben tener creados los dos Jugadores, el mapa y el arbol
// POST: Trabaja en bucle en base a las opciones ingresadas por el usuario, hasta que se quiera guardar y salir
void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *> & arbol, Mapa*& mapa);

// PRE: Se debe haber ingresado una opción valida del menu (de 1 a 12, 13 es para salir)
// POST: Realiza una acción del menú en base a la opción elegida por el usuario
void opciones_segundo_menu(unsigned int opcion, Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa);

// PRE: Se deben tener creados los dos Jugadores
// POST: Se indica cual es el jugador que inicia la partida
Jugador* inicializar_jugador(Jugador* jugador_uno, Jugador* jugador_dos);

// PRE: Se deben tener creados los dos Jugadores, se debe haber finalizado el turno o que el jugador actual se haya quedado sin energía
// POST: Se modifica el jugador que trabajará con el menú
void cambiar_jugador(Mapa* & mapa, Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol);

// PRE: El jugador debe haber realizado una acción sin errores en su validación
// POST: Se verifica el nivel del energia del jugador. Si se quedó sin energía, se cambia de jugador
void verificar_energia_nula(Mapa* & mapa, Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol);

// PRE: 
// POST: 
void cargar_ubicaciones (Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio*>& arbol, Mapa*& mapa);

// PRE: Recibe puntero auxiliar
// POST: Retorna dato validado
unsigned int validar_linea_ubicaciones(char* aux);


// PRE: 
// POST: Verifica la existencia del archivo ubicaciones 
bool existe_archivo_ubicaciones();

// PRE: Recibe puntero de los jugadores y referencia del mapa 
// POST: Carga las coordenadas para el jugador
void cargar_posiciones_jugadores(Jugador *jugador_uno, Jugador *jugador_dos, Mapa*& mapa);

// PRE: Recibe por referencia el arbol
// POST: Guarda los cambios en el archivo
void guardar_edificios(ABB<Edificio *>& arbol);

#endif //SEGUNDO_MENU_H
