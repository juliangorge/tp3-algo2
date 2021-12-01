#ifndef ENLISTAR_MATERIALES_H
#define ENLISTAR_MATERIALES_H

#include "material.h"

#include <string>

using namespace std;

const string NOMBRE_ARCHIVO_MATERIALES = "materiales.txt";

// PRE: -
// POS: verifica si existe el archivo que aloja a los materiales. Si no existe, lo crea
void verificar_existencia_archivo_materiales();

// PRE: debe existir el archivo con los materiales y si los hubiera deben seguir el formato "material cant_jugador_1 cant_jugador_2".
// POS: enlista los materiales que encuentra en el archivo. Si un material se encuentra repetido, lo agrupa en un solo ítem.
void enlistar_materiales(Material *** lista_jugador_1, unsigned * cantidad_jugador_1, Material *** lista_jugador_2, unsigned * cantidad_jugador_2);

// PRE: -
// POS: se encarga de ver si es necesario usar "agregar_material_inexistente" o "agregar_material_existente" y la ejecuta
void agregar_material(string nombre_material, unsigned cantidad_material, Material *** lista, unsigned * largo_lista);

// PRE: el material debe existir
// POS: si la cantidad de material en inventario es suficiente como para restarle la cantidad indicada, se resta y retorna true. Si no, retorna false. 
bool decrementar_material(string nombre_material, unsigned cantidad_material, Material *** lista, unsigned largo_lista);

// PRE: -
// POS: añade un nuevo material a la lista, con nombre y cantidad indicados
void agregar_material_inexistente(string nombre_material, unsigned cantidad_material, Material *** lista, unsigned * largo_lista);

// PRE: recibe un material con su cantidad y la lista
// POS: retorna TRUE si el material existía y lo pudo agregar, retorna FALSE en caso contrario
bool agregar_material_existente(string nombre_material, unsigned cantidad_material, Material *** lista, unsigned largo_lista);

//PRE: largo debe coincidir con la longitud real de la lista
//POS: libera la memoria de la lista que se le pasa por argumento
void eliminar_lista(Material *** lista, unsigned largo);

// PRE: -
// POS: imprime por consola la lista de materiales de los jugadores 1 y 2
void imprimir_lista_materiales(Material ** lista_jugador_1, unsigned cantidad_jugador_1, Material ** lista_jugador_2, unsigned cantidad_jugador_2);

// PRE: -
// POS: devuelve la cantidad que hay del material que se ingresa por comando, ó 0 si no hay tal material
unsigned obtener_cantidad_material(string nombre_material, Material ** lista, unsigned cantidad_items);

// PRE: -
// POS: reescribe el archivo de materiales con la info de las listas y lo cierra
void guardar_archivo_materiales(Material ** lista_jugador_1, unsigned cantidad_jugador_1, Material ** lista_jugador_2, unsigned cantidad_jugador_2);


#endif