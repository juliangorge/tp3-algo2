#ifndef EDIFICIO_INCLUDED
#define EDIFICIO_INCLUDED

#include <string>
#include <iostream>

#include "Constantes.h"

using namespace std;

class Edificio {

    // Atributos
    private:
        string nombre;
        unsigned int piedra;
        unsigned int madera;
        unsigned int metal;
        unsigned int maximo;
        char caracter;
        bool provee_materiales;
        bool contiene_escudo;
        bool fue_atacado;
        unsigned int materiales_proveidos;

    // Metodos
    public:
        // PRE: Debe haber al menos un edificio en el archivo edificios.txt
	    // POST: Crea un objeto Edificio, con nombre, materiales requeridos, y maximo posible de construir
        Edificio(string nombre, unsigned int piedra, unsigned int madera, unsigned int metal, unsigned int maximo);      

        ~Edificio();

        // PRE:
        // POST: Devuelve el nombre
        string obtener_nombre();

        // PRE:
        // POST: Establece el caracter del edificio, si provee materiales (con su cantidad) o no, y si puede ser atacado 2 veces (escudo), en base a su nombre
        void establecer_parametros();

        // PRE:
        // POST: Devuelve la cantidad de piedra necesaria para su construccion
        unsigned int obtener_piedra();

        // PRE:
        // POST: Devuelve la cantidad de madera necesaria para su construccion
        unsigned int obtener_madera();

        // PRE:
        // POST: Devuelve la cantidad de metal necesario para su construccion
        unsigned int obtener_metal();

        // PRE: La cantidad por parametro debe ser menor que el maximo
        // POST: Devuelve la cantidad restante de edificios posibles de construir (maximo - cantidad)
        unsigned int obtener_restantes(unsigned int cantidad_construidos);

        // PRE:
        // POST: Devuelve la cantidad maxima posible de edificios construidos
        unsigned int obtener_maximo();

        // PRE: 
        // POST: Retorna si el edificio provee materiales o no
        bool obtener_provee_materiales();

        // PRE: 
        // POST: Retorna si el edificio puede ser atacado 2 veces
        bool obtener_contiene_escudo();

        // PRE: El edificio debe tener escudo
        // POST: Retorna si el edificio fue atacado o no
        bool obtener_fue_atacado();

        // PRE: El edificio debe tener escudo
        // POST: Si fue atacado es reparado y viceversa
        void cambio_estado_edificio();

        // PRE: El edificio debe proveer materiales
        // POST: Retorna la cantidad de materiales que provee el edificio
        unsigned int obtener_materiales_proveidos();

        // PRE: 
        // POST: Retorna el caracter caracteristico del edificio
        char obtener_caracter();

        // PRE: Las cantidades deben estar entre 0 50000
        void actualizar_materiales(unsigned int piedra, unsigned int madera, unsigned int metal);
};
        // PRE: 
        // POST: Sobrecarga el operador << para la muestra de edificios contenidos en el ABB
        ostream& operator<<(ostream& salida, Edificio& edificio);

#endif 
