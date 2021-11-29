#include "inicio_juego.h"

void iniciar_juego()
{
	int opcion_salida = trabajar_primer_menu();
	switch(opcion_salida){
		case OPCION_COMENZAR_PARTIDA:
			trabajar_segundo_menu();
			break;
		case OPCION_SALIR_PRIMER_MENU:
			// Guardarcambios de edificios.txt
			break;
		break;
	}

}

