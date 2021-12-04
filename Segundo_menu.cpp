#include "Segundo_menu.h"

estados_t construir_edificio(Jugador* jugador, ABB<Edificio *> arbol, Mapa* mapa){
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_CONSTRUIR_EDIFICIO;

    // Verifico la energia
    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK) return st;

    // Verifico que exista el edificio
    string nombre;
    cout << "Escribe el nombre del edificio: ";
    cin >> nombre;
    cout << endl;

    // Verifico que existo
    if(!arbol.buscar(nombre)) return ST_ERROR_NOMBRE_INVALIDO;
    Edificio* edificio = arbol.obtener_dato(nombre);

    // Verifico máximo alcanzado
    if(!edificio->obtener_restantes()) return ST_ERROR_EDIFICIO_MAXIMO_ALCANZADO;

    // Verifico materiales
    if(jugador->verificar_material_necesario("piedra", edificio->obtener_piedra() != ST_OK)) return ST_ERROR_MATERIALES_INSUFICIENTES;
    if(jugador->verificar_material_necesario("madera", edificio->obtener_madera() != ST_OK)) return ST_ERROR_MATERIALES_INSUFICIENTES;
    if(jugador->verificar_material_necesario("metal", edificio->obtener_metal() != ST_OK)) return ST_ERROR_MATERIALES_INSUFICIENTES;

    // Solicito confirmacion
    if(pedido_confirmacion() != ST_OK) return ST_MSJ_SALIR;
    
    // Solicito coordenadas
    unsigned int fila, columna;
    if(consultar_coordenadas(mapa, fila, columna) != ST_OK) return ST_ERROR_COORDENADAS_INVALIDAS;

    Casillero * casillero_aux = mapa->obtener_casillero(fila, columna);
    if(casillero_aux == NULL) return ST_ERROR_COORDENADAS_INVALIDAS;

    if(!mapa->es_construible(casillero_aux)) return ST_ERROR_CASILLERO_NO_CONSTRUIBLE;

    casillero_aux->cargar(edificio);
    jugador->agregar_casillero(casillero_aux);

    jugador->restar_materiales("piedra", edificio->obtener_piedra());
    jugador->restar_materiales("madera", edificio->obtener_madera());
    jugador->restar_materiales("metal", edificio->obtener_metal());

    jugador->decrementar_energia(costo_energia);

    cout << "Construido exitosamente!" << endl;
    return st;
}

estados_t mostrar_edificios(ABB<Edificio *> arbol, Jugador* jugador_uno, Jugador* jugador_dos){
    estados_t st = ST_OK;

    jugador_uno->mostrar_edificios();

    return st;
}

estados_t demoler_edificio(Jugador* jugador, ABB<Edificio *> arbol, Mapa* mapa){
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_DEMOLER_EDIFICIO;
    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK) return st;

    unsigned int fila, columna;
    if(consultar_coordenadas(mapa, fila, columna) != ST_OK) return ST_ERROR_COORDENADAS_INVALIDAS;

    Casillero* casillero_aux = mapa->obtener_casillero(fila, columna);
    if(casillero_aux->obtener_edificio() != NULL){
        
        cout << "Demolido correctamente" << endl;

        jugador->remover_edificio(casillero_aux);
        jugador->agregar_material("metal", static_cast<unsigned int>(casillero_aux->obtener_edificio()->obtener_metal() / 2));
        jugador->agregar_material("madera", static_cast<unsigned int>(casillero_aux->obtener_edificio()->obtener_madera() / 2));
        jugador->agregar_material("piedra", static_cast<unsigned int>(casillero_aux->obtener_edificio()->obtener_piedra() / 2));
        mapa->remover_edificio(fila, columna);

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
    if(jugador->obtener_caracter() == 'J')
        jugador = jugador_dos;
    else if (jugador->obtener_caracter() == 'U')
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
            if((st = mostrar_edificios(arbol, jugador_uno, jugador_dos)) != ST_OK) imprimir_error(st);
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