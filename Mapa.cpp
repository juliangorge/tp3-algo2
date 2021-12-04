#include "Mapa.h"

Mapa::Mapa()
{
    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    this->matriz_mapa = nullptr;
    this->leer_mapa();
}

Mapa::~Mapa(){
    
}

void Mapa::leer_mapa()
{
    ifstream archivo;
    archivo.open(ARCHIVO_MAPA.c_str());
    char caracter_casillero;

    if(!archivo)
    {
        cout << "No se pudo leer el archivo: " << ARCHIVO_MAPA << endl;
        exit(1);
    }

    archivo >> this->cantidad_filas >> this->cantidad_columnas;

    this->matriz_mapa = new Casillero**[this->cantidad_filas];

    for (unsigned int pos_fila = 0; pos_fila < this->cantidad_filas; pos_fila++)
    {

        this->matriz_mapa[pos_fila] = new Casillero*[this->cantidad_columnas];

        for (unsigned int pos_columna = 0; pos_columna < this->cantidad_columnas; pos_columna++)
        {

            archivo >> caracter_casillero;
            this->cargar_mapa(pos_fila,pos_columna,caracter_casillero);

        }
    }

    archivo.close();

}

void Mapa::cargar_mapa(unsigned int pos_fila, unsigned int pos_columna, char caracter_casillero)
{
    switch(caracter_casillero)
    {
        case 'T':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroTerreno();
            break;

        case 'C':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroCamino();
            break;

        case 'L':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroLago();
            break;

        case 'M':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroMuelle();
            break;

        case 'B':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroBetun();
            break;
    }
}

void Mapa::mostrar_mapa_vacio()
{
    cout << "Filas: " << this->cantidad_filas << endl;
    cout << "Columnas: " << this->cantidad_columnas << endl;

    for (unsigned int i = 0; i < this->cantidad_filas; i++){

        for (unsigned int j = 0; j < this->cantidad_columnas; j++){

            cout << this->matriz_mapa[i][j]->obtener_caracter() << " ";

        }

        cout << endl;
    }
}

Casillero * Mapa:: obtener_casillero(unsigned int fila, unsigned int columna){
    if(!chequear_coordenadas(fila, columna)) return nullptr;
    return this->matriz_mapa[fila][columna];
}

bool Mapa:: chequear_coordenadas(unsigned int fila, unsigned int columna){
    return fila <= this->cantidad_filas && columna <= this->cantidad_columnas;
}

/*void Mapa::set_jugador_casillero(Jugador* jugador)
{
    int fila = jugador->obtener_x(), columna = jugador->obtener_y(), numero = jugador->obtener_numero();
    string nombre = "jugador 1";
    char caracter = jugador->obtener_caracter();
    this->matriz_mapa[fila][columna]->ocupar_casillero(nombre, caracter, numero);
    return;
}

void Mapa::set_edificio_casillero(int jugador, unsigned int fila, unsigned int columna, Edificio *edificio)
{
    string nombre = edificio->obtener_nombre();
    char caracter = edificio->obtener_caracter();
    this->matriz_mapa[fila][columna]->ocupar_casillero(nombre, caracter, jugador);
    return;
}*/