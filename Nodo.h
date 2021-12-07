#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>

using namespace std;

template < typename Tipo >
class Nodo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo<Tipo>* siguiente;
    unsigned int x;
    unsigned int y;

/*MÉTODOS*/
public:
    Nodo(string nombre);

    //post: devuelve el nodo siguiente.
    Nodo<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    string obtenerNombre();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(Nodo<Tipo>* siguiente);

    unsigned int obtener_x();

    unsigned int obtener_y();

    ~Nodo();
};

template<typename Tipo>
Nodo<Tipo>::Nodo(string nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo<Tipo>::obtenerNombre() {
    return elemento -> obtenerNombre();
}

template<typename Tipo>
void Nodo<Tipo>::asignarSiguiente(Nodo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template < typename Tipo >
unsigned int Nodo<Tipo>::obtener_x()
{
    return this->x;
}

template < typename Tipo >
unsigned int Nodo<Tipo>::obtener_y()
{
    return this->y;
}

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
