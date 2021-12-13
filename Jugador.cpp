#include "Jugador.h"

Jugador:: Jugador(char caracter){
    this->energia = ENERGIA_INICIAL;
    this->caracter = caracter;
    this->tipos_de_materiales = 0;
    this->posicion_fila = 0;
    this->posicion_columna = 0;

    this->casilleros_jugador = nullptr;
    this->cantidad_casilleros = 0;
    
    this->objetivos = new Objetivo();

    this->andycoins_acumuladas=ANDYCOINS_INICIALES;
    this->bombas_compradas=0;
    this->bombas_usadas=0;

    this->acumulador_por_turno =1;
}

Jugador:: ~Jugador(){
    for (unsigned int i = 0; i < this->cantidad_casilleros; i++){
        this->casilleros_jugador[i] = nullptr;
    }

    for (unsigned int i = 0; i < this->tipos_de_materiales; i++){
        delete this->materiales_jugador[i];
    }

    this->cantidad_casilleros = 0;
    this->tipos_de_materiales = 0;

    delete [] this->casilleros_jugador;
    delete [] this->materiales_jugador;

    delete this->objetivos;
}

char Jugador::obtener_caracter()
{
    return this->caracter;
}

unsigned int Jugador::obtener_energia()
{
    return this->energia;
}

unsigned int Jugador::obtener_tipos_de_materiales()
{
    return this->tipos_de_materiales;
}

void Jugador::agregar_coordenadas(unsigned int posicion_fila, unsigned int posicion_columna)
{
    this->posicion_fila = posicion_fila;
    this->posicion_columna = posicion_columna;
}

void Jugador::agregar_material_a_lista(Material* material){
    Material** materiales_aux = new Material*[this->tipos_de_materiales + 1];
    for (int i = 0; i < this->tipos_de_materiales; i++){
        materiales_aux[i] = this->materiales_jugador[i];
    }

    materiales_aux[this->tipos_de_materiales] = material;

    if(this->tipos_de_materiales != 0){
        delete[] this->materiales_jugador;
    }

    this->materiales_jugador = materiales_aux;
    this->tipos_de_materiales++;
}


