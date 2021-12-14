#ifndef ABB_H
#define ABB_H

#include <iostream>
#include "ABB_nodo.h"

#include <string>
#include <fstream>

using namespace std;
template <class T>
class ABB
{
private:
    //Atributos

    ABBnodo<T> *raiz;

    //Metodos

    // PRE: Clave y dato válido
    // POST: Verifica si nodo = 0 y en caso afirmativo crea un nodo y setea exito en true.
    // En caso contrario compara la clave del nodo con clave para ver donde insertar el dato.
    // Si la clave del nodo es igual a clave pone exito en false y no inserta el dato.
    ABBnodo<T> *insertar(ABBnodo<T> *nodo, K clave, T dato, bool* exito);

    // POST: Imprime la rama izquierda al nodo, luego el nodo y rama derecha.    
    void imprimir_en_orden(ABBnodo<T> *nodo);

    // POST: Escribe en archivo, la rama izquierda al nodo, luego el nodo y rama derecha.    
    void exportar_en_orden(ABBnodo<T> *nodo, ofstream& archivo);

    // POST: Si la clave del nodo es clave o si nodo = 0 devuelve nodo.
    // Si la clave del nodo es menor a clave aplica buscar al hijo derecho.
    // Si la clave del nodo es mayor a clave aplica buscar al hijo izquierdo.
    ABBnodo<T>* buscar(ABBnodo<T>* nodo, K clave);

    // POST: Si nodo en 0 devuelve CLAVE_INVALIDA.
    // Si el nodo no tiene hijo izquierdo devuleve la clave del nodo.
    // En otro caso aplica encontrarMinimo al hijo izquierdo.
    T buscar_min(ABBnodo<T> *nodo);

    // POST: Si nodo en 0 devuelve CLAVE_INVALIDA.
    // Si el nodo no tiene hijo derecho devuleve la clave del nodo.
    // En otro caso aplica buscar_max al hijo derecho..+
    T buscar_max(ABBnodo<T> *nodo);

    // POST: dado un nodo devuelve la clave sucesora a la del mimo.
    // Si no existe devuelve CLAVE_INVALIDA
    T sucesor(ABBnodo<T> *nodo);

    // POST: dado un nodo devuelve la clave predecesora a la del mimo.
    // Si no existe devuelve CLAVE_INVALIDA
    T predecesor(ABBnodo<T> *nodo);

    // POST: Si la clave del nodo es clave remueve el nodo. Si no tiene 2 hijo devuelve alguno de los hijos
    // Si tiene 2 hijos cambia el dato con el del sucesor y adquiere la clave del mismo.
    // Devuelve nodo y aplica ramover al sucesor.
    // Si la clave del nodo es mayor a clave aplica remover al hijo izquierdo.
    // Si la clave del nodo es menor a clave aplica remover al hijo derecho.
    // En Estos 2 casos devuelve nodo.
    ABBnodo<T> *remover(ABBnodo<T> *nodo, T dato);

    // POST: Dado un nodo devuelve su altura.
    void eliminar_todo(ABBnodo<T> *nodo);

public:
    // PRE:
    // POST: Crea un arbol vacio
    ABB();
    
    // PRE: Clave y dato válidos
    // POST: Agrega un nuevo nodo. 
    // Si el arbol esta vacio, el nodo insertado será la raiz. 
    // Devuelve true si se pudo insertar
    bool insertar(K clave, T dato);

    // PRE:
    // POST: devuleve true si el ABB esta vacio
    bool vacio();

    // PRE:
    // POST: Imprime toda la data almacenada en el ABB, ordenado desde el valor mas pequeño hasta el mas grande
    void imprimir_en_orden();

    // PRE: Recibe archivo
    // POST: Guarda en un archivo toda la data almacenada en el ABB, ordenado desde el valor mas pequeño hasta el mas grande
    void exportar_en_orden(ofstream& archivo);

    // PRE: Clave válida
    // POST: Busca un valor dado en el ABB. Si existe devuelve TRUE, sino FALSE.
    bool buscar(K clave);

    // PRE: Clave válida
    // POST: Retorna el dato asociado a una clave
    T obtener_dato(K clave);

    // PRE: -
    // POST: Encuentra el minimo valor que existe en el ABB.
    // Retorna CLAVE_INVALIDA si el arbol esta vacio
    T buscar_min();

    // PRE: -
    // POST: Encuentra el maximo valor que existe en el ABB.
    // Retorna CLAVE_INVALIDA si el arbol esta vacio
    T buscar_max();

    // PRE: Dato válido
    // POST: Encuentra el sucesor de un valor dado.
    // Retorna CLAVE_INVALIDA si no existe un sucesor o la clave ingresada no se encuentra.    
    T sucesor(T dato);

    // PRE: Dato válido
    // POST: Encuentra el predecesor de un valor dado.
    // Retorna CLAVE_INVALIDA si no existe un predecesor o la clave ingresada no se encuentra.
    T predecesor(T dato);

    // PRE: Dato válido
    // POST: Remueve la clave y el dato asociado a la misma
    void remover(T dato);

