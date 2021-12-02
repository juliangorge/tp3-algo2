#include <iostream>
#include <fstream>
#include <string>

#include "casillero.h"
#include "casillero_construible.h"

using namespace std;

Casillero_construible::Casillero_construible(char caracter)
{
    this->caracter = caracter;
    this->transitable=false;
    this->construible=true;
    this->inaccesible=false;
    this->casillero_ocupado=false;
    this->jugador=0;
}

char Casillero_construible::get_caracter()
{
    return this->caracter;
}

int Casillero_construible::get_jugador()
{
    return this->jugador;
}

/*bool casillero_construible::casillero()
{
	return (this->square_type == this->type_of_object);
}
void casillero_construible::changeObject(string object_name, char type_of_object, int jugador)
{
	this->object_name = object_name;
	this->type_of_object = type_of_object;
	this->jugador = jugador;
	return;
}

string casillero_construible::getSquareName()
{
	return this->square_name;
}

void casillero_construible::emptySquare()
{
	this->object_name.clear();
	this->type_of_object=this->square_type;
}*/



Casillero_construible::~Casillero_construible(){
}