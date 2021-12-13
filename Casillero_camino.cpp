#include "Casillero_camino.h"

CasilleroCamino::CasilleroCamino(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = CARACTER_CAMINO;
    this->caracter = this->caracter_casillero;
    this->caracter_jugador = this->caracter_casillero;
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = NOMBRE_CAMINO;
    this->costo_energia_J = ENERGIA_CAMINO_JUG_DOS;
    this->costo_energia_U = ENERGIA_CAMINO_JUG_UNO;
	
}

void CasilleroCamino::cambiar_caracter(){
    this->caracter = this->material->obtener_caracter();
}

void CasilleroCamino::mostrar_casillero()
{
	cout << MSJ_CASILLERO_UNO << this->nombre_casillero << MSJ_CASILLERO_Y;
	if(esta_libre())
		cout << MSJ_CASILLERO_VACIO << endl;
	else if(material == nullptr){
		switch(this->caracter){
			case CARACTER_JUGADOR_UNO:
				cout << MSJ_CASILLERO_CONTIENE_JUG_UNO << endl;
				break;
			case CARACTER_JUGADOR_DOS:
				cout << MSJ_CASILLERO_CONTIENE_JUG_DOS << endl;
				break;
		}
	}
	else 
		cout << MSJ_CASILLERO_CONTIENE_MATERIAL << this->material->obtener_nombre() << endl;
}

void CasilleroCamino::limpiar_casillero()
{
	this->material = nullptr;
	this->caracter = this->caracter_casillero;
}