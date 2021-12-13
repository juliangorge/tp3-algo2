#include "Parser.h"

Parser::Parser(string valor_entrada)
{
    this->entrada = valor_entrada;
}

string Parser::nombre()
{
    string delimitador = PRIMER_DELIMITADOR;
    return extraer_campo(this->entrada, delimitador);
}

unsigned int Parser::coordenada_fila()
{
    string delimitador = SEGUNDO_DELIMITADOR;
    return static_cast<unsigned int>(stoul(extraer_campo(this->entrada, delimitador)));
}

unsigned int Parser::coordenada_columna()
{
    string delimitador = TERCER_DELIMITADOR;
    return static_cast<unsigned int>(stoul(extraer_campo(this->entrada, delimitador)));
}

string Parser::extraer_campo(string & entrada , string delimitador)
{
    string campo;
    size_t pos = 0;

    while ((pos = entrada.find(delimitador)) != string::npos)
    {
        campo = entrada.substr(0, pos);
        entrada.erase(0, entrada.find(delimitador) + delimitador.length());
    }

    return campo;
}
