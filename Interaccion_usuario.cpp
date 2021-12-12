#include "Interaccion_usuario.h"

int obtener_opcion_primer_menu()
{
	string opcion;

    int respuesta;

    cout << "Ingrese el número de su acción elegida: ";
    cin >> opcion;
    bool es_opcion_valida = (opcion[PRIMER_CARACTER] >= (int)'1' && opcion[PRIMER_CARACTER] <= (int)'5' && opcion[SEGUNDO_CARACTER] == '\0');
    while(!es_opcion_valida){
        cout << MSJ_ERROR_OPCION_INVALIDA;
        cin >> opcion;
        es_opcion_valida = (opcion[PRIMER_CARACTER] >= (int)'1' && opcion[PRIMER_CARACTER] <= (int)'5' && opcion[SEGUNDO_CARACTER] == '\0') ;
    }

    respuesta = stoi(opcion);

    return respuesta;
}

int obtener_opcion_segundo_menu()
{
    string opcion;

    int respuesta;

    cout << "Ingrese el número de su acción elegida: ";
    cin >> opcion;
    bool es_opcion_valida = (opcion[PRIMER_CARACTER] >= (int)'1' && opcion[PRIMER_CARACTER] <= (int)'9' && opcion[SEGUNDO_CARACTER] == '\0') || 
                         (opcion[PRIMER_CARACTER] == (int)'1' && opcion[SEGUNDO_CARACTER] >= (int)'0' && 
                         opcion[SEGUNDO_CARACTER] <= (int)'3' && opcion[TERCER_CARACTER] == '\0');
    while(!es_opcion_valida){
        cout << MSJ_ERROR_OPCION_INVALIDA;
        cin >> opcion;
        es_opcion_valida = (opcion[PRIMER_CARACTER] >= (int)'1' && opcion[PRIMER_CARACTER] <= (int)'9' && opcion[SEGUNDO_CARACTER] == '\0') || 
                         (opcion[PRIMER_CARACTER] == (int)'1' && opcion[SEGUNDO_CARACTER] >= (int)'0' && 
                         opcion[SEGUNDO_CARACTER] <= (int)'3' && opcion[TERCER_CARACTER] == '\0');
    }

    respuesta = stoi(opcion);

    return respuesta;
}

int obtener_numero_jugador()
{
    string opcion;

    int respuesta;

    cout << "Ingrese el numero de jugador que se desea ser: ";
    cin >> opcion;
    bool es_opcion_valida = (opcion[PRIMER_CARACTER] >= (int)'1' && opcion[PRIMER_CARACTER] <= (int)'2' && opcion[SEGUNDO_CARACTER] == '\0');

    while(!es_opcion_valida){
        cout << MSJ_ERROR_OPCION_INVALIDA;
        cin >> opcion;
        es_opcion_valida = (opcion[PRIMER_CARACTER] >= (int)'1' && opcion[PRIMER_CARACTER] <= (int)'2' && opcion[SEGUNDO_CARACTER] == '\0') ;
    }

    respuesta = stoi(opcion);

    return respuesta;
}


estados_t obtener_valor_cantidad(unsigned int & cantidad)
{
    cout << "Ingrese la cantidad deseada: ";
    cin >> cantidad;

    cin.clear();
    fflush(stdin);

    if(cantidad < CANTIDAD_MINIMA_MATERIAL || cantidad > CANTIDAD_MAXIMA_MATERIAL) return ST_ERROR_CANTIDAD_INVALIDA;
    return ST_OK;
}

bool es_numero(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

estados_t obtener_coordenadas(Mapa* mapa, unsigned int & fila, unsigned int & columna){
    string fila_aux, columna_aux;

    cout << "Ingrese la fila: ";
    cin >> fila_aux;

    cout << "Ingrese la columna: ";
    cin >> columna_aux;

    if(!es_numero(fila_aux) || !es_numero(columna_aux)) return ST_ERROR_NO_ES_NUMERO;

    fila = stoi(fila_aux);
    columna = stoi(columna_aux);

    if(mapa->obtener_cantidad_filas() < fila || mapa->obtener_cantidad_columnas() < columna) return ST_ERROR_COORDENADAS_INVALIDAS;

    return ST_OK;
}

estados_t pedido_confirmacion()
{
    char confirmar;

    cout << "Escribe `Y` para confirmar: ";
    cin >> confirmar;
    
    if(confirmar == CARACTER_CONFIRMACION_MAYUS || confirmar == CARACTER_CONFIRMACION_MINUS) return ST_OK;
    return ST_MSJ_SALIR;
}

string ingresar_nombre()
{
    string nombre;
    cout << "Escribe el nombre del edificio: ";
    cin.ignore();
    getline(cin,nombre);
    cout << endl;
    return nombre;
}