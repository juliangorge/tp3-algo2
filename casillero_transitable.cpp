#include <iostream>
#include <fstream>
#include <string>

#include "casillero.h"
#include "casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable(char caracter)
{
    this->caracter = caracter;
    this->transitable=true;
    this->construible=false;
    this->inaccesible=false;
}
