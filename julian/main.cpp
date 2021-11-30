//#include "Andypolis.h"
//#include "Programa.h"


#include "ABB.h"
#include "ABB_nodo.h"

#include "Edificio.h"

#include <string>

using namespace std;

int main()
{
    //Andypolis ciudad;

    ABB<Edificio*> arbol;
    Edificio* edificio = new Edificio("mina", 1, 1, 1, 2);

    arbol.insertar("mina", edificio);

    arbol.imprimir_en_orden();


    //mostrar_menus();
    return 0;
}

/*
Carga de los archivos:
materiales.txt: presenta modificaciones.
edificios.txt: mantendrá el formato del trabajo practico anterior.
ubicaciones.txt: presenta modificaciones.
mapa.txt: mantendrá el formato del trabajo practico anterior.

TP2 -> Lista: materiales
Arbol: edificios
Tp2 -> ubicaciones (con materiales)
TP2 -> Mapa Ídem

Betún y Muelle = Camino (sólo cambian costes de energía)

*/