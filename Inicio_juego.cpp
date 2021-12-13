#include "Inicio_juego.h"

void cargar_edificios(ABB<Edificio*> &arbol){
    ifstream archivo(ARCHIVO_EDIFICIOS);

    string aux, nombre;
    unsigned int piedra, madera, metal, maximo;

    while (archivo >> nombre){
        archivo >> aux;

        // Verifico si es un número
        if (aux[POSICION_PRIMER_LETRA] >= (int)'0' && aux[POSICION_PRIMER_LETRA] <= (int)'9'){
            piedra = stoi(aux);
        }else{
            nombre += ' ' + aux;
            archivo >> piedra;
        }

        archivo >> madera >> metal >> maximo;
        agregar_edificio(arbol, nombre, new Edificio(nombre, piedra, madera, metal, maximo));
    }

    archivo.close();
}

void agregar_edificio(ABB<Edificio*> &arbol, string nombre, Edificio* edificio){
	arbol.insertar(nombre, edificio);
}

void iniciar_juego()
{
	ABB<Edificio*> arbol;
	cargar_edificios(arbol);

	Mapa * mapa = new Mapa();

	char caracter_jugador_uno = CARACTER_JUGADOR_UNO, caracter_jugador_dos = CARACTER_JUGADOR_DOS;
	srand(time(NULL));
	Jugador* jugador_uno = new Jugador(caracter_jugador_uno);
	Jugador* jugador_dos = new Jugador(caracter_jugador_dos);

	cargar_materiales_jugadores(jugador_uno,jugador_dos);
	mapa->cargar_materiales(jugador_uno);
	int opcion_salida = trabajar_primer_menu(arbol, mapa);

	switch(opcion_salida){
		case OPCION_COMENZAR_PARTIDA:
			trabajar_segundo_menu(jugador_uno, jugador_dos, arbol, mapa);
			break;
		case OPCION_SALIR_PRIMER_MENU:
			// Guardar cambios de edificios.txt
			break;
	}

	guardar_materiales(jugador_uno, jugador_dos, mapa);
	delete jugador_uno;
	delete jugador_dos;
	delete mapa;
}

void guardar_materiales(Jugador *jugador_uno, Jugador *jugador_dos, Mapa *mapa)
{
	ofstream archivo_materiales;
    archivo_materiales.open(ARCHIVO_MATERIALES.c_str());
    string nombre_material;
    unsigned int cantidad_jugador_uno, cantidad_jugador_dos;
	unsigned int cantidad_materiales = jugador_uno->obtener_tipos_de_materiales();
	Material **materiales_aux = jugador_uno->obtener_lista_materiales();

    for(int i=0; i<cantidad_materiales; i++){
		nombre_material = materiales_aux[i]->obtener_nombre();
    	cantidad_jugador_uno = jugador_uno->mostrar_cantidad_material(nombre_material);
		cantidad_jugador_dos = jugador_dos->mostrar_cantidad_material(nombre_material);
		archivo_materiales << nombre_material << cantidad_jugador_uno << cantidad_jugador_dos;
    }	
    archivo_materiales.close();

}
