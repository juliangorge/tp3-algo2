#include "Andypolis.h"
#include "Menus.h"

int main()
{
    Andypolis ciudad;

    mostrarMenus();
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