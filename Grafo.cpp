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
    unsigned int posicion_origen=0, posicion_destino=0;
    
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

unsigned int Grafo::camino_minimo(Casillero *origen, Casillero *destino) 
{
    unsigned int posicion_origen = vertices->obtener_posicion(origen->obtener_fila(), origen->obtener_columna());
    unsigned int posicion_destino = vertices->obtener_posicion(destino->obtener_fila(), destino->obtener_columna());

    if(posicion_origen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicion_destino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }
    return camino_minimo(posicion_origen, posicion_destino);
}

void Grafo::agrandar_matriz_adyacencia() {
    unsigned int** matriz_auxiliar;
    unsigned int nuevaCantidadDeVertices = vertices->obtener_cantidad_elementos() + 1;
    matriz_auxiliar = new unsigned int*[nuevaCantidadDeVertices];
    for(unsigned int i = 0; i < nuevaCantidadDeVertices; i++){
        matriz_auxiliar[i] = new unsigned int[nuevaCantidadDeVertices];
    }

    copiar_matriz_adyacencia(matriz_auxiliar);
    inicializar_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacencia(unsigned int** nueva_adyacente) {
    for(unsigned int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        for(unsigned int j = 0; j < vertices -> obtener_cantidad_elementos(); j++){
            nueva_adyacente[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_vertice(unsigned int** nueva_adyacente) {
    for(unsigned int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        nueva_adyacente[vertices -> obtener_cantidad_elementos()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_cantidad_elementos()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_cantidad_elementos()][vertices -> obtener_cantidad_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(unsigned int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
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

void Grafo::mostrar_matriz_adyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(unsigned int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        for(unsigned int j = 0; j < vertices -> obtener_cantidad_elementos() * 2; j++) {
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
unsigned int Grafo::camino_minimo(unsigned int origen, unsigned int destino) {
    return algoritmo_camino_minimo -> camino_minimo(origen, destino);
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

void Grafo::asignar_pesos(Casillero *origen, Casillero *destino, unsigned int *peso_origen, unsigned int *peso_destino, char jugador)
{
    *peso_origen=origen->obtener_costo_energia(jugador);
    *peso_destino=destino->obtener_costo_energia(jugador);
}

estados_t Grafo::usar_grafo(Casillero *origen, Casillero *destino, Mapa *mapa, Jugador *jugador)
{
    unsigned int costo_camino = 0;
    estados_t st = ST_OK;
    asignar_adyacentes(jugador->obtener_caracter(), origen, destino, mapa);
    usar_dijkstra();
    
    costo_camino = camino_minimo(origen, destino);
    cout << "Costo del camino: " << costo_camino << endl;
    
    if((st = jugador->verificar_energia_suficiente(costo_camino))== ST_OK)
        jugador->decrementar_energia(costo_camino);

    return st;
}

void Grafo::recorrer_casilleros_paso(Mapa *mapa, Casillero *origen, Casillero *destino, Jugador *jugador)
{
    unsigned int fila_paso=0, columna_paso=0;
    unsigned int posicion_origen = vertices->obtener_posicion(origen->obtener_fila(), origen->obtener_columna());
    unsigned int posicion_destino = vertices->obtener_posicion(destino->obtener_fila(), destino->obtener_columna());

    algoritmo_camino_minimo->obtener_casillero_recorrido(&fila_paso, &columna_paso, posicion_origen, posicion_destino);

    Casillero *casillero_aux = mapa->obtener_casillero(fila_paso, columna_paso);
    Material *material_aux;
    
    if((material_aux = casillero_aux->obtener_material())!=nullptr)
    {
        jugador->agregar_material(material_aux->obtener_nombre(), material_aux->obtener_cantidad());
        casillero_aux->limpiar_casillero();
    }
    do
    {
        posicion_destino = algoritmo_camino_minimo->obtener_posicion_destino(posicion_destino);
        algoritmo_camino_minimo->obtener_casillero_recorrido(&fila_paso, &columna_paso, posicion_origen, posicion_destino);
        casillero_aux = mapa->obtener_casillero(fila_paso, columna_paso);
        if ((material_aux = casillero_aux->obtener_material()) != nullptr)
        {
            cout << "En el camino se encontro " << material_aux->obtener_cantidad() << " de " << material_aux->obtener_nombre() << endl;
            jugador->agregar_material(material_aux->obtener_nombre(), material_aux->obtener_cantidad());

            if(material_aux->obtener_nombre() == NOMBRE_ANDYCOINS)
                jugador->agregar_andycoins_acumuladas(material_aux->obtener_cantidad());

            casillero_aux->limpiar_casillero();
        }

    } while (posicion_origen != posicion_destino);

}