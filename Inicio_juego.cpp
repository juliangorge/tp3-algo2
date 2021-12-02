#include "Inicio_juego.h"
#include "ABB.h"
#include "ABB_nodo.h"
#include "Edificio.h"

void iniciar_juego()
{
	ABB<Edificio*> arbol;
	Mapa * mapa = new Mapa("mapa.txt");
	char caracter_jugador_uno = 'J', caracter_jugador_dos = 'U';

	Jugador* jugador_uno = new Jugador(caracter_jugador_uno);
	Jugador* jugador_dos = new Jugador(caracter_jugador_dos);

	cargar_materiales_jugadores(jugador_uno,jugador_dos);
	int opcion_salida = trabajar_primer_menu(arbol);

	switch(opcion_salida){
		case OPCION_COMENZAR_PARTIDA:
			trabajar_segundo_menu(jugador_uno, jugador_dos);
			break;
		case OPCION_SALIR_PRIMER_MENU:
			// Guardar cambios de edificios.txt
			break;
		break;
	}

}

