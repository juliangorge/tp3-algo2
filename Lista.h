#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";

template < typename Tipo >
class Lista{
/*ATRIBUTOS*/
private:
    int cantidad_elementos;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;


/*MÉTODOS*/
public:
    Lista();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtenerCantidadDeElementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtener_posicion(unsigned int x, unsigned int y);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    string obtenerNombre(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(string nuevoElemento);

    unsigned int obtener_x();

    unsigned int obtener_y();

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
int Lista<Tipo>::obtenerCantidadDeElementos(){
    return cantidad_elementos;
}




template < typename Tipo >
int Lista<Tipo>::obtener_posicion(unsigned int casillero_x, unsigned int casillero_y) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidad_elementos){
        if(auxiliar->obtener_x() == casillero_x && auxiliar->obtener_y() == casillero_y){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(string nuevoElemento) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(nuevoElemento);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidad_elementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
string Lista<Tipo>::obtenerNombre(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_elementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar -> obtenerNombre();
}

#endif //GRAFOS_LISTA_H
