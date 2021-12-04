/*#include "Cargar_ubicaciones.h"

void cargar_ubicaciones (Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio*> arbol, Mapa* mapa)
{
    ifstream archivo_ubicaciones("ubicaciones.txt");
    unsigned int fila=0, columna=0;
    int elemento = 0, jugador = 0;
    string str_aux, nombre_aux;

    while (getline(archivo_ubicaciones, str_aux))
    {
        Parser parser = Parser(str_aux);
        nombre_aux = parser.nombre();
        fila = parser.coordenada_x();
        columna = parser.coordenada_y();
        elemento = validar_linea(&str_aux[0]); //elemento vale 0 si es material o edificio, sino vale el numero de jugador.
        Edificio *edificio_aux;
        
        cout << elemento;
        cout << " " << str_aux << endl;
        
        if (elemento == 0)
        {
            if (arbol.buscar(nombre_aux)) //buscar(T dato)
            {
                edificio_aux = arbol.obtener_dato(nombre_aux);
                if (jugador == 1) //agrego edificios del jugador 1
                    mapa->set_edificio_casillero(jugador_uno->obtener_numero(), fila, columna, edificio_aux);
                else if (jugador == 2) //agrego edificios del jugador 2
                    mapa->set_edificio_casillero(jugador_dos->obtener_numero(), fila, columna, edificio_aux);
                    //this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));
            }
        }

        if (elemento == 1)
        {
            jugador = 1;
            mapa->set_jugador_casillero(jugador_uno);

            //this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, '1');
        }
        else if (elemento == 2)
        {
            jugador = 2;
            mapa->set_jugador_casillero(jugador_dos);
        }
    }

    archivo_ubicaciones.close();

}*/


/*
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


/*****
int validar_linea(char *aux)
{
    int tipo_dato = 0;

    if(isdigit(*aux))
    {
        tipo_dato = atoi(aux);
    }
    else
    {
        tipo_dato = 0;
    }

    return tipo_dato;
}********/