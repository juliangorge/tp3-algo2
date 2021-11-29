#include "TerrainSquare.h"

#include <string>

using namespace std;

TerrainSquare::TerrainSquare()
{
	this->type_square = 'T';
	this->is_it_path = false;
	this->is_it_terrain = true;
	this->square_name = "casillero construible";

}

bool TerrainSquare::isPath()
{
	return this->is_it_path;
}

bool TerrainSquare::isTerrain()
{
	return this->is_it_terrain;
}




string TerrainSquare::getSquareName()
{
	return this->square_name;
}

char TerrainSquare::getTypeSquare(){
	return this->type_square;
}

void TerrainSquare::changeObject(){
}


void TerrainSquare::emptySquare()
{

}

TerrainSquare:: ~TerrainSquare(){
}