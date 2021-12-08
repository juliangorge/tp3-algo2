#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include <string>
#include "Edificio.h"
#include "Material.h"
#include "Mensajes_de_error.h"

using namespace std;

/*
Métodos virtuales:
Debería delegarlos esta_libre() y cambiarObjeto()?
*/

class Casillero
{
    protected:

        unsigned int fila;
        unsigned int columna;

        // Es un camino transitable
        bool es_camino;

        // Es un terreno
        bool es_terreno;

        // Nombre del casillero (fijo)
        string nombre_casillero;

        char caracter;

        char caracter_casillero;

        char caracter_jugador;

        Edificio* edificio;

        Material* material;

        unsigned int costo_energia;

        bool necesita_reparacion;

    public:
        Casillero(unsigned int fila, unsigned int columna);
        //~Casillero();

        unsigned int obtener_fila();
        unsigned int obtener_columna();

        // PRE:
        // POST: Retorna si el casillero está libre de construcciones/materiales
        bool esta_libre();

        // PRE: 
        // POST: Retorna el objeto Edificio
        Edificio* obtener_edificio();
        
        // PRE: 
        // POST: Retorna el objeto Material
        Material* obtener_material();
        
        // PRE:
        // POST: Retorna el caracter del casillero o del elemento que contiene
        char obtener_caracter();

        // PRE:
        // POST: Retorna el caracter de casillero
        char obtener_caracter_casillero();

        // PRE:
        // POST: Retorna el nombre del casillero
        string obtener_nombre_casillero();
        
        // PRE: Recibe puntero edificio
        // POST: Referencia el atributo edificio al parametro recibido
        estados_t cargar_edificio(Edificio* edificio, char caracter_jugador);

        // PRE: Recibe puntero material
        // POST: Referencia el atributo material al parametro recibido
        void cargar_material(Material* material);
    
        // PRE:
        // POST: Cambia el tipo de casillero por edificio_char en el caso de que el mismo este ocupado por una construccion
        virtual void cambiar_objeto() = 0;

        // PRE: 
        // POST: Desreferencia el atributo edificio
        estados_t limpiar_casillero(char a);

        // PRE:
        // POST: Retorna el costo de energía
        unsigned int obtener_costo_de_energia();
 
        bool es_construible();

        void mostrar_edificios();

        void ocupar_casillero(char caracter);

        virtual void mostrar_casillero() = 0;
};

#endif // CASILLERO_H
