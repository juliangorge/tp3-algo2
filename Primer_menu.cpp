#include "Primer_menu.h"

int trabajar_primer_menu(ABB<Edificio*> &arbol, Mapa* mapa)
{
    
    mostrar_primer_menu();
    int opcion = obtener_opcion_primer_menu();
    while(opcion < OPCION_COMENZAR_PARTIDA){
        opciones_primer_menu(opcion, arbol, mapa);
        mostrar_primer_menu();
        opcion = obtener_opcion_primer_menu();
    }
    return opcion;
}

estados_t modificar_edificios(ABB<Edificio*> &arbol){
    estados_t st = ST_OK;
    string nombre;

    cout << "Escribe el nombre del edificio: ";
    cin >> nombre;
    cout << endl;

    if(!arbol.buscar(nombre)) return ST_ERROR_NOMBRE_INVALIDO;

    Edificio* edificio = arbol.obtener_dato(nombre);

    if(edificio->obtener_nombre() == "obelisco") return ST_ERROR_MODIFICANDO_OBELISCO;

    unsigned int piedra_aux, madera_aux, metal_aux;

    cout << "Piedra" << endl;
    if((st = obtener_valor_cantidad(piedra_aux)) != ST_OK) return st;

    cout << "Madera" << endl;
    if((st = obtener_valor_cantidad(madera_aux)) != ST_OK) return st;

    cout << "Metal" << endl;
    if((st = obtener_valor_cantidad(metal_aux)) != ST_OK) return st;


    edificio->actualizar_materiales(piedra_aux, madera_aux, metal_aux);
    cout << "Actualizado correctamente" << endl;

    return st;

}

void listar_edificios(ABB<Edificio*> &arbol){
    arbol.imprimir_en_orden();
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
            mapa->mostrar();
            break;
    }
}