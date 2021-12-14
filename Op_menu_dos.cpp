#include "Op_menu_dos.h"

estados_t construir_edificio(Jugador *jugador, ABB<Edificio *> &arbol, Mapa *&mapa)
{
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_CONSTRUIR_EDIFICIO, fila, columna, resta_material = FACTOR_CONSTRUCCION;

    if ((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK)
        return st;

    string nombre = ingresar_nombre();

    if (!arbol.buscar(nombre))
    {
        st = ST_ERROR_NOMBRE_INVALIDO;
        return st;
    }
    Edificio *edificio = arbol.obtener_dato(nombre);

    if (!edificio->obtener_restantes(jugador->obtener_cant_edificio(edificio->obtener_nombre())))
    {
        st = ST_ERROR_EDIFICIO_MAXIMO_ALCANZADO;
        return st;
    }
    if (((st = verificar_materiales(jugador, edificio, resta_material)) != ST_OK))
        return st;

    if ((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK)
        return st;

    if ((st = mapa->obtener_casillero(fila, columna)->verificar_condiciones_construccion(jugador->obtener_caracter())) != ST_OK)
        return st;

    if ((st = pedido_confirmacion()) != ST_OK)
        return st;

    mapa->obtener_casillero(fila, columna)->cargar_edificio(edificio, jugador->obtener_caracter());
    jugador->agregar_casillero(mapa->obtener_casillero(fila, columna));
    restar_materiales(jugador, edificio, resta_material);
    jugador->decrementar_energia(costo_energia);
    cout << endl
         << MSJ_CONSTRUICCION_EXITOSA << endl;
    return st;
}

void mostrar_edificios_construidos(Jugador *jugador)
{
    cout << endl
         << MSJ_EDIFICIOS_CONSTRUIDOS_JUGADOR << endl;
    jugador->mostrar_edificios();
}

estados_t demoler_edificio(Jugador *jugador, ABB<Edificio *> &arbol, Mapa *&mapa)
{
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_DEMOLER_EDIFICIO, fila, columna;

    if ((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK)
        return st;

    if ((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK)
        return st;

    if ((st = mapa->obtener_casillero(fila, columna)->verificar_condiciones_demolicion(jugador->obtener_caracter())) != ST_OK)
        return st;

    if ((st = pedido_confirmacion()) != ST_OK)
        return st;

    agregar_materiales(jugador, mapa->obtener_casillero(fila, columna)->obtener_edificio());
    mapa->obtener_casillero(fila, columna)->limpiar_casillero();
    jugador->borrar_edificio_casillero(mapa->obtener_casillero(fila, columna));
    jugador->decrementar_energia(costo_energia);
    cout << endl
         << MSJ_DEMOLICION_EXITOSA << endl;
    return st;
}

estados_t atacar_edificio(Jugador *jugador, Jugador *jugador_uno, Jugador *jugador_dos, ABB<Edificio *> &arbol, Mapa *&mapa)
{
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_ATACAR_EDIFICIO, fila, columna;
    string nombre_bombas = NOMBRE_BOMBAS;
    if ((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK)
        return st;

    if (!jugador->mostrar_cantidad_material(nombre_bombas))
    {
        st = ST_ERROR_BOMBAS_INSUFICIENTES;
        return st;
    }
    if ((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK)
        return st;

    if ((st = mapa->obtener_casillero(fila, columna)->verificar_condiciones_ataque(jugador->obtener_caracter())) != ST_OK)
        return st;

    if ((st = pedido_confirmacion()) != ST_OK)
        return st;

    mapa->obtener_casillero(fila, columna)->atacar_edificio();

    if (!mapa->obtener_casillero(fila, columna)->obtener_edificio())
    {
        if (jugador->obtener_caracter() == CARACTER_JUGADOR_UNO)
            jugador_dos->borrar_edificio_casillero(mapa->obtener_casillero(fila, columna));
        else
            jugador_uno->borrar_edificio_casillero(mapa->obtener_casillero(fila, columna));
    }

    jugador->restar_materiales(nombre_bombas, 1);
    jugador->decrementar_energia(costo_energia);
    cout << endl
         << MSJ_ATAQUE_EXITOSO << endl;
    return st;
}

estados_t reparar_edificio(Jugador *jugador, ABB<Edificio *> &arbol, Mapa *&mapa)
{
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_REPARAR_EDIFICIO;
    unsigned int resta_material = FACTOR_REPARACION;
    if ((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK)
        return st;

    unsigned int fila, columna;
    if ((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK)
        return st;

    if ((st = mapa->obtener_casillero(fila, columna)->verificar_condiciones_demolicion(jugador->obtener_caracter())) != ST_OK)
        return st;

    if (!mapa->obtener_casillero(fila, columna)->obtener_edificio()->obtener_fue_atacado())
    {
        st = ST_ERROR_NO_REQUIERE_REPARACION;
        return st;
    }

    Edificio *edificio = arbol.obtener_dato(mapa->obtener_casillero(fila, columna)->obtener_edificio()->obtener_nombre());

    if (((st = verificar_materiales(jugador, edificio, resta_material)) != ST_OK))
        return st;

    if ((st = pedido_confirmacion()) != ST_OK)
        return st;

    restar_materiales(jugador, mapa->obtener_casillero(fila, columna)->obtener_edificio(), resta_material);
    mapa->obtener_casillero(fila, columna)->obtener_edificio()->cambio_estado_edificio();
    jugador->decrementar_energia(costo_energia);
    cout << endl
         << MSJ_REPARACION_EXITOSA << endl;
    return st;
}

estados_t comprar_bombas(Jugador *jugador)
{
    estados_t st = ST_OK;
    string nombre_andycoins = NOMBRE_ANDYCOINS, nombre_bombas = NOMBRE_BOMBAS;
    unsigned int costo_energia = ENERGIA_COMPRAR_BOMBAS, bombas,
                 cantidad_minima = CANTIDAD_MINIMA_BOMBAS, cantidad_maxima = CANTIDAD_MAXIMA_BOMBAS;

    if ((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK)
        return st;

    cout << MSJ_CANTIDAD_BOMBAS;

    if ((st = obtener_valor_cantidad(bombas, cantidad_minima, cantidad_maxima)) != ST_OK)
        return st;

    unsigned int precio_bombas = PRECIO_BOMBA * bombas;

    if ((!jugador->verificar_material_necesario(nombre_andycoins, precio_bombas)))
    {
        st = ST_ERROR_ANDYCOINS_INSUFICIENTES;
        return st;
    }

    if ((st = pedido_confirmacion()) != ST_OK)
        return st;

    jugador->comprar_bombas(bombas, precio_bombas);
    jugador->decrementar_energia(costo_energia);
    cout << endl
         << MSJ_COMPRA_BOMBAS_EXITOSA << endl
         << endl;
    cout << MSJ_MATERIALES_DISPONIBLES << endl;
    cout << NOMBRE_ANDYCOINS << ": " << jugador->mostrar_cantidad_material(nombre_andycoins) << endl;
    cout << NOMBRE_BOMBAS << ": " << jugador->mostrar_cantidad_material(nombre_bombas) << endl;
    return st;
}

estados_t consultar_coordenadas(Mapa *&mapa)
{
    estados_t st = ST_OK;
    unsigned int fila, columna;
    if ((st = obtener_coordenadas(mapa, fila, columna)) != ST_OK)
        return st;
    mapa->obtener_casillero(fila, columna)->mostrar_casillero();
    return st;
}

void mostrar_inventario(Jugador *jugador)
{
    cout << endl
         << MSJ_MOSTRAR_INVENTARIO << endl;
    jugador->mostrar_inventario();
}

void mostrar_objetivos(Jugador *jugador, ABB<Edificio *> &arbol)
{
    string nombre_escuela = NOMBRE_ESCUELA;
    Edificio *edificio = arbol.obtener_dato(nombre_escuela);
    unsigned int maximo_escuelas = edificio->obtener_maximo();
    jugador->mostrar_objetivos(maximo_escuelas);
}

estados_t recolectar_recursos(Jugador *jugador)
{
    estados_t st = ST_OK;
    unsigned int costo_energia = ENERGIA_RECOLECTAR_RECURSOS;

    if ((st = jugador->verificar_energia_suficiente(costo_energia)) != ST_OK)
        return st;

    if (!jugador->obtener_acumulador_por_turno()){
        st = ST_ERROR_RECOLECCION_REPETIDA;
        return st;
    }

    if (!jugador->obtener_cantidad_casilleros_edificios()){
        st = ST_ERROR_NO_HAY_CONSTRUCCIONES;
        return st;
    }

    if ((st = pedido_confirmacion()) != ST_OK)
        return st;

    jugador->recolectar_recursos();
    jugador->decrementar_energia(costo_energia);
    return st;
}

estados_t moverse_coordenada(Jugador *jugador, Mapa *&mapa)
{
    unsigned int fila = 0, columna = 0;
    estados_t st = ST_OK;
    Grafo grafo;
    bool energia_suficiente=true;
    Casillero *destino, *origen;

    while (st != ST_OK && st!=ST_ERROR_ENERGIA_INSUFICIENTE)
    {
        if (obtener_coordenadas(mapa, fila, columna) != ST_OK)
            st = ST_ERROR_COORDENADAS_INVALIDAS;
    
        else
        {
            origen = mapa->obtener_casillero(jugador->obtener_fila(), jugador->obtener_columna());
            destino = mapa->obtener_casillero(fila, columna);
            if (destino->no_tiene_jugador() && destino->obtener_edificio() == nullptr)
                st = grafo.usar_grafo(origen, destino, mapa, jugador);

            else
            {
                cout << "Casillero destino ocupado, intente nuevamente" << endl << endl;
                st = ST_ERROR_CASILLERO_OCUPADO;
            }
        }
    }
    if(st==ST_OK)
    {

        grafo.recorrer_casilleros_paso(mapa, origen, destino, jugador);
        jugador->set_posicion(destino->obtener_fila(), destino->obtener_columna());
        destino->ocupar_casillero(jugador->obtener_caracter());
        origen->limpiar_casillero();
    }


    return st;
}

estados_t verificar_materiales(Jugador *jugador, Edificio *edificio, unsigned int factor_resta)
{
    estados_t st = ST_OK;
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL;

    if (!jugador->verificar_material_necesario(nombre_piedra, edificio->obtener_piedra() / factor_resta))
        st = ST_ERROR_MATERIALES_INSUFICIENTES;

    if (!jugador->verificar_material_necesario(nombre_madera, edificio->obtener_madera() / factor_resta))
        st = ST_ERROR_MATERIALES_INSUFICIENTES;

    if (!jugador->verificar_material_necesario(nombre_metal, edificio->obtener_metal() / factor_resta))
        st = ST_ERROR_MATERIALES_INSUFICIENTES;

    return st;
}

void agregar_materiales(Jugador *jugador, Edificio *edificio)
{
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL;
    jugador->agregar_material(nombre_piedra, edificio->obtener_piedra() / FACTOR_DEMOLICION);
    jugador->agregar_material(nombre_madera, edificio->obtener_madera() / FACTOR_DEMOLICION);
    jugador->agregar_material(nombre_metal, edificio->obtener_metal() / FACTOR_DEMOLICION);
}

void restar_materiales(Jugador *jugador, Edificio *edificio, unsigned int factor_resta)
{
    string nombre_piedra = NOMBRE_PIEDRA, nombre_madera = NOMBRE_MADERA, nombre_metal = NOMBRE_METAL;
    jugador->restar_materiales(nombre_piedra, edificio->obtener_piedra() / factor_resta);
    jugador->restar_materiales(nombre_madera, edificio->obtener_madera() / factor_resta);
    jugador->restar_materiales(nombre_metal, edificio->obtener_metal() / factor_resta);
}
