#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include "Casillero.h"

using namespace std;

template < typename Tipo >
class Nodo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo(Casillero *casillero);

    //post: devuelve el nodo siguiente.
    Nodo<Tipo>* obtener_siguiente();

    //post: devuelve el casillero del nodo
    Casillero *obtener_casillero();

    //post: le asigna como siguiente el nodo recibido
    void asignar_siguiente(Nodo<Tipo>* siguiente);

    unsigned int obtener_x();

    unsigned int obtener_y();

    ~Nodo();
};

template<typename Tipo>
Nodo<Tipo>::Nodo(Casillero *casillero) {
    elemento = new Tipo(casillero);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::obtener_siguiente() {
    return siguiente;
}

template<typename Tipo>
Casillero *Nodo<Tipo>::obtener_casillero() {
    return elemento -> obtener_casillero();
}

template<typename Tipo>
void Nodo<Tipo>::asignar_siguiente(Nodo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

/*template < typename Tipo >
unsigned int Nodo<Tipo>::obtener_x()
{
    return this->x;
}

template < typename Tipo >
unsigned int Nodo<Tipo>::obtener_y()
{
    return this->y;
}*/

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
