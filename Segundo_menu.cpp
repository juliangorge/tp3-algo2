#include "Segundo_menu.h"


estados_t construir_edificio(Jugador* jugador, ABB<Edificio *> arbol, Mapa* mapa){
    estados_t st = ST_OK;
    string nombre;
    unsigned int costo_energia = ENERGIA_CONSTRUIR_EDIFICIO;

    cout << "Escribe el nombre del edificio: ";
    cin >> nombre;
    cout << endl;

    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK) return st;

    if(!arbol.buscar(nombre)) return ST_ERROR_NOMBRE_INVALIDO;

    Edificio* edificio = arbol.obtener_dato(nombre);

    if(!edificio->obtener_restantes()) return ST_ERROR_EDIFICIO_MAXIMO_ALCANZADO;

    if(jugador->verificar_material_necesario("piedra", edificio->obtener_piedra() != ST_OK)) return ST_ERROR_MATERIALES_INSUFICIENTES;
    if(jugador->verificar_material_necesario("madera", edificio->obtener_madera() != ST_OK)) return ST_ERROR_MATERIALES_INSUFICIENTES;
    if(jugador->verificar_material_necesario("metal", edificio->obtener_metal() != ST_OK)) return ST_ERROR_MATERIALES_INSUFICIENTES;

    
    ///////// PEDIR JUGADOR /////////////////
    string confirm;
    cout << "Escribe `Y` para confirmar: ";
    cin >> confirm;
    if (confirm == "Y" || confirm == "y"){
        // Indicar coordenadas, verificar.
        unsigned int fila = 1, columna = 2;

        if(mapa->es_construible(fila, columna)){
            cout << "Si" << endl;
            Casillero * casillero = mapa->obtener_casillero(fila, columna);
            if(casillero != NULL){
                casillero->cargar(edificio);
                jugador->decrementar_energia(costo_energia);
                cout << "Confirmado" << endl;
            }
        }        
    
    }
    else
    {
        cout << "Cancelado" << endl;
    }


    return st;
}

void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *> arbol, Mapa* mapa)
{
    Jugador* jugador = jugador_dos;
	mostrar_segundo_menu();
	int opcion = obtener_opcion_segundo_menu();
	while(opcion != OPCION_SALIR_SEGUNDO_MENU){
		opciones_segundo_menu(opcion, jugador, arbol, mapa);
		mostrar_segundo_menu();
		opcion = obtener_opcion_segundo_menu();
	}
}	

void opciones_segundo_menu(int opcion, Jugador* jugador, ABB<Edificio *> arbol, Mapa* mapa){
    estados_t st;
    
    switch(opcion){
        case OPCION_CONSTRUIR_EDIFICIO:
            //Modificar edificios
            if((st = construir_edificio(jugador, arbol, mapa)) != ST_OK) imprimir_error(st);
            break;
        case OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS:
            //Listar edificios
            break;
        case OPCION_DEMOLER_COORDENADA:
            //Mostrar mapa
            break;
        case OPCION_ATACAR_EDIFICIO:
            //Mostrar mapa
            break;
        case OPCION_REPARAR_EDIFICIO:
            //Mostrar mapa
            break;
        case OPCION_COMPRAR_BOMBAS:
            if((st = comprar_bombas(jugador)) != ST_OK){
                imprimir_error(st);
            }
            else{
                mostrar_compra_realizada(jugador);
            }
            break;
        case OPCION_CONSULTAR_COORDENADA:
            //Mostrar mapa
            break;
        case OPCION_MOSTRAR_INVENTARIO:
            jugador->mostrar_inventario();
            break;
        case OPCION_MOSTRAR_OBJETIVOS:
            //Mostrar mapa
            break;
        case OPCION_RECOLECTAR_RECURSOS:
            //Mostrar mapa
            break;
        case OPCION_MOVERSE_A_COORDENADA:
            //Mostrar mapa
            break;
        case OPCION_FINALIZAR_TURNO:
            //Mostrar mapa
            break;
    }
}