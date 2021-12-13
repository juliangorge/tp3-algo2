#include "Mapa.h"

Mapa::Mapa()
{
    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    this->matriz_mapa = nullptr;
    this->leer_mapa();
    this->cantidad_casilleros_camino = 0;
    this->obtener_casilleros_transitables();
}

Mapa::~Mapa(){
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

    for (unsigned int i = 0; i < this->cantidad_casilleros_camino; i++){
        this->casilleros_camino[i] = nullptr;
    }
    delete [] this->casilleros_camino;
    this->casilleros_camino = nullptr;
    this->cantidad_casilleros_camino = 0;
}

void Mapa::leer_mapa()
{
    ifstream archivo;
    archivo.open(ARCHIVO_MAPA.c_str());
    char caracter_casillero;

    if(!archivo)
    {
        cout << MSJ_ERROR_LECTURA_ARCHIVO << ARCHIVO_MAPA << endl;
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
        case CARACTER_TERRENO:
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroTerreno(pos_fila, pos_columna);
            break;

        case CARACTER_CAMINO:
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroCamino(pos_fila, pos_columna);
            break;

        case CARACTER_LAGO:
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroLago(pos_fila, pos_columna);
            break;

        case CARACTER_MUELLE:
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroMuelle(pos_fila, pos_columna);
            break;

        case CARACTER_BETUN:
            this->matriz_mapa[pos_fila][pos_columna] = new CasilleroBetun(pos_fila, pos_columna);
            break;
    }
}

unsigned int Mapa::obtener_cantidad_filas()
{
    return this->cantidad_filas;
}

unsigned int Mapa::obtener_cantidad_columnas()
{
    return this->cantidad_columnas;
}

void Mapa::obtener_casilleros_transitables()
{
    for(unsigned int fila = 0; fila < this->cantidad_filas; fila++){
        for(unsigned int columna = 0; columna < this->cantidad_columnas; columna++){
            if(this->obtener_casillero(fila,columna)->es_transitable() && this->obtener_casillero(fila,columna)->esta_libre())
                agregar_casillero_transitable(this->obtener_casillero(fila,columna));
        }
    }
}

void Mapa::agregar_casillero_transitable(Casillero * casillero){
    Casillero** casilleros_aux = new Casillero*[this->cantidad_casilleros_camino + 1];
    for (unsigned int i = 0; i < this->cantidad_casilleros_camino; i++){
        casilleros_aux[i] = this->casilleros_camino[i];
    }

    casilleros_aux[this->cantidad_casilleros_camino] = casillero;

    if(this->cantidad_casilleros_camino != 0){
        delete[] this->casilleros_camino;
    }

    this->casilleros_camino = casilleros_aux;
    this->cantidad_casilleros_camino++;
}

void Mapa::borrar_casillero_transitable(Casillero * casillero){
    unsigned int posicion;
    for (unsigned int i = 0; i < this->cantidad_casilleros_camino; i++)
    {
        if(this->casilleros_camino[i] == casillero){
            posicion = i;
            this->casilleros_camino[i] = nullptr;
        }
    }
    Casillero** casilleros_aux = new Casillero*[this->cantidad_casilleros_camino - 1];
    for (unsigned int i = 0; i < posicion; i++){
        casilleros_aux[i] = this->casilleros_camino[i];
    }
    for (unsigned int i = posicion; i < this->cantidad_casilleros_camino -1; i++)
    {
        casilleros_aux[i] = this->casilleros_camino[i+1];
    }
    if(this->cantidad_casilleros_camino != 0){
        delete[] this->casilleros_camino;
    }
    this->casilleros_camino = casilleros_aux;
    this->cantidad_casilleros_camino--;
}

void Mapa::mostrar_mapa_vacio()
{
    cout << MSJ_FILAS_MAPA << this->cantidad_filas << endl;
    cout << MSJ_COLUMNAS_MAPA << this->cantidad_columnas << endl;

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
    cout << MSJ_ENCABEZADOS_MAPAS;
    cout << endl;

    for (unsigned int i = 0; i < this->cantidad_filas; i++){

        for (unsigned int j = 0; j < this->cantidad_columnas; j++){
            cout << this->matriz_mapa[i][j]->obtener_caracter_casillero() << " "; 
        }

        cout << MSJ_SEPARACION_ENTRE_MAPAS;
        
        for (unsigned int j = 0; j < this->cantidad_columnas; j++){
            cout << this->matriz_mapa[i][j]->obtener_caracter() << " ";
        }

        cout << endl;
    }
}

