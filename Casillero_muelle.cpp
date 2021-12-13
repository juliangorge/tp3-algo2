#include "Casillero_muelle.h"

CasilleroMuelle::CasilleroMuelle(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = 'M';
    this->caracter = this->caracter_casillero;
    this->caracter_jugador = this->caracter_casillero;
    this->es_camino = true;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero Muelle transitable";
    this->costo_energia_J = 5;
	this->costo_energia_U = 2;
}

void CasilleroMuelle::cambiar_caracter(){
	this->caracter = this->material->obtener_caracter();
}

void CasilleroMuelle::mostrar_casillero()
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

void CasilleroMuelle::limpiar_casillero()
{
	this->material = nullptr;
	this->caracter = this->caracter_casillero;
}