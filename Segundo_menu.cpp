#include "Segundo_menu.h"

void trabajar_segundo_menu(Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa)
{   
    unsigned int opcion_minima = OPCION_SEGUNDO_MENU_MINIMA, opcion_maxima = OPCION_SEGUNDO_MENU_MAXIMA;
    if(!existe_archivo_ubicaciones()){
        cargar_posiciones_jugadores(jugador_uno, jugador_dos, mapa);
        mapa->lluvia_recursos();
    }
    else
        cargar_ubicaciones(jugador_uno, jugador_dos, arbol, mapa);
    Jugador* jugador = inicializar_jugador(jugador_uno, jugador_dos);
    
    mostrar_segundo_menu();
    mapa->mostrar_mapas();
    cout << MSJ_ENERGIA_DISPONIBLE << jugador->obtener_energia() << endl << endl;
    cout << MSJ_ELEGIR_OPCION;
    unsigned int opcion = obtener_numero_por_consola(opcion_minima, opcion_maxima);
    while(opcion != OPCION_SALIR_SEGUNDO_MENU){ //&& !jugador_uno->objetivos_cumplidos() && !jugador_dos->objetivos_cumplidos()){ 
        opciones_segundo_menu(opcion, jugador, jugador_uno, jugador_dos, arbol, mapa);
        mostrar_segundo_menu();
        mapa->mostrar_mapas();
        cout << MSJ_ENERGIA_DISPONIBLE << jugador->obtener_energia() << endl << endl;
        cout << MSJ_ELEGIR_OPCION;
        opcion = obtener_numero_por_consola(opcion_minima, opcion_maxima);
    }
}   

