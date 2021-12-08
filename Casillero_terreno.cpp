#include "Casillero_terreno.h"

CasilleroTerreno:: CasilleroTerreno(unsigned int fila, unsigned int columna) : Casillero(fila, columna){
    this->caracter_casillero = 'T';
    this->caracter = this->caracter_casillero;
    this->es_camino = false;
    this->es_terreno = true;
    this->nombre_casillero = "Casillero Terreno construible";
    this->costo_energia = 25;
}

void CasilleroTerreno:: cambiar_objeto(){
    this->caracter = this->edificio->obtener_caracter();
}

void CasilleroTerreno:: mostrar_casillero()
{
	cout << "Soy un " << this->nombre_casillero << " y ";
	if(esta_libre())
		cout << "me encuentro vacío" << endl;
	else if(edificio == nullptr){
		switch(this->caracter){
			case 'J':
				cout << "contengo al jugador 1" << endl;
				break;
			case 'U':
				cout << "contengo al jugador 2" << endl;
				break;
		}
	}
	else {
		cout << "contengo al edificio " << this->edificio->obtener_nombre();
		switch(this->caracter_jugador){
			case 'J':
				cout << " del jugador 1" << endl;
				break;
			case 'U':
				cout << " del jugador 2" << endl;
				break;
		}
	}
}