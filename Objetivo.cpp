#include <iostream>
#include "objetivo.h"

using namespace std;

/*void mostrar_objetivos(Jugador *jugador_uno, Jugador *jugador_dos)
{

}
*/

mostrar_progreso(jugador_uno, objetivo 1)
mostrar_progreso(jugador_uno, objetivo 2)
mostrar_progreso(jugador_uno, objetivo 3)

mostrar_progreso(jugador_dos)

void mostrar_progreso(Jugador *jugador, objetivos numero_objetivo)//recibe un enum
{
    //objetivos objetivos_enum = numero_objetivo;
    cout << "su progreso con el objetivo " << numero_objetivo << ": " << endl;

    switch(numero_objetivo){
        case COMPRAR_ANDYPOLIS:
            objetivo_comprar_andypolis(jugador, numero_objetivo);
            break;
        case EDAD_PIEDRA:
            objetivo_edad_piedra(jugador, numero_objetivo);
            break;
        case BOMBARDERO:
            objetivo_bombardero(jugador, numero_objetivo); 
            break;
        case ENERGETICO:
            objetivo_estado_energetico(jugador, numero_objetivo);
            break;
        case LETRADO:
            objetivo_letrado(jugador, numero_objetivo);
            break;
        case MINERO:
            objetivo_minero(jugador), numero_objetivo;
            break;
        case CANSADO:
        objetivo_cansado(jugador, numero_objetivo);
            break;
        case CONSTRUCTOR:
            objetivo_constructor(jugador, numero_objetivo);
            break;
        case ARMADO:
            break;
        case EXTREMISTA:
            objetivo_extremista(jugador, numero_objetivo);
            break;
    }
}

void objetivo_comprar_andypolis (Jugador *jugador, int objetivo) 
{          
    unsigned int cantidad_andycoins = jugador->obtener_andycoins_juntadas();

    if(cantidad_andycoins < CANTIDAD_ANDYCOINS_OBJETIVO)
        cout << cantidad_andycoins << " andyocoins juntadas" << endl;
    else
    {
        cout << "Objetivo COMPRAR ANDYPOLIS cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
}

void objetivo_edad_piedra(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_piedra = jugador->obtener_piedra_juntada();

    if(cantidad_piedra < CANTIDAD_PIEDRA_OBJETIVO)
        cout << cantidad_piedra << " de piedra juntada" << endl;
    else
    {
        cout << "Objetivo EDAD PIEDRA cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
}

void objetivo_bombardero(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_bombas = jugador->obtener_bombas_usadas();

    if(cantidad_bombas < BOMBAS_USADAS_OBJETIVO)
        cout << cantidad_bombas << " de bombas usadas" << endl;
    else
    {
        cout << "Objetivo BOMBARDERO cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
}

void objetivo_estado_energetico(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_energia = jugador->obtener_energia();

    if(!jugador->obtener_100_energia()) //debe devolver un booleano
        cout << cantidad_energia << " de energía almacenada" << endl;
        
    else
    {
        cout << "Objetivo ENERGÉTICO cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
}

void objetivo_letrado(Jugador *jugador, int objetivo)
{
    if(jugador->obtener_escuelas_construidas < jugador->obtener_max_escuelas)
        cout << "Restan por construir " << jugador->obtener_max_escuelas - jugador->obtener_escuelas_construidas << " para alcanzar el objetivo" << endl;    
    else
    {
        cout << "Objetivo de máxima construcción de escuelas completado" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
}

void objetivo_minero(Jugador *jugador, int objetivo)
{
    if(jugador->obtener_minas_metal() >= MINAS_METAL_OBJETIVO && jugador->obtener_minas_oro() >= MINAS_ORO_OBJETIVO)
    {    
        cout << "Objetivo MINERO completado" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
    else if(jugador->obtener_minas_metal() < MINAS_METAL_OBJETIVO && jugador->obtener_minas_oro() < MINAS_ORO_OBJETIVO)
        cout << "Resta construir una mina de metal y una mina de oro" << endl;
    
    else if(jugador->obtener_minas_metal() < MINAS_METAL_OBJETIVO)
        cout << "Resta construir una mina de metal" << endl;

    else
        cout << "Resta construir una mina de oro" << endl;

}


void objetivo_cansado(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_cansado = jugador->obtener_energia();



    if(cantidad_cansado > CANTIDAD_CANSADO_OBJETIVO)
        cout << cantidad_cansado << " de energia restante" << endl;
    else
    {
        cout << "Objetivo CANSADO cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
}

void set_objetivo_cumplido(int objetivo)
{

}

void objetivo_constructor(Jugador *jugador, int objetivo, Mapa *mapa)
{
    string mensaje_salida = "Resta construir: ";
    bool objetivo_cumplido = true;

    if(jugador->obtener_cant_mina_metal() == 0)
    {
        mensaje_salida += "mina de metal ";
        objetivo_cumplido = false;
    }
    
    if(jugador->obtener_cant_mina_oro() == 0)
    {
        mensaje_salida += "mina de oro ";
        objetivo_cumplido = false;
    }

    if(jugador->obtener_cant_aserradero() == 0)
    {
        mensaje_salida += "aserradero ";
        objetivo_cumplido = false;
    }

    if(jugador->obtener_cant_fabrica() == 0)
    {
        mensaje_salida += "fabrica ";
        objetivo_cumplido = false;
    }
    
    if(jugador->obtener_cant_mina_metal() == 0)
    {
        mensaje_salida += "mina de metal ";
        objetivo_cumplido = false;
    }
    
    if(jugador->obtener_cant_escuela() == 0)
    {
        mensaje_salida += "escuela ";
        objetivo_cumplido = false;
    }

    if(jugador->obtener_cant_planta_electrica() == 0)
    {
        mensaje_salida += "planta eléctrica ";
        objetivo_cumplido = false;
    }

    if(objetivo_cumplido)
    {
        cout << "Objetivo CONSTRUCTOR cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
    else   
        cout << mensaje_salida << endl;

}

void objetivo_armado(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_armado = jugador->obtener_bombas();

    if(cantidad_armado < CANTIDAD_ARMADO_OBJETIVO)
        cout << cantidad_armado << " de bombas en el inventario" << endl;
    else
    {
        cout << "Objetivo ARMADO cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
}

void objetivo_extremista(Jugador *jugador, int objetivo)
{
    unsigned int cantidad_bombas_compradas = jugador->obtener_bombas_compradas();

    if(cantidad_bombas_compradas < CANTIDAD_EXTREMISTA_OBJETIVO)
        cout << cantidad_bombas_compradas << " de bombas compradas en una partida" << endl;
    else
    {
        cout << "Objetivo EXTREMISTA cumplido" << endl;
        jugador->set_objetivo_cumplido(objetivo);
    }
}
