#include <iostream>
#include <fstream>
#include <string>

#include "casillero.h"
#include "casillero_inaccesible.h"

using namespace std;

Casillero_inaccesible::Casillero_inaccesible(char caracter)
{
    this->caracter = caracter;
    this->transitable=false;
    this->construible=false;
    this->inaccesible=true;
}
