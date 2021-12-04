#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <fstream>
#include <iostream>
#include "Material.h"
#include "Mensajes_de_error.h"
using namespace std;

const string ARCHIVO_MATERIALES = "materiales.txt";


const unsigned int ENERGIA_INICIAL = 50;

class Jugador {

    // Attributes
    private:

        Material** materiales_jugador;
        unsigned int tipos_de_materiales;
        unsigned int energia;
        //Objetivos
        char caracter_jugador;
        unsigned int posicion_x;
        unsigned int posicion_y;

    // Methods
    public:
		// PRE:
        // POST: Destruye un objeto Andypolis.
    	Jugador(char caracter_jugador);

    	// PRE:
        // POST: Destruye un objeto Andypolis.
        ~Jugador();

        unsigned int obtener_energia();

        char obtener_caracter_jugador();


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

        unsigned int mostrar_cantidad_material(string nombre_material);

        int obtener_numero();

        int obtener_x();

        int obtener_y();



};

void cargar_materiales_jugadores(Jugador* jugador_uno, Jugador* jugador_dos);
#endif //JUGADOR_H