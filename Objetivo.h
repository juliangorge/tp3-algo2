#ifndef OBJETIVO_H
#define OBJETIVO_H

#include<stdlib.h>
#include<time.h>
#include <string>

#include "ABB.h"
#include "Edificio.h"
#include "Constantes.h"
#include "Utilidades.h"

using namespace std;



class Objetivo {

    // Atributos
    private:
        bool objetivo_principal;
        bool estado_objetivos[CANTIDAD_OBJETIVOS];
        unsigned int objetivos[CANTIDAD_OBJETIVOS];

    // metodos
    public:
		// PRE: Se debe tener creado al objeto Jugador
        // POST: Crea un objeto Objetivo asignando 3 de los 9 posibles objetivos secundarios (estos, mas el objetivo principal en false)
    	Objetivo();

        //PRE:
        //POST: Se genera un numero aletorio de 1 a 9, y en base a eso se selecciona el objetivo secundario a cumplir (no se repiten los numeros)
        void asignar_objetivos();

        //PRE: Se deben tener los objetivos asignados
        //POST: Verifica si se cumple el objetivo principal, o bien al menos 2 de los 3 objetivos secundarios
        bool estados_objetivos();

        //PRE: Se deben tener los objetivos asignados
        //POST: Se analiza el progreso de cada objetivo secundario asignado, asi tambien como el del objetivo principal
        void mostrar_progreso(unsigned int atributos_objetivos[CANTIDAD_VALORES_OBJETIVOS], unsigned int tipos_edificios_construidos[7]);

        //PRE:
        //POST: Se verifica si se tiene algun obelisco construido
        void chequear_objetivo_principal(unsigned int obeliscos_construidos);

        // Posibles objetivos secundarios

        //PRE:
        //POST: Se verifica si la cantidad de andycoins acumuladas es menor o no a 100000
        void comprar_andypolis(bool & objetivo_comprar_andycoins, unsigned int andycoins_acumuladas);

        //PRE:
        //POST: Se verifica si se posee en el inventario del jugador 50000 de piedra
        void edad_piedra(bool & objetivo_edad_piedra, unsigned int cantidad_piedra);

        //PRE:
        //POST: Se verifica si se utilizaron 5 bombas o más
        void bombardero(bool & objetivo_bombardero, unsigned int bombas_usadas);

        //PRE:
        //POST: Se verifica si el jugador posee 100 de energía
        void energetico(bool & objetivo_energetico, unsigned int energia);

        //PRE:
        //POST: Se verifica si se construyó la cantidad máxima posibles de escuelas
        void letrado(bool & objetivo_letrado, unsigned int escuelas_construidas, unsigned int maximo_escuelas);

        //PRE:
        //POST: Se verifica si se construyó una mina y una mina de oro
        void minero(bool & objetivo_minero, unsigned int tipos_edificios_construidos[CANTIDAD_TIPOS_EDIFICIOS]);

        //PRE:
        //POST: Se verifica si el jugador posee 0 de energía
        void cansado(bool & objetivo_cansado, unsigned int energia);

        //PRE:
        //POST: Se verifica si se construyó un edificio de cada tipo (exceptuando obelisco)
        void constructor(bool & objetivo_constructor, unsigned int tipos_edificios_construidos[CANTIDAD_TIPOS_EDIFICIOS]);

        //PRE:
        //POST: Se verifica si se poseen 10 bombas en el inventario o más
        void armado(bool & objetivo_armado, unsigned int cantidad_bombas);

        //PRE:
        //POST: Se verifica si se compraron 500 bombas o más
        void extremista(bool & objetivo_extremista, unsigned int bombas_compradas);

};

#endif //OBJETIVO_H
