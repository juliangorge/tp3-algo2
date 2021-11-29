#ifndef MAPA_H
#define MAPA_H

#include "Square.h"

#include "PathSquare.h"
#include "TerrainSquare.h"
#include "LakeSquare.h"

#include <string>

using namespace std;

class Mapa
{
    private:
        unsigned int rows;
        unsigned int columns;
        unsigned int path_square_quantity;
        Square*** squares;

    public:
        Mapa();
        void readMap();
        void loadMap(unsigned int rows, unsigned int columns, char square_type);
        void addCoords(unsigned int & row_pos, unsigned int & column_pos);
        bool checkCoords(unsigned int row_pos, unsigned int column_pos);

        void showMap();
        void showCoord(unsigned int row_pos, unsigned int column_pos);
        void emptySquare(unsigned int row_pos, unsigned int column_pos);

};


#endif // MAP_H
