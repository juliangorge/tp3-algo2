#include "Jugador.h"

Jugador:: Jugador(char caracter){
    this->energia = ENERGIA_INICIAL;
    this->caracter = caracter;
    this->tipos_de_materiales = 0;
    this->posicion_x = 0;
    this->posicion_y = 0;

    this->casilleros_jugador = nullptr;
    this->cantidad_casilleros = 0;
}

Jugador:: ~Jugador(){

}

int Jugador::obtener_numero()
{
    return atoi(&(this->caracter));
}

unsigned int Jugador::obtener_energia()
{
    return this->energia;
}

char Jugador::obtener_caracter()
{
    return this->caracter;
}

void cargar_materiales_jugadores(Jugador* jugador_uno, Jugador* jugador_dos)
{
    ifstream archivo_materiales;
    archivo_materiales.open(ARCHIVO_MATERIALES.c_str());
    string nombre_material;
    unsigned int cantidad_jugador_uno, cantidad_jugador_dos;

    while(archivo_materiales >> nombre_material >> cantidad_jugador_uno >> cantidad_jugador_dos){
		jugador_uno->agregar_material_a_lista(new Material(nombre_material, cantidad_jugador_uno));
		jugador_dos->agregar_material_a_lista(new Material(nombre_material, cantidad_jugador_dos));
        
    }

    archivo_materiales.close();

}

void Jugador::agregar_material_a_lista(Material* material){
    int tipos_de_materiales_previo = this->tipos_de_materiales;
    Material** materiales_aux = new Material*[tipos_de_materiales_previo + 1];
    for (int i = 0; i < tipos_de_materiales_previo; i++){
        materiales_aux[i] = this->materiales_jugador[i];
    }

    materiales_aux[tipos_de_materiales_previo] = material;

    if(this->tipos_de_materiales != 0){
        delete[] this->materiales_jugador;
    }

    this->materiales_jugador = materiales_aux;
    this->tipos_de_materiales++;
}


void Jugador::mostrar_inventario()
{
    cout << endl << "======================" << endl << endl;
    cout << "Materiales para construir " << endl;
    for(unsigned int i = 0; i < this->tipos_de_materiales; i++){
        cout << "# " << this->materiales_jugador[i]->obtener_nombre() << " - " << this->materiales_jugador[i]->obtener_cantidad() << endl;
    }
    cout << endl << "======================" << endl << endl;
}

estados_t Jugador::verificar_energia_suficiente(unsigned int costo_energia)
{
    if(this->energia < costo_energia)
        return ST_ERROR_ENERGIA_INSUFICIENTE;
    return ST_OK;
}

void Jugador::decrementar_energia(unsigned int costo_energia)
{
    this->energia-=costo_energia;
}

bool Jugador::verificar_energia_nula()
{
    return this->energia == 0;
}

unsigned int Jugador::obtener_posicion_material(string nombre_material)
{
    unsigned int posicion_material;
    for(unsigned int i = 0; i < this->tipos_de_materiales; i++){
        if(this->materiales_jugador[i]->obtener_nombre() == nombre_material)
            posicion_material = i;
    }
    return posicion_material;
}

estados_t Jugador::verificar_material_necesario(string nombre_material, unsigned int cantidad_a_restar)
{
    unsigned int posicion_material = this->obtener_posicion_material(nombre_material);
    if(this->materiales_jugador[posicion_material]->obtener_cantidad() < cantidad_a_restar)
        return ST_ERROR_MATERIALES_INSUFICIENTES;
    return ST_OK;

}

void Jugador::comprar_bombas(unsigned int bombas, unsigned int precio_bombas)
{
    string nombre_andycoins = NOMBRE_ANDYCOINS, nombre_bombas = NOMBRE_BOMBAS;
    unsigned int pos_andycoins = this->obtener_posicion_material(nombre_andycoins);
    unsigned int pos_bombas = this->obtener_posicion_material(nombre_bombas);
    this->materiales_jugador[pos_andycoins]->restar_materiales(precio_bombas);
    this->materiales_jugador[pos_bombas]->sumar_materiales(bombas);
}

unsigned int Jugador::mostrar_cantidad_material(string nombre_material)
{
    unsigned int cantidad, posicion_material = this->obtener_posicion_material(nombre_material);
    cantidad = this->materiales_jugador[posicion_material]->obtener_cantidad();
    return cantidad;
}

int Jugador::obtener_x()
{
    return this->posicion_x;
}

int Jugador::obtener_y()
{
    return this->posicion_y;
}

void Jugador:: agregar_material(string nombre_material, int cantidad){

    unsigned int pos = this->obtener_posicion_material(nombre_material);

    // aumentar...

}

void Jugador:: agregar_casillero(Casillero * casillero){
    int cantidad_casilleros_previo = this->cantidad_casilleros;
    Casillero** casilleros_aux = new Casillero*[cantidad_casilleros_previo + 1];
    for (int i = 0; i < cantidad_casilleros_previo; i++){
        casilleros_aux[i] = this->casilleros_jugador[i];
    }

    casilleros_aux[cantidad_casilleros_previo] = casillero;

    if(this->cantidad_casilleros != 0){
        delete[] this->casilleros_jugador;
    }

    this->casilleros_jugador = casilleros_aux;
    this->cantidad_casilleros++;
}

void Jugador:: mostrar_edificios(){

    for (int i = 0; i < cantidad_casilleros; i++){
        this->casilleros_jugador[i]->mostrar_coordenadas_de_edificio_por_jugador(this->caracter);
    }

}

void Jugador:: remover_edificio(Casillero * casillero){
    bool encontrado = false;
    int i = 0;
    while(!encontrado){
        if(this->casilleros_jugador[i] == casillero){
            cout << "Puntero liberado" << endl;
            this->casilleros_jugador[i] = nullptr;
            encontrado = true;   
        }
        i++;
    }
}