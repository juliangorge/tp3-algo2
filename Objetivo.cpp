#include <iostream>
#include "Objetivo.h"


Objetivo:: Objetivo(){

    this->numero=0;
    this->estado=false;
}

Objetivo:: ~Objetivo(){

}

void Objetivo::mostrar_progreso(Jugador *jugador)
{
    for(int i=0; i<CANT_OBJETIVOS_JUGADOR; i++)
        estado_objetivo(jugador, jugador->obtener_objetivo(i));

}


void Objetivo::estado_objetivo(Jugador *jugador, int numero_objetivo)
{
    cout << "su progreso con el objetivo " << numero_objetivo << ": " << endl;

    switch(numero_objetivo){
        case COMPRAR_ANDYPOLIS:
            this->comprar_andypolis(jugador, numero_objetivo);
            break;
        case EDAD_PIEDRA:
            this->edad_piedra(jugador, numero_objetivo);
            break;
        case BOMBARDERO:
            this->bombardero(jugador, numero_objetivo); 
            break;
        case ENERGETICO:
            this->estado_energetico(jugador, numero_objetivo);
            break;
        case LETRADO:
            this->letrado(jugador, numero_objetivo);
            break;
        case MINERO:
            this->minero(jugador, numero_objetivo);
            break;
        case CANSADO:
            this->cansado(jugador, numero_objetivo);
            break;
        case CONSTRUCTOR:
            this->constructor(jugador, numero_objetivo);
            break;
        case ARMADO:
            this->armado(jugador, numero_objetivo);
            break;
        case EXTREMISTA:
            this->extremista(jugador, numero_objetivo);
            break;
    }
}

