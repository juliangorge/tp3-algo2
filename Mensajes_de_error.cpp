#include "Mensajes_de_error.h"

void imprimir_error(estados_t st)
{
	switch(st){
		case ST_ERROR_OPCION_INVALIDA:
			cout << MSJ_ERROR_OPCION_INVALIDA << endl;
			break;
		case ST_ERROR_CANTIDAD_INVALIDA:
			cout << MSJ_ERROR_CANTIDAD_INVALIDA << endl;
			break;
		case ST_ERROR_NOMBRE_INVALIDO:
			cout << MSJ_ERROR_NOMBRE_INVALIDO << endl;
			break;
		case ST_ERROR_COORDENADAS_INVALIDAS:
			cout << MSJ_ERROR_COORDENADAS_INVALIDAS << endl;
			break;
		case ST_ERROR_MAXIMO_SUPERADO:
			cout << MSJ_ERROR_MAXIMO_SUPERADO << endl;
			break;
		case ST_ERROR_CASILLERO_NO_CONSTRUIBLE:
			cout << MSJ_ERROR_CASILLERO_NO_CONSTRUIBLE << endl;
			break;
		case ST_ERROR_CASILLERO_OCUPADO:
			cout << MSJ_ERROR_CASILLERO_OCUPADO << endl;
			break;
		case ST_ERROR_MATERIALES_INSUFICIENTES:
			cout << MSJ_ERROR_MATERIALES_INSUFICIENTES << endl;
			break;
		case ST_ERROR_CASILLERO_VACIO:
			cout << MSJ_ERROR_CASILLERO_VACIO << endl;
			break;
		case ST_ERROR_NO_ES_EDIFICIO_PROPIO:
			cout << MSJ_ERROR_NO_ES_EDIFICIO_PROPIO << endl;
			break;
		case ST_ERROR_ES_EDIFICIO_PROPIO:
			cout << MSJ_ERROR_ES_EDIFICIO_PROPIO << endl;
			break;
		case ST_ERROR_CASILLERO_ES_JUGADOR:
			cout << MSJ_ERROR_CASILLERO_ES_JUGADOR << endl;
			break;
		case ST_ERROR_BOMBAS_INSUFICIENTES:
			cout << MSJ_ERROR_BOMBAS_INSUFICIENTES << endl;
			break;
		case ST_ERROR_NO_REQUIERE_REPARACION:
			cout << MSJ_ERROR_NO_REQUIERE_REPARACION << endl;
			break;
		case ST_ERROR_ANDYCOINS_INSUFICIENTES:
			cout << MSJ_ERROR_ANDYCOINS_INSUFICIENTES << endl;
			break;
		case ST_ERROR_RECOLECCION_REPETIDA:
			cout << MSJ_ERROR_RECOLECCION_REPETIDA << endl;
			break;
		case ST_ERROR_ENERGIA_INSUFICIENTE:
			cout << MSJ_ERROR_ENERGIA_INSUFICIENTE << endl;
			break;
		case ST_ERROR_MODIFICANDO_OBELISCO:
			cout << MSJ_ERROR_MODIFICANDO_OBELISCO << endl;
			break;
		case ST_ERROR_EDIFICIO_MAXIMO_ALCANZADO:
			cout << MSJ_ERROR_EDIFICIO_MAXIMO_ALCANZADO << endl;
			break;
		case ST_ERROR_DEMOLER_EDIFICIO:
			cout << MSJ_ERROR_DEMOLER_EDIFICIO << endl;
			break;
		case ST_ERROR_NO_ES_NUMERO:
			cout << MSJ_ERROR_NO_ES_NUMERO << endl;
			break;
		case ST_MSJ_SALIR:
			cout << MSJ_SALIR << endl;
			break;
		case ST_OK:
			break;
	}

}
