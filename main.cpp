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
    
    Material ** lista_materiales_jugador_1 = 0;
    unsigned cantidad_materiales_jugador_1 = 0;
    Material ** lista_materiales_jugador_2 = 0;
    unsigned cantidad_materiales_jugador_2 = 0;

    enlistar_materiales(&lista_materiales_jugador_1, &cantidad_materiales_jugador_1, &lista_materiales_jugador_2, &cantidad_materiales_jugador_2);
    
    imprimir_lista_materiales(lista_materiales_jugador_1, cantidad_materiales_jugador_1, lista_materiales_jugador_2, cantidad_materiales_jugador_2);

    guardar_archivo_materiales(lista_materiales_jugador_1,cantidad_materiales_jugador_1,lista_materiales_jugador_2,cantidad_materiales_jugador_2);

    
    
}