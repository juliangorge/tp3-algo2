#include "Inicio_juego.h"

void cargar_edificios(ABB<Edificio*> &arbol){
    ifstream archivo(ARCHIVO_EDIFICIOS);

    string aux, nombre;
    unsigned int piedra, madera, metal, maximo;

    while (archivo >> nombre){
        archivo >> aux;

        // Verifico si es un número
        if (aux[POSICION_PRIMER_LETRA] >= (int)'0' && aux[POSICION_PRIMER_LETRA] <= (int)'9'){
            piedra = static_cast<unsigned int>(stoul(aux));
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
	srand( static_cast<unsigned int>(time(nullptr)));
	Jugador* jugador_uno = new Jugador(caracter_jugador_uno);
	Jugador* jugador_dos = new Jugador(caracter_jugador_dos);

	cargar_materiales_jugadores(jugador_uno,jugador_dos);
	mapa->cargar_materiales(jugador_uno);
	int opcion_salida = trabajar_primer_menu(arbol, mapa);

	if(opcion_salida == OPCION_COMENZAR_PARTIDA){
		trabajar_segundo_menu(jugador_uno, jugador_dos, arbol, mapa);
		guardar_ubicaciones(mapa, jugador_uno, jugador_dos);
        analizar_ganador(jugador_uno, jugador_dos);		
	}

	guardar_materiales(jugador_uno, jugador_dos);
	guardar_edificios(arbol);
	delete jugador_uno;
	delete jugador_dos;
	delete mapa;
}

void guardar_materiales(Jugador *jugador_uno, Jugador *jugador_dos)
{
	ofstream archivo;
    archivo.open(ARCHIVO_MATERIALES.c_str());
    string nombre_material;
	Material** materiales_aux = jugador_uno->obtener_lista_materiales();

    for(unsigned int i = 0; i < jugador_uno->obtener_tipos_de_materiales()-1; i++){
		nombre_material = materiales_aux[i]->obtener_nombre();
		archivo << nombre_material << ' ' << jugador_uno->mostrar_cantidad_material(nombre_material) << ' ' << jugador_dos->mostrar_cantidad_material(nombre_material) << '\n';
    }	
    	nombre_material = materiales_aux[jugador_uno->obtener_tipos_de_materiales()-1]->obtener_nombre();
		archivo << nombre_material << ' ' << jugador_uno->mostrar_cantidad_material(nombre_material) << ' ' << jugador_dos->mostrar_cantidad_material(nombre_material);
    archivo.close();
}


void guardar_ubicaciones(Mapa* & mapa, Jugador* jugador_uno, Jugador* jugador_dos){
	ofstream archivo;
    archivo.open(ARCHIVO_UBICACIONES.c_str());
    mapa->cargar_ubicaciones_materiales(archivo);
    archivo << NUMERO_JUGADOR_UNO << PRIMER_DELIMITADOR << jugador_uno->obtener_fila() << SEGUNDO_DELIMITADOR << jugador_uno->obtener_columna() << TERCER_DELIMITADOR;
    jugador_uno->cargar_ubicaciones_edificios(archivo);
    archivo << '\n';
    archivo << NUMERO_JUGADOR_DOS << PRIMER_DELIMITADOR << jugador_dos->obtener_fila() << SEGUNDO_DELIMITADOR << jugador_dos->obtener_columna() << TERCER_DELIMITADOR;
    jugador_dos->cargar_ubicaciones_edificios(archivo);
    archivo.close();
	
}

void analizar_ganador(Jugador*& jugador_uno, Jugador*& jugador_dos)
{
    if(jugador_uno->objetivos_cumplidos())
        cout << MSJ_JUGADOR_UNO_GANA << endl;
    else if (jugador_dos->objetivos_cumplidos())
        cout << MSJ_JUGADOR_DOS_GANA << endl;
}