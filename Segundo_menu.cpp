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

    if(verificar_materiales(jugador,edificio) != ST_OK) return st;

    // Solicito coordenadas
    unsigned int fila, columna;
    if(consultar_coordenadas(mapa, fila, columna) != ST_OK) return st;

    // Verifico en el mapa las coordenadas dadas
    //if(mapa->verificar_en_mapa(fila, columna) != ST_OK) return st;

    if(mapa->set_edificio_casillero(jugador->obtener_caracter_jugador(), fila ,columna, edificio) != ST_OK) return st;

    // Solicito confirmacion
    if(pedido_confirmacion() != ST_OK) return st;

    jugador->agregar_casillero(mapa->obtener_casillero(fila, columna));

    // Resta de los materiales

    restar_materiales(jugador, edificio);

    jugador->decrementar_energia(costo_energia);

    cout << "Construido exitosamente!" << endl;
    return st;
}

estados_t verificar_materiales(Jugador* jugador, Edificio* edificio)
{
    estados_t st = ST_OK;
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL;
    if(jugador->verificar_material_necesario(nombre_piedra, edificio->obtener_piedra() != ST_OK)) return st;
    if(jugador->verificar_material_necesario(nombre_madera, edificio->obtener_madera() != ST_OK)) return st;
    if(jugador->verificar_material_necesario(nombre_metal, edificio->obtener_metal() != ST_OK)) return st;
    return st;
}

void restar_materiales(Jugador* jugador, Edificio* edificio)
{
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL;
    jugador->restar_materiales(nombre_piedra, edificio->obtener_piedra());
    jugador->restar_materiales(nombre_madera, edificio->obtener_madera());
    jugador->restar_materiales(nombre_metal, edificio->obtener_metal());
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

/*estados_t moverse_coordenada(Jugador *jugador, Mapa *mapa)
{
    unsigned int fila, columna;
    Grafo *grafo;
    if(consultar_coordenadas(mapa, fila, columna) != ST_OK) 
        return ST_ERROR_COORDENADAS_INVALIDAS;

    Casillero *casillero_origen = mapa->obtener_casillero(jugador->obtener_x(), jugador->obtener_y());
    Casillero *casillero_destino = mapa->obtener_casillero(fila, columna);
    if(casillero_destino == NULL) 
        return ST_ERROR_COORDENADAS_INVALIDAS;

    grafo->asignar_pesos(grafo, jugador->obtener_caracter(), casillero_origen, casillero_destino);

    return ST_OK;

    
}*/


void verificar_energia_nula(Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos)
{
    if(jugador_uno->verificar_energia_nula()){
        cout << "El jugador 1 se ha quedado sin energia, se finaliza el turno" << endl;
        cambiar_jugador(jugador, jugador_uno, jugador_dos);
    }
    else if(jugador_dos->verificar_energia_nula()){
        cout << "El jugador 2 se ha quedado sin energia, se finaliza el turno" << endl;
        cambiar_jugador(jugador, jugador_uno, jugador_dos);
    }
}

void cambiar_jugador(Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos)
{   
    if(jugador->obtener_caracter() == 'J'){
        jugador = jugador_dos;        
    }
    else if (jugador->obtener_caracter() == 'U'){
        jugador = jugador_uno;
    }
}

void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *> arbol, Mapa* mapa)
{
    cargar_ubicaciones(jugador_uno, jugador_dos, arbol, mapa);
    Objetivo *objetivo;
    Jugador* jugador = inicializar_jugador(jugador_uno, jugador_dos);
    objetivo->asignar(jugador);
    mostrar_segundo_menu();
    mapa->mostrar_mapas();
	int opcion = obtener_opcion_segundo_menu();
	while(opcion != OPCION_SALIR_SEGUNDO_MENU){
		opciones_segundo_menu(opcion, jugador, objetivo, jugador_uno, jugador_dos, arbol, mapa);
		mostrar_segundo_menu();
        mapa->mostrar_mapas();
        cout << "Energia disponible: " << jugador->obtener_energia() << endl << endl;
		opcion = obtener_opcion_segundo_menu();
	}
}	

void opciones_segundo_menu(int opcion, Jugador* & jugador, Objetivo *objetivo, Jugador* jugador_uno, Jugador *jugador_dos, ABB<Edificio *> arbol, Mapa* mapa){
    estados_t st;
    switch(opcion){
        case OPCION_CONSTRUIR_EDIFICIO:
            if((st = construir_edificio(jugador_uno, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos);
            break;
        case OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS:
            if((st = mostrar_edificios(arbol, jugador_uno, jugador_dos)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos);
            break;
        case OPCION_DEMOLER_COORDENADA:
            if((st = demoler_edificio(jugador_uno, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos);
            break;
        case OPCION_ATACAR_EDIFICIO:
            //if((st = atacar_edificio(jugador_uno, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos);
            break;
        case OPCION_REPARAR_EDIFICIO:
            //Mostrar mapa
            //if((st = reparar_edificio(jugador_uno, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos);
            break;
        case OPCION_COMPRAR_BOMBAS:
            if((st = comprar_bombas(jugador)) != ST_OK){
                imprimir_error(st);
            }else{
                mostrar_compra_realizada(jugador);
            }
            verificar_energia_nula(jugador, jugador_uno, jugador_dos);
            break;
        case OPCION_CONSULTAR_COORDENADA:
            break;
        case OPCION_MOSTRAR_INVENTARIO:
            jugador->mostrar_inventario();
            break;
        case OPCION_MOSTRAR_OBJETIVOS:
            objetivo->mostrar_progreso(jugador);
            break;
        case OPCION_RECOLECTAR_RECURSOS:
            break;
        case OPCION_MOVERSE_A_COORDENADA:
            //moverse_coordenada(jugador, mapa);
            break;
        case OPCION_FINALIZAR_TURNO:
            unsigned int energia_nueva = ENERGIA_RECUPERADA_POR_TURNO;
            jugador->incrementar_energia(energia_nueva);
            cambiar_jugador(jugador, jugador_uno, jugador_dos);
            cout << " Finalizo el turno" << endl;

            ///// CONTAR OBJETIVOS CUMPLIDOS NO ESTÁ CONTANDO ///////

            if(objetivo->contar_cumplidos(jugador)>=2)
                cout << "El jugador " << jugador->obtener_caracter_jugador() << "ha cumplido los objetivos" <<endl;

            break;
    }

    //if(opcion != OPCION_FINALIZAR_TURNO) mostrar_mapa();
}