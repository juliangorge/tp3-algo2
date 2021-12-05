<<<<<<< HEAD
/*#ifndef EDIFICIO_MINA_H
#define EDIFICII_MINA_H
=======
#ifndef EDIFICIO_MINA_H
#define EDIFICIO_MINA_H
>>>>>>> 8511418196802496177b7797dc0f87ee6ae66277

#include "Edificio.h"
#include "Material.h"

#include <string>

using namespace std;

class Mina : public Edificio
{
    public:
        // Constructor
        // PRE: -
        // POS: crea un objeto del tipo escuela
        Mina(string nombre, unsigned int piedra, unsigned int madera, unsigned int metal, unsigned int maximo);

        // PRE: -
        // POS: devuelve al inventario la cantidad de materiales correspondiente a este objeto
        void recolectar_materiales(Material **lista_mats, int cantidad_mats_lista);

};

#endif*/