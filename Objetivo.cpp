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
        this->objetivos[i] = aleatorio(OBJETIVO_MINIMO,OBJETIVO_MAXIMO);

        while(!objetivo_repetido && j<i && i>0)
        {
            if(this->objetivos[j] == this->objetivos[i] || this->objetivos[i] == this->objetivos[0])
                objetivo_repetido = true;

            j++;

            if (objetivo_repetido)
            {
                this->objetivos[i]= aleatorio(OBJETIVO_MINIMO,OBJETIVO_MAXIMO);
                j = 0;
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
        if(!this->estado_objetivos[i])
            objetivos_cumplidos++;
    }

    if(objetivos_cumplidos >= CANTIDAD_OBJETIVOS_CUMPLIDOS || this->objetivo_principal)
        estados_objetivos = true;

    return estados_objetivos;
}

void Objetivo::mostrar_progreso(unsigned int atributos_objetivos[CANTIDAD_VALORES_OBJETIVOS], unsigned int tipos_edificios_construidos[CANTIDAD_TIPOS_EDIFICIOS])
{
    cout << endl;
    chequear_objetivo_principal(tipos_edificios_construidos[POS_OBELISCO]);
    
    for (unsigned int i = 0; i < CANTIDAD_OBJETIVOS; i++)
    {
        cout << MSJ_OBJETIVO_PROGRESO << objetivos[i] << endl;

        switch(objetivos[i]){

            case COMPRAR_ANDYPOLIS:
                    comprar_andypolis(this->estado_objetivos[i], atributos_objetivos[POS_ANDYCOINS_ACUM]);
                break;
            case EDAD_PIEDRA:
                    edad_piedra(this->estado_objetivos[i], atributos_objetivos[POS_CANTIDAD_PIEDRA]);
                break;
            case BOMBARDERO:
                    bombardero(this->estado_objetivos[i], atributos_objetivos[POS_BOMBAS_USADAS]);
                break;
            case ENERGETICO:
                    energetico(this->estado_objetivos[i], atributos_objetivos[POS_ENERGIA]);
                break;
            case LETRADO:
                    letrado(this->estado_objetivos[i], atributos_objetivos[POS_ESCUELAS_CONST], atributos_objetivos[POS_ESCUELAS_MAX]);
                break;
            case MINERO:
                    minero(this->estado_objetivos[i], tipos_edificios_construidos);
                break;
            case CANSADO:
                    cansado(this->estado_objetivos[i], atributos_objetivos[POS_ENERGIA]);
                break;
            case CONSTRUCTOR:
                    constructor(this->estado_objetivos[i], tipos_edificios_construidos);
                break;
            case ARMADO:
                    armado(this->estado_objetivos[i], atributos_objetivos[POS_CANTIDAD_BOMBAS]);
                break;
            case EXTREMISTA:
                    extremista(this->estado_objetivos[i], atributos_objetivos[POS_BOMBAS_COMPRADAS]);
                break;
        }
    }
    cout << endl;
}

void Objetivo::chequear_objetivo_principal(unsigned int obeliscos_construidos){
    cout << MSJ_OBJETIVO_PROGRESO_PRINCIPAL << endl;

    if(this->objetivo_principal)
        cout << MSJ_OBJETIVO_PRINCPIAL_CUMPLIDO << endl << endl;
    else if(!obeliscos_construidos)
        cout << MSJ_OBJETIVO_PRINCPIAL_NO_CUMPLIDO << endl << endl;
    else
        cout << MSJ_OBJETIVO_PRINCPIAL_CUMPLIDO << endl << endl;
} 

void Objetivo::comprar_andypolis(bool & objetivo_comprar_andycoins, unsigned int andyocoins_acumuladas) 
{   
    if(objetivo_comprar_andycoins)
      cout << MSJ_OBJETIVO_CUMPLIDO_COMPRAR_ANDYPOLIS << endl << endl;        

    else if(andyocoins_acumuladas < CANTIDAD_ANDYCOINS_OBJETIVO)
        cout << MSJ_OBJETIVO_PROGRESO_COMPRAR_ANDYPOLIS << andyocoins_acumuladas << SEPARADOR_CANTIDADES << CANTIDAD_ANDYCOINS_OBJETIVO << endl << endl;
    
    else{
        objetivo_comprar_andycoins = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_COMPRAR_ANDYPOLIS << endl << endl;  
    }
}

void Objetivo::edad_piedra(bool & objetivo_edad_piedra, unsigned int cantidad_piedra)
{
    if(objetivo_edad_piedra)
        cout << MSJ_OBJETIVO_CUMPLIDO_EDAD_PIEDRA << endl << endl; 

    else if(cantidad_piedra < CANTIDAD_PIEDRA_OBJETIVO)
        cout << MSJ_OBJETIVO_PROGRESO_EDAD_PIEDRA << cantidad_piedra  << SEPARADOR_CANTIDADES << CANTIDAD_PIEDRA_OBJETIVO << endl << endl;
    
    else{
        objetivo_edad_piedra = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_EDAD_PIEDRA << endl << endl;   
    }
}

void Objetivo::bombardero(bool & objetivo_bombardero, unsigned int bombas_usadas)
{
    if(objetivo_bombardero)
        cout << MSJ_OBJETIVO_CUMPLIDO_BOMBARDERO << endl << endl; 

    else if(bombas_usadas < BOMBAS_USADAS_OBJETIVO)
        cout << MSJ_OBJETIVO_PROGRESO_BOMBARDERO << bombas_usadas << SEPARADOR_CANTIDADES << BOMBAS_USADAS_OBJETIVO << endl << endl;
    
    else{
        objetivo_bombardero = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_BOMBARDERO << endl << endl;    
    }
}

