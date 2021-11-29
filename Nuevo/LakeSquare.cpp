#include "LakeSquare.h"

#include <string>

using namespace std;

LakeSquare::LakeSquare()
{
	this->type_square = 'L';
	this->is_it_path = false;
    this->is_it_terrain = false;
    this->square_name = "casillero con agua";
}

bool LakeSquare::isPath()
{
	return this->is_it_path;
}

bool LakeSquare::isTerrain()
{
	return this->is_it_terrain;
}



string LakeSquare::getSquareName()
{
	return this->square_name;
}

char LakeSquare::getTypeSquare(){
	return this->type_square;
}



void LakeSquare::changeObject(){
}

void LakeSquare::emptySquare(){

}

LakeSquare:: ~LakeSquare(){
}