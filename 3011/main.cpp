#include <iostream>
#include <string>
#include <fstream>
#include "Andypolis.h"
#include "Map.h"
#include "enlistar_materiales.h"

const string PATH_MATERIALS = "materiales.txt";
const string PATH_BUILDINGS = "edificios.txt";
const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
using namespace std;



int main()
{
    //Andypolis ciudad;
    //ciudad.procesar_archivo_ubicaciones(PATH_UBICACIONES);

    verificar_existencia_archivo_materiales();
    
    // Corrección TP2: no es cómodo trabajar con la cantidad de elementos de la lista, las funciones quedan con muchos argumentos
    // Propuesta: meter la lista y la cantidad como atributos dentro del objeto jugador
    Material ** lista_materiales_jugador_1 = 0;
    unsigned cantidad_materiales_jugador_1 = 0;
    Material ** lista_materiales_jugador_2 = 0;
    unsigned cantidad_materiales_jugador_2 = 0;

    enlistar_materiales(&lista_materiales_jugador_1, &cantidad_materiales_jugador_1, &lista_materiales_jugador_2, &cantidad_materiales_jugador_2);
    
    imprimir_lista_materiales(lista_materiales_jugador_1, cantidad_materiales_jugador_1, lista_materiales_jugador_2, cantidad_materiales_jugador_2);

    guardar_archivo_materiales(lista_materiales_jugador_1,cantidad_materiales_jugador_1,lista_materiales_jugador_2,cantidad_materiales_jugador_2);

    
    Mapa mapa("mapa.txt");

    mapa.imprimir_mapa();
    
}