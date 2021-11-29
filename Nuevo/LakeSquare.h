#ifndef LAKESQUARE
#define LAKESQUARE

#include "Square.h"
class LakeSquare : public Square
{
    public:
        LakeSquare();
        ~LakeSquare();
        bool isPath();
        bool isTerrain();
        string getSquareName();
        char getTypeSquare();

        void changeObject();
        void emptySquare();
};

#endif //LAKESQUARE_H
