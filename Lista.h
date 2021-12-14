#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include "Nodo.h"
#include "Constantes.h"

using namespace std;

template < typename Tipo >
class Lista{
/*ATRIBUTOS*/
private:
    unsigned int cantidad_elementos;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;

/*MÉTODOS*/
public:
    // PRE:
    // POST: Crea un objeto Lista
    Lista();

    // POST: devuelve la cantidad de elementos que tiene la lista
    unsigned int obtener_cantidad_elementos();

    // POST: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    unsigned int obtener_posicion(unsigned int x, unsigned int y);

    // POST: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    Casillero *obtener_casillero_nodo(int posicion);

    // POST: agrega un nuevo elemento a la lista
    void agregar(Casillero *nuevo_elemento);

    // POST: devuelve las coordendas de un casillero en formato cadena para imprimirlas
    string obtener_nombre(unsigned int posicion);

    // POST: asigna las coordenadas de un casillero que se encuentra en la lista
    void obtener_posicion_mapa(unsigned int posicion, unsigned int *fila, unsigned int *columna);
    
    // PRE:
    // POST: Destruye un objeto Lista
    ~Lista();
};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidad_elementos = 0;
    ultimo = nullptr;
    primero = nullptr;
}

template < typename Tipo >
unsigned int Lista<Tipo>::obtener_cantidad_elementos(){
    return cantidad_elementos;
}

template < typename Tipo >
unsigned int Lista<Tipo>::obtener_posicion(unsigned int casillero_x, unsigned int casillero_y) {
    bool elemento_encontrado = false;
    unsigned int i = 0;
    Nodo<Tipo>* auxiliar = primero;
    while(!elemento_encontrado && i < cantidad_elementos){
        if(auxiliar->obtener_casillero()->obtener_fila() == casillero_x && auxiliar->obtener_casillero()->obtener_columna() == casillero_y){
            elemento_encontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elemento_encontrado)
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
    unsigned int i = 0;
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


template<typename Tipo>
string Lista<Tipo>::obtener_nombre(unsigned int posicion)
{
    unsigned int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_elementos){
        return "Posicion no encontrada";
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }

    string nombre = "[";
    nombre += to_string(auxiliar->obtener_casillero()->obtener_fila());
    nombre += ",";
    nombre += to_string(auxiliar->obtener_casillero()->obtener_columna());
    nombre += "]";

    return nombre;
}

template<typename Tipo>
void Lista<Tipo>::obtener_posicion_mapa(unsigned int posicion, unsigned int *fila, unsigned int *columna)
{
    unsigned int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }

    *fila = auxiliar->obtener_casillero()->obtener_fila();
    *columna = auxiliar->obtener_casillero()->obtener_columna();
}

#endif //GRAFOS_LISTA_H
