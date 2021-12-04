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

    // // // // // //

    if(pedido_confirmacion() != ST_OK) return ST_MSJ_SALIR;
    
    unsigned int fila, columna;
    if(consultar_coordenadas(mapa, fila, columna) != ST_OK) return ST_ERROR_COORDENADAS_INVALIDAS;
        
    mapa->obtener_casillero(fila, columna)->cargar(edificio);
    jugador->decrementar_energia(costo_energia);

    return st;
}

estados_t demoler_edificio(Jugador* jugador, ABB<Edificio *> arbol, Mapa* mapa){
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_DEMOLER_EDIFICIO;
    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK) return st;

    unsigned int fila, columna;
    if(consultar_coordenadas(mapa, fila, columna) != ST_OK) return ST_ERROR_COORDENADAS_INVALIDAS;
    if(mapa->obtener_casillero(fila, columna)->obtener_edificio() != NULL){
        
        cout << "Demolido correctamente" << endl;
        // Demoler y devolver la mitad de los materiales utilizados

        jugador->decrementar_energia(costo_energia);
        return ST_OK;
    }

    return ST_ERROR_DEMOLER_EDIFICIO;
}

Jugador* inicializar_jugador(Jugador* jugador_uno, Jugador* jugador_dos)
{
    Jugador* jugador;
    int opcion = obtener_numero_jugador();
    cout << "El jugador que inicia la partida es el jugador " << opcion << endl;
    switch(opcion){
        case OPCION_JUGADOR_UNO:
            jugador = jugador_uno;
            break;
        case OPCION_JUGADOR_DOS:
            jugador = jugador_dos;
            break;
    }
    return jugador;
}

void verificar_energia_nula(Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos)
{
    if(jugador_uno->verificar_energia_nula())
        cambiar_jugador(jugador, jugador_uno, jugador_dos);
    else if(jugador_dos->verificar_energia_nula())
        cambiar_jugador(jugador, jugador_uno, jugador_dos);
}

void cambiar_jugador(Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos)
{      
    if(jugador->obtener_caracter_jugador() == 'J')
        jugador = jugador_dos;
    else if (jugador->obtener_caracter_jugador() == 'U')
        jugador = jugador_uno;
}

void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *> arbol, Mapa* mapa)
{
    //cargar_ubicaciones(jugador_uno, jugador_dos, arbol, mapa);
    Jugador* jugador = inicializar_jugador(jugador_uno, jugador_dos);
    mostrar_segundo_menu();
	int opcion = obtener_opcion_segundo_menu();
	while(opcion != OPCION_SALIR_SEGUNDO_MENU){
        verificar_energia_nula(jugador, jugador_uno, jugador_dos);
		opciones_segundo_menu(opcion, jugador, jugador_uno, jugador_dos, arbol, mapa);
		mostrar_segundo_menu();
		opcion = obtener_opcion_segundo_menu();
	}
}	

void opciones_segundo_menu(int opcion, Jugador* & jugador, Jugador* jugador_uno, Jugador *jugador_dos, ABB<Edificio *> arbol, Mapa* mapa){
    estados_t st;
    switch(opcion){
        case OPCION_CONSTRUIR_EDIFICIO:
            //Modificar edificios
            if((st = construir_edificio(jugador_uno, arbol, mapa)) != ST_OK) imprimir_error(st);
            break;
        case OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS:
            //Listar edificios

            /*
            Arbol tiene Edificios con cantidad_jugador{1,2}
            Casillero::mostrar_coordenadas_de_edificio_por_jugador()
            */

            break;
        case OPCION_DEMOLER_COORDENADA:
            //Mostrar mapa
            if((st = demoler_edificio(jugador_uno, arbol, mapa)) != ST_OK) imprimir_error(st);
            break;
        case OPCION_ATACAR_EDIFICIO:
            //Mostrar mapa
            //if((st = atacar_edificio(jugador_uno, arbol, mapa)) != ST_OK) imprimir_error(st);
            break;
        case OPCION_REPARAR_EDIFICIO:
            //Mostrar mapa
            //if((st = reparar_edificio(jugador_uno, arbol, mapa)) != ST_OK) imprimir_error(st);
            break;
        case OPCION_COMPRAR_BOMBAS:
            if((st = comprar_bombas(jugador_uno)) != ST_OK){
                imprimir_error(st);
            }
            else{
                mostrar_compra_realizada(jugador_uno);
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
            cambiar_jugador(jugador, jugador_uno, jugador_dos);
            cout << " Finalizo el turno" << endl;
            break;
    }
}