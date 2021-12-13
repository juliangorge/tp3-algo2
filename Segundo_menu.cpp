#include "Segundo_menu.h"

estados_t construir_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa){
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_CONSTRUIR_EDIFICIO;
    unsigned int fila, columna;

    // Verifico la energia
    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK) return st;

    // Ingreso el nombre del edificio a construir
    string nombre = ingresar_nombre();

    // Verifico que exista el edificio ingresado
    if(!arbol.buscar(nombre)) return ST_ERROR_NOMBRE_INVALIDO;
    Edificio* edificio = arbol.obtener_dato(nombre);

    // Verifico máximo alcanzado de construidos
    if( !edificio->obtener_restantes(jugador->obtener_cant_edificio(edificio->obtener_nombre()))) return ST_ERROR_EDIFICIO_MAXIMO_ALCANZADO;

    // Verifico materiales necesarios
    if(((st = verificar_materiales(jugador,edificio, 1)) != ST_OK)) return st;

    // Solicito coordenadas
    if((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK) return st;

    // Verifico las condiciones en el casillero para que se pueda construir
    if((st = (mapa->verificar_condiciones_construccion(jugador->obtener_caracter(), fila ,columna))) != ST_OK) return st;

    // Solicito confirmacion
    if((st = pedido_confirmacion()) != ST_OK) return st;

    //Agregado del edificio al mapa y a la lista de edificios del jugador
    mapa->set_edificio_casillero(jugador->obtener_caracter(), fila ,columna, edificio);
    jugador->agregar_casillero(mapa->obtener_casillero(fila, columna));

    // Resta de los materiales
    restar_materiales(jugador, edificio, 1);

    // Decremento la energia del jugador
    jugador->decrementar_energia(costo_energia);
    
    cout << endl << "Construido exitosamente!" << endl;
    return st;
}

estados_t verificar_materiales(Jugador* jugador, Edificio* edificio, unsigned int factor_cont_rep)
{
    estados_t st = ST_OK;
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL;
    if(!jugador->verificar_material_necesario(nombre_piedra, edificio->obtener_piedra() / factor_cont_rep))
        st = ST_ERROR_MATERIALES_INSUFICIENTES;
    if(!jugador->verificar_material_necesario(nombre_madera, edificio->obtener_madera() / factor_cont_rep))
        st = ST_ERROR_MATERIALES_INSUFICIENTES;
    if(!jugador->verificar_material_necesario(nombre_metal, edificio->obtener_metal() / factor_cont_rep)) 
        st = ST_ERROR_MATERIALES_INSUFICIENTES;
    return st;
}

void restar_materiales(Jugador* jugador, Edificio* edificio, unsigned int factor_cont_rep)
{
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL;
    jugador->restar_materiales(nombre_piedra, edificio->obtener_piedra() / factor_cont_rep);
    jugador->restar_materiales(nombre_madera, edificio->obtener_madera() / factor_cont_rep);
    jugador->restar_materiales(nombre_metal, edificio->obtener_metal() / factor_cont_rep);
}

estados_t demoler_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa){
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_DEMOLER_EDIFICIO;
    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK) return st;

    unsigned int fila, columna;
    if((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK) return st;

    // Verifico las condiciones en el casillero para que se pueda construir
    if((st = mapa->verificar_condiciones_demolicion(jugador->obtener_caracter(), fila ,columna)) != ST_OK) return st;

    // Solicito confirmacion
    if((st = pedido_confirmacion()) != ST_OK) return st;

    agregar_materiales(jugador, mapa->obtener_casillero(fila, columna)->obtener_edificio());
    

    mapa->demoler_edificio_casillero(fila ,columna);

    jugador->borrar_edificio_casillero(mapa->obtener_casillero(fila, columna));
    
    jugador->decrementar_energia(costo_energia);

    cout << endl << "Destruido exitosamente!" << endl;

    return st;
}

void agregar_materiales(Jugador* jugador, Edificio* edificio){
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL;
    jugador->agregar_material(nombre_piedra, edificio-> obtener_piedra() / 2);
    jugador->agregar_material(nombre_madera, edificio-> obtener_madera() / 2);
    jugador->agregar_material(nombre_metal, edificio-> obtener_metal() / 2);
}


estados_t atacar_edificio(Jugador* jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa){
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_ATACAR_EDIFICIO;
    string nombre_bombas = NOMBRE_BOMBAS;
    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK) return st;

    if(!jugador->mostrar_cantidad_material(nombre_bombas)){
        st = ST_ERROR_BOMBAS_INSUFICIENTES;
        return st;
    } 
    unsigned int fila, columna;
    if((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK) return st;

    if((st = mapa->verificar_condiciones_ataque(jugador->obtener_caracter(), fila ,columna)) != ST_OK) return st;

    // Solicito confirmacion
    if((st = pedido_confirmacion()) != ST_OK) return st;

    mapa->atacar_edificio_casillero(fila,columna);
    if(!mapa->obtener_casillero(fila, columna)->obtener_edificio()){
        if(jugador->obtener_caracter() == 'J')
            jugador_dos->borrar_edificio_casillero(mapa->obtener_casillero(fila, columna));
        else
            jugador_uno->borrar_edificio_casillero(mapa->obtener_casillero(fila, columna));
    }

    jugador->restar_materiales(nombre_bombas, 1);

    jugador->decrementar_energia(costo_energia);

    cout << endl << "Ataque exitoso!" << endl;

    return st;

}