Casillero * Mapa:: obtener_casillero(unsigned int fila, unsigned int columna){
    return this->matriz_mapa[fila][columna];
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
    switch(material->obtener_nombre()[POSICION_PRIMER_LETRA]){
        case PRIMER_LETRA_MAD_MET:
            cantidad_material = CANTIDAD_MATERIAL_MAD_MET;
            break;
        case PRIMER_LETRA_PIEDRA:
            cantidad_material = CANTIDAD_MATERIAL_PIEDRA;
            break;
        case PRIMER_LETRA_ANDYCOINS:
            cantidad_material = CANTIDAD_MATERIAL_ANDYCOINS;
            break;
        default:
            cantidad_material = CANTIDAD_MATERIAL_OTRO;
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

void Mapa::lluvia_recursos()
{
    srand( static_cast<unsigned int>(time(nullptr)));
    string nombre_material = NOMBRE_PIEDRA;
    unsigned int cota_minima = MIN_LLUVIA_PIEDRA, cota_maxima = MAX_LLUVIA_PIEDRA;
    this->crear_colocar_conjuntos(nombre_material, cota_minima, cota_maxima);

    nombre_material = NOMBRE_MADERA;
    cota_minima = MIN_LLUVIA_MADERA, cota_maxima = MAX_LLUVIA_MADERA;
    this->crear_colocar_conjuntos(nombre_material, cota_minima, cota_maxima);
    
    nombre_material = NOMBRE_METAL;
    cota_minima = MIN_LLUVIA_METAL, cota_maxima = MAX_LLUVIA_METAL;
    this->crear_colocar_conjuntos(nombre_material, cota_minima, cota_maxima);
    
    nombre_material = NOMBRE_ANDYCOINS;
    cota_minima = MIN_LLUVIA_ANDYCOINS, cota_maxima = MAX_LLUVIA_ANDYCOINS;
    this->crear_colocar_conjuntos(nombre_material, cota_minima, cota_maxima);

    if(!this->cantidad_casilleros_camino)
        cout << MSJ_ERROR_CASILLEROS_TRANSITABLES_OCUPADOS << endl;
    
}

void Mapa::crear_colocar_conjuntos(string nombre_material, unsigned int cota_minima, unsigned int cota_maxima)
{
    unsigned int conjunto = aleatorio(cota_minima, cota_maxima);
    for(unsigned int i = 0; i < conjunto && this->cantidad_casilleros_camino; i++)
        agregar_material_casilleros_camino(nombre_material);
}

void Mapa::agregar_material_casilleros_camino(string nombre_material)
{ 
    unsigned int posicion_lista = aleatorio(0, this->cantidad_casilleros_camino);
    Material* material = obtener_material(nombre_material);
    unsigned int fila = this->casilleros_camino[posicion_lista]->obtener_fila();
    unsigned int columna = this->casilleros_camino[posicion_lista]->obtener_columna();
    this->obtener_casillero(fila, columna)->cargar_material(material);
    this->borrar_casillero_transitable(this->obtener_casillero(fila, columna));
}

void Mapa::cargar_ubicaciones_materiales(ofstream& archivo)
{
    Casillero* casillero_aux;
    for(unsigned int fila = 0; fila < this->cantidad_filas; fila++){
        for(unsigned int columna = 0; columna < this->cantidad_columnas; columna++){
            casillero_aux = this->obtener_casillero(fila, columna);
            if(casillero_aux->es_transitable() && !casillero_aux->esta_libre() && casillero_aux->no_tiene_jugador())
                archivo << casillero_aux->obtener_material()->obtener_nombre() << PRIMER_DELIMITADOR << casillero_aux->obtener_fila()
                        << SEGUNDO_DELIMITADOR << casillero_aux->obtener_columna() << TERCER_DELIMITADOR << '\n';
        }
    }
}
