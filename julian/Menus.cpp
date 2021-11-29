#include "Menus.h"

using namespace std;

void ejecutarMenu(){
    cout << "Bienvenido!" << endl;
    mostrarOpciones();
    int respuesta = obtenerOpcion();

    while(respuesta != EXIT_OPCION){
        opcionSeleccionada(ciudad, respuesta);
        mostrarOpciones();
        respuesta = obtenerOpcion();
    }
    
    cout << "Gracias!" << endl;
}

void mostrarOpciones(){
    cout << endl; 
    cout << "1. Construir edificio por nombre." << endl;
    cout << "2. Listar los edificios construidos." << endl;
    cout << "3. Listar todos los edificios." << endl;
    cout << "4. Demoler un edificio por coordenada." << endl;
    cout << "5. Mostrar mapa." << endl;
    cout << "6. Consultar coordenada." << endl;
    cout << "7. Mostrar inventario." << endl;
    cout << "8. Recolectar recursos producidos." << endl;
    cout << "9. Lluvia de recursos." << endl;
    cout << "10. Guardar y salir. " << endl;
    cout << endl;
}

void opcionSeleccionada(Andypolis& ciudad, int respuesta){
    switch(respuesta){
        /*case 1:
            ciudad.newBuildingByName();
            break;
        case 2:
            ciudad.showBuiltBuildings();
            break;
        case 3:
            ciudad.showBuildings();
            break;
        case 4:
            ciudad.deleteBuildingByCoords();
            break;
        case 5:
            ciudad.showMap();
            break;
        case 6:
            ciudad.checkCoords();
            break;
        case 7:
            ciudad.showInventory();
            break;
        case 8:
            ciudad.colectResources();
            break;
        case 9:
            ciudad.rainResources();
            break;
        case 10:
            break;*/
    }
}

int obtenerOpcion(){
    string opcion;

    int respuesta;

    cout << "Ingrese el número de su acción elegida: ";
    cin >> opcion;

    bool isValidOpcion = (opcion[FIRST_POS] >= (int)'1' && opcion[FIRST_POS] <= (int)'9' && opcion[SECOND_POS] == '\0') || 
                         (opcion[FIRST_POS] == (int)'1' && opcion[SECOND_POS] == (int)'0' && opcion[THIRD_POS] == '\0');

    while(!isValidOpcion){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> opcion;
        isValidOpcion = (opcion[FIRST_POS] >= (int)'1' && opcion[FIRST_POS] <= (int)'9' && opcion[SECOND_POS] == '\0') || 
                         (opcion[FIRST_POS] == (int)'1' && opcion[SECOND_POS] == (int)'0' && opcion[THIRD_POS] == '\0');
    }

    respuesta = stoi(opcion);

    return respuesta;
}