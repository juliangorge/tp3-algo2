#include "Casillero_lago.h"

CasilleroLago:: CasilleroLago(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = 'L';
    this->caracter = this->caracter_casillero;
    this->es_camino = false;
    this->es_terreno = false;
    this->nombre_casillero = "Casillero Lago intransitable";
    this->costo_energia_U = 5; 
	this->costo_energia_J = 2;
}

void CasilleroLago:: cambiar_caracter(){

}

void CasilleroLago::mostrar_casillero()
{
	cout << "Soy un " << this->nombre_casillero << " y ";
	if(esta_libre())
		cout << "me encuentro vacío" << endl;
	else{
		switch(this->caracter){
			case 'J':
				cout << "contengo al jugador 1" << endl;
				break;
			case 'U':
				cout << "contengo al jugador 2" << endl;
				break;
		}
	}
}

void CasilleroLago::limpiar_casillero()
{

}