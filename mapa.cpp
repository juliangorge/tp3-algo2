#include <iostream>
#include <fstream>
#include <string>

#include "mapa.h"

using namespace std;

Mapa::Mapa()
{
    this->filas = 0;
    this->columnas = 0;
    this->leer();
}

Mapa::~Mapa(){

}

void Mapa::leer()
{
    ifstream file;
    file.open(CAMINO_ARCHIVO_MAPA.c_str());
    char casillero_caracter;

    if(!file)
    {
        cout << "No se pudo leer el archivo: " << CAMINO_ARCHIVO_MAPA << endl;
        exit(1);
    }

    file >> this->filas >> this->columnas;

    this->casilleros = new Casillero**[this->filas];

    for (unsigned int fila_pos = 0; fila_pos < this->filas; fila_pos++)
    {

        this->casilleros[fila_pos] = new Casillero*[this->columnas];

        for (unsigned int columna_pos = 0; columna_pos < this->columnas; columna_pos++)
        {

            file >> casillero_caracter;
            this->cargar(fila_pos, columna_pos, casillero_caracter);

        }
    }

    file.close();

}

void Mapa::cargar(unsigned int fila_pos, unsigned int columna_pos, char casillero_caracter)
{
    switch(casillero_caracter)
    {
        case 'T':
            this->casilleros[fila_pos][columna_pos] = new CasilleroTerreno();
            break;

        case 'C':
            this->casilleros[fila_pos][columna_pos] = new CasilleroCamino();
            break;

        case 'L':
            this->casilleros[fila_pos][columna_pos] = new CasilleroLago();
            break;

        case 'M':
            this->casilleros[fila_pos][columna_pos] = new CasilleroMuelle();
            break;

        case 'B':
            this->casilleros[fila_pos][columna_pos] = new CasilleroBetun();
            break;
    }

}

void Mapa::mostrar()
{
    cout << "Filas: " << this->filas << endl;
    cout << "Columnas: " << this->columnas << endl;

    for (unsigned int i = 0; i < this->filas; i++){
        for (unsigned int j = 0; j < this->columnas; j++){
            cout << this->casilleros[i][j]->obtener_caracter() << " ";
        }
        cout << endl;
    }
}

bool Mapa::consultar_coordenada(unsigned int fila_pos, unsigned int columna_pos){
    return fila_pos < filas && columna_pos < columnas;
}

bool Mapa::es_construible(unsigned int fila_pos, unsigned int columna_pos){
    return consultar_coordenada(fila_pos, columna_pos) && this->casilleros[fila_pos][columna_pos]->es_construible();
}

Casillero * Mapa::obtener_casillero(unsigned int fila_pos, unsigned int columna_pos){
    return this->casilleros[fila_pos][columna_pos];
}