estados_t reparar_edificio(Jugador* jugador, ABB<Edificio *>& arbol, Mapa*& mapa){
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_REPARAR_EDIFICIO;
    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK) return st;

    unsigned int fila, columna;
    if((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK) return st;

    // Verifico las condiciones en el casillero para que se pueda construir
    if((st = mapa->verificar_condiciones_demolicion(jugador->obtener_caracter(), fila ,columna)) != ST_OK) return st;
    if(!mapa->obtener_casillero(fila, columna)->obtener_edificio()->obtener_fue_atacado()){
        st = ST_ERROR_NO_REQUIERE_REPARACION;
        return st;
    } 

    Edificio* edificio = arbol.obtener_dato(mapa->obtener_casillero(fila, columna)->obtener_edificio()->obtener_nombre());

    if(((st = verificar_materiales(jugador,edificio, 4)) != ST_OK)) return st;
    // Solicito confirmacion
    if((st = pedido_confirmacion()) != ST_OK) return st;

    restar_materiales(jugador, mapa->obtener_casillero(fila, columna)->obtener_edificio(), 4);

    mapa->obtener_casillero(fila,columna)->obtener_edificio()->cambio_estado_edificio();
    
    jugador->decrementar_energia(costo_energia);

    cout << endl << "Edificio reparado exitosamente!" << endl;

    return st;
}

Jugador* inicializar_jugador(Jugador* jugador_uno, Jugador* jugador_dos)
{
    Jugador* jugador;
    
    int opcion = obtener_numero_jugador();
    cout << endl << "El jugador que inicia la partida es el jugador " << opcion << endl;
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

estados_t moverse_coordenada(Jugador *jugador, Mapa *mapa)
{
    unsigned int fila=0, columna=0;
    Grafo grafo;
    //if(obtener_coordenadas(mapa, fila, columna) != ST_OK) 
    //    return ST_ERROR_COORDENADAS_INVALIDAS;

    Casillero *casillero_origen = mapa->obtener_casillero(jugador->obtener_fila(), jugador->obtener_columna());
    Casillero *casillero_destino = mapa->obtener_casillero(fila, columna);
    grafo.asignar_adyacentes(jugador->obtener_caracter(), casillero_origen, casillero_destino, mapa);
    
    //grafo->asignar_pesos(casillero_destino, casillero_origen, jugador->obtener_caracter());

    return ST_OK;
    
    
}


void verificar_energia_nula(Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol)
{
    if(jugador_uno->verificar_energia_nula()){
        cout << "El jugador 1 se ha quedado sin energia, se finaliza el turno" << endl;
        cambiar_jugador(jugador, jugador_uno, jugador_dos, arbol);
    }
    else if(jugador_dos->verificar_energia_nula()){
        cout << "El jugador 2 se ha quedado sin energia, se finaliza el turno" << endl;
        cambiar_jugador(jugador, jugador_uno, jugador_dos, arbol);
    }
}

void cambiar_jugador(Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol)
{   
    unsigned int energia_nueva = ENERGIA_RECUPERADA_POR_TURNO;
    mostrar_objetivos(jugador, arbol);
    jugador->incrementar_energia(energia_nueva);
    jugador->aumentar_acumulador_por_turno();
    if(jugador->obtener_caracter() == 'J'){
        jugador = jugador_dos;        
    }
    else if (jugador->obtener_caracter() == 'U'){
        jugador = jugador_uno;
    }
}

void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa)
{
    bool partida_nueva = verificar_existencia_archivo(ARCHIVO_UBICACIONES);

    if(partida_nueva)
        cargar_posiciones_jugadores(jugador_uno, jugador_dos, mapa);
    else
        cargar_ubicaciones(jugador_uno, jugador_dos, arbol, mapa);
    
    Jugador* jugador = inicializar_jugador(jugador_uno, jugador_dos);
    mostrar_segundo_menu();
    mapa->mostrar_mapas();
    cout << "Energia disponible: " << jugador->obtener_energia() << endl << endl;
	int opcion = obtener_opcion_segundo_menu();
	while(opcion != OPCION_SALIR_SEGUNDO_MENU){
        mapa->lluvia_recursos();
		opciones_segundo_menu(opcion, jugador, jugador_uno, jugador_dos, arbol, mapa);
		mostrar_segundo_menu();
        mapa->mostrar_mapas();
        cout << "Energia disponible: " << jugador->obtener_energia() << endl << endl;
		opcion = obtener_opcion_segundo_menu();
	}
}	

