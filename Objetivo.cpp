#include <iostream>
#include "Objetivo.h"


Objetivo:: Objetivo(){

    asignar_objetivos();
    for(unsigned int i = 0; i<CANTIDAD_OBJETIVOS; i++){
        this->estado_objetivos[i] = false;
    }
}

Objetivo:: ~Objetivo(){

}

void Objetivo::asignar_objetivos()
{
    //srand(time(NULL));
    unsigned int j=0;
    bool objetivo_repetido = false;

    //this->objetivos[0]= aleatorio(1,9);
    
    for(unsigned int i = 0; i<CANTIDAD_OBJETIVOS; i++)
    {
        this->objetivos[i] = aleatorio(1,9);

        while(!objetivo_repetido && j<i && i>0)
        {
            if(this->objetivos[j] == this->objetivos[i] || this->objetivos[i] == this->objetivos[0])
                objetivo_repetido = true;

            j++;

            if (objetivo_repetido)
            {
                this->objetivos[i]= aleatorio(1,9);
                j=0;
                objetivo_repetido = false;
            }          
        }
    }
}

int Objetivo::aleatorio(int cota_inferior, int cota_superior)
{
    return int(rand()%cota_superior + cota_inferior);
}

bool Objetivo::estado_objetivo()
{
    bool estado_objetivo = true;
    for(unsigned int i=0; i<CANTIDAD_OBJETIVOS; i++){
        if(this->estado_objetivos[i] != true);
        estado_objetivo = false;
    }
    return estado_objetivo;
}

void Objetivo::mostrar_progreso(unsigned int atributos_objetivos[8])
{
    cout << endl;
    for (unsigned int i = 0; i < CANTIDAD_OBJETIVOS; i++)
    {
        cout << "Progreso con el objetivo " << objetivos[i] << ": " << endl;

        switch(objetivos[i]){

            case COMPRAR_ANDYPOLIS:
               // if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = this->comprar_andypolis(atributos_objetivos[0]);
                break;
            case EDAD_PIEDRA:
                //if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = this->edad_piedra(atributos_objetivos[4]);
                break;
            case BOMBARDERO:
              //  if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = this->bombardero(atributos_objetivos[2]);
                break;
            case ENERGETICO:
               // if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = this->estado_energetico(atributos_objetivos[3]);
                break;
            case LETRADO:
               // if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = this->letrado(atributos_objetivos[6], atributos_objetivos[7]);
                break;
            case MINERO:
                //if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = this->minero();
                break;
            case CANSADO:
                //if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = this->cansado(atributos_objetivos[3]);
                break;
            case CONSTRUCTOR:
                //if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = this->constructor();
                break;
            case ARMADO:
                //if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = armado(atributos_objetivos[5]);
                break;
            case EXTREMISTA:
                //if(!this->estado_objetivos[i])
                    this->estado_objetivos[i] = extremista(atributos_objetivos[1]);
                break;
        }
    }
    cout << endl;
}

bool Objetivo::comprar_andypolis(unsigned int andyocoins_acumuladas) 
{          
    bool objetivo_comprar_andycoins = false;

    if(andyocoins_acumuladas < CANTIDAD_ANDYCOINS_OBJETIVO)
        cout << andyocoins_acumuladas << " andyocoins acumuladas de " << CANTIDAD_ANDYCOINS_OBJETIVO << endl;
    else
    {
        cout << "Objetivo Comprar Andypolis cumplido" << endl;
        objetivo_comprar_andycoins = true;
    }
    return objetivo_comprar_andycoins;
}

bool Objetivo::edad_piedra(unsigned int cantidad_piedra)
{
    bool objetivo_edad_piedra = false;
    if(cantidad_piedra < CANTIDAD_PIEDRA_OBJETIVO)
        cout << cantidad_piedra << " de piedra juntada de " << CANTIDAD_PIEDRA_OBJETIVO << endl;
    else
    {
        cout << "Objetivo Edad de piedra cumplido" << endl;
        objetivo_edad_piedra = true;
    }
    return objetivo_edad_piedra;
}

bool Objetivo::bombardero(unsigned int bombas_usadas)
{
    bool objetivo_bombardero = false;

    if(bombas_usadas < BOMBAS_USADAS_OBJETIVO)
        cout << "Faltan usar " << BOMBAS_USADAS_OBJETIVO - bombas_usadas << " bombas" << endl;
    else
    {
        cout << "Objetivo Bombardero cumplido" << endl;
        objetivo_bombardero = true;
    }
    return objetivo_bombardero;
}

bool Objetivo::estado_energetico(unsigned int energia)
{
    bool objetivo_energetico = false;

    if(energia< 100)
        cout << "Resta por almacenar " << 100 - energia << " energia" << endl;
        
    else
    {
        cout << "Objetivo Energetico cumplido" << endl;
        objetivo_energetico = true;
    }
    return objetivo_energetico;
}

bool Objetivo::letrado(unsigned int escuelas_construidas, unsigned int maximo_escuelas)
{
    bool objetivo_letrado = false;

    if(escuelas_construidas < maximo_escuelas)
        cout << "Restan por construir " << maximo_escuelas - escuelas_construidas << " para alcanzar el objetivo" << endl;    
    else
    {
        cout << "Objetivo Letrado cumplido" << endl;
        objetivo_letrado = true;
    }
    return objetivo_letrado;
}

bool Objetivo::minero()
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
    return true;

}


bool Objetivo::cansado(unsigned int energia)
{
    bool objetivo_cansado = false;
    if(energia > CANTIDAD_CANSADO_OBJETIVO)
        cout << energia << " de energia restante" << endl;
    else
    {
        cout << "Objetivo Cansado cumplido" << endl;
        objetivo_cansado = true;
    }
    return objetivo_cansado;
}

bool Objetivo::constructor()
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
    return true;

}

bool Objetivo::armado(unsigned int cantidad_bombas)
{
    bool objetivo_armado = false;
    if(cantidad_bombas < CANTIDAD_ARMADO_OBJETIVO)
        cout << cantidad_bombas << " bombas en el inventario" << endl;
    else
    {
        cout << "Objetivo Armado cumplido" << endl;
        objetivo_armado = true;
    }
    return objetivo_armado;
}

bool Objetivo::extremista(unsigned int bombas_compradas)
{
    bool objetivo_extremista = false;
    if(bombas_compradas < CANTIDAD_EXTREMISTA_OBJETIVO)
        cout << bombas_compradas << " bombas compradas// en una partida" << endl;
    else
    {
        cout << "Objetivo Extremista cumplido" << endl;
        objetivo_extremista = true;
    }
    return objetivo_extremista;
}
