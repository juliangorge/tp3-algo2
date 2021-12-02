#include <iostream>
#include "ABB.h"
#include "ABB_nodo.h"
#include "mapa.h"

/*void cargar_ubicaciones (Mapa* mapa, ABB<int>* abb, string filename)
{
    ifstream archivo_ubicaciones(filename);
    unsigned int x_aux, y_aux, row_pos, col_pos;
    int elemento = 0, jugador = 0;

    if(buscar(T dato))
    {
        if (elemento == 0) //leo una linea que no es un jugador
        {
            if (jugador == 0) //tomo jugador 0 como los materiales
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));
            
            else if (jugador == 1) //agrego edificios del jugador 1
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));

            else if (jugador == 2) //agrego edificios del jugador 2
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));
        }
        else if (elemento == 1)
        {
            jugador = 1;
            this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, '1');
        }
        else if (elemento == 2)
        {
            jugador = 2;
            this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, '2');
        }
    }

    }

    archivo_ubicaciones.close();

}
Del archivo ubicaciones.txt saco la clave dle edificio.
hago la funcion abb.buscar en el arbol que contiene todos objetos edificios.
me devuelve el objeto y lo pongo en la ubicacion del mapa seǵun lo que tambien lei del ubicaciones.txt

cuando encuentro me va a devolver un puntero al nodo donde esta el arbol. 
aumento la cantida de edificios en el jugador correspoondiente y lo pongo en el mapa.

void cargar_ubicaciones (Mapa *mapa, arbol de edificios (puntero a la raiz))

void Andypolis::procesar_archivo_ubicaciones(string filename)
{
    ifstream archivo_ubicaciones(filename);

    string aux_3, aux, coords, row_aux, col_aux, nombre_aux, str_aux;
    unsigned int x_aux, y_aux, row_pos, col_pos;
    int elemento = 0, jugador = 0;

    while (getline(archivo_ubicaciones, str_aux))
    {
        Parser parser = Parser(str_aux);
        nombre_aux = parser.nombre();
        x_aux = parser.coordenada_x();
        y_aux = parser.coordenada_y();
        elemento = validar_linea(&str_aux[0]); //elemento vale 0 si es material o edificio, sino vale el numero de jugador.
        cout << elemento;
        cout << " " << str_aux << endl;

        if (elemento == 0) //leo una linea que no es un jugador
        {
            if (jugador == 0) //tomo jugador 0 como los materiales
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));
            
            else if (jugador == 1) //agrego edificios del jugador 1
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));

            else if (jugador == 2) //agrego edificios del jugador 2
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));
        }
        else if (elemento == 1)
        {
            jugador = 1;
            this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, '1');
        }
        else if (elemento == 2)
        {
            jugador = 2;
            this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, '2');
        }
    }

    archivo_ubicaciones.close();
} */