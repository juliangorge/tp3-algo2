#include "Cargar_ubicaciones.h"

void cargar_ubicaciones (Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio*> arbol, Mapa* mapa)
{
    ifstream archivo_ubicaciones(ARCHIVO_UBICACIONES);
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
        
        //cout << elemento;
        if (elemento == 0)
        {
            if (arbol.buscar(nombre_aux)) //buscar(T dato)
            {
                edificio_aux = arbol.obtener_dato(nombre_aux);
                if (jugador == 1) //agrego edificios del jugador 1
                    mapa->set_edificio_casillero(jugador_uno->obtener_caracter_jugador(), fila, columna, edificio_aux);
                else if (jugador == 2) //agrego edificios del jugador 2
                    mapa->set_edificio_casillero(jugador_dos->obtener_caracter_jugador(), fila, columna, edificio_aux);
            }
            else{

                //mapa->set_material_casillero()
                cout << "HAY MATERIAL" << endl;
            }
            
        }

        if (elemento == 1)
        {
            jugador = 1;
            jugador_uno->agregar_coordenadas(fila, columna);
            mapa->set_jugador_casillero(jugador_uno);

            //this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, '1');
        }
        else if (elemento == 2)
        {
            jugador = 2;
            jugador_dos->agregar_coordenadas(fila, columna);
            mapa->set_jugador_casillero(jugador_dos);
        }
    }

    archivo_ubicaciones.close();

}

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
}