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

estados_t obtener_valor_cantidad(unsigned int & cantidad)
{
    string valor;
    cout << "Ingrese la cantidad deseada: ";
    getline(cin,valor);
    getline(cin,valor);

    cantidad = stoi(valor);

    cin.clear();
    fflush(stdin);

    if(cantidad < CANTIDAD_MINIMA || cantidad > CANTIDAD_MAXIMA)
        return ST_ERROR_CANTIDAD_INVALIDA;
    return ST_OK;
}