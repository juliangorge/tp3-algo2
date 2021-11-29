#ifndef CASILLERO_H
#define CASILLERO_H

#include <string>
#include "Edificio.h"
#include "Material.h"

using namespace std;

/*
Métodos virtuales:
Debería delegarlos estaLibre() y cambiarObjeto()?
*/

class Casillero
{
    protected:
        // Es un camino transitable
        bool es_camino;

        // Es un terreno
        bool es_terreno;

        // Nombre del casillero (fijo)
        string nombre_casillero;

        char tipo_casillero;

        Edificio* edificio;

        Material* material;

        unsigned int costo_energia;

    public:
        Casillero();
        ~Casillero();

        // PRE:
        // POST: Retorna si el casillero está libre de construcciones/materiales
        bool estaLibre();
        
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
        // POST: Retorna el tipo de casillero
        char obtener_tipo_casillero();
        
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
