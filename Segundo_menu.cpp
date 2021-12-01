#include "Segundo_menu.h"

void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos)
{
    Jugador* jugador = jugador_dos;
	mostrar_segundo_menu();
	int opcion = obtener_opcion_segundo_menu();
	while(opcion != OPCION_SALIR_SEGUNDO_MENU){
		opciones_segundo_menu(opcion, jugador);
		mostrar_segundo_menu();
		opcion = obtener_opcion_segundo_menu();
	}
}	

void opciones_segundo_menu(int opcion, Jugador* jugador){
    switch(opcion){
        case OPCION_CONSTRUIR_EDIFICIO:
            //Modificar edificios
            break;
        case OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS:
            //Listar edificios
            break;
        case OPCION_DEMOLER_COORDENADA:
            //Mostrar mapa
            break;
        case OPCION_ATACAR_EDIFICIO:
            //Mostrar mapa
            break;
        case OPCION_REPARAR_EDIFICIO:
            //Mostrar mapa
            break;
        case OPCION_COMPRAR_BOMBAS:
            //Mostrar mapa
            break;
        case OPCION_CONSULTAR_COORDENADA:
            //Mostrar mapa
            break;
        case OPCION_MOSTRAR_INVENTARIO:
            jugador->mostrar_inventario();
            break;
        case OPCION_MOSTRAR_OBJETIVOS:
            //Mostrar mapa
            break;
        case OPCION_RECOLECTAR_RECURSOS:
            //Mostrar mapa
            break;
        case OPCION_MOVERSE_A_COORDENADA:
            //Mostrar mapa
            break;
        case OPCION_FINALIZAR_TURNO:
            //Mostrar mapa
            break;
    }
}