#include "Inicio_juego.h"
#include "ABB.h"
#include "ABB_nodo.h"
#include "Edificio.h"


void cargar_edificios(ABB<Edificio*> &arbol){
    ifstream file("edificios.txt");

    string aux, nombre;
    unsigned int piedra, madera, metal, maximo;

    while (file >> nombre){
        file >> aux;

        // Verifico si es un número
        if (aux[0] >= (int)'0' && aux[0] <= (int)'9'){
            piedra = stoi(aux);
        }else{
            nombre += ' ' + aux;
            file >> piedra;
        }

        file >> madera >> metal >> maximo;
        agregar_edificio(arbol, nombre, new Edificio(nombre, piedra, madera, metal, maximo));
    }

    file.close();
}

void agregar_edificio(ABB<Edificio*> &arbol, string nombre, Edificio* edificio){
	arbol.insertar(nombre, edificio);
}


void iniciar_juego()
{
	//Mapa * mapa = new Mapa("mapa.txt");
	
	ABB<Edificio*> arbol;
	cargar_edificios(arbol);

	Mapa * mapa = new Mapa();

	char caracter_jugador_uno = 'J', caracter_jugador_dos = 'U';

	Jugador* jugador_uno = new Jugador(caracter_jugador_uno);
	Jugador* jugador_dos = new Jugador(caracter_jugador_dos);

	cargar_materiales_jugadores(jugador_uno,jugador_dos);
	int opcion_salida = trabajar_primer_menu(arbol, mapa);

	switch(opcion_salida){
		case OPCION_COMENZAR_PARTIDA:
			trabajar_segundo_menu(jugador_uno, jugador_dos, arbol, mapa);
			break;
		case OPCION_SALIR_PRIMER_MENU:
			// Guardar cambios de edificios.txt
			break;
		break;
	}

}

