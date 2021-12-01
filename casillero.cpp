#include <iostream>
#include <fstream>
#include <string>

#include "casillero.h"

using namespace std;

char Casillero::obtener_caracter()
{
    return caracter;
}

bool Casillero::es_construible()
{
    return construible;
}

bool Casillero::es_inaccesible()
{
    return inaccesible;
}

bool Casillero::es_transitable()
{
    return transitable;
}