#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <fstream>
#include <iostream>
#include "Casillero.h"
#include "Objetivo.h"

using namespace std;

class Jugador {

    // Atributos
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

        Objetivo* objetivos;

        unsigned int andycoins_acumuladas;
        unsigned int bombas_compradas;
        unsigned int bombas_usadas;

        unsigned int acumulador_por_turno;

    // Metodos
    public:
		// PRE:
        // POST: Construye un objeto Jugador con su caracter que lo representará en en mapa
    	Jugador(char caracter);

    	// PRE:
        // POST: Destruye el objeto Jugador junto con su lista de Casilleros que referencian al mapa y la lista de materiales
        ~Jugador();

        // PRE:
        // POST: Devuelve el caracter que lo representa en el mapa
        char obtener_caracter();

        // PRE:
        // POST: Devuelve la energía del jugador
        unsigned int obtener_energia();

        // PRE:
        // POST: Devuelve la fila en la que se encuentra el jugador
        unsigned int obtener_fila();

        // PRE:
        // POST: Devuelve la columna en la que se encuentra el jugador
        unsigned int obtener_columna();

        // PRE:
        // POST: Devuelve la cantidad tipos de materiales que contiene la lista de materiales
        unsigned int obtener_tipos_de_materiales();

        // PRE: La lista de materiales debe estar bien cargada
        // POST: Devuelve la lista de materiales 
        Material** obtener_lista_materiales();

        // PRE: Las coordenadas deben ser validas
        // POST: Setea los atributos posicion_fila y posicion_columna
        void agregar_coordenadas(unsigned int posicion_fila, unsigned int posicion_columna);

		// PRE: Debe existir el archivo con los materiales y si los hubiera deben seguir el formato "material cant_jugador_1 cant_jugador_2".
		// POS: Enlista los materiales que encuentra en el archivo
		void agregar_material_a_lista(Material* material);

    	// PRE: 
		// POS: Imprime por consola la lista de materiales del jugador
		void mostrar_inventario();

        // PRE: 
        // POS: Verifica si el valor del atributo energia es mayor o no al costo de energia que entra por parametro
        estados_t verificar_energia_suficiente(unsigned int costo_energia);

        // PRE: el costo de energia debe ser menor a la energia del Jugador
        // POS: Sustrae el costo de energia por parametro al atributo energia
        void decrementar_energia(unsigned int costo_energia);

        // PRE: 
        // POS: Se incrementa la energia del jugador en un valor ingresado por parametro. En caso de que la energia sea mayor a 100, se mantiene en este valor
        void incrementar_energia(unsigned int energia_nueva);

        // PRE: 
        // POS: Devuelve verdadero si la energia del Jugador es 0
        bool verificar_energia_nula();

        // PRE: El material debe existir en la lista
        // POS: Devuelve la posicion del material en la lista de materiales del Jugador
        unsigned int obtener_posicion_material(string nombre_material);

        // PRE: Las bombas*precio_bombas debe ser menor o igual a la cantidad de andycoins que se posea
        // POS: Se obtiene una cantidad de bombas por parametro, y se resta una cantidad bombas*precio_bombas de andycoins de la lista
        void comprar_bombas(unsigned int bombas, unsigned int precio_bombas);

        // PRE: 
        // POS: Devuelve verdadero si se posee la cantidad material pasado por nombre mayor o igual a la cantidad a restar 
        bool verificar_material_necesario(string nombre_material, unsigned int cantidad_a_restar);

        // PRE: La cantidad a restar debe ser menor igual a la cantidad disponible de material pasado por nombre
        // POS: Resta de la cantidad del material pasado por nombre una cantidad por parametro
        void restar_materiales(string nombre_material, unsigned int cantidad_a_restar);

        // PRE: El material buscado debe existir en la lista
        // POST: Devuelve la cantidad del material pasado por nombre
        unsigned int mostrar_cantidad_material(string nombre_material);

        // PRE: El material buscado debe existir en la lista
        // POST: Suma a cantidad del material pasado por nombre una cantidad por parametro
        void agregar_material(string nombre_material, unsigned int cantidad);

        // PRE: Se debe haber cumplido las condicioes para la construccion de un edificio
        // POST: Se agrega al Casillero** casilleros_jugador una referencia al edificio en el mapa que éste construyó
        void agregar_casillero(Casillero* casillero);

        // PRE: 
        // POST: Muestra todos los edificios referenciados a Casillero** casilleros_jugador, con su nombre, coordenadas y si necesitan reparacion o no
        void mostrar_edificios();

        // PRE: Se debe haber cumplido las condicioes para la demolicion o ataque del jugador contrario de un edificio
        // POST: Se borra del Casillero** casilleros_jugador una referencia al edificio en el mapa que éste se destruyó
        void borrar_edificio_casillero(Casillero * casillero);

        // PRE: Se deben tener objetivos asignados
        // POST: Se verifica si se cumplieron 2 o mas de los objetivos secundarios, o bien el objetivo principal
        bool objetivos_cumplidos();

        // PRE: 
        // POST: Se obtienen todos los valores relevantes para analizar el avance de los objetivos asignados, y luego se muestra el progreso
        void mostrar_objetivos(unsigned int maximo_escuelas);

        // PRE: 
        // POST: Se busca de Casillero** casilleros_jugador la cantidad de edificios con el nombre dado que tiene el jugador construidos
        unsigned int obtener_cant_edificio(string nombre);

        // PRE: 
        // POST: Se busca de Casillero** casilleros_jugador los edificios que este tiene construidos y obtiene los materiales que éste aporta y los agrega al inventario
        void recolectar_recursos();

        // PRE: 
        // POST: Pone en 0 el acumulador para que no se pueda recolectar recursos mas de una vez por turno
        void reset_acumulador_por_turno();

        // PRE: 
        // POST: Devuelve el acumulador que se incrementa en cada turno si no se recolectan los recursos
        unsigned int obtener_acumulador_por_turno();

        // PRE: 
        // POST: Aumenta en 1 el acumulador una vez que se finaliza el turno
        void aumentar_acumulador_por_turno();

        void cargar_ubicaciones_materiales(ofstream& archivo);

};

#endif //JUGADOR_H
