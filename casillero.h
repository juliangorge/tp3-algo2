#ifndef CASILLERO_H
#define CASILLERO_H

#include <string>
#include "Edificio.h"
#include "Material.h"


using namespace std;

/*
Métodos virtuales:
Debería delegarlos esta_libre() y cambiarObjeto()?
*/

class Casillero
{
    protected:
        string nombre;
        char caracter;
        bool transitable;
        bool inaccesible;
        bool construible;
        bool casillero_ocupado;
        int jugador;
        // Es un camino transitable
        bool es_camino;

        // Es un terreno
        bool es_terreno;

        // Nombre del casillero (fijo)
        string nombre_casillero;

        char caracter;

        Edificio* edificio;

        Material* material;

        unsigned int costo_energia;

    public:
        Casillero();
        //~Casillero();

        // PRE: -
        // POS: retorna true si es transitable, false si no lo es
        bool es_transitable();

        // PRE: -
        // POS: retorna true si es inaccesible, false si no lo es
        bool es_inaccesible();

        // PRE: -
        // POS: retorna true si es construible, false si no lo es
        bool es_construible();

        // PRE: -
        // POS: Cambia el valor de un casillero según el objeto que lo ocupe
        void cambiar_objeto(string nombre, char tipo_objeto, int jugador);
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
        // POST: Retorna el nombre del casillero
        string obtener_nombre_casillero();
        
        // PRE:
        // POST: Retorna el obtener_caracter de casillero
        char obtener_caracter();
        
        // PRE: Recibe puntero edificio
        // POST: Referencia el atributo edificio al parametro recibido
        void cargar(Edificio* edificio);

        // PRE: Recibe puntero material
        // POST: Referencia el atributo material al parametro recibido
        void cargar(Material* material);
    
        // PRE:
        // POST: Cambia el tipo de casillero por edificio_char en el caso de que el mismo este ocupado por una construccion
        void cambiar_objeto();

        // PRE: 
        // POST: Desreferencia el atributo edificio
        void limpiar_casillero();

        // PRE:
        // POST: Retorna el costo de energía
        unsigned int obtener_costo_de_energia();
};

#endif // CASILLERO_H
