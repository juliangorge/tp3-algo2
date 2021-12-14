#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include <string>

#include "Casillero_camino.h"
#include "Casillero_betun.h"
#include "Casillero_lago.h"
#include "Casillero_muelle.h"
#include "Casillero_terreno.h"
#include "Jugador.h"
#include "Utilidades.h"

using namespace std;

class Mapa
{
    // Atributos
    private:
        unsigned int cantidad_filas;
        unsigned int cantidad_columnas;
        Casillero *** matriz_mapa;
        Material** materiales_mapa;
        unsigned int cantidad_de_materiales;
        Casillero ** casilleros_camino;
        unsigned int cantidad_casilleros_camino;

    // Metodos
    public:

        // PRE: debe existir un archivo con un mapa cargado en el camino especificado y con el formato correcto
        // POST: carga los atributos del objeto con lo que obtiene del archivo mapa
        Mapa();

        // PRE:
        // POST: Elimina la matriz de punteros a casillero, asi como tambien la lista de materiales que contiene el mapa
        ~Mapa();

        // PRE: EL archivo mapa.txt debe existir 
        // POST: Abre el archivo mapa.txt y obtiene las posiciones y el caracter del mapa para cargar el objeto correspondiente
        void leer_mapa();

        // PRE: El archivo mapa.txt se debe haber abierto correctamente
        // POST: Crea el objeto Casillero correspondiente en base al caracter que recibe por parámentro
        void cargar_mapa(unsigned int cantidad_filas, unsigned int cantidad_columnas, char square_type);

        // PRE:
        // POST: Devuelve la cantidad de filas que posee el mapa
        unsigned int obtener_cantidad_filas();

        // PRE:
        // POST:Devuelve la cantidad de columnas que posee el mapa
        unsigned int obtener_cantidad_columnas();

        // PRE: El Mapa debe estar bien cargado
        // POST: Recorre el mapa buscando casilleros transitables libres y los referencia en vector Casillero** casilleros_camino
        void obtener_casilleros_transitables();

        // PRE: 
        // POST: Cuando encuentra un casillero transitable libre lo agrega al vector Casillero** casilleros_camino
        void agregar_casillero_transitable(Casillero * casillero);

        // PRE: 
        // POST: Cuando un casillero transitable libre se le agrega un material, se sustrae del vector Casillero** casilleros_camino
        void borrar_casillero_transitable(Casillero * casillero);

        // PRE: El mapa debe estar cargado correctamente
        // POST: Muestra el mapa vacío, es decir, sin que se le hayan cargado los jugadores, materiales y edificios.
        void mostrar_mapa_vacio();

        // PRE: El mapa debe estar cargado correctamente, el archivo ubicaciones.txt debe estar correctamente cargado
        // POST: Muestra simulataneamente el mapa vacío, asi como tambien el mapa con los elementos cargados hasta el momento
        void mostrar_mapas();

        // PRE: Las coordenadas ingresadas deben ser válidas
        // POST: Se devuelve el Objeto casillero que se encuentra en la fila y columna ingresadas por parámetros
        Casillero * obtener_casillero(unsigned int fila, unsigned int columna);

        // PRE: La lista de materiales de Jugador debe estar cargada en ese objeto
        // POST: Se carga una lista de materiales de alguno de los jugadores para copiar sus objetos, para luego setear cantidades fijas a cada uno
        void cargar_materiales(Jugador* jugador);

        // PRE: 
        // POST: Asigna una cantidad a un material copiado de la lista de Jugador, que se utiliza para la recoleccion cuando el Jugador pase por el casillero que contenga este material
        unsigned int set_cantidad_material(Material* material);

        // PRE: La lista de materiales del Mapa debe estar cargada
        // POST: Se devuelve el Material de la lista que contiene el nombre ingresado por parámetro
        Material* obtener_material(string nombre_material);

        // PRE: La lista de casilleros transitables libres  del Mapa debe estar cargada
        // POST: Se crean conjuntos aleatorios de materiales especificos que se van colocando en el mapa a partir del vector Casillero** casilleros_camino
        void lluvia_recursos();

        // PRE: La lista de casilleros transitables libres  del Mapa debe estar cargada
        // POST: Crea un conjunto de cantidad aleatoria entre sus cotas de un material es especifico
        void crear_colocar_conjuntos(string nombre_material, unsigned int cota_minima, unsigned int cota_maxima);

        // PRE: La lista de casilleros transitables libres  del Mapa debe estar cargada
        // POST: Agrega de forma aleatoria en el mapa los conjuntos de materiales a partir del vector Casillero** casilleros_camino
        void agregar_material_casilleros_camino(string material);
        
        // PRE: El archivo ubicaciones.txt debe estar abierto
        // POST: Recorre el mapa buscando casilleros transitables con materiales y los agrega al archivo ubicaciones.txt
        void cargar_ubicaciones_materiales(ofstream& archivo);

};

#endif //MAPA_H
