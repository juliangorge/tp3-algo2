#ifndef ABB_NODO_H
#define ABB_NODO_H

#include <iostream>
#include <string>
#include "Constantes.h"

template <class T>
class ABBnodo
{
    private:
        K clave;
        T dato;
        ABBnodo<T>* izquierda; //puntero al arbol izquierdo
        ABBnodo<T>* derecha; //puntero al arbol derecho
        ABBnodo<T>* padre;

    public:
        //PRE:
        //POST: Crea un objeto ABBnodo, inicializando hijo izquierda, derecha y padre en nulo
        ABBnodo(K clave, T dato);

        //PRE:
        //POST: destruye en objeto ABBnodo
        virtual ~ABBnodo();

        //PRE:
        //POST: Retorna la clave del nodo
        K get_clave();

        //PRE:
        //POST: Retorna el dato del nodo
        T get_dato();

        //PRE: clave y dato válidos
        //POST: setea la clave del nodo
        void set_clave(K clave, T dato);

        //PRE: dato válido
        //POST: setea el dato del nodo
        void set_dato(T dato);

        //PRE: puntero a nodo derecha y padre validos
        //POST: setea el hijo derecho y el padre
        void set_derecha(ABBnodo<T>* derecha, ABBnodo<T>* padre);
        
        //PRE: puntero a nodo derecha y padre validos
        //POST: setea el hijo izquierdo y el padre
        void set_izquierda(ABBnodo<T>* izquierda, ABBnodo<T>* padre);
        
        //PRE: puntero a nodo derecha y padre validos
        //POST: setea el hijo izquierdo
        void set_derecha(ABBnodo<T>* derecha);
        
        //PRE: puntero a nodo derecha y padre validos
        //POST: setea el hijo derecho
        void set_izquierda(ABBnodo<T>* izquierda);

        //PRE: puntero a nodo padre valido
        //POST: setea el padre
        void set_padre(ABBnodo<T>* padre);

        //PRE:
        //POST: Retorna Hijo derecho        
        ABBnodo<T>* get_derecha();

        //PRE:
        //POST: Retorna Hijo izquierdo
        ABBnodo<T>* get_izquierda();

        //PRE:
        //POST: Retorna padre
        ABBnodo<T>* get_padre();

        //PRE:
        //POST: Retorna TRUE si no tiene hijos
        bool es_hoja();

        //PRE:
        //POST: Retorna TRUE si tiene hijo derecho pero no izquierdo
        bool solo_hijo_derecha();

        //PRE:
        //POST: Retorna TRUE si tiene hijo izquierdo pero no derecho
        bool solo_hijo_izquierda();
};

template <class T>
ABBnodo<T>::ABBnodo(K clave, T dato)
{
    this->clave = clave;
    this->dato = dato;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->padre = NULL;
}


template <class T>
ABBnodo<T>::~ABBnodo()
{
    if(dato != 0) delete dato;
}

template <class T>
K ABBnodo<T>::get_clave()
{
    return this->clave;
}

template <class T>
T ABBnodo<T>::get_dato()
{
    return this->dato;
}

template <class T>
void ABBnodo<T>::set_derecha(ABBnodo<T>* derecha, ABBnodo<T>* padre)
{
    this->derecha = derecha;
    this->padre = padre;
}

template <class T>
void ABBnodo<T>::set_derecha(ABBnodo<T>* derecha)
{
    this->derecha = derecha;
}

template <class T>
void ABBnodo<T>::set_izquierda(ABBnodo<T>* izquierda, ABBnodo<T>* padre)
{
    this->izquierda = izquierda;
    this->padre = padre;
}

template <class T>
void ABBnodo<T>::set_padre(ABBnodo<T> *padre) 
{
    this->padre = padre;
}


template <class T>
void ABBnodo<T>::set_dato(T dato) 
{
    this->dato = dato;
}


template <class T>
void ABBnodo<T>::set_izquierda(ABBnodo<T>* izquierda)
{
    this->izquierda = izquierda;
}

template <class T>
ABBnodo<T>* ABBnodo<T>::get_derecha()
{
    return this->derecha;
}

template <class T>
ABBnodo<T>* ABBnodo<T>::get_izquierda()
{
    return this->izquierda;
}

template <class T>
ABBnodo<T>* ABBnodo<T>::get_padre()
{
    return this->padre;
}

template <class T>
bool ABBnodo<T>::es_hoja() {
    return (this->get_izquierda() == NULL && this->get_derecha() == NULL);
}

template <class T>
bool ABBnodo<T>::solo_hijo_derecha() {
    return (this->get_izquierda() == NULL && this->get_derecha() != NULL);
}

template <class T>
bool ABBnodo<T>::solo_hijo_izquierda() {
    return (this->get_izquierda() != NULL && this->get_derecha() == NULL);
}

#endif//ABB_NODO_H