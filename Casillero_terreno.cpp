#include "Casillero_terreno.h"

CasilleroTerreno:: CasilleroTerreno(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = CARACTER_TERRENO;
    this->caracter = this->caracter_casillero;
    this->caracter_jugador = this->caracter_casillero;
    this->es_camino = false;
    this->es_terreno = true;
    this->nombre_casillero = NOMBRE_TERRENO;
    this->costo_energia_U = ENERGIA_TERRENO_JUG_UNO;
	this->costo_energia_J = ENERGIA_TERRENO_JUG_DOS;
}

CasilleroTerreno::~CasilleroTerreno(){
}

void CasilleroTerreno:: cambiar_caracter(){
    this->caracter = this->edificio->obtener_caracter();
}

void CasilleroTerreno:: mostrar_casillero()
{
	cout << MSJ_CASILLERO_UNO << this->nombre_casillero << MSJ_CASILLERO_Y;
	if(esta_libre())
		cout << MSJ_CASILLERO_VACIO << endl;
	else if(edificio == nullptr){
		switch(this->caracter){
			case CARACTER_JUGADOR_UNO:
				cout << MSJ_CASILLERO_CONTIENE_JUG_UNO << endl;
				break;
			case CARACTER_JUGADOR_DOS:
				cout << MSJ_CASILLERO_CONTIENE_JUG_DOS << endl;
				break;
		}
	}
	else {
		cout << MSJ_CASILLERO_CONTIENE_EDIFICIO << this->edificio->obtener_nombre();
		switch(this->caracter_jugador){
			case CARACTER_JUGADOR_UNO:
				cout << MSJ_CASILLERO_CONTIENE_EDIFICIO_JUG_UNO << endl;
				break;
			case CARACTER_JUGADOR_DOS:
				cout << MSJ_CASILLERO_CONTIENE_EDIFICIO_JUG_DOS << endl;
				break;
		}
	}
}

void CasilleroTerreno::limpiar_casillero()
{
	this->edificio = nullptr;
	this->caracter = this->caracter_casillero;
	this->caracter_jugador = this->caracter_casillero;
}