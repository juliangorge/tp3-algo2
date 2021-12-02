#include <iostream>
#include <fstream>
#include <string>

#include "mapa.h"

using namespace std;

Mapa::Mapa(string CAMINO_ARCHIVO_MAPA)
{
    fstream archivo_mapa(CAMINO_ARCHIVO_MAPA, ios::in);

    Casillero ** matriz_mapa = nullptr;
    
	if (!archivo_mapa.is_open())
	{
		cout << "No se encontro un archivo con nombre \"" << CAMINO_ARCHIVO_MAPA << "\", se va a crear el archivo" << endl;
		archivo_mapa.open(CAMINO_ARCHIVO_MAPA, ios::out);

		archivo_mapa.close();
		archivo_mapa.open(CAMINO_ARCHIVO_MAPA, ios::in);

		archivo_mapa.close();

	}
    else
    {
        string filas_aux;
        string col_aux;
        char letra_casillero;

        archivo_mapa >> filas_aux;
        archivo_mapa >> col_aux;

        this->cantidad_filas = stoi(filas_aux);
        this->cantidad_columnas = stoi(col_aux);

        matriz_mapa = new Casillero * [this->cantidad_filas * this->cantidad_columnas];
        unsigned int i = 0 ;

        while(archivo_mapa >> letra_casillero)
        {
                // Esto se podría refactorear como una funcion que devuelva el casillero creado
                // o sea una sola funcion con switch
            switch(letra_casillero){
                case 'L':
                    matriz_mapa[i] = new CasilleroLago();
                    break;

                case 'C':
                    matriz_mapa[i] = new CasilleroCamino();
                    break;

                case 'B':
                    matriz_mapa[i] = new CasilleroBetun();
                    break;

                case 'M':
                    matriz_mapa[i] = new CasilleroMuelle();
                    break;

                case 'T':
                    matriz_mapa[i] = new CasilleroTerreno();
                    break;

            }
            /*if(letra_casillero == ARREGLO_CHAR_CONSTRUIBLES[0])
            {
                matriz_mapa[i] = new Casillero_construible(letra_casillero);
            }
            else if(letra_casillero == ARREGLO_CHAR_INACCESIBLES[0])
            {
                matriz_mapa[i] = new Casillero_inaccesible(letra_casillero);
            }
            else if(letra_casillero == ARREGLO_CHAR_TRANSITABLES[0] || letra_casillero == ARREGLO_CHAR_TRANSITABLES[1] || letra_casillero == ARREGLO_CHAR_TRANSITABLES[2])
            {
                matriz_mapa[i] = new Casillero_transitable(letra_casillero);
            }*/

            i++; 
        }

        archivo_mapa.close();
    }

    this->matriz_mapa = matriz_mapa;

}

unsigned int Mapa::obtener_cantidad_filas()
{
    return this->cantidad_filas;
}

unsigned int Mapa::obtener_cantidad_columnas()
{
    return this->cantidad_columnas;
}

Casillero* Mapa::consultar_coordenada (unsigned int fila, unsigned int columna)
{

    // Validar fila y cantidad_filas, y columna y cantidad_columnas

    unsigned int num_elemento=0;

    if(!fila)
        num_elemento = columna;
    else
        num_elemento = fila*cantidad_columnas+columna;

    return (matriz_mapa[num_elemento]);
}

void Mapa::imprimir_mapa()
{
    unsigned int fil_aux = 0;
    unsigned int col_aux = 0;

    while(fil_aux < cantidad_filas)
    {
        cout << (consultar_coordenada(fil_aux,col_aux))->obtener_caracter() << " " ;

        col_aux++;

        if(col_aux >= cantidad_columnas)
        {
            col_aux = 0;
            fil_aux++;
            cout << endl;
        }
    }
}