#ifndef Jugador_INCLUDED
#define Jugador_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Jugador {

    // Attributes
    private:
        unsigned int numero;
        unsigned int coordenada_x;
        unsigned int coordenada_y;
        unsigned int energia;
        Building** buildings;
        Material** materials;

    // Methods
    public:

        // PRE: Los parametros deben ser validos.
	    // POST: Crea un objeto Jugador.
        Jugador(unsigned int numero, unsigned int x, unsigned int y);

        // PRE:
        // POST: Destruye un objeto Jugador.
        ~Jugador();

        // PRE:
        // POST: Retorna el numero
        unsigned int get_numero();

        unsigned int get_x();

        unsigned int get_y();

        // PRE:
        // POST: Suma una unidad a la posición x
        void incrementar_x();
    
        // PRE:
        // POST: Resta una unidad a la posición x
        void decrementar_x();

        // PRE:
        // POST: Suma una unidad a la posición y
        void incrementar_y();
    
        // PRE:
        // POST: Resta una unidad a la posición y
        void decrementar_y();

        // PRE:
        // POST: Incrementa una cantidad de energia al jugador
        void incrementar_energia(unsigned int cantidad);

        // PRE:
        // POST: Resta una cantidad de energia al jugador
        void decrementar_energia(unsigned int cantidad);

};

#endif