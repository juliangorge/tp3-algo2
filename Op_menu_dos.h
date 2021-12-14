#ifndef OP_MENU_DOS_H
#define OP_MENU_DOS_H

#include <iostream>
#include "Menu_consola.h"
#include "Interaccion_usuario.h"
#include "Grafo.h"
#include <string>

// Opciones de menu

// PRE: El jugador, ABB y Mapa deben estar bien inicializados
// POST: Se construye un edificio por nombre de un jugador siempre y cuando se cumplan las condiciones necesarias (energia, nombre, materiales, maximo, coordenadas, casilleros)
estados_t construir_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa);

// PRE:
// POST: Muestra todos los edificios del jugador del mapa, en una lista, mostrando su nombre, coordendas y si requieren reparación o no
void mostrar_edificios_construidos(Jugador* jugador);

// PRE: El jugador, ABB y Mapa deben estar bien inicializados
// POST: Se destruye un edificio por coordenada de un jugador siempre y cuando se cumplan las condiciones necesarias (energia, coordenadas, casilleros)
estados_t demoler_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa);

// PRE: El jugador, ABB y Mapa deben estar bien inicializados
// POST: Se ataca el edificio por coordenada  del jugador contrario siempre y cuando se cumplan las condiciones necesarias (energia, bombas,  coordenadas, casilleros)
estados_t atacar_edificio(Jugador* jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa);

// PRE: El jugador, ABB y Mapa deben estar bien inicializados
// POST: Se ataca el edificio por coordenada del jugador contrario siempre y cuando se cumplan las condiciones necesarias (energia, materiales, coordenadas, casilleros)
estados_t reparar_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa);

// PRE: El jugador debe estar bien inicializado
// POST: Se realiza la compra de una cantidad de bombas siempre y cuando se tengan los andycoins suficientes
estados_t comprar_bombas(Jugador* jugador);

// PRE: El mapa y el ABB deben estar bien inicializados
// POST: Se consulta las coordendas en el mapa y se obtiene información del casillero (siempre que las coordenadas sean válidas)
estados_t consultar_coordenadas(Mapa* mapa);

// PRE:
// POST: Muestra todos los materiales disponibles del jugador con nombre y cantidad
void mostrar_inventario(Jugador* jugador);

// PRE:
// POST: Muestra todos los objetivos que tiene asignados el jugador, junto con el progreso que se tienen de los mismos
void mostrar_objetivos(Jugador* jugador, ABB<Edificio *>& arbol);

// PRE:
// POST: Recolecta los recursos de los edificios que el jugador posee construidos. Solo se puede hacer una vez por turno y son acumulables
estados_t recolectar_recursos(Jugador* jugador);

// PRE:
// POST: 
estados_t moverse_coordenada(Jugador *jugador, Mapa* mapa);

// PRE:
// POST:
estados_t verificar_materiales(Jugador* jugador, Edificio* edificio, unsigned int factor_cont_rep);

// PRE: Se deben cumplir todas las condiciones para la construcción/reparación del edificio deseado
// POST: Resta de la lista de materiales del jugador, la cantidad requerida del material para el edificio, con un factor que depende si es construcción o reparación
void restar_materiales(Jugador* jugador, Edificio* edificio, unsigned int factor_cont_rep);

// PRE: Se deben cumplir todas las condiciones para la demolición del edificio deseado
// POST: Suma a la lista de materiales del jugador, la mitad de la cantidad requerida del material para el edificio
void agregar_materiales(Jugador* jugador, Edificio* edificio);



#endif //OP_MENU_DOS_H