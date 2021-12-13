#ifndef SEGUNDO_MENU_H
#define SEGUNDO_MENU_H

#include <iostream>
#include "Menu_consola.h"
#include "Interaccion_usuario.h"
#include "Cargar_ubicaciones.h"
#include "Mensajes_de_error.h"
#include "Grafo.h"
#include "Constantes.h"


#include "ABB.h"
#include "Edificio.h"

using namespace std;

void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa);

estados_t construir_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa);

void opciones_segundo_menu(int opcion, Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa);

Jugador* inicializar_jugador(Jugador* jugador_uno, Jugador* jugador_dos);

void cambiar_jugador(Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol);

void verificar_energia_nula(Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol);

estados_t verificar_materiales(Jugador* jugador, Edificio* edificio, unsigned int factor_cont_rep);

void restar_materiales(Jugador* jugador, Edificio* edificio, unsigned int factor_cont_rep);

void agregar_materiales(Jugador* jugador, Edificio* edificio);

void guardar_edificios(ABB<Edificio *>& arbol);

void mostrar_objetivos(Jugador* jugador, ABB<Edificio *>& arbol);

estados_t consultar_coordenadas(Mapa*& mapa);

void cargar_materiales_jugadores(Jugador* jugador_uno, Jugador* jugador_dos);

estados_t demoler_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa);

estados_t atacar_edificio(Jugador* jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa);

estados_t reparar_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa);

estados_t comprar_bombas(Jugador* jugador);

void mostrar_compra_realizada(Jugador* jugador);

estados_t recolectar_recursos(Jugador* jugador);

bool verificar_existencia_archivo(string nombre);

void inicializar_archivo_ubicaciones();

void cargar_posiciones_jugadores(Jugador *jugador_uno, Jugador *jugador_dos, Mapa *mapa);
//void agregar_materiales(Jugador* jugador, Edificio* edificio);

//estados_t moverse_coordenada(Jugador *jugador, Mapa *mapa);

#endif //SEGUNDO_MENU_H
