#include "Casillero_camino.h"

CasilleroCamino::CasilleroCamino(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = CARACTER_CAMINO;
    this->caracter = this->caracter_casillero;
    this->caracter_jugador = this->caracter_casillero;
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero Camino transitable";
    this->costo_energia_U = 4;
	this->costo_energia_J = 4;
}

void CasilleroCamino::cambiar_caracter(){
    this->caracter = this->material->obtener_caracter();
}

void CasilleroCamino::mostrar_casillero()
{
	cout << "Soy un " << this->nombre_casillero << " y ";
	if(esta_libre())
		cout << "me encuentro vacío" << endl;
	else if(material == nullptr){
		switch(this->caracter){
			case CARACTER_JUGADOR_UNO:
				cout << "contengo al jugador 1" << endl;
				break;
			case CARACTER_JUGADOR_DOS:
				cout << "contengo al jugador 2" << endl;
				break;
		}
	}
	else 
		cout << "contengo al material " << this->material->obtener_nombre() << endl;
}

void CasilleroCamino::limpiar_casillero()
{
	this->material = nullptr;
	this->caracter = this->caracter_casillero;
}