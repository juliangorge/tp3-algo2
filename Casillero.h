#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include <string>
#include "Edificio.h"
#include "Material.h"
#include "Mensajes_de_error.h"

using namespace std;

class Casillero
{
    // Atributos de la clase madre e hijas
    protected:

        unsigned int fila;
        unsigned int columna;
        bool es_camino;
        bool es_terreno;
        string nombre_casillero;
        char caracter;
        char caracter_casillero;
        char caracter_jugador;
        Edificio* edificio;
        Material* material;
        unsigned int costo_energia_J;
        unsigned int costo_energia_U;

    // Metodos
    public:

    	// PRE: Debe estar cargado el archivo mapa.txt
	    // POST: Crea un objeto Casillero, guardando sus coordenadas del mapa
        Casillero(unsigned int fila, unsigned int columna);

        // PRE: 
	    // POST: Devuelve la posicion fila del Casillero en el mapa
        unsigned int obtener_fila();

        // PRE: 
	    // POST: Devuelve la posicion columna del Casillero en el mapa
        unsigned int obtener_columna();

        // PRE:
        // POST: Retorna si el casillero está libre de construcciones/materiales/jugador
        bool esta_libre();

        // PRE: El casillero debe ser de tipo Terreno
        // POST: Retorna el objeto Edificio
        Edificio* obtener_edificio();
        
        // PRE: El casillero debe ser de tipo Muelle, Betun o Camino
        // POST: Retorna el objeto Material
        Material* obtener_material();
        
        // PRE:
        // POST: Retorna el caracter del Casillero que esta representando en el mapa: jugador/edificio/material
        char obtener_caracter();

        // PRE:
        // POST: Retorna el caracter que representa al tipo de Casillero 
        char obtener_caracter_casillero();

        // PRE:
        // POST: Retorna el nombre del casillero
        string obtener_nombre_casillero();
        
        // PRE: Se deben haber cumplido todas las condiciones para construir
        // POST: Referencia el atributo edificio al edificio contenido en el ABB.
        void cargar_edificio(Edificio* edificio, char caracter_jugador);

        // PRE: 
        // POST: Referencia el atributo material al material contenido en el Mapa
        void cargar_material(Material* material);

        // PRE: Se deben haber cumplido todas las condiciones para atacar
        // POST: Se pone en NULL el puntero al edificio en base a si tiene escudo o no, y si requeria reparacion o no
        void atacar_edificio();
    
        // PRE:
        // POST: Cambia el caracter casillero por el caracter de edificio/material que se coloca alli
        virtual void cambiar_caracter() = 0;

        // PRE: 
        // POST: Desreferencia al atributo edificio/material, y coloca el caracter casillero
        virtual void limpiar_casillero() = 0;

        // PRE:
        // POST: Devuelve el costo de energía en base al caracter del jugador que recibe
        unsigned int obtener_costo_energia(char jugador);
 
        // PRE: El edificio debe estar referenciado en el Casillero
        // POST: Devuelve el costo de energía en base al caracter del jugador que recibe
        void mostrar_edificio();

        // PRE:
        // POST: Coloca en el casillero el caracter jugador, para que éste se muestre en el mapa
        void ocupar_casillero(char caracter);

        // PRE:
        // POST: Devuelve informacion del tipo de casillero, si esta libre o en caso contrario, que objeto contiene
        virtual void mostrar_casillero() = 0;

		// PRE: 
        // POST: Devuelve OK si se cumplen las condiciones para que se pueda construir, caso contrario devuelve un valor que se usa para indicar que no se cumplió
        estados_t verificar_condiciones_construccion(char caracter_jugador);

        // PRE: 
        // POST: Devuelve OK si se cumplen las condiciones para que se pueda demoler, caso contrario devuelve un valor que se usa para indicar que no se cumplió
        estados_t verificar_condiciones_demolicion(char caracter_jugador);

        // PRE: 
        // POST: Devuelve OK si se cumplen las condiciones para que se pueda atacar, caso contrario devuelve un valor que se usa para indicar que no se cumplió
        estados_t verificar_condiciones_ataque(char caracter_jugador);
};

#endif // CASILLERO_H
