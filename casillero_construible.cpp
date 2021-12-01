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
}
