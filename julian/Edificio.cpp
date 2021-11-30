#include "Edificio.h"
#include <string>

using namespace std;


Edificio::Edificio(string name, unsigned int stone, unsigned int wood, unsigned int iron, unsigned int max)
{
    this->name = name;
    this->stone = stone;
    this->wood = wood;
    this->iron = iron;
    this->quantity = 0;
    this->max = max;
    this->building_char = 'B';
    this->provide_materials = true;

    //this->getChar();
}

string Edificio::getName(){
    return this->name;
}

ostream& operator<<(ostream& salida, Edificio& edificio)
{
    salida << endl << edificio.getName() << endl;
    return salida;
}
