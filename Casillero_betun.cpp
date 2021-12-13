#include "Casillero_betun.h"

CasilleroBetun::CasilleroBetun(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = 'B';
    this->caracter = this->caracter_casillero;
    this->caracter_jugador = this->caracter_casillero;
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero Betun transitable";
    this->costo_energia_J = 0;
	this->costo_energia_U = 0;
}

void CasilleroBetun::cambiar_caracter(){
	this->caracter = this->material->obtener_caracter();
}

void CasilleroBetun::mostrar_casillero()
{
	cout << "Soy un " << this->nombre_casillero << " y ";
	if(esta_libre())
		cout << "me encuentro vacío" << endl;
	else if(material == nullptr){
		switch(this->caracter){
			case 'J':
				cout << "contengo al jugador 1" << endl;
				break;
			case 'U':
				cout << "contengo al jugador 2" << endl;
				break;
		}
	}
	else 
		cout << "contengo al material " << this->material->obtener_nombre() << endl;
}

void CasilleroBetun::limpiar_casillero()
{
	this->material = nullptr;
	this->caracter = this->caracter_casillero;
}