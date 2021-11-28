#include "jugador.h"
#include <string>

using namespace std;

Jugador:: Jugador(unsigned int numero, unsigned int x, unsigned int y)
{
    this->numero = numero;
    this->coordenada_x = x;
    this->coordenada_y = y;
    this->energia = 50;
    

}

unsigned int Jugador:: get_numero(){
    return this->numero;
}

unsigned int Jugador:: get_x()
{
    return this->coordenada_x;
}

unsigned int Jugador:: get_y()
{
    return this->coordenada_y;
}

void Jugador:: incrementar_x()
{
    this->coordenada_x++;
}

void Jugador:: decrementar_x()
{
    this->coordenada_x--;
}

void Jugador:: incrementar_y()
{
    this->coordenada_y++;
}

void Jugador:: decrementar_y()
{
    this->coordenada_y--;
}

void Jugador::incrementar_energia(unsigned int cantidad)
{
    this->energia -= cantidad;
}

void Jugador::decrementar_energia(unsigned int cantidad)
{
    this->energia -= cantidad;
}

Jugador:: ~Jugador(){
    
}


/*
char Jugador::agregar_jugador(string name)
{
    int pos = checkIfBuildingExistsByName(name);

    this->buildings[pos]->increaseQuantity();

    return this->buildings[pos]->getBuildingChar();
}*/