    // PRE:
    // POST: el atributo raiz.
    ABBnodo<T> *get_raiz();

    // POST: Borra todos los nodos del ABB
    void eliminar_todo();

    // PRE:
    // POST: Destruye ABB
    ~ABB<T>();
};

template <class T>
ABB<T>::ABB()
{
    this->raiz = NULL;
}

template <class T>
ABBnodo<T>* ABB<T>::insertar(ABBnodo<T>* nodo, K clave, T dato, bool* exito) {

    if (nodo == 0) {
        nodo = new ABBnodo<T>(clave, dato);
        *exito = true;
    }

    else if (clave > nodo->get_clave()) {
        nodo->set_derecha(insertar(nodo->get_derecha(), clave, dato, exito), nodo);
    }

    else if (clave < nodo->get_clave()){
        nodo->set_izquierda(insertar(nodo->get_izquierda(), clave, dato, exito), nodo);
    }
    else
    {
        *exito = false;
    }
    return nodo;
}

template <class T>
bool ABB<T>::insertar(K clave, T dato)
{
    bool exito = false;
    if (clave == CLAVE_INVALIDA)
        cout << "clave invalida, no se pued eusar en el ABB" <<endl;
    else
        this->raiz = insertar(this->raiz, clave, dato, &exito);
    return exito;
}

template <class T>
bool ABB<T>::vacio()
{
    return this->raiz == NULL;
}

template <class T>
void ABB<T>::imprimir_en_orden(ABBnodo<T> *nodo)
{
    if(nodo == NULL)
        return;
    else{
        imprimir_en_orden(nodo->get_izquierda());

        cout<<"\t"<<*(nodo->get_dato())<<endl;

        imprimir_en_orden(nodo->get_derecha()); 
    }
}

template <class T>
void ABB<T>::exportar_en_orden(ABBnodo<T> *nodo, ofstream& archivo)
{
    if(nodo == NULL)
        return;
    else{
        exportar_en_orden(nodo->get_izquierda(), archivo);

        archivo >>*(nodo->get_dato());
        archivo << '\n';

        exportar_en_orden(nodo->get_derecha(), archivo);
    }
}

template <class T>
void ABB<T>::imprimir_en_orden()
{
    return imprimir_en_orden(this->raiz);
}

template <class T>
void ABB<T>::exportar_en_orden(ofstream& archivo)
{
    return exportar_en_orden(this->raiz, archivo);
}

template <class T>
ABBnodo<T> *ABB<T>::buscar(ABBnodo<T> *nodo, K clave) //misma complejidad que busqueda binaria, log2(n)
{
    if (nodo == NULL || nodo->get_clave() == clave)
        return nodo;

    if (clave > nodo->get_clave())
        return buscar(nodo->get_derecha(), clave);

    return buscar(nodo->get_izquierda(), clave);
}

template <class T>
bool ABB<T>::buscar(K clave)
{
    ABBnodo<T> *result = buscar(this->raiz, clave);

    return result != NULL;
}

template <class T>
T ABB<T>:: obtener_dato(K clave){
    ABBnodo<T>* resultado = buscar(this->raiz, clave);

    //if(resultado != 0)
    return resultado->get_dato();
    //return 0;
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
    return buscar_min(this->raiz);
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
    return buscar_max(this->raiz);
}

template <class T>
T ABB<T>::sucesor(ABBnodo<T> *nodo)

{
    if (nodo->get_derecha() != NULL)
    {
        return buscar_min(nodo->get_derecha());
    }
    ABBnodo<T> *sucesor = NULL;
    ABBnodo<T> *ancestor = this->raiz;
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
    ABBnodo<T> *dato_nodo = this->buscar(this->raiz, dato);
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
    ABBnodo<T> *ancestor = this->raiz;
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
    ABBnodo<T> *dato_nodo = this->buscar(this->raiz, dato);

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
        if (nodo->es_hoja())
            delete nodo;
        else if (nodo->solo_hijo_derecha())
        {
            // The only child will be connected to the parent's of nodo directly
            nodo->get_derecha()->set_padre(nodo->get_padre());
            // Bypass nodo
            ABBnodo<T> *aux = nodo;
            nodo = nodo->get_derecha();
            delete aux;
        }
        else if (nodo->solo_hijo_izquierda())
        {
            // The only child will be connected to the parent's of nodo directly
            nodo->get_izquierda()->set_padre(nodo->get_padre());
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
    this->raiz = remover(this->raiz, dato);
}

template <class T>
ABBnodo<T> *ABB<T>::get_raiz()
{
    return this->raiz;
}

template <class T>
void ABB<T>::eliminar_todo(ABBnodo<T> *nodo)
{
    if (nodo == NULL) return;

    this->eliminar_todo(nodo->get_izquierda());
    this->eliminar_todo(nodo->get_derecha());
    delete nodo;
}

template <class T>
void ABB<T>::eliminar_todo()
{
    this->eliminar_todo(this->raiz);
    raiz = 0;
}

template <class T>
ABB<T>::~ABB<T>()
{
    this->eliminar_todo();
}

#endif