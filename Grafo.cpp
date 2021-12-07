#include "Grafo.h"
#include "Dijkstra.h"
#include <iostream>

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    vertices = new Lista<Vertice>();
    algoritmo_camino_minimo = nullptr;
}

void Grafo::agregarVertice(string nuevoVertice) {
    agrandarmatriz_adyacencia();
    vertices -> agregar(nuevoVertice);
}

void Grafo::mostrarGrafo() {
    mostrarVertices();
    mostrarMatrizAdyacencia();
}

void Grafo::agregar_camino(Casillero *origen, Casillero *destino, int peso_origen, int peso_destino) {
    int posicion_origen = vertices->obtener_posicion(origen->obtener_fila(), origen->obtener_columna());
    int posicion_destino = vertices->obtener_posicion(destino->obtener_fila(), destino->obtener_columna());

    matriz_adyacencia[posicion_origen][posicion_destino] = peso_destino;
    matriz_adyacencia[posicion_destino][posicion_origen] = peso_origen;
}

//Con el grafo siempre interactuo con strings. La lista es algo particular del grafo
void Grafo::camino_minimo(Casillero *origen, Casillero *destino) {
    int posicion_origen = vertices->obtener_posicion(origen->obtener_fila(), origen->obtener_columna());
    int posicion_destino = vertices->obtener_posicion(origen->obtener_fila(), origen->obtener_columna());

    if(posicion_origen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicion_destino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    camino_minimo(posicion_origen, posicion_destino);
}

void Grafo::agrandarmatriz_adyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtenerCantidadDeElementos() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiarMatrizAdyacente(matrizAuxiliar);
    inicializarNuevoVertice(matrizAuxiliar);
    liberarMatrizAdyacencia();
    matriz_adyacencia = matrizAuxiliar;
}

void Grafo::copiarMatrizAdyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos(); j++){
            nuevaAdyacente[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializarNuevoVertice(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        nuevaAdyacente[vertices -> obtenerCantidadDeElementos()][i] = INFINITO;
        nuevaAdyacente[i][vertices -> obtenerCantidadDeElementos()] = INFINITO;
    }
    nuevaAdyacente[vertices -> obtenerCantidadDeElementos()][vertices -> obtenerCantidadDeElementos()] = 0;
}

void Grafo::liberarMatrizAdyacencia() {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

Grafo::~Grafo() {
    liberarMatrizAdyacencia();
    matriz_adyacencia = nullptr;
    delete vertices;
    delete algoritmo_camino_minimo;
}

void Grafo::mostrarVertices() {
    cout << "Lista de vértices: [";
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        cout << vertices -> obtenerNombre(i + 1);
        if(i + 1 != vertices -> obtenerCantidadDeElementos()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrarMatrizAdyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos() * 2; j++) {
            if(j == vertices -> obtenerCantidadDeElementos() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matriz_adyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matriz_adyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

//Hago una sobre carga de camino minimo para hallar el camino minimo entre origen y destino
void Grafo::camino_minimo(int origen, int destino) {
    algoritmo_camino_minimo -> camino_minimo(origen, destino);
}

void Grafo::usarDijkstra() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Dijkstra(vertices, matriz_adyacencia);
}

void Grafo::asignar_pesos(char jugador, Casillero *origen, Casillero *destino)
{
    //this->agregarVertice(casillero);

    if(jugador == 'J')
        asignar_adyacentes(origen, destino, PESO_LAGO_1, PESO_MUELLE_1);

    if(jugador == 'U')
        asignar_adyacentes(origen, destino, PESO_LAGO_2, PESO_MUELLE_2);

    /*this->mostrarGrafo();

    this->usarDijkstra();

    this->camino_minimo("A", "B");*/

}

void Grafo::asignar_adyacentes(Casillero *casillero_origen, Casillero *casillero_destino, unsigned int peso_L, unsigned int peso_M)
{
    int peso_origen;
    switch (casillero_origen->obtener_caracter())
    {
    case 'L':
        peso_origen=PESO_LAGO_1;
        break;

    case 'B':
        peso_origen=PESO_BETUN;
        break;

    case 'M':
        peso_origen=PESO_MUELLE_1;
        break;

    case 'T':
        peso_origen=PESO_TERRENO;
        break;

    case 'C':
        peso_origen=PESO_CAMINO;
        break;
    default:
        break;
    }
    char char_destino=casillero_destino->obtener_caracter();
    switch (char_destino)
    {
    case 'L':
        this->agregar_camino(casillero_origen, casillero_destino, peso_origen, peso_L);//peso_destino);
        break;

    case 'B':
        this->agregar_camino(casillero_origen, casillero_destino, peso_origen, PESO_BETUN);
        break;

    case 'M':
        this->agregar_camino(casillero_origen, casillero_destino, peso_origen, peso_M);
        break;

    case 'T':
        this->agregar_camino(casillero_origen, casillero_destino, peso_origen, PESO_TERRENO);
        break;

    case 'C':
        this->agregar_camino(casillero_origen, casillero_destino, peso_origen, PESO_CAMINO);
        break;
    default:
        break;
    }

}