void Objetivo::comprar_andypolis (Jugador *jugador, int objetivo) 
{          
    unsigned int cantidad_andycoins = jugador->obtener_andycoins_juntadas();

    if(cantidad_andycoins < CANTIDAD_ANDYCOINS_OBJETIVO)
        cout << cantidad_andycoins << " andyocoins juntadas" << endl;
    else
    {
        cout << "Objetivo Comprar Andypolis cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
}

void Objetivo::edad_piedra(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_piedra = jugador->mostrar_cantidad_material("piedra");

    if(cantidad_piedra < CANTIDAD_PIEDRA_OBJETIVO)
        cout << cantidad_piedra << " de piedra juntada" << endl;
    else
    {
        cout << "Objetivo Edad de piedra cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
}

void Objetivo::bombardero(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_bombas = jugador->obtener_bombas_usadas();

    if(cantidad_bombas < BOMBAS_USADAS_OBJETIVO)
        cout << cantidad_bombas << " bombas usadas" << endl;
    else
    {
        cout << "Objetivo Bombardero cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
}

void Objetivo::estado_energetico(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_energia = jugador->obtener_energia();

    if(cantidad_energia < 100)
        cout << cantidad_energia << " de energía almacenada" << endl;
        
    else
    {
        cout << "Objetivo Energetico cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
}

void Objetivo::letrado(Jugador *jugador, int objetivo)
{

    if(jugador->obtener_cant_edificio("escuela") < MAX_ESCUELAS)
        cout << "Restan por construir " << MAX_ESCUELAS - jugador->obtener_cant_edificio("escuela") << " para alcanzar el objetivo" << endl;    
    else
    {
        cout << "Objetivo Letrado cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
}

void Objetivo::minero(Jugador *jugador, int objetivo)
{
    if(jugador->obtener_cant_edificio("mina") >= MINAS_METAL_OBJETIVO && jugador->obtener_cant_edificio("mina oro") >= MINAS_ORO_OBJETIVO)
    {    
        cout << "Objetivo Minero completado" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
    else if(jugador->obtener_cant_edificio("mina") < MINAS_METAL_OBJETIVO && jugador->obtener_cant_edificio("mina oro") < MINAS_ORO_OBJETIVO)
        cout << "Resta construir una mina de metal y una mina de oro" << endl;
    
    else if(jugador->obtener_cant_edificio("mina") < MINAS_METAL_OBJETIVO)
        cout << "Resta construir una mina de metal" << endl;

    else
        cout << "Resta construir una mina de oro" << endl;

}


void Objetivo::cansado(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_cansado = jugador->obtener_energia();



    if(cantidad_cansado > CANTIDAD_CANSADO_OBJETIVO)
        cout << cantidad_cansado << " de energia restante" << endl;
    else
    {
        cout << "Objetivo Cansado cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
}

void Objetivo::constructor(Jugador *jugador, int objetivo)
{
    string mensaje_salida = "Resta construir: ";
    bool objetivo_cumplido = true;

    if(jugador->obtener_cant_edificio("mina") == 0)
    {
        mensaje_salida += "mina de metal, ";
        objetivo_cumplido = false;
    }
    
    if(jugador->obtener_cant_edificio("mina oro") == 0)
    {
        mensaje_salida += "mina de oro, ";
        objetivo_cumplido = false;
    }

    if(jugador->obtener_cant_edificio("aserradero") == 0)
    {
        mensaje_salida += "aserradero, ";
        objetivo_cumplido = false;
    }

    if(jugador->obtener_cant_edificio("fabrica") == 0)
    {
        mensaje_salida += "fabrica, ";
        objetivo_cumplido = false;
    }
    
    if(jugador->obtener_cant_edificio("escuela") == 0)
    {
        mensaje_salida += "escuela, ";
        objetivo_cumplido = false;
    }

    if(jugador->obtener_cant_edificio("planta electrica") == 0)
    {
        mensaje_salida += "planta eléctrica, ";
        objetivo_cumplido = false;
    }

    if(objetivo_cumplido)
    {
        cout << "Objetivo Constructor cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
    else   
        cout << mensaje_salida << endl;

}

void Objetivo::armado(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_armado = jugador->obtener_bombas();

    if(cantidad_armado < CANTIDAD_ARMADO_OBJETIVO)
        cout << cantidad_armado << " bombas en el inventario" << endl;
    else
    {
        cout << "Objetivo Armado cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
}

void Objetivo::extremista(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_bombas_compradas = jugador->obtener_bombas_compradas();

    if(cantidad_bombas_compradas < CANTIDAD_EXTREMISTA_OBJETIVO)
        cout << cantidad_bombas_compradas << " bombas compradas en una partida" << endl;
    else
    {
        cout << "Objetivo Extremista cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
}

void Objetivo::asignar(Jugador *jugador)
{
    srand(time(NULL));
    int objetivos[CANT_OBJETIVOS_JUGADOR], j=0;
    bool objetivo_repetido = false;

    objetivos[0]= aleatorio(1,9);
    
    for(int i=1; i<CANT_OBJETIVOS_JUGADOR; i++)
    {
        objetivos[i]= aleatorio(1,9);

        while(!objetivo_repetido && j<i)
        {
            if(objetivos[j] == objetivos[i])
                objetivo_repetido = true;

            j++;

            if (objetivo_repetido)
            {
                objetivos[i]= aleatorio(1,9);
                j=0;
                objetivo_repetido = false;
            }          
        }
    }

    jugador->set_objetivos(objetivos);

}

int Objetivo::aleatorio(int cota_inferior, int cota_superior)
{
    return int(rand()%cota_superior + cota_inferior);
}

int Objetivo::contar_cumplidos(Jugador *jugador)
{
    int cant_cumplidos=0;

    for(int i=0; i<CANT_OBJETIVOS_JUGADOR; i++)
    {
        cout << "Estado del objetivo " << i << ": " <<jugador->objetivo_cumplido(i) << endl;
        if(jugador->objetivo_cumplido(i))
            cant_cumplidos++;
    }
    cout << "Cantidad de objetivos cumplidos: " << cant_cumplidos << endl;
    return cant_cumplidos;
}