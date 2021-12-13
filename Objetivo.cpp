#include <iostream>
#include "Objetivo.h"


Objetivo:: Objetivo(){

    this->objetivo_principal = false;
    asignar_objetivos();
    for(unsigned int i = 0; i<CANTIDAD_OBJETIVOS; i++){
        this->estado_objetivos[i] = false;
    }
}

void Objetivo::asignar_objetivos()
{
    unsigned int j=0;
    bool objetivo_repetido = false;
    
    for(unsigned int i = 0; i<CANTIDAD_OBJETIVOS; i++)
    {
        this->objetivos[i] = aleatorio(1,10);

        while(!objetivo_repetido && j<i && i>0)
        {
            if(this->objetivos[j] == this->objetivos[i] || this->objetivos[i] == this->objetivos[0])
                objetivo_repetido = true;

            j++;

            if (objetivo_repetido)
            {
                this->objetivos[i]= aleatorio(1,10);
                j=0;
                objetivo_repetido = false;
            }          
        }
    }
}

bool Objetivo::estados_objetivos()
{   
    unsigned int objetivos_cumplidos = 0;
    bool estados_objetivos = false;

    for(unsigned int i=0; i<CANTIDAD_OBJETIVOS; i++){
        if(this->estado_objetivos[i] != true);
        objetivos_cumplidos++;
    }

    if(objetivos_cumplidos >= 2 || this->objetivo_principal)
        estados_objetivos = true;

    return estados_objetivos;
}

void Objetivo::mostrar_progreso(unsigned int atributos_objetivos[8])
{
    cout << endl;
    
    for (unsigned int i = 0; i < CANTIDAD_OBJETIVOS; i++)
    {
        cout << "Progreso con los objetivos secundarios: " << objetivos[i] << ": " << endl;

        switch(objetivos[i]){

            case COMPRAR_ANDYPOLIS:
                    comprar_andypolis(this->estado_objetivos[i], atributos_objetivos[0]);
                break;
            case EDAD_PIEDRA:
                    edad_piedra(this->estado_objetivos[i], atributos_objetivos[4]);
                break;
            case BOMBARDERO:
                    bombardero(this->estado_objetivos[i], atributos_objetivos[2]);
                break;
            case ENERGETICO:
                    estado_energetico(this->estado_objetivos[i], atributos_objetivos[3]);
                break;
            case LETRADO:
                    letrado(this->estado_objetivos[i], atributos_objetivos[6], atributos_objetivos[7]);
                break;
            case MINERO:
                    minero(this->estado_objetivos[i]);
                break;
            case CANSADO:
                    cansado(this->estado_objetivos[i], atributos_objetivos[3]);
                break;
            case CONSTRUCTOR:
                    constructor(this->estado_objetivos[i]);
                break;
            case ARMADO:
                    armado(this->estado_objetivos[i], atributos_objetivos[5]);
                break;
            case EXTREMISTA:
                    extremista(this->estado_objetivos[i], atributos_objetivos[1]);
                break;
        }
    }
    cout << endl;
}

void Objetivo::comprar_andypolis(bool & objetivo_comprar_andycoins, unsigned int andyocoins_acumuladas) 
{          

    if(!objetivo_comprar_andycoins || andyocoins_acumuladas < CANTIDAD_ANDYCOINS_OBJETIVO)
        cout << andyocoins_acumuladas << " andyocoins acumuladas de " << CANTIDAD_ANDYCOINS_OBJETIVO << endl;
    else
    {
        objetivo_comprar_andycoins = true;
        cout << "Objetivo Comprar Andypolis cumplido" << endl;  
    }
}

void Objetivo::edad_piedra(bool & objetivo_edad_piedra, unsigned int cantidad_piedra)
{

    if(!objetivo_edad_piedra ||  cantidad_piedra < CANTIDAD_PIEDRA_OBJETIVO)
        cout << cantidad_piedra << " de piedra juntada de " << CANTIDAD_PIEDRA_OBJETIVO << endl;
    else
    {
        objetivo_edad_piedra = true;
        cout << "Objetivo Edad de piedra cumplido" << endl;   
    }
}

void Objetivo::bombardero(bool & objetivo_bombardero, unsigned int bombas_usadas)
{

    if(!objetivo_bombardero || bombas_usadas < BOMBAS_USADAS_OBJETIVO)
        cout << "Faltan usar " << BOMBAS_USADAS_OBJETIVO - bombas_usadas << " bombas" << endl;
    else
    {
        objetivo_bombardero = true;
        cout << "Objetivo Bombardero cumplido" << endl;    
    }
}

void Objetivo::estado_energetico(bool & objetivo_energetico, unsigned int energia)
{

    if(!objetivo_energetico || energia< 100)
        cout << "Resta por almacenar " << 100 - energia << " energia" << endl;
    else
    {
        objetivo_energetico = true;
        cout << "Objetivo Energetico cumplido" << endl;       
    }
}

void Objetivo::letrado(bool & objetivo_letrado, unsigned int escuelas_construidas, unsigned int maximo_escuelas)
{

    if(!objetivo_letrado || escuelas_construidas < maximo_escuelas)
        cout << "Restan por construir " << maximo_escuelas - escuelas_construidas << " para alcanzar el objetivo" << endl;    
    else
    {
        objetivo_letrado = true;
        cout << "Objetivo Letrado cumplido" << endl;   
    }
}

void Objetivo::minero(bool & objetivo)
{
    /*if(jugador->obtener_cant_edificio("mina") >= MINAS_METAL_OBJETIVO && jugador->obtener_cant_edificio("mina oro") >= MINAS_ORO_OBJETIVO)
    {    
        cout << "Objetivo Minero completado" << endl;
        jugador->set_objetivo_cumplido(objetivo, jugador);
    }
    else if(jugador->obtener_cant_edificio("mina") < MINAS_METAL_OBJETIVO && jugador->obtener_cant_edificio("mina oro") < MINAS_ORO_OBJETIVO)
        cout << "Resta construir una mina de metal y una mina de oro" << endl;
    
    else if(jugador->obtener_cant_edificio("mina") < MINAS_METAL_OBJETIVO)
        cout << "Resta construir una mina de metal" << endl;

    else
        cout << "Resta construir una mina de oro" << endl;*/
}


void Objetivo::cansado(bool & objetivo_cansado, unsigned int energia)
{
    if(!objetivo_cansado || energia > CANTIDAD_CANSADO_OBJETIVO)
        cout << energia << " de energia restante" << endl;
    else
    {
        objetivo_cansado = true;
        cout << "Objetivo Cansado cumplido" << endl;       
    }
}

void Objetivo::constructor(bool & objetivo)
{
    /*string mensaje_salida = "Resta construir: ";
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
        cout << mensaje_salida << endl;*/

}

void Objetivo::armado(bool & objetivo_armado, unsigned int cantidad_bombas)
{
    if(!objetivo_armado || cantidad_bombas < CANTIDAD_ARMADO_OBJETIVO)
        cout << cantidad_bombas << " bombas en el inventario" << endl;
    else
    {
        objetivo_armado = true;
        cout << "Objetivo Armado cumplido" << endl;      
    }
}

void Objetivo::extremista(bool & objetivo_extremista, unsigned int bombas_compradas)
{
    if(!objetivo_extremista || bombas_compradas < CANTIDAD_EXTREMISTA_OBJETIVO)
        cout << bombas_compradas << " bombas compradas// en una partida" << endl;
    else
    {
        objetivo_extremista = true;
        cout << "Objetivo Extremista cumplido" << endl;    
    }
}
