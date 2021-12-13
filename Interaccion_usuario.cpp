#include "Interaccion_usuario.h"

int obtener_numero_por_consola(unsigned int valor_minimo, unsigned int valor_maximo)
{
	string opcion;
    int respuesta;
    cin >> opcion;
    while(!es_numero(opcion) || (stoi(opcion) < valor_minimo || stoi(opcion) > valor_maximo)){
        cout << MSJ_ERROR_OPCION_INVALIDA;
        cin >> opcion;
    }

    respuesta = stoi(opcion);
    return respuesta;
}

estados_t obtener_valor_cantidad(unsigned int & cantidad, unsigned int cantidad_minima, unsigned int cantidad_maxima)
{
    string valor;
    cin >> valor;

    if(!es_numero(valor)) return ST_ERROR_NO_ES_NUMERO;

    cantidad = static_cast<unsigned int>(stoul(valor));

    if(cantidad < cantidad_minima || cantidad > cantidad_maxima) return ST_ERROR_CANTIDAD_INVALIDA;

    return ST_OK;
}

bool es_numero(const string& valor)
{
    string::const_iterator it = valor.begin();

    while (it != valor.end() && isdigit(*it)) ++it;

    return !valor.empty() && it == valor.end();
}

estados_t obtener_coordenadas(Mapa* mapa, unsigned int & fila, unsigned int & columna){
    string fila_aux, columna_aux;

    cout << MSJ_INGRESAR_FILA;
    cin >> fila_aux;

    cout << MSJ_INGRESAR_COLUMNA;
    cin >> columna_aux;

    if(!es_numero(fila_aux) || !es_numero(columna_aux)) return ST_ERROR_NO_ES_NUMERO;

    fila = static_cast<unsigned int>(stoul(fila_aux));
    columna = static_cast<unsigned int>(stoul(columna_aux));

    if(mapa->obtener_cantidad_filas() < fila || mapa->obtener_cantidad_columnas() < columna) return ST_ERROR_COORDENADAS_INVALIDAS;

    return ST_OK;
}

estados_t pedido_confirmacion()
{
    char confirmar;
    cout << MSJ_CONFIRMACION;
    cin >> confirmar;
    if(confirmar == CARACTER_CONFIRMACION_MAYUS || confirmar == CARACTER_CONFIRMACION_MINUS) return ST_OK;
    return ST_MSJ_SALIR;
}

string ingresar_nombre()
{
    string nombre;
    cout << MSJ_INGRESAR_EDIFICIO;
    cin.ignore();
    getline(cin,nombre);
    cout << endl;
    return nombre;
}