#ifndef TERRAINSQUARE
#define TERRAINSQUARE

#include "Square.h"
class TerrainSquare : public Square
{
    public:
        TerrainSquare();
        ~TerrainSquare();
        bool isPath();
		bool isTerrain();
        bool isFreeSquare();

        string getSquareName();
        char getTypeSquare();
        void changeObject();
        void emptySquare();
};

#endif //TERRAINSQUARE_H
