#include "parser.h"
//#include "edificios.h"
#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

Parser::Parser(string argv)
{
    this->entrada = argv;
}

string Parser::nombre()
{
    return extraer_campo(&entrada, " (");
}

unsigned int Parser::coordenada_x()
{
    return stoi(extraer_campo(&entrada, ", "));
}

unsigned int Parser::coordenada_y()
{
    //return atoi(this->entrada[]);
    return stoi(extraer_campo(&entrada, ")"));
}

string Parser :: extraer_campo(string *entrada , string delimitador)
{
    string campo;
    size_t pos = 0;

    while ((pos = entrada->find(delimitador)) != string::npos)
    {
        campo = entrada->substr(0, pos);
        entrada->erase(0, entrada->find(delimitador) + delimitador.length());
    }
    
    return campo;
}
