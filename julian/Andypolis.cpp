#include "Andypolis.h"
//#include <string>
#include <fstream>
//#include <ctype.h>
//#include <stdlib.h>

using namespace std;

/*
const int MAX_WOOD = 1;
const int MIN_WOOD = 0;
const int MAX_STONE = 2;
const int MIN_STONE = 1;
const int MAX_IRON = 4;
const int MIN_IRON = 2;
*/

Andypolis:: Andypolis(){
    //this->building_quantity = 0;
    //this->building_quantity_total = 0;
    //this->material_quantity = 0;
    /*this->map = new Map();

    this->processBuildingsFile();
    this->processMaterialsFile();
    this->processLocationsFile();*/

    this->procesarArchivoEdificios();

    this->edificios->imprimir_en_orden();
}

Andypolis:: procesarArchivoEdificios(){
    ifstream file(PATH_ARCHIVO_EDIFICIOS);

    string aux, nombre;
    unsigned int piedra, madera, metal, max;

    while(file >> nombre){
        file >> aux;

        // Verifico si es un número
        if(aux[0] >= (int)'0' && aux[0] <= (int)'9'){
            piedra = static_cast<unsigned int>(stoul(aux));
        }else{
            nombre += ' ' + aux;
            file >> piedra;
        }

        file >> madera >> metal >> max;
        this->edificios->add(new Edificio(nombre, piedra, madera, metal, max));
    }

    file.close();
}

Andypolis:: ~Andypolis(){
    //this->saveChanges();
}