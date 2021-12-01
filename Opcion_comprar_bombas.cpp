#include "Opcion_comprar_bombas.h"

estados_t comprar_bombas(Jugador* jugador)
{
	estados_t st = ST_OK;
	string nombre_andycoins = NOMBRE_ANDYCOINS;
	unsigned int costo_energia = ENERGIA_COMPRAR_BOMBAS, bombas;

	if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK)
		return st;

	if((st = obtener_valor_cantidad(bombas)) != ST_OK)
		return st;

	unsigned int precio_bombas = PRECIO_BOMBA*bombas;

	if((st = jugador->verificar_material_necesario(nombre_andycoins, precio_bombas)) != ST_OK){
		st = ST_ERROR_ANDYCOINS_INSUFICIENTES;
		return st;
	}

	jugador-> comprar_bombas(bombas, precio_bombas);
	jugador-> decrementar_energia(costo_energia);

	return st;
}

void mostrar_compra_realizada(Jugador* jugador)
{
	cout << endl << "Se realizo la compra con exito" << endl;
	string nombre_andycoins = NOMBRE_ANDYCOINS;
	string nombre_bombas = NOMBRE_BOMBAS;
	cout << NOMBRE_ANDYCOINS << ": " << jugador->mostrar_cantidad_material(nombre_andycoins) << endl;
	cout << NOMBRE_BOMBAS << ": " << jugador->mostrar_cantidad_material(nombre_bombas) << endl;
}

//estados_t chequear_condiciones_opcion_comprar_bombas()