void opciones_segundo_menu(unsigned int opcion, Jugador* & jugador, Jugador* jugador_uno, Jugador *jugador_dos, ABB<Edificio *>& arbol, Mapa*& mapa){
    estados_t st;
    switch(opcion){
        case OPCION_CONSTRUIR_EDIFICIO:
            if((st = construir_edificio(jugador, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(mapa, jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS:
            mostrar_edificios_construidos(jugador);
            break;
        case OPCION_DEMOLER_COORDENADA:
            if((st = demoler_edificio(jugador, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(mapa, jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_ATACAR_EDIFICIO:
            if((st = atacar_edificio(jugador, jugador_uno, jugador_dos, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(mapa, jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_REPARAR_EDIFICIO:
            if((st = reparar_edificio(jugador, arbol, mapa)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(mapa, jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_COMPRAR_BOMBAS:
            if((st = comprar_bombas(jugador)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(mapa, jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_CONSULTAR_COORDENADA:
            if((st = consultar_coordenadas(mapa)) != ST_OK) imprimir_error(st);
            break;
        case OPCION_MOSTRAR_INVENTARIO:
            mostrar_inventario(jugador);
            break;
        case OPCION_MOSTRAR_OBJETIVOS:
            mostrar_objetivos(jugador, arbol);
            break;
        case OPCION_RECOLECTAR_RECURSOS:
            if((st = recolectar_recursos(jugador)) != ST_OK) imprimir_error(st);
            verificar_energia_nula(mapa, jugador, jugador_uno, jugador_dos, arbol);
            break;
        case OPCION_MOVERSE_A_COORDENADA:
            moverse_coordenada(jugador, mapa);
            break;
        case OPCION_FINALIZAR_TURNO:
            cambiar_jugador(mapa, jugador, jugador_uno, jugador_dos, arbol);
            cout << MSJ_TURNO_FINALIZADO << endl;
            break;
    }

}

Jugador* inicializar_jugador(Jugador* jugador_uno, Jugador* jugador_dos)
{
    unsigned int opcion_minima = NUMERO_JUGADOR_UNO, opcion_maxima = NUMERO_JUGADOR_DOS;
    Jugador* jugador;
    cout << MSJ_INGRESAR_JUGADOR;
    unsigned int opcion = obtener_numero_por_consola(opcion_minima, opcion_maxima);
    cout << endl << MSJ_JUGADOR_INGRESADO << opcion << endl;
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

void verificar_energia_nula(Mapa* & mapa, Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol)
{
    if(jugador_uno->verificar_energia_nula()){
        cout << MSJ_JUGADOR_UNO_SIN_ENERGIA << endl;
        cambiar_jugador(mapa, jugador, jugador_uno, jugador_dos, arbol);
    }
    else if(jugador_dos->verificar_energia_nula()){
        cout << MSJ_JUGADOR_DOS_SIN_ENERGIA << endl;
        cambiar_jugador(mapa, jugador, jugador_uno, jugador_dos, arbol);
    }
}

void cambiar_jugador(Mapa* & mapa, Jugador* & jugador, Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio *>& arbol)
{   
    unsigned int energia_nueva = ENERGIA_RECUPERADA_POR_TURNO;
    mostrar_objetivos(jugador, arbol);
    jugador->objetivos_cumplidos();
    jugador->incrementar_energia(energia_nueva);
    jugador->aumentar_acumulador_por_turno();
    if(jugador->obtener_caracter() == CARACTER_JUGADOR_UNO){
        jugador = jugador_dos;        
    }
    else if (jugador->obtener_caracter() == CARACTER_JUGADOR_DOS){
        jugador = jugador_uno;
    }
    mapa->lluvia_recursos();
}

void cargar_ubicaciones (Jugador* jugador_uno, Jugador* jugador_dos, ABB<Edificio*>& arbol, Mapa*& mapa)
{
    ifstream archivo;
    archivo.open(ARCHIVO_UBICACIONES.c_str());
    unsigned int fila, columna, jugador_seleccionado;
    unsigned int elemento;
    string str_aux, nombre_aux;
    while (getline(archivo, str_aux))
    {   
        Edificio* edificio_aux;
        Material* material_aux;
        Parser parser = Parser(str_aux);
        nombre_aux = parser.nombre();
        fila = parser.coordenada_fila();
        columna = parser.coordenada_columna();
        elemento = validar_linea_ubicaciones(&nombre_aux[POSICION_PRIMER_LETRA]);    
        switch(elemento){
            case ELEMENTO_NO_JUGADOR:
                if (arbol.buscar(nombre_aux)) 
                {
                    edificio_aux = arbol.obtener_dato(nombre_aux);
                    switch(jugador_seleccionado){
                        case NUMERO_JUGADOR_UNO:
                            mapa->obtener_casillero(fila, columna)->cargar_edificio(edificio_aux, jugador_uno->obtener_caracter());
                            jugador_uno->agregar_casillero(mapa->obtener_casillero(fila, columna)); 
                            break;
                        case NUMERO_JUGADOR_DOS:
                            mapa->obtener_casillero(fila, columna)->cargar_edificio(edificio_aux, jugador_dos->obtener_caracter());
                            jugador_dos->agregar_casillero(mapa->obtener_casillero(fila, columna));
                            break;
                    }                   
                }
                else{
                    material_aux = mapa->obtener_material(nombre_aux);
                    mapa->obtener_casillero(fila, columna)->cargar_material(material_aux);
                    mapa->borrar_casillero_transitable(mapa->obtener_casillero(fila, columna));
                }
                break;

            case NUMERO_JUGADOR_UNO:
                jugador_seleccionado = NUMERO_JUGADOR_UNO;
                jugador_uno->agregar_coordenadas(fila, columna);
                mapa->obtener_casillero(fila, columna)->ocupar_casillero(jugador_uno->obtener_caracter());
                break;

            case NUMERO_JUGADOR_DOS:
                jugador_seleccionado = NUMERO_JUGADOR_DOS;
                jugador_dos->agregar_coordenadas(fila, columna);
                mapa->obtener_casillero(fila, columna)->ocupar_casillero(jugador_dos->obtener_caracter());
                break;
        }
    }

    archivo.close();

}

unsigned int validar_linea_ubicaciones(char* aux)
{
    unsigned int tipo_dato = 0;

    if(isdigit(*aux))
        tipo_dato = static_cast<unsigned int>(stoul(aux));

    return tipo_dato;
}

void cargar_posiciones_jugadores(Jugador *jugador_uno, Jugador *jugador_dos, Mapa*& mapa)
{
    unsigned int fila, columna;
    estados_t st;
    cout << "Ingrese las nuevas coordenadas para el jugador 1" << endl;
    while((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK)
        imprimir_error(st);
    jugador_uno->agregar_coordenadas(fila, columna);
    mapa->obtener_casillero(fila, columna)->ocupar_casillero(jugador_uno->obtener_caracter());
    cout << "Ingrese las nuevas coordenadas para el jugador 2" << endl;
    while((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK || (!mapa->obtener_casillero(fila,columna)->esta_libre() ? st = ST_ERROR_CASILLERO_OCUPADO : st = ST_OK))
        imprimir_error(st);
    jugador_dos->agregar_coordenadas(fila, columna);
    mapa->obtener_casillero(fila, columna)->ocupar_casillero(jugador_dos->obtener_caracter());

}

bool existe_archivo_ubicaciones()
{
    bool existe_archivo = true;
    fstream archivo(ARCHIVO_UBICACIONES, ios::in);
    if(!archivo.is_open()){
        cout << "No se encontro un archivo con nombre \"" << ARCHIVO_UBICACIONES << "\", se va a crear el archivo" << endl << endl;
        archivo.open(ARCHIVO_UBICACIONES, ios::out);
        archivo.close();
        archivo.open(ARCHIVO_UBICACIONES, ios::in);
        existe_archivo = false;
    }

    else if(archivo.peek()==ifstream::traits_type::eof()){
            existe_archivo= false;
            cout << "El archivo " << ARCHIVO_UBICACIONES << " se encuentra vacío" << endl;
        } 
            
    archivo.close();
    return existe_archivo;
}

void guardar_edificios(ABB<Edificio *>& arbol){
    ofstream archivo(ARCHIVO_EDIFICIOS);
    arbol.exportar_en_orden(archivo);
    archivo.close();
}

    