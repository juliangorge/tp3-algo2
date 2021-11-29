#ifndef ABB_NODO_H
#define ABB_NODO_H

template <class T>
class ABBnodo
{
    private:
        T dato;
        ABBnodo<T>* izquierda; //puntero al arbol izquierdo
        ABBnodo<T>* derecha; //puntero al arbol derecho
        ABBnodo<T>* padre;

    public:
        ABBnodo(T dato);
        T get_dato();
        void set_dato(T dato);
        void set_derecha(ABBnodo<T>* derecha, ABBnodo<T>* padre);
        void set_izquierda(ABBnodo<T>* izquierda, ABBnodo<T>* padre);
        void set_derecha(ABBnodo<T>* derecha);
        void set_izquierda(ABBnodo<T>* izquierda);
        void set_padre(ABBnodo<T>* padre);
        ABBnodo<T>* get_derecha();
        ABBnodo<T>* get_izquierda();
        ABBnodo<T>* get_padre();
        bool es_hoja();
        bool solo_hijo_derecha();
        bool solo_hijo_izquierda();
};

template <class T>
ABBnodo<T>::ABBnodo(T dato)
{
    this->dato = dato;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->padre = NULL;
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
