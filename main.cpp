#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "enlistar_materiales.h"


int main()
{
    verificar_existencia_archivo_materiales();

    Material ** lista_materiales_jugador_1 = 0;
    unsigned cantidad_materiales_jugador_1 = 0;
    Material ** lista_materiales_jugador_2 = 0;
    unsigned cantidad_materiales_jugador_2 = 0;

    enlistar_materiales(&lista_materiales_jugador_1, &cantidad_materiales_jugador_1, &lista_materiales_jugador_2, &cantidad_materiales_jugador_2);
    
    imprimir_lista_materiales(lista_materiales_jugador_1, cantidad_materiales_jugador_1, lista_materiales_jugador_2, cantidad_materiales_jugador_2);

    guardar_archivo_materiales(lista_materiales_jugador_1,cantidad_materiales_jugador_1,lista_materiales_jugador_2,cantidad_materiales_jugador_2);

    
    
}