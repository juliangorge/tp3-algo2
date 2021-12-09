#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include "Nodo.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;

template < typename Tipo >
class Lista{
/*ATRIBUTOS*/
private:
    int cantidad_elementos;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;
    int x;
    int y;


/*MÉTODOS*/
public:
    Lista();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtener_cantidad_elementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtener_posicion(unsigned int x, unsigned int y);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    Casillero *obtener_casillero_nodo(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(Casillero *nuevo_elemento);
    
    /*unsigned int obtener_x();

    unsigned int obtener_y();*/

    ~Lista();
};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidad_elementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
    int x=0;
    int y=0;
}

template < typename Tipo >
int Lista<Tipo>::obtener_cantidad_elementos(){
    return cantidad_elementos;
}




template < typename Tipo >
int Lista<Tipo>::obtener_posicion(unsigned int casillero_x, unsigned int casillero_y) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;
    Casillero *casillero = auxiliar->obtener_casillero();

    while(!elementoEncontrado && i < cantidad_elementos){
        if(casillero->obtener_fila() == casillero_x && casillero->obtener_columna() == casillero_y){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elementoEncontrado)
    {
        cout << "Posicion no encontrada" << endl;
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(Casillero *nuevo_elemento) {
    Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(nuevo_elemento);
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    cantidad_elementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
Casillero *Lista<Tipo>::obtener_casillero_nodo(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_elementos){
        cout << "Casillero no encontrado" << endl;
        return nullptr;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    
    return auxiliar -> obtener_casillero();
}

#endif //GRAFOS_LISTA_H
