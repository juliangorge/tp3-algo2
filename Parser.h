#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include "Mapa.h"
//#include "edificios.h"

using namespace std;

class Parser
{
private:
    string entrada;

public:
    Parser(string argv);
    std::string nombre(); //hago que me devuelva un string
    unsigned int coordenada_x();
    unsigned int coordenada_y();
    std::string extraer_campo(string *entrada , string delimitador);
};

#endif