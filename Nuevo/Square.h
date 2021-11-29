#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>

using namespace std;

class Square
{
    protected:
        // Es un camino transitable
        bool is_it_path;

        // Es un terreno
        bool is_it_terrain;

        // Nombre del casillero (fijo)
        string square_name;

        char type_square;

    public:
        Square(){};
        virtual ~Square() {};
        
        // PRE:
        // POST: Retorna si es un camino
        virtual bool isPath() = 0;
        
        // PRE:
        // POST: Retorna si es un terreno
        virtual bool isTerrain() = 0;

        
        
        // PRE:
        // POST: Retorna el nombre del casillero
        virtual string getSquareName() = 0;
        
        // PRE:
        // POST: Retorna el tipo de casillero
        virtual char getTypeSquare() = 0;
        
        // PRE:
        // POST: Cambia el tipo de casillero por building_char en el caso de que el mismo este ocupado por una construccion
        virtual void changeObject() = 0;

        // PRE: 
        // POST: Desreferencia el atributo building
        virtual void emptySquare() = 0;
};

#endif // SQUARE_H
