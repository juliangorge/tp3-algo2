#include "Primer_menu.h"

int trabajar_primer_menu(ABB<Edificio*> &arbol, Mapa* mapa)
{
    unsigned int opcion_minima = OPCION_PRIMER_MENU_MINIMA, opcion_maxima = OPCION_PRIMER_MENU_MAXIMA;
    mostrar_primer_menu();
    cout << MSJ_ELEGIR_OPCION;
    int opcion = obtener_numero_por_consola(opcion_minima, opcion_maxima);
    while(opcion < OPCION_COMENZAR_PARTIDA){
        opciones_primer_menu(opcion, arbol, mapa);
        mostrar_primer_menu();
        cout << MSJ_ELEGIR_OPCION;
        opcion = obtener_numero_por_consola(opcion_minima, opcion_maxima);
    }
    return opcion;
}

void opciones_primer_menu(int opcion, ABB<Edificio*> &arbol, Mapa *mapa){
    estados_t st;

    switch(opcion){
        case OPCION_MODIFICAR_EDIFICIOS:
            if((st = modificar_edificios(arbol)) != ST_OK) imprimir_error(st);
            break;
        case OPCION_LISTAR_EDIFICIOS:
            listar_edificios(arbol);
            break;
        case OPCION_MOSTRAR_MAPA:
            mapa->mostrar_mapa_vacio();
            break;
    }
}

estados_t modificar_edificios(ABB<Edificio*> &arbol){
    estados_t st = ST_OK;
    string nombre = ingresar_nombre();
    unsigned int cantidad_minima = CANTIDAD_MINIMA_MATERIAL, cantidad_maxima = CANTIDAD_MAXIMA_MATERIAL;

    if(!arbol.buscar(nombre)) return ST_ERROR_NOMBRE_INVALIDO;

    Edificio* edificio = arbol.obtener_dato(nombre);

    if(edificio->obtener_nombre() == NOMBRE_OBELISCO) return ST_ERROR_MODIFICANDO_OBELISCO;

    unsigned int piedra_aux, madera_aux, metal_aux;

    cout << NOMBRE_PIEDRA << endl;
    cout << MSJ_CANTIDAD_MATERIAL_REQ;
    if((st = obtener_valor_cantidad(piedra_aux, cantidad_minima, cantidad_maxima)) != ST_OK) return st;

    cout << NOMBRE_MADERA << endl;
    cout << MSJ_CANTIDAD_MATERIAL_REQ;
    if((st = obtener_valor_cantidad(madera_aux, cantidad_minima, cantidad_maxima)) != ST_OK) return st;

    cout << NOMBRE_METAL << endl;
    cout << MSJ_CANTIDAD_MATERIAL_REQ;
    if((st = obtener_valor_cantidad(metal_aux, cantidad_minima, cantidad_maxima)) != ST_OK) return st;


    edificio->actualizar_materiales(piedra_aux, madera_aux, metal_aux);
    cout << MSJ_ACTUALIZACION_EDIFICIOS << endl;

    return st;

}

void listar_edificios(ABB<Edificio*> &arbol){
    arbol.imprimir_en_orden();
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

    string nombre = NOMBRE_ANDYCOINS;
    jugador_uno->agregar_andycoins_acumuladas(jugador_uno->mostrar_cantidad_material(nombre));
    jugador_dos->agregar_andycoins_acumuladas(jugador_dos->mostrar_cantidad_material(nombre));
}