void opciones_segundo_menu(int opcion, Jugador* & jugador, Jugador* jugador_uno, Jugador *jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa){
    estados_t st;
    switch(opcion){
        case OPCION_CONSTRUIR_EDIFICIO:
            if((st = construir_edificio(jugador, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS:
            jugador->mostrar_edificios();
            break;
        case OPCION_DEMOLER_COORDENADA:
            if((st = demoler_edificio(jugador, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_ATACAR_EDIFICIO:
            if((st = atacar_edificio(jugador, jugador_uno, jugador_dos, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_REPARAR_EDIFICIO:
            if((st = reparar_edificio(jugador, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_COMPRAR_BOMBAS:
            if((st = comprar_bombas(jugador)) != ST_OK){
                imprimir_error(st);
            }else
                mostrar_compra_realizada(jugador);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_CONSULTAR_COORDENADA:
            if((st = consultar_coordenadas(mapa)) != ST_OK) imprimir_error(st);
            break;
        case OPCION_MOSTRAR_INVENTARIO:
            jugador->mostrar_inventario();
            break;
        case OPCION_MOSTRAR_OBJETIVOS:
            mostrar_objetivos(jugador, arbol);
            break;
        case OPCION_RECOLECTAR_RECURSOS:
            if((st = recolectar_recursos(jugador)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_MOVERSE_A_COORDENADA:
            moverse_coordenada(jugador, mapa);
            break;
        case OPCION_FINALIZAR_TURNO:
            cambiar_jugador(jugador, jugador_uno, jugador_dos, arbol);
            cout << "Finalizo el turno" << endl;
        case OPCION_SALIR_SEGUNDO_MENU:
            cout << "Guardando cambios" << endl;
            guardar_edificios(arbol);
            break;
    }

}

void guardar_edificios(ABB<Edificio *>& arbol){
    arbol.exportar_en_orden();
}

void mostrar_objetivos(Jugador* jugador, ABB<Edificio *>& arbol)
{
    string nombre_escuela = NOMBRE_ESCUELA;
    Edificio* edificio = arbol.obtener_dato(nombre_escuela);
    unsigned int maximo_escuelas = edificio->obtener_maximo();
    jugador->mostrar_objetivos(maximo_escuelas);
}

estados_t consultar_coordenadas(Mapa*& mapa)
{
    estados_t st = ST_OK;
    unsigned int fila, columna;
    if((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK)
        return st;
    mapa->consultar_coordenadas(fila, columna);
    return st;
}

void cargar_materiales_jugadores(Jugador* jugador_uno, Jugador* jugador_dos)
{
    ifstream archivo_materiales;
    archivo_materiales.open(ARCHIVO_MATERIALES.c_str());
    string nombre_material;
    unsigned int cantidad_jugador_uno, cantidad_jugador_dos;

    while(archivo_materiales >> nombre_material >> cantidad_jugador_uno >> cantidad_jugador_dos){
        jugador_uno->agregar_material_a_lista(new Material(nombre_material, cantidad_jugador_uno));
        jugador_dos->agregar_material_a_lista(new Material(nombre_material, cantidad_jugador_dos));
        
    }

    archivo_materiales.close();

}

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

    if((!jugador->verificar_material_necesario(nombre_andycoins, precio_bombas))){
        st = ST_ERROR_ANDYCOINS_INSUFICIENTES;
        return st;
    }

    if((st = pedido_confirmacion()) != ST_OK) return st;

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

estados_t recolectar_recursos(Jugador* jugador)
{
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_RECOLECTAR_RECURSOS;

    if((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK)
        return st;

    if(!jugador->obtener_acumulador_por_turno()){
        st = ST_ERROR_RECOLECCION_REPETIDA;
        return st;
    }

    if((st = pedido_confirmacion()) != ST_OK) return st;

    jugador-> recolectar_recursos();
    jugador-> decrementar_energia(costo_energia);

    return st;
}

bool verificar_existencia_archivo(string nombre)
{
    ifstream archivo;
    archivo.open(nombre);
    bool partida_nueva = false;
    if(!archivo)
    {
        cout << "No se pudo leer el archivo: " << nombre << endl;
        partida_nueva = true;
        archivo.open(ARCHIVO_UBICACIONES, ios::out);       

    }
    else
        if(archivo.peek()==ifstream::traits_type::eof()) //valido si esta vacio
            partida_nueva=true;
    

    archivo.close();
    return partida_nueva;
}

void cargar_posiciones_jugadores(Jugador *jugador_uno, Jugador *jugador_dos, Mapa *mapa)
{
    unsigned int fila=0, columna=0;
    estados_t st;
    cout << "Ingrese las nuevas coordenadas para el jugador 1" << endl;
    st = obtener_coordenadas(mapa, fila, columna);
    jugador_uno->agregar_coordenadas(fila, columna);
    mapa->set_jugador_casillero(jugador_uno);

    cout << "Ingrese las nuevas coordenadas para el jugador 2" << endl;
    st = obtener_coordenadas(mapa, fila, columna);
    jugador_dos->agregar_coordenadas(fila, columna);
    mapa->set_jugador_casillero(jugador_dos);

}