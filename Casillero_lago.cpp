#include "Casillero_lago.h"

CasilleroLago::CasilleroLago(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = CARACTER_LAGO;
    this->caracter = this->caracter_casillero;
    this->caracter_jugador = this->caracter_casillero;
    this->es_camino = false;
    this->es_terreno = false;
    this->nombre_casillero = NOMBRE_LAGO;
    this->costo_energia_J = ENERGIA_LAGO_JUG_UNO;
    this->costo_energia_U = ENERGIA_LAGO_JUG_DOS; 
	
}

CasilleroLago::~CasilleroLago(){
}

void CasilleroLago::cambiar_caracter(){

}

void CasilleroLago::mostrar_casillero()
{
	cout << MSJ_CASILLERO_UNO << this->nombre_casillero << MSJ_CASILLERO_Y;
	if(esta_libre())
		cout << MSJ_CASILLERO_VACIO << endl;
	else{
		switch(this->caracter){
			case CARACTER_JUGADOR_UNO:
				cout << MSJ_CASILLERO_CONTIENE_JUG_UNO << endl;
				break;
			case CARACTER_JUGADOR_DOS:
				cout << MSJ_CASILLERO_CONTIENE_JUG_DOS << endl;
				break;
		}
	}
}

void CasilleroLago::limpiar_casillero()
{
	this->caracter = this->caracter_casillero;
	this->caracter_jugador = this->caracter_casillero;
}