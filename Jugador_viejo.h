/*#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <fstream>
#include <iostream>
#include "Casillero.h"
#include "Material.h"
#include "Mensajes_de_error.h"
using namespace std;

const string ARCHIVO_MATERIALES = "materiales.txt";
const int CANT_OBJETIVOS_JUGADOR = 3;


const unsigned int ENERGIA_INICIAL = 50;

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
        unsigned int posicion_x;
        unsigned int posicion_y;
        
        //Objetivos
        bool estado_objetivos[CANT_OBJETIVOS_JUGADOR];
        int objetivos[CANT_OBJETIVOS_JUGADOR];

        unsigned int andycoins_acumuladas;
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

        bool verificar_energia_nula();

        unsigned int obtener_posicion_material(string nombre_material);

        estados_t verificar_material_necesario(string nombre_material, unsigned int cantidad_a_restar);

        void comprar_bombas(unsigned int bombas, unsigned int precio_bombas);

        void restar_materiales(string nombre_material, unsigned int cantidad_a_restar);

        unsigned int mostrar_cantidad_material(string nombre_material);

        int obtener_numero();

        int obtener_x();

        int obtener_y();

        void agregar_material(string nombre_material, unsigned int cantidad);

        void agregar_casillero(Casillero * casillero);

        void mostrar_edificios();

        void remover_edificio(Casillero * casillero);

        void set_objetivo_cumplido(int objetivo);

        void set_objetivos(int objetivos[]);

        int obtener_andycoins_juntadas();

        int obtener_bombas_usadas();

        int obtener_bombas_compradas();

        int obtener_escuelas();

        int obtener_max_escuelas();

        int obtener_minas_oro();

        int obtener_minas_metal();

        int obtener_aserradero();

        int obtener_fabrica();

        int obtener_planta_electrica();

        unsigned int obtener_cant_edificio(Casillero * casillero, string nombre);

};

void cargar_materiales_jugadores(Jugador* jugador_uno, Jugador* jugador_dos);
#endif //JUGADOR_H