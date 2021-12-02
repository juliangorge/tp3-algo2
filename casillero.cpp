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

void Casillero::cambiar_objeto(string nombre, char tipo_objeto, int jugador)
{
	this->nombre = nombre;
	this->caracter = tipo_objeto;
	this->jugador = jugador;
    this->casillero_ocupado = true;

	return;
}