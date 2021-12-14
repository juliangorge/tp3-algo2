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
    // PRE: 
    // POST: Construye el objeto Nodo
    Nodo(Casillero *casillero);

    // POST: Retorna el nodo siguiente.
    Nodo<Tipo>* obtener_siguiente();

    // POST: Retorna el casillero del nodo
    Casillero *obtener_casillero();

    // PRE: Recibe nodo valido
    // POST: Asigna como siguiente el nodo recibido
    void asignar_siguiente(Nodo<Tipo>* siguiente);

    // PRE: 
    // POST: Destruye el objeto Nodo
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


template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
