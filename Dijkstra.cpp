#include "Dijkstra.h"

Dijkstra::Dijkstra(Lista<Vertice> *vertices, unsigned int **matriz_adyacencia) : Camino_minimo(vertices, matriz_adyacencia) {
    vertices_visitados = new bool[cantidad_vertices];//vector de booleanos
    distancia = new unsigned int[cantidad_vertices];
    recorrido = new unsigned int[cantidad_vertices];
}

unsigned int Dijkstra::camino_minimo(unsigned int origen, unsigned int destino) {
    inicializar_visitados(origen);
    inicializar_distancia(matriz_adyacencia[origen]);
    inicializar_recorrido(origen);

    unsigned int minimo_vertice;

    bool destino_arribado = origen == destino;
    unsigned int vertices_recorridos = 1;
    while(!destino_arribado){
        minimo_vertice = vertice_minima_distancia();
        destino_arribado = minimo_vertice == destino;

        if(!destino_arribado){
            vertices_visitados[minimo_vertice] = true;
            actualizar_distancia(minimo_vertice);
        }
        vertices_recorridos++;
    }

    mostrar_recorrido(origen, destino);
    return distancia[destino];
}

unsigned int Dijkstra::vertice_minima_distancia() {
    unsigned int minima_distancia = INFINITO;
    unsigned int minimo_vertice;

    for(unsigned int i = 0; i < cantidad_vertices; i++){
        if(!vertices_visitados[i] && distancia[i] <= minima_distancia){
            minima_distancia = distancia[i];
            minimo_vertice = i;
        }
    }

    return minimo_vertice;
}

void Dijkstra::inicializar_visitados(unsigned int origen) {
    for(unsigned int i = 0; i < cantidad_vertices; i++)
        vertices_visitados[i] = false;
    vertices_visitados[origen] = true;
}

void Dijkstra::inicializar_recorrido(unsigned int origen) {
    for(unsigned int i = 0; i < cantidad_vertices; i++)
        recorrido[i] = origen;
}

Dijkstra::~Dijkstra() {
    delete[] vertices_visitados;
    delete[] distancia;
    delete[] recorrido;
}

void Dijkstra::inicializar_distancia(const unsigned int * distancia_origen) {
    for(unsigned int i = 0; i < cantidad_vertices; i++)
        distancia[i] = distancia_origen[i];
}

void Dijkstra::actualizar_distancia(unsigned int vertice) {
    for(unsigned int i = 0; i < cantidad_vertices; i++){
        //se fija que el vertice no este visitado                       Condicion para saber si tengo que actualizar una distancia o no
        if(!vertices_visitados[i] && distancia[vertice] != INFINITO && distancia[i] > matriz_adyacencia[vertice][i] + distancia[vertice]){
            distancia[i] = matriz_adyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

void Dijkstra::mostrar_recorrido(unsigned int origen, unsigned int destino) {
    if(distancia[destino] == INFINITO){
        cout << "No hay un camino que conecte " <<  vertices->obtener_nombre(origen+1) << " con " << vertices->obtener_nombre(destino+1);
    }else{
        cout << "El camino minimo que une " <<  vertices->obtener_nombre(origen+1) << " con " << vertices->obtener_nombre(destino+1);
        cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
        cout << vertices->obtener_nombre(destino+1);
        do{
            destino = recorrido[destino];
            cout << " <- " << vertices->obtener_nombre(destino+1);
        }while(origen != destino);
    }
    cout << endl;
}

unsigned int Dijkstra::obtener_posicion_destino(unsigned int destino)
{
    return this->recorrido[destino];
}


void Dijkstra::obtener_casillero_recorrido(unsigned int *fila, unsigned int *columna, unsigned int origen, unsigned int destino)
{

    vertices->obtener_posicion_mapa(destino + 1, fila, columna);

}
