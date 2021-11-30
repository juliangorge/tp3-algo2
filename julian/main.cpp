//#include "Andypolis.h"

//#include "Programa.h"
#include "ABB.h"
#include "ABB_nodo.h"

#include "Edificio.h"

#include <string>

using namespace std;

void modificar_edificio_por_nombre(ABB<Edificio*> &arbol, string nombre){
    if(!arbol.buscar(nombre)){
        cout << "No se encontró " << nombre << endl;
        return;
    }

    Edificio* edificio = arbol.obtener_dato(nombre);

    if(edificio->obtener_nombre() == "obelisco"){
        cout << "No se pueden modificar los valores de obelisco" << endl;
        return;
    }    

    // Solicitar al usuario que ingrese valores de construcción (cantidad de piedra, madera y metal)
    //cout << edificio->obtener_nombre() << endl;


}

void mostrar_edificios(ABB<Edificio*> &arbol){
    arbol.imprimir_en_orden();
}

int main()
{
    //Andypolis ciudad;

    ABB<Edificio*> arbol;
    Edificio* edificio = new Edificio("mina", 1, 1, 1, 2);
    Edificio* edificio_2 = new Edificio("yacimiento", 1, 1, 1, 2);
    Edificio* edificio_3 = new Edificio("planta electrica", 1, 1, 1, 2);
    Edificio* edificio_4 = new Edificio("escuela", 1, 1, 1, 2);

    /*
    1. Modificar edificio por nombre.
        Se deberá verificar que exista el edificio, en caso de que el nombre ingresado sea correcto se le pedirá
        al usuario que ingrese los nuevos valores de construcción (cantidad de piedra, madera y metal
        necesarios) para el edificio seleccionado. 
        Se le deberá dar la opción al usuario de saltearse un material si no desea modificar ese valor. En caso de
        desear modificarlo se deberá verificar que el numero ingresado sea mayor a 0 y menor a 50000
        Por último, si el usuario desea modificar los valores de “obelisco” se le deberá indicar que ese edificio
        no es modificable.

    2. Listar todos los edificios.
        Se deberán listar todos los edificios indicando para cada uno de ellos: cuantas unidades de cada
        material se requieren para construir uno, cuantos fueron construidos hasta el momento, cuantos más
        puedo construir3
        sin superar el máximo permitido y si me brinda algún tipo de material4.

    3. Mostrar mapa.
        Mostrará el mapa indicando los edificios y materiales que se encuentren en el mismo. También se
        deberá mostrar ya sea con el código de colores sugerido en la sección mapa o imprimiendo una
        segunda matriz con las letras indicadas los tipos de terrenos presentes en el mapa. 
    4. Comenzar partida.
    5. Guardar y salir. 
    */

    arbol.insertar("mina", edificio);
    arbol.insertar("yacimiento", edificio_2);
    arbol.insertar("planta electrica", edificio_3);
    arbol.insertar("escuela", edificio_4);

    //arbol.imprimir_en_orden();
    mostrar_edificios(arbol);
    //modificar_edificio_por_nombre(arbol, "mina");

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