void Jugador::mostrar_inventario()
{
    cout << endl << "======================" << endl << endl;
    cout << MSJ_MATERIALES_DISPONIBLES << endl;
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

void Jugador::incrementar_energia(unsigned int energia_nueva)
{
    if((this->energia+=energia_nueva) > ENERGIA_MAXIMA){
        this->energia = ENERGIA_MAXIMA;
    }
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

Material** Jugador::obtener_lista_materiales()
{
    return this->materiales_jugador;
}

bool Jugador::verificar_material_necesario(string nombre_material, unsigned int cantidad_a_restar)
{
    unsigned int posicion_material = this->obtener_posicion_material(nombre_material);
    return (this->materiales_jugador[posicion_material]->obtener_cantidad() >= cantidad_a_restar);
}

void Jugador::comprar_bombas(unsigned int bombas, unsigned int precio_bombas)
{
    string nombre_andycoins = NOMBRE_ANDYCOINS, nombre_bombas = NOMBRE_BOMBAS;
    unsigned int pos_andycoins = this->obtener_posicion_material(nombre_andycoins);
    unsigned int pos_bombas = this->obtener_posicion_material(nombre_bombas);
    this->materiales_jugador[pos_andycoins]->restar_materiales(precio_bombas);
    this->materiales_jugador[pos_bombas]->sumar_materiales(bombas);
    this->bombas_compradas += bombas;
}

void Jugador::restar_materiales(string nombre_material, unsigned int cantidad_a_restar){
    unsigned int posicion_material = this->obtener_posicion_material(nombre_material);
    this->materiales_jugador[posicion_material]->restar_materiales(cantidad_a_restar);
}

unsigned int Jugador::mostrar_cantidad_material(string nombre_material)
{
    unsigned int cantidad, posicion_material = this->obtener_posicion_material(nombre_material);
    cantidad = this->materiales_jugador[posicion_material]->obtener_cantidad();
    return cantidad;
}

unsigned int Jugador::obtener_fila()
{
    return this->posicion_fila;
}

unsigned int Jugador::obtener_columna()
{
    return this->posicion_columna;
}

void Jugador:: agregar_material(string nombre_material, unsigned int cantidad){
    unsigned int pos = this->obtener_posicion_material(nombre_material);
    this->materiales_jugador[pos]->sumar_materiales(cantidad);
}

void Jugador:: agregar_casillero(Casillero * casillero){
    Casillero** casilleros_aux = new Casillero*[this->cantidad_casilleros + 1];
    for (unsigned int i = 0; i < this->cantidad_casilleros; i++){
        casilleros_aux[i] = this->casilleros_jugador[i];
    }

    casilleros_aux[this->cantidad_casilleros] = casillero;

    if(this->cantidad_casilleros != 0){
        delete[] this->casilleros_jugador;
    }

    this->casilleros_jugador = casilleros_aux;
    this->cantidad_casilleros++;
}

void Jugador:: mostrar_edificios(){
    unsigned int cantidad_edificio = 0;
    for (unsigned int i = 0; i < this->cantidad_casilleros; i++){
        this->casilleros_jugador[i]->mostrar_edificio();
        cantidad_edificio++;
    }
    cout << MSJ_EDIFICIOS_CONSTRUIDOS << cantidad_edificio << endl << endl;;
}

void Jugador:: borrar_edificio_casillero(Casillero * casillero){
    unsigned int posicion;
    for (unsigned int i = 0; i < this->cantidad_casilleros; i++)
    {
        if(this->casilleros_jugador[i] == casillero){
            posicion = i;
            this->casilleros_jugador[i] = nullptr;
        }
    }
    Casillero** casilleros_aux = new Casillero*[this->cantidad_casilleros - 1];
    for (unsigned int i = 0; i < posicion; i++){
        casilleros_aux[i] = this->casilleros_jugador[i];
    }
    for (unsigned int i = posicion; i < this->cantidad_casilleros-1; i++)
    {
        casilleros_aux[i] = this->casilleros_jugador[i+1];
    }
    if(this->cantidad_casilleros != 0){
        delete[] this->casilleros_jugador;
    }
    this->casilleros_jugador = casilleros_aux;
    this->cantidad_casilleros--;
}

bool Jugador::objetivos_cumplidos()
{
    bool objetivos_cumplidos = this->objetivos->estados_objetivos();
    return objetivos_cumplidos;
}

void Jugador::mostrar_objetivos(unsigned int maximo_escuelas)
{    
    string nombre_piedra = NOMBRE_PIEDRA, nombre_bombas = NOMBRE_BOMBAS, nombre_escuela = NOMBRE_ESCUELA;
    unsigned int escuelas_construidas = obtener_cant_edificio(nombre_escuela),
                 pos_piedra = this->obtener_posicion_material(nombre_piedra),
                 cantidad_piedra = this->materiales_jugador[pos_piedra]->obtener_cantidad(),                 
                 pos_bombas = this->obtener_posicion_material(nombre_bombas),
                 cantidad_bombas = this->materiales_jugador[pos_bombas]->obtener_cantidad();

    unsigned int atributos_objetivos[8];
    atributos_objetivos[0] = this->andycoins_acumuladas;
    atributos_objetivos[1] = this->bombas_compradas;
    atributos_objetivos[2] = this->bombas_usadas;
    atributos_objetivos[3] = this->energia;
    atributos_objetivos[4] = cantidad_piedra;
    atributos_objetivos[5] = cantidad_bombas;
    atributos_objetivos[6] = escuelas_construidas;
    atributos_objetivos[7] = maximo_escuelas;

    this->objetivos->mostrar_progreso(atributos_objetivos);
}

unsigned int Jugador::obtener_cant_edificio(string nombre)
{
    unsigned int contador = 0;
    for (unsigned int i = 0; i < this->cantidad_casilleros; i++)
    {
        if(this->casilleros_jugador[i]->obtener_edificio()->obtener_nombre() == nombre)
            contador++;
    }

    return contador;
}

void Jugador::aumentar_acumulador_por_turno()
{
    this->acumulador_por_turno++;
}

void Jugador::reset_acumulador_por_turno()
{
    this->acumulador_por_turno = 0;
}

unsigned int Jugador::obtener_acumulador_por_turno()
{
    return this->acumulador_por_turno;
}

void Jugador::recolectar_recursos()
{
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL, nombre_andycoins = NOMBRE_ANDYCOINS;
    Edificio* edificio;
    for (unsigned int i = 0; i < cantidad_casilleros; i++)
    {
        edificio = this->casilleros_jugador[i]->obtener_edificio();
        if(edificio->obtener_provee_materiales()){
            switch(edificio->obtener_nombre()[0]){
                case PRIMER_LETRA_MINA:
                    if(edificio->obtener_nombre().length() == 4){
                        agregar_material(nombre_piedra, edificio->obtener_materiales_proveidos() * this->acumulador_por_turno);
                    }
                    else
                        agregar_material(nombre_andycoins, edificio->obtener_materiales_proveidos() * this->acumulador_por_turno);
                    break;
                case PRIMER_LETRA_ASERRADERO:
                    agregar_material(nombre_madera, edificio->obtener_materiales_proveidos() * this->acumulador_por_turno);
                    break;
                case PRIMER_LETRA_FABRICA:
                    agregar_material(nombre_metal, edificio->obtener_materiales_proveidos() * this->acumulador_por_turno);
                    break;
                case PRIMER_LETRA_ESCUELA:
                    agregar_material(nombre_andycoins, edificio->obtener_materiales_proveidos() * this->acumulador_por_turno);
                    break;
                case PRIMER_LETRA_PLANTA_ELEC:
                    incrementar_energia(edificio->obtener_materiales_proveidos() * this->acumulador_por_turno);
                    break;
                default:
                    break;
            }
        }
    }
    reset_acumulador_por_turno();
}

void Jugador::cargar_ubicaciones_materiales(ofstream& archivo)
{
    for (unsigned int i = 0; i < this->cantidad_casilleros-1; i++){
        archivo << casilleros_jugador[i]->obtener_edificio()->obtener_nombre() << PRIMER_DELIMITADOR << casilleros_jugador[i]->obtener_fila()
            << SEGUNDO_DELIMITADOR << casilleros_jugador[i]->obtener_columna() << TERCER_DELIMITADOR << '\n';
    }
    archivo << casilleros_jugador[cantidad_casilleros-1]->obtener_edificio()->obtener_nombre() << PRIMER_DELIMITADOR << casilleros_jugador[cantidad_casilleros-1]->obtener_fila()
            << SEGUNDO_DELIMITADOR << casilleros_jugador[cantidad_casilleros-1]->obtener_columna() << TERCER_DELIMITADOR;

}