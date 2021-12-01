#include <iostream>
#include <fstream>
#include <string>

#include "jugador.h"

Jugador:: Jugador(char caracter_jugador){
    this->energia = ENERGIA_INICIAL;
    this->caracter_jugador = caracter_jugador;
    this->tipos_de_materiales = 0;
}

Jugador:: ~Jugador(){

}


void cargar_materiales_jugadores(Jugador* jugador_uno, Jugador* jugador_dos)
{
    ifstream archivo_materiales;
    archivo_materiales.open(ARCHIVO_MATERIALES.c_str());
    string nombre_material;
    unsigned int cantidad_jugador_uno, cantidad_jugador_dos;

    while(archivo_materiales >> nombre_material >> cantidad_jugador_uno >> cantidad_jugador_dos){
		jugador_uno->agregar_material(new Material(nombre_material, cantidad_jugador_uno));
		jugador_dos->agregar_material(new Material(nombre_material, cantidad_jugador_dos));
        
    }

    archivo_materiales.close();

}

void Jugador::agregar_material(Material* material){
    int tipos_de_materiales_previo = this->tipos_de_materiales;
    Material** materiales_aux = new Material*[tipos_de_materiales_previo + 1];
    for (int i = 0; i < tipos_de_materiales_previo; i++){
        materiales_aux[i] = this->materiales_jugador[i];
    }

    materiales_aux[tipos_de_materiales_previo] = material;

    if(this->tipos_de_materiales != 0){
        delete[] this->materiales_jugador;
    }

    this->materiales_jugador = materiales_aux;
    this->tipos_de_materiales++;
}


void Jugador::mostrar_inventario()
{
    cout << endl << "======================" << endl << endl;
    cout << "Materiales para construir " << endl;
    for(unsigned int i = 0; i < this->tipos_de_materiales; i++){
        cout << "# " << this->materiales_jugador[i]->obtener_nombre() << " - " << this->materiales_jugador[i]->obtener_cantidad() << endl;
    }
    cout << endl << "======================" << endl << endl;
}