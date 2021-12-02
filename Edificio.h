#ifndef EDIFICIO_INCLUDED
#define EDIFICIO_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Edificio {

    // Attributes
    private:
        string nombre;
        unsigned int piedra;
        unsigned int madera;
        unsigned int metal;
        unsigned int cantidad;
        unsigned int maximo;
        char caracter_edificio;
        bool provee_materiales;
        unsigned int materiales_proveidos;

    // Methods
    public:
    
        // PRE: Los parametros deben ser validos.
	    // POST: Crea un objeto Edificio.
        Edificio(string nombre, unsigned int piedra, unsigned int madera, unsigned int metal, unsigned int maximo);
        
        // PRE:
        // POST: Destruye un objeto Edificio.
        ~Edificio();

        // PRE:
        // POST: Retorna el nombre.
        string obtener_nombre();

        // PRE:
        // POST: Retorna la cantidad de piedra.
        unsigned int obtener_piedra();

        // PRE:
        // POST: Retorna la cantidad de madera.
        unsigned int obtener_madera();

        // PRE:
        // POST: Retorna la cantidad de metal.
        unsigned int obtener_metal();

        // PRE:
        // POST: Retorna la cantidad de edificios construidos.
        unsigned int obtener_cantidad();

        // PRE:
        // POST: Retorna la cantidad restante de edificios construidos (maximo - cantidad)
        unsigned int obtener_restantes();

        // PRE: 
        // POST: Retorna un string Si si es true y No si es false
        string obtener_provee_materiales();

        // PRE:
        // POST: Retorna la cantidad de materiales que provee el edificio
        unsigned int obtener_materiales_proveidos();

        // PRE:
        // POST: Retorna el caracter del edificio.
        char obtener_caracter_edificio();

        // PRE:
        // POST: Suma una unidad a la cantidad
        void incrementar_cantidad();
    
        // PRE: Recibe un valor entero
        // POST: Suma el valor ingresado a la cantidad previa
        void incrementar_cantidad(unsigned int cantidad);
        
        // PRE:
        // POST: Resta una unidad a la cantidad
        void decrementar_cantidad();

        // PRE: Recibe un valor entero
        // POST: Resta el valor ingresado a la cantidad previa
        void decrementar_cantidad(unsigned int cantidad);

        // PRE:
        // POST: Retorna la cantidad maxima de edificios.
        unsigned int obtener_maximo();

        // PRE: 
        // POST: Retorna el valor valido
        void obtener_caracter();

        void actualizar_materiales(unsigned int piedra, unsigned int madera, unsigned int metal);
};

ostream& operator<<(ostream& salida, Edificio& edificio);

#endif 