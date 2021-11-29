#include <iostream>
#include "ABB_nodo.h"

#ifndef ABB_H
#define ABB_H

template <class T>
class ABB
{
private:
    //atributos
    ABBnodo<T> *root;
    //metodos
    ABBnodo<T> *insertar(ABBnodo<T> *nodo, T dato);
    void imprimir_en_orden(ABBnodo<T> *nodo);
    ABBnodo<T> *buscar(ABBnodo<T> *nodo, T dato);
    T buscar_min(ABBnodo<T> *nodo);
    T buscar_max(ABBnodo<T> *nodo);
    T sucesor(ABBnodo<T> *nodo);
    T predecesor(ABBnodo<T> *nodo);
    ABBnodo<T> *remover(ABBnodo<T> *nodo, T dato);
    void eliminar_todo(ABBnodo<T> *nodo);

public:
    ABB();
    void insertar(T dato);
    bool vacio();
    void imprimir_en_orden();
    bool buscar(T dato);
    T buscar_min();
    T buscar_max();
    T sucesor(T dato);
    T predecesor(T dato);
    void remover(T dato);
    ABBnodo<T> *get_root();
    // Deletes all the nodes in the BST
    void eliminar_todo();
    ~ABB<T>();
};

template <class T>
ABB<T>::ABB()
{
    this->root = NULL;
}

template <class T>
ABBnodo<T> *ABB<T>::insertar(ABBnodo<T> *nodo, T dato) //recibe la raiz y el dato
{
    //cada vez que quiera agregar un dato, tengo que compararlo con el nodo que
    //tengo como raiz para ver si es más grande o más chico
    if (nodo == NULL)
    {
        nodo = new ABBnodo<T>(dato);
    }

    else if (dato > nodo->get_dato())
    {
        nodo->set_derecha(insertar(nodo->get_derecha(), dato, nodo));
    }

    else
    {
        nodo->set_izquierda(insertar(nodo->get_izquierda(), dato), nodo);
    }

    return nodo;
}

template <class T>
bool ABB<T>::vacio()
{
    return this->root == NULL;
}

template <class T>
void ABB<T>::insertar(T dato)
{
    this->root = insertar(this->root, dato);
}

template <class T>
void ABB<T>::imprimir_en_orden(ABBnodo<T> *nodo)
{
    if (nodo != NULL)
    {
        imprimir_en_orden(nodo->get_izquierda());
    }
}

template <class T>
ABBnodo<T> *ABB<T>::buscar(ABBnodo<T> *nodo, T dato) //misma complejidad que busqueda binaria, log2(n)
{
    if (nodo == NULL || nodo->get_dato() == dato)
        return nodo;

    if (dato > nodo->get_dato())
        return buscar(nodo->get_derecha(), dato);

    return buscar(nodo->get_izquierda(), dato);
}

template <class T>
bool ABB<T>::buscar(T dato)
{
    ABBnodo<T> *result = buscar(this->root, dato);

    return result != NULL;
}

template <class T>
T ABB<T>::buscar_min(ABBnodo<T> *nodo)
{
    if (nodo == NULL)
        return -1;
    else if (nodo->get_izquierda() == NULL)
        return nodo->get_dato();
    else
        return buscar_min(nodo->get_izquierda());
}

template <class T>
T ABB<T>::buscar_min()
{
    return buscar_min(this->root);
}

template <class T>
T ABB<T>::buscar_max(ABBnodo<T> *nodo)
{
    if (nodo == NULL)
        return -1;
    else if (nodo->get_derecha() == NULL)
        return nodo->get_dato();
    else
        return buscar_max(nodo->get_derecha());
}

template <class T>
T ABB<T>::buscar_max()
{
    return buscar_max(this->root);
}

template <class T>
T ABB<T>::sucesor(ABBnodo<T> *nodo)

{
    if (nodo->get_derecha() != NULL)
    {
        return buscar_min(nodo->get_derecha());
    }
    ABBnodo<T> *sucesor = NULL;
    ABBnodo<T> *ancestor = this->root;
    while (ancestor != nodo)
    {
        if (nodo->get_dato() < ancestor->get_dato())
        {
            sucesor = ancestor;
            ancestor = ancestor->get_izquierda();
        }
        else
            ancestor = ancestor->get_derecha();
    }
    return sucesor->get_dato();
}

template <class T>
T ABB<T>::sucesor(T dato) //el sucesor de un nodo que quiera borrar, va a ser el minimo valor de su sub-arbol derecho
                          //si el nodo no tiene sub-arbol derecho, hay que buscar los ancestros del nodo hasta encontrar uno mayor que el que quiero borrar.
                          //si el nodo a borrar es el máximo del arbol, no tiene sucesor.
{
    ABBnodo<T> *dato_nodo = this->buscar(this->root, dato);
    // Return the key. If the key is not found or sucesor is not found, return -1
    if (dato_nodo == NULL)
        return -1;
    else
        return sucesor(dato_nodo);
}

template <class T>
T ABB<T>::predecesor(ABBnodo<T> *nodo)
//Si el nodo tiene un subarbol izquierdo, su predecesor será el de máximo  valor en ese sub-arbol izquierdo.
//si no tiene sub-arbol izquierdo, hay que buscar en los ancestros un nodo menor al actual.
//Si es el nodo de menor valor, no tiene predecesor.

{
    if (nodo->get_izquierda() != NULL)
    {
        return buscar_max(nodo->get_izquierda());
    }

    ABBnodo<T> *sucesor = NULL;
    ABBnodo<T> *ancestor = this->root;
    while (ancestor != nodo)
    {
        if (nodo->get_dato() > ancestor->get_dato())
        {
            sucesor = ancestor; // so far this is the deepest nodo for which current nodo is in izquierda
            ancestor = ancestor->get_derecha();
        }
        else
            ancestor = ancestor->get_izquierda();
    }
    return sucesor->get_dato();
}

template <class T>
T ABB<T>::predecesor(T dato)
{
    ABBnodo<T> *dato_nodo = this->buscar(this->root, dato);

    if (dato_nodo == NULL)
        return -1;
    else
        return predecesor(dato_nodo);
}

template <class T>
ABBnodo<T> *ABB<T>::remover(ABBnodo<T> *nodo, T dato) //si borro un nodo, tengo que reacomodar todo el arbol para que quede ensamblado y ordenado
{
    // The given nodo is not found in ABB
    if (nodo == NULL)
        return NULL;

    if (nodo->get_dato() == dato)
    {
        if (nodo->isLeaf())
            delete nodo;
        else if (nodo->solo_hijo_derecha())
        {
            // The only child will be connected to the parent's of nodo directly
            nodo->get_derecha()->set_parent(nodo->get_parent());
            // Bypass nodo
            ABBnodo<T> *aux = nodo;
            nodo = nodo->get_derecha();
            delete aux;
        }
        else if (nodo->solo_hijo_izquierda())
        {
            // The only child will be connected to the parent's of nodo directly
            nodo->get_izquierda()->set_parent(nodo->get_parent());
            // Bypass nodo
            ABBnodo<T> *aux = nodo;
            nodo = nodo->get_izquierda();
            delete aux;
        }

        // The nodo has two children (izquierda and derecha)
        else
        {
            // Find sucesor or predecesor to avoid quarrel
            T sucesor_dato = this->sucesor(dato);

            // Replace nodo's key with sucesor's key
            nodo->set_dato(sucesor_dato);

            // Delete the old sucesor's key
            nodo->set_derecha(remover(nodo->get_derecha(), sucesor_dato));
        }
    }

    else if (nodo->get_dato() < dato)
        nodo->set_derecha(remover(nodo->get_derecha(), dato));

    else
        nodo->set_izquierda(remover(nodo->get_izquierda(), dato));

    return nodo;
}

template <class T>
void ABB<T>::remover(T dato)
{
    this->root = remover(this->root, dato);
}

template <class T>
ABBnodo<T> *ABB<T>::get_root()
{
    return this->root;
}

template <class T>
bool ABB<T>::vacio()
{
    return this->root == NULL;
}

template <class T>
void ABB<T>::eliminar_todo(ABBnodo<T> *nodo)
{
    if (nodo == NULL)
        return;
    this->eliminar_todo(nodo->get_izquierda());
    this->eliminar_todo(nodo->get_derecha());
    delete nodo;
}

template <class T>
void ABB<T>::eliminar_todo()
{
    this->eliminar_todo(this->root);
}

template <class T>
ABB<T>::~ABB<T>()
{
    this->eliminar_todo();
}

#endif