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
    int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    Camino_minimo * algoritmo_camino_minimo;

/*MÉTODOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void camino_minimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandarmatriz_adyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiarMatrizAdyacente(int** nuevaAdyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializarNuevoVertice(int** nuevaAdyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

    //post: imprime por pantalla los vertices del grafo
    void mostrarVertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrarMatrizAdyacencia();
public:

    Grafo();
    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregarVertice(string nuevoVertice);

    //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //post: muestra por terminal el camino mínimo desde un origen a un destino
    void camino_minimo(Casillero *origen, Casillero *destino);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregar_camino(Casillero *origen, Casillero *destino, int peso_origen, int peso_destino);

    //post: imprime por pantalla el grafo
    void mostrarGrafo();

    //post: selecciona el algortimo de Floyd para calcular el camino mínimo
    void usarFloyd();

    //post: selecciona el algortimo de Dijkstra para calcular el camino mínimo
    void usarDijkstra();

    void asignar_adyacentes(char jugador, Casillero *origen, Casillero *destino, Mapa*mapa);

    void asignar_pesos(Casillero *casillero_origen, Casillero *casillero_destino, char jugador);
    
    void obtener_peso(char tipo_casillero, int *peso, int peso_L, int peso_M);

    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
