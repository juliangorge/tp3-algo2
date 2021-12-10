#ifndef OBJETIVO__H
#define OBJETIVO__H

#include "Jugador.h"
#include<stdlib.h>
#include<time.h>
#include <string>
#include "utilidades.h"
using namespace std;

const int MINAS_METAL_OBJETIVO = 1;
const int MINAS_ORO_OBJETIVO = 1;
const int MAX_ESCUELAS = 4;

const int CANTIDAD_ANDYCOINS_OBJETIVO = 100000;
const int CANTIDAD_PIEDRA_OBJETIVO = 500;
const int BOMBAS_USADAS_OBJETIVO = 5;
const int CANTIDAD_CANSADO_OBJETIVO = 0;
const int CANTIDAD_ARMADO_OBJETIVO = 10;
const int CANTIDAD_EXTREMISTA_OBJETIVO = 500;


/*typedef enum {
    COMPRAR_ANDYPOLIS=1,
    EDAD_PIEDRA,
    BOMBARDERO,
    ENERGETICO,
    LETRADO,
    MINERO,
    CANSADO,
    CONSTRUCTOR,
    ARMADO,
    EXTREMISTA
    }objetivos;*/

const int COMPRAR_ANDYPOLIS=1;
const int EDAD_PIEDRA=2;
const int BOMBARDERO=3;
const int ENERGETICO=4;
const int LETRADO=5;
const int MINERO=6;
const int CANSADO=7;
const int CONSTRUCTOR=8;
const int ARMADO=9;
const int EXTREMISTA=10;

class Objetivo {

    // Atributos
    private:
        unsigned int numero;
        bool estado;

    // metodos
    public:
		// PRE:
        // POST: Destruye un objeto Andypolis.
    	Objetivo();

        // PRE:
        // POST: Destruye un objeto Andypolis.
        ~Objetivo();

        //PRE:
        //POST:
        void asignar_objetivos(Jugador *jugador);

        //PRE:
        //POST:
        int contar_cumplidos(Jugador *jugador);
        
        void mostrar_progreso(Jugador *jugador);

        //PRE:
        //POST:
        void estado_objetivo(Jugador *jugador, int objetivo);

        //PRE:
        //POST:
        void comprar_andypolis (Jugador *jugador, int objetivo);

        void edad_piedra(Jugador *jugador, int objetivo);

        void bombardero(Jugador *jugador, int objetivo);

        void estado_energetico(Jugador *jugador, int objetivo);

        void letrado(Jugador *jugador, int objetivo);

        void minero(Jugador *jugador, int objetivo);

        void cansado(Jugador *jugador, int objetivo);

        void constructor(Jugador *jugador, int objetivo);

        void armado(Jugador *jugador, int objetivo);

        void extremista(Jugador *jugador, int objetivo);

        void asignar(Jugador *jugador);

};
#endif