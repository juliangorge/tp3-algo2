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
                         (opcion[PRIMER_CARACTER] == (int)'1' && opcion[SEGUNDO_CARACTER] >= (int)'1' && 
                         opcion[SEGUNDO_CARACTER] <= (int)'3' && opcion[TERCER_CARACTER] == '\0');

    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
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

    if(cantidad < CANTIDAD_MINIMA || cantidad > CANTIDAD_MAXIMA) return ST_ERROR_CANTIDAD_INVALIDA;
    return ST_OK;
}

bool es_numero(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

estados_t consultar_coordenadas(Mapa* mapa, unsigned int & fila, unsigned int & columna){
    string fila_aux, columna_aux;

    cout << "Ingrese la fila: ";
    cin >> fila_aux;

    cout << "Ingrese la columna: ";
    cin >> columna_aux;

    if(!es_numero(fila_aux) || !es_numero(columna_aux)) return ST_ERROR_CANTIDAD_INVALIDA;

    if(!mapa->chequear_coordenadas(stoul(fila_aux), stoul(columna_aux))) return ST_ERROR_COORDENADAS_INVALIDAS;

    fila = stoi(fila_aux);
    columna = stoi(columna_aux);

    return ST_OK;
}

estados_t pedido_confirmacion(){
    string confirm;

    cout << "Escribe `Y` para confirmar: ";
    cin >> confirm;
    
    if(confirm == "Y" || confirm == "y") return ST_OK;
    return ST_MSJ_SALIR;
}