void Objetivo::energetico(bool & objetivo_energetico, unsigned int energia)
{
    if(objetivo_energetico)
        cout << MSJ_OBJETIVO_CUMPLIDO_ENERGETICO << endl << endl;

    else if(energia < ENERGIA_MAXIMA)
        cout <<  MSJ_OBJETIVO_PROGRESO_ENERGETICO << ENERGIA_MAXIMA - energia << endl << endl;

    else{
        objetivo_energetico = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_ENERGETICO << endl << endl;       
    }
}

void Objetivo::letrado(bool & objetivo_letrado, unsigned int escuelas_construidas, unsigned int maximo_escuelas)
{
    if(objetivo_letrado)
        cout << MSJ_OBJETIVO_CUMPLIDO_LETRADO << endl << endl;

    else if(escuelas_construidas < maximo_escuelas)
        cout << MSJ_OBJETIVO_PROGRESO_LETRADO << maximo_escuelas - escuelas_construidas << endl << endl; 

    else{
        objetivo_letrado = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_LETRADO << endl << endl;   
    }
}

void Objetivo::minero(bool & objetivo_minero, unsigned int tipos_edificios_construidos[CANTIDAD_TIPOS_EDIFICIOS])
{
    if(objetivo_minero)
        cout << MSJ_OBJETIVO_CUMPLIDO_MINERO << endl << endl; 

    else if(!tipos_edificios_construidos[POS_MINA] || !tipos_edificios_construidos[POS_MINA_ORO]){
        cout << MSJ_OBJETIVO_PROGRESO_MINERO << endl;
        cout << "   *" << NOMBRE_MINA << ": " <<tipos_edificios_construidos[POS_MINA] << endl;
        cout << "   *" << NOMBRE_MINA_ORO << ": " <<tipos_edificios_construidos[POS_MINA_ORO] << endl;
        cout << endl;
    }

    else{
        objetivo_minero = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_MINERO << endl << endl; 
    }
}


void Objetivo::cansado(bool & objetivo_cansado, unsigned int energia)
{   
    if(objetivo_cansado)
        cout << MSJ_OBJETIVO_CUMPLIDO_CANSADO << endl << endl;

    else if(energia > CANTIDAD_CANSADO_OBJETIVO)
        cout << MSJ_OBJETIVO_PROGRESO_CANSADO << energia << endl << endl;

    else{
        objetivo_cansado = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_CANSADO << endl << endl;       
    }
}

void Objetivo::constructor(bool & objetivo_constructor, unsigned int tipos_edificios_construidos[CANTIDAD_TIPOS_EDIFICIOS])
{
    bool todos_construidos = true;

    for(unsigned int i = 0; i < CANTIDAD_TIPOS_EDIFICIOS-1; i++){
        if(!tipos_edificios_construidos[i])
            todos_construidos = false;
    }

    if(objetivo_constructor)
        cout << MSJ_OBJETIVO_CUMPLIDO_CONSTRUCTOR << endl << endl; 

    else if(!todos_construidos){
        cout << MSJ_OBJETIVO_PROGRESO_CONSTRUCTOR << endl;
        cout << "   *" << NOMBRE_MINA << ": " <<tipos_edificios_construidos[POS_MINA] << endl;
        cout << "   *" << NOMBRE_MINA_ORO << ": " <<tipos_edificios_construidos[POS_MINA_ORO] << endl;
        cout << "   *" << NOMBRE_ASERRADERO << ": " <<tipos_edificios_construidos[POS_ASERRADERO] << endl;
        cout << "   *" << NOMBRE_FABRICA << ": " <<tipos_edificios_construidos[POS_FABRICA] << endl;
        cout << "   *" << NOMBRE_ESCUELA << ": " <<tipos_edificios_construidos[POS_ESCUELA] << endl;
        cout << "   *" << NOMBRE_PLANTA_ELEC << ": " <<tipos_edificios_construidos[POS_PLANTA_ELEC] << endl;
        cout << endl;
    }

    else{
        objetivo_constructor = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_CONSTRUCTOR << endl << endl; 
    }

}

void Objetivo::armado(bool & objetivo_armado, unsigned int cantidad_bombas)
{
    if(objetivo_armado)
        cout << MSJ_OBJETIVO_CUMPLIDO_ARMADO << endl << endl;

    else if(cantidad_bombas < CANTIDAD_ARMADO_OBJETIVO)
        cout << MSJ_OBJETIVO_PROGRESO_ARMADO << cantidad_bombas << SEPARADOR_CANTIDADES << CANTIDAD_ARMADO_OBJETIVO  << endl << endl;
    
    else{
        objetivo_armado = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_ARMADO << endl << endl;      
    }
}

void Objetivo::extremista(bool & objetivo_extremista, unsigned int bombas_compradas)
{
    if(objetivo_extremista)
        cout << MSJ_OBJETIVO_CUMPLIDO_EXTREMISTA << endl << endl;

    else if(bombas_compradas < CANTIDAD_EXTREMISTA_OBJETIVO)
        cout << MSJ_OBJETIVO_PROGRESO_EXTREMISTA << bombas_compradas << SEPARADOR_CANTIDADES << CANTIDAD_EXTREMISTA_OBJETIVO << endl << endl;
    
    else{
        objetivo_extremista = true;
        cout << MSJ_OBJETIVO_CUMPLIDO_EXTREMISTA << endl << endl;    
    }
}
