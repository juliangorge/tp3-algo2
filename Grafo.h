#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "Casillero.h"
#include "Camino_minimo.h"
#include "Mapa.h"

using namespace std;

const int PESO_BETUN = 0;
const int PESO_CAMINO = 4;
const int PESO_TERRENO = 25;
const int PESO_LAGO_1 = 2;
const int PESO_LAGO_2 = 5;
const int PESO_MUELLE_1 = 5;
const int PESO_MUELLE_2 = 2;

class Grafo {
/*ATRIBUTOS*/
private:
    unsigned int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    Camino_minimo * algoritmo_camino_minimo;

/*MÉTODOS*/

    //PRE: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //POST: muestra el camino minimo entre el origen y el destino. Devuelve el costo del camino en energia.
    int camino_minimo(int origen, int destino);

    //POST: agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_adyacencia();

    //PRE: la matriz que se le envie ya debe tener memoria reservada
    //POST: copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacencia(unsigned int** nueva_adyacente);

    //POST inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_vertice(unsigned int** nueva_adyacente);

    //POST libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

    //POST: imprime por pantalla los vertices del grafo
    void mostrar_vertices();

    //POST: imprime por pantalla la matriz de adyacencia
    void mostrar_matriz_adyacencia();
public:

    Grafo();
    //PRE: No hay vertices repetidos en nombre
    //POST: agrega un nuevo vertice al grafo
    void agregar_vertice(Casillero *vertice);

    //PRE: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //POST: muestra por terminal el camino mínimo desde un origen a un destino
    int camino_minimo(Casillero *origen, Casillero *destino);
     
    //PRE:
    //POST: 
    void agregar_camino(Mapa *mapa, char jugador);

    //POST: imprime por pantalla el grafo
    void mostrar_grafo();

    //POST: selecciona el algortimo de Dijkstra para calcular el camino mínimo
    void usar_dijkstra();

    //PRE:
    //POST: asigna los pesos de los casilleros que son vecinos entre si
    void asignar_adyacentes(char jugador, Casillero *origen, Casillero *destino, Mapa*mapa);
     
    //PRE:
    //POST: asigna un peso segun el tipo de casillero que se le pase.
    void obtener_peso(char tipo_casillero, int *peso, int peso_L, int peso_M);
     
    //PRE:
    //POST: toma todos los casilleros del mapa y los agrega a una lista de casileros
    void agregar_vertices(Mapa *mapa);
     
    //PRE:
    //POST: segun los tipos de casillero que se les pase, le asigna un peso para completar la matriz de adyacencias
    void asignar_pesos(Casillero *origen, Casillero *destino, unsigned int *peso_origen, unsigned int *peso_destino, char jugador);
          
    //PRE: destino debe ser un casillero no ocupado por jugadores o edificios
    //POST: encargado de cargar el grafo y llamar a las funciones de calculo
    estados_t usar_grafo(Casillero *origen, Casillero *destino, Mapa *mapa, Jugador *jugador);

    //PRE: jugador, origen y destino deben ser los mismos utilizados para realizar el trazado del grafo
    //POST: Recorre los casilleros del grafo y recolecta los materiales en el camino
    void recorrer_casilleros_paso(Mapa *mapa, Casillero *origen, Casillero *destino, Jugador *jugador);

   ~Grafo();
};


#endif //GRAFOS_GRAFO_H
