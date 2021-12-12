#ifndef OBJETIVO_H
#define OBJETIVO_H

#include<stdlib.h>
#include<time.h>
#include <string>

#include "ABB.h"
#include "Edificio.h"
#include "Constantes.h"

using namespace std;



class Objetivo {

    // Atributos
    private:
        bool estado_objetivos[CANTIDAD_OBJETIVOS];
        unsigned int objetivos[CANTIDAD_OBJETIVOS];

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
        void asignar_objetivos();

        //PRE:
        //POST:

        //PRE:
        //POST:
        int aleatorio(int cota_inferior, int cota_superior);

        //PRE:
        //POST:
        bool estado_objetivo();

        void mostrar_progreso(unsigned int atributos_objetivos[8]);

        //PRE:
        //POST:
        bool comprar_andypolis (unsigned int andycoins_acumuladas);

        bool edad_piedra(unsigned int cantidad_piedra);

        bool bombardero(unsigned int bombas_usadas);

        bool estado_energetico(unsigned int energia);

        bool letrado(unsigned int escuelas_construidas, unsigned int maximo_escuelas);

        bool minero();

        bool cansado(unsigned int energia);

        bool constructor();

        bool armado(unsigned int cantidad_bombas);

        bool extremista(unsigned int bombas_usadas);

};

#endif //OBJETIVO_H