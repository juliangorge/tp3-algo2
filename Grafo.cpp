#include "Grafo.h"
#include "Dijkstra.h"
#include <iostream>

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    vertices = new Lista<Vertice>();
    algoritmo_camino_minimo = nullptr;
}

void Grafo::agregar_vertice(Casillero *nuevo_vertice) {
    agrandar_matriz_adyacencia();
    vertices -> agregar(nuevo_vertice);
}

void Grafo::mostrar_grafo() {
    //mostrar_vertices();
    mostrar_matriz_adyacencia();
}


void Grafo::agregar_camino(Mapa *mapa, char jugador) 
{
    Casillero *origen, *destino;
    unsigned int peso_origen = 0, peso_destino = 0;
    int posicion_origen=0, posicion_destino=0;
    char jugador_contrario;
    for (unsigned int i = 0; i < mapa->obtener_cantidad_filas(); i++)
    {   
        for (unsigned int j = 0; j < mapa->obtener_cantidad_columnas(); j++)
        {  
            if(j < mapa->obtener_cantidad_filas()-1 )//Condicion para que no busque casillero a la derecha si esta en la ultima columna
            {   //Hallo la distancia entre un casillero y el de su derecha
                origen = mapa->obtener_casillero(i,j);
                destino = mapa->obtener_casillero(i,j+1);
                posicion_origen = vertices->obtener_posicion(i, j);
                posicion_destino = vertices->obtener_posicion(i, j+1);

                asignar_pesos(origen, destino, &peso_origen, &peso_destino, jugador);

                matriz_adyacencia[posicion_origen][posicion_destino] = peso_destino;
                matriz_adyacencia[posicion_destino][posicion_origen] = peso_origen;
            }
            if(i < mapa->obtener_cantidad_columnas()-1 )//Condicion para que no busque casillero abajo si esta en la ultima fila
            {   //Hallo la distancia entre un casillero y el que tiene abajo
                destino = mapa->obtener_casillero(i+1,j);
                posicion_destino = vertices->obtener_posicion(i+1, j);

                asignar_pesos(origen, destino, &peso_origen, &peso_destino, jugador);

                matriz_adyacencia[posicion_origen][posicion_destino] = peso_destino;
                matriz_adyacencia[posicion_destino][posicion_origen] = peso_origen;
            }
        }
    }

}

void Grafo::camino_minimo(Casillero *origen, Casillero *destino) 
{
    int posicion_origen = vertices->obtener_posicion(origen->obtener_fila(), origen->obtener_columna());
    int posicion_destino = vertices->obtener_posicion(destino->obtener_fila(), destino->obtener_columna());

    if(posicion_origen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicion_destino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    camino_minimo(posicion_origen, posicion_destino);
    //delete algoritmo_camino_minimo;//borro el dijkstra
}

void Grafo::agrandar_matriz_adyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtener_cantidad_elementos() + 1;
    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiar_matriz_adyacencia(matrizAuxiliar);
    inicializar_vertice(matrizAuxiliar);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matrizAuxiliar;
}

void Grafo::copiar_matriz_adyacencia(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        for(int j = 0; j < vertices -> obtener_cantidad_elementos(); j++){
            nueva_adyacente[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        nueva_adyacente[vertices -> obtener_cantidad_elementos()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_cantidad_elementos()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_cantidad_elementos()][vertices -> obtener_cantidad_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_adyacencia = nullptr;
    delete vertices;
    delete algoritmo_camino_minimo;
}

/*void Grafo::mostrar_vertices() {
    cout << "Lista de vértices: [";
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        Casillero *casillero_aux = new Casillero;
        cout << vertices -> obtener_nombre_nodo(i + 1);
        if(i + 1 != vertices -> obtener_cantidad_elementos()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}*/

void Grafo::mostrar_matriz_adyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        for(int j = 0; j < vertices -> obtener_cantidad_elementos() * 2; j++) {
            if(j == vertices -> obtener_cantidad_elementos() * 2 - 1){
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

void Grafo::usar_dijkstra() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Dijkstra(vertices, matriz_adyacencia);
}

void Grafo::asignar_adyacentes(char jugador, Casillero *origen, Casillero *destino, Mapa *mapa)
{
    agregar_vertices(mapa);

    agregar_camino(mapa, jugador);

}

/*void Grafo::asignar_pesos(Casillero *casillero_origen, Casillero *casillero_destino, char jugador)
{
    int peso_origen = 0, peso_destino = 0;
    if(jugador == 'J')
    {
        obtener_peso(casillero_origen->obtener_caracter(), &peso_origen, PESO_LAGO_1, PESO_MUELLE_1);
        obtener_peso(casillero_destino->obtener_caracter(), &peso_destino, PESO_LAGO_1, PESO_MUELLE_1);
    }
    if(jugador == 'U')
    {
        obtener_peso(casillero_origen->obtener_caracter(), &peso_origen, PESO_LAGO_2, PESO_MUELLE_2);
        obtener_peso(casillero_destino->obtener_caracter(), &peso_destino, PESO_LAGO_2, PESO_MUELLE_2);
    }
    this->agregar_camino(casillero_origen, casillero_destino, peso_origen, peso_destino);//peso_destino);
}*/

void Grafo::obtener_peso(char tipo_casillero, int *peso, int peso_L, int peso_M)
{   
    switch (tipo_casillero)
    {
    case 'L':
        break;
        *peso = peso_L;
    case 'B':
        *peso = PESO_BETUN;
        break;
    case 'M':
        *peso = peso_M;
        break;
    case 'T':
        *peso = PESO_TERRENO;
        break;
    case 'C':
        *peso = PESO_CAMINO;
        break;
    default:
        break;
    }
    
}

void Grafo::agregar_vertices(Mapa *mapa)
{
    Casillero *casillero;
    for (unsigned int i = 0; i < mapa->obtener_cantidad_filas(); i++)
        for (unsigned int j = 0; j < mapa->obtener_cantidad_columnas(); j++)
        {
            casillero = mapa->obtener_casillero(i,j);
            agregar_vertice(casillero);
        }
}

void Grafo::asignar_pesos(Casillero *casillero_origen, Casillero *casillero_destino, unsigned int *peso_origen, unsigned int *peso_destino, char jugador)
{
    *peso_origen=casillero_origen->obtener_costo_energia(jugador);
    *peso_destino=casillero_destino->obtener_costo_energia(jugador);
}

int Grafo::asignar_peso_jugador_contrario(char jugador_contrario, char jugador_actual)
{
    int peso_destino=0;
    //vertices->obtener_posicion(i, j);

    if(jugador_contrario=='U')
        if(jugador_actual=='J')
            peso_destino = INFINITO;//asignar_peso_jugador_contrario(i, j+1, jugador_contrario, mapa);

    if(jugador_contrario=='J')
        if(jugador_actual=='U')
            peso_destino = INFINITO;

    return peso_destino;
}
