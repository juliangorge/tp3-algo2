#include "Mapa.h"

Mapa::Mapa()
{
    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    this->matriz_mapa = nullptr;
    this->materiales_mapa = nullptr;
    this->leer_mapa();
}

Mapa::~Mapa()
{
    for (unsigned int i = 0; i < this->cantidad_filas; i++){
        for (unsigned int j = 0; j < this->cantidad_columnas; j++){
            delete this->matriz_mapa[i][j];
        }

        delete [] this->matriz_mapa[i];
    }
    delete [] this->matriz_mapa;
    this->matriz_mapa = nullptr;

    for (unsigned int i = 0; i < this->cantidad_de_materiales; i++){
        delete this->materiales_mapa[i];
    }

    delete [] this->materiales_mapa;
    this->materiales_mapa = nullptr;
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
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroTerreno(pos_fila, pos_columna);
            break;

        case 'C':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroCamino(pos_fila, pos_columna);
            break;

        case 'L':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroLago(pos_fila, pos_columna);
            break;

        case 'M':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroMuelle(pos_fila, pos_columna);
            break;

        case 'B':
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroBetun(pos_fila, pos_columna);
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

void Mapa::mostrar_mapas()
{
    cout << endl;
    cout << "         Mapa vacío" << '\t' << '\t' << '\t' << "      Mapa de la partida";
    cout << endl;

    for (unsigned int i = 0; i < this->cantidad_filas; i++){

        for (unsigned int j = 0; j < this->cantidad_columnas; j++){

            cout << this->matriz_mapa[i][j]->obtener_caracter_casillero() << " "; 

        }

        cout << '\t' << '\t';

        for (unsigned int j = 0; j < this->cantidad_columnas; j++){

            cout << this->matriz_mapa[i][j]->obtener_caracter() << " ";

        }

        cout << endl;
    }
}

Casillero * Mapa:: obtener_casillero(unsigned int fila, unsigned int columna){
    return this->matriz_mapa[fila][columna];
}

void Mapa::set_jugador_casillero(Jugador* jugador)
{
    int fila = jugador->obtener_fila(), columna = jugador->obtener_columna();
    this->matriz_mapa[fila][columna]->ocupar_casillero(jugador->obtener_caracter());
    return;
}

estados_t Mapa::verificar_condiciones_construccion(char caracter_jugador, unsigned int fila, unsigned int columna)
{
    estados_t st = this->matriz_mapa[fila][columna]-> verificar_condiciones_construccion(caracter_jugador);
    return st;
}

void Mapa::set_edificio_casillero(char caracter_jugador, unsigned int fila, unsigned int columna, Edificio* edificio)
{
    this->matriz_mapa[fila][columna]->cargar_edificio(edificio, caracter_jugador);
}

estados_t Mapa::set_material_casillero(unsigned int fila, unsigned int columna, Material* material)
{
    estados_t st;
    Casillero *casillero=this->obtener_casillero(fila, columna);

    if(casillero->es_transitable() && casillero->obtener_material()==nullptr)
    {   
        if(casillero_sin_material(fila, columna))
        {
            this->matriz_mapa[fila][columna]->cargar_material(material);
            st = ST_OK;
        }
        else
            st = ST_ERROR_CASILLERO_OCUPADO;
    }
    else
        st = ST_ERROR_CASILLLERO_INTRANSITABLE;
    
    return st;
}
estados_t Mapa::verificar_condiciones_demolicion(char caracter_jugador, unsigned int fila, unsigned int columna)
{
    estados_t st = this->matriz_mapa[fila][columna]-> verificar_condiciones_demolicion(caracter_jugador);
    return st;
}

void Mapa::demoler_edificio_casillero(unsigned int fila, unsigned int columna){
    this->matriz_mapa[fila][columna]->limpiar_casillero();
}

estados_t Mapa::verificar_condiciones_ataque(char caracter_jugador, unsigned int fila, unsigned int columna)
{
    estados_t st = this->matriz_mapa[fila][columna]-> verificar_condiciones_ataque(caracter_jugador);
    return st;
}

void Mapa::atacar_edificio_casillero(unsigned int fila, unsigned int columna){
    this->matriz_mapa[fila][columna]->atacar_edificio();
}

void Mapa::consultar_coordenadas(unsigned int fila, unsigned int columna)
{
    this->matriz_mapa[fila][columna]->mostrar_casillero();
}

void Mapa::cargar_materiales(Jugador* jugador)
{
    unsigned int cantidad_material;
    Material** materiales_jugador = jugador->obtener_lista_materiales();
    this->cantidad_de_materiales = jugador->obtener_tipos_de_materiales();
    this->materiales_mapa = new Material*[this->cantidad_de_materiales];
    for (unsigned int i = 0; i < this->cantidad_de_materiales; i++)
    {
        cantidad_material = set_cantidad_material(materiales_jugador[i]);
        materiales_mapa[i] = new Material(materiales_jugador[i]->obtener_nombre(), cantidad_material);
    }
}

unsigned int Mapa::set_cantidad_material(Material* material)
{
    unsigned int cantidad_material;
    switch(material->obtener_nombre()[0]){
        case 'm':
            cantidad_material = 50;
            break;
        case 'p':
            cantidad_material = 100;
            break;
        case 'a':
            cantidad_material = 250;
            break;
        default:
            cantidad_material = 0;
            break;
    }
    return cantidad_material;
}

Material* Mapa::obtener_material(string nombre_material)
{
    Material* material;
    for (unsigned int i = 0; i < this->cantidad_de_materiales; i++)
    {
        if(this->materiales_mapa[i]->obtener_nombre() == nombre_material)
            material = this->materiales_mapa[i];
    }
    return material;
}

unsigned int Mapa::obtener_cantidad_filas()
{
    return this->cantidad_filas;
}

unsigned int Mapa::obtener_cantidad_columnas()
{
    return this->cantidad_columnas;
}

void Mapa::lluvia_recursos()
{
    /*int conjuntos_piedra = aleatorio(MIN_LLUVIA_PIEDRA, MAX_LLUVIA_PIEDRA);
    int conjuntos_madera = aleatorio(MIN_LLUVIA_MADERA, MAX_LLUVIA_MADERA);
    int conjuntos_metal = aleatorio(MIN_LLUVIA_METAL, MAX_LLUVIA_METAL);
    int conjuntos_andycoins = aleatorio(MIN_LLUVIA_ANDYCOINS, MAX_LLUVIA_ANDYCOINS);
    int i = 0;
    for(i=0; i<conjuntos_piedra; i++)
        setear_material_aleatorio(&i, "piedra");

    for(i=0; i<conjuntos_madera; i++)
        setear_material_aleatorio(&i, "madera");

    for(i=0; i<conjuntos_metal; i++)
        setear_material_aleatorio(&i, "metal");
        
    for(i=0; i<conjuntos_andycoins; i++)
        setear_material_aleatorio(&i, "andycoins");*/

    /*cout << endl << "Mapa de materiales" << endl;
    this->mostrar_mapa_materiales();
    cout << endl << endl;*/


    
}


void Mapa::setear_material_aleatorio(int *i, string material)
{ 
    int fila = 0, columna = 0;
    Material *material_aux;

    fila = aleatorio(0, this->cantidad_filas - 1);
    columna = aleatorio(0, this->cantidad_columnas - 1);
    material_aux = obtener_material(material);
    if (set_material_casillero(fila, columna, material_aux)!=ST_OK)
        *i--;
}

bool Mapa:: casillero_sin_material(unsigned int fila, unsigned int columna)
{
    return (matriz_mapa[fila][columna] == nullptr);
}

void Mapa::mostrar_mapa_materiales()
{
    cout << "Filas: " << this->cantidad_filas << endl;
    cout << "Columnas: " << this->cantidad_columnas << endl;

    for (unsigned int i = 0; i < this->cantidad_filas; i++){

        for (unsigned int j = 0; j < this->cantidad_columnas; j++){

            cout << this->matriz_mapa[i][j]->obtener_material()->obtener_caracter() << " ";

        }

        cout << endl;
    }
}