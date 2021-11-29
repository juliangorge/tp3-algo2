#include "mapa.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const string PATH = "mapa.txt";

Mapa::Mapa()
{
    this->rows = 0;
    this->columns = 0;
    this->squares = nullptr;
    this->path_square_quantity = 0;
    this->readMap();
}


void Mapa::readMap()
{
    ifstream file;
    file.open(PATH.c_str());
    char square_type;

    if(!file)
    {
        cout << "No se pudo leer el archivo: " << PATH << endl;
        exit(1);
    }

    file >> this->rows >> this->columns;

    this->squares = new Square**[this->rows];

    for (unsigned int row_pos = 0; row_pos < this->rows; row_pos++)
    {

        this->squares[row_pos] = new Square*[this->columns];

        for (unsigned int column_pos = 0; column_pos < this->columns; column_pos++)
        {

            file >> square_type;
            this->loadMap(row_pos,column_pos,square_type);

        }
    }

    file.close();

}

void Mapa::loadMap(unsigned int row_pos, unsigned int column_pos, char square_type)
{
    switch(square_type)
    {
        case 'T':
            this->squares[row_pos][column_pos] = new TerrainSquare();
            break;

        case 'C':
            this->path_square_quantity++;
            this->squares[row_pos][column_pos] = new PathSquare();
            break;

        case 'L':
            this->squares[row_pos][column_pos] = new LakeSquare();
            break;
    }
}

void Mapa::addCoords(unsigned int & row_pos, unsigned int & column_pos)
{
    cout << "Escribe la fila: ";
    cin >> row_pos;

    row_pos--;

    cout << "Escribe la columna: ";
    cin >> column_pos;

    column_pos--;
}

bool Mapa::checkCoords(unsigned int row_pos, unsigned int column_pos)
{
	return (row_pos < this->rows &&  column_pos < this->columns);
}



void Mapa::showMap()
{
    cout << "Filas: " << this->rows << endl;
    cout << "Columnas: " << this->columns << endl;
    for (unsigned int i = 0; i < this->rows; i++)
    {
        for (unsigned int j = 0; j < this->columns; j++)
        {
            cout << this->squares[i][j]->getTypeSquare() << " ";
        }
        cout << endl;
    }
}


        

void Mapa::showCoord(unsigned int row_pos, unsigned int column_pos)
{
    cout << "Ese casillero es: " << this->squares[row_pos][column_pos]->getTypeSquare() << endl;
}




void Mapa::emptySquare(unsigned int row_pos, unsigned int column_pos){
    this->squares[row_pos][column_pos]->emptySquare();
}

