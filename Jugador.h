#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <fstream>
#include <iostream>
#include "Casillero.h"
#include "Material.h"
#include "Mensajes_de_error.h"
//#include "Objetivo.h"

using namespace std;

const string ARCHIVO_MATERIALES = "materiales.txt";
const int CANT_OBJETIVOS_JUGADOR = 3;


const unsigned int ENERGIA_INICIAL = 50;
const unsigned int ENERGIA_MAXIMA = 100;
const unsigned int ANDYCOINS_INICIALES = 0;
class Jugador {

    // Attributes
    private:
        Casillero** casilleros_jugador;
        unsigned int cantidad_casilleros;

        Material** materiales_jugador;
        unsigned int tipos_de_materiales;
        unsigned int energia;

        //Mapa
        char caracter;
        unsigned int posicion_fila;
        unsigned int posicion_columna;
        
        //Objetivos
        bool estado_objetivos[CANT_OBJETIVOS_JUGADOR];
        int objetivos[CANT_OBJETIVOS_JUGADOR];

        unsigned int andycoins;
        unsigned int andycoins_acumuladas;
        unsigned int bombas_compradas;
        unsigned int bombas_usadas;
        unsigned int bombas;
    // Methods
    public:
		// PRE:
        // POST: Destruye un objeto Andypolis.
    	Jugador(char caracter);

    	// PRE:
        // POST: Destruye un objeto Andypolis.
        ~Jugador();

        unsigned int obtener_energia();

        char obtener_caracter();

        unsigned int obtener_tipos_de_materiales();

        Material** obtener_lista_materiales();

        void agregar_coordenadas(unsigned int posicion_fila, unsigned int posicion_columna);

		// PRE: debe existir el archivo con los materiales y si los hubiera deben seguir el formato "material cant_jugador_1 cant_jugador_2".
		// POS: enlista los materiales que encuentra en el archivo. Si un material se encuentra repetido, lo agrupa en un solo ítem.
		


		void agregar_material_a_lista(Material* material);

    	// PRE: -
		// POS: imprime por consola la lista de materiales de los jugadores 1 y 2
		void mostrar_inventario();

		// PRE: -
		// POS: reescribe el archivo de materiales con la info de las listas y lo cierra
		//void guardar_archivo_materiales(Jugador* jugador_uno, Jugador* jugador_dos);

        estados_t verificar_energia_suficiente(unsigned int costo_energia);

        void decrementar_energia(unsigned int costo_energia);

        void incrementar_energia(unsigned int energia_nueva);

        bool verificar_energia_nula();

        unsigned int obtener_posicion_material(string nombre_material);

        bool verificar_material_necesario(string nombre_material, unsigned int cantidad_a_restar);

        void comprar_bombas(unsigned int bombas, unsigned int precio_bombas);

        void restar_materiales(string nombre_material, unsigned int cantidad_a_restar);

        unsigned int mostrar_cantidad_material(string nombre_material);

        unsigned int obtener_fila();

        unsigned int obtener_columna();

        void agregar_material(string nombre_material, unsigned int cantidad);

        void agregar_casillero(Casillero * casillero);

        void mostrar_edificios();

        void borrar_edificio_casillero(Casillero * casillero);

        void set_objetivo_cumplido(int objetivo, Jugador *jugador);

        void set_objetivos(int objetivos[]);

        int obtener_objetivo(int posicion);

        bool objetivo_cumplido(int posicion);

        unsigned int obtener_andycoins_juntadas();

        unsigned int obtener_bombas_usadas();

        unsigned int obtener_bombas_compradas();

        unsigned int obtener_bombas();

        unsigned int obtener_max_escuelas();

        unsigned int obtener_cant_edificio(string nombre);

};

void cargar_materiales(Jugador* jugador_uno, Jugador* jugador_dos);
#endif //JUGADOR_H
