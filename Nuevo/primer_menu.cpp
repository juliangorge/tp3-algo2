#include "primer_menu.h"

int trabajar_primer_menu()
{
    Mapa* mapa = new Mapa;
    mostrar_primer_menu();
    int opcion = obtener_opcion_primer_menu();
    while(opcion < OPCION_COMENZAR_PARTIDA){
        opciones_primer_menu(opcion,mapa);
        mostrar_primer_menu();
        opcion = obtener_opcion_primer_menu();
    }
    return opcion;
}

void opciones_primer_menu(int opcion,Mapa* mapa){
    switch(opcion){
        case OPCION_MODIFICAR_EDIFICIOS:
            //Modificar edificios
            break;
        case OPCION_LISTAR_EDIFICIOS:
            //Listar edificios
            break;
        case OPCION_MOSTRAR_MAPA:
            mapa->showMap();
            break;
    }
}