#include "Andypolis.h"
#include <string>
#include <fstream>
#include <ctype.h>
#include "parser.h"
#include "jugador.h"

using namespace std;

Andypolis::Andypolis()
{
    this->building_quantity = 0;
    this->building_quantity_total = 0;
    this->material_quantity = 0;
    this->map = new Map();
}

/*

// Andypolis:: Crea un Array dinámico temporal para dimensionar el actual, reemplazandolo y borrandolo.
void Andypolis::addBuilding(Building *building)
{
    int prev_building_quantity = this->building_quantity;

    Building **new_buildings = new Building *[prev_building_quantity + 1];

    for (int i = 0; i < prev_building_quantity; i++)
    {
        new_buildings[i] = this->buildings[i];
    }

    new_buildings[prev_building_quantity] = building;

    if (this->building_quantity != 0)
        delete[] this->buildings;

    this->buildings = new_buildings;
    this->building_quantity++;
}



int Andypolis::validar_linea(char *aux)
{
    int tipo_dato = 0;
    //const char *aux_char = &aux;

    if(isdigit(*aux))
    {
        tipo_dato = atoi(aux);
    }
    else
    {
        tipo_dato = 0;
    }

    return tipo_dato;
}

void Andypolis::procesar_archivo_ubicaciones(string filename)
{
    ifstream archivo_ubicaciones(filename);
    unsigned int x_aux, y_aux, row_pos, col_pos;
    int elemento = 0, jugador = 0;

    while (getline(archivo_ubicaciones, str_aux))
    {
        Parser parser = Parser(str_aux);
        nombre_aux = parser.nombre();
        x_aux = parser.coordenada_x();
        y_aux = parser.coordenada_y();
        elemento = validar_linea(&str_aux[0]); //elemento vale 0 si es material o edificio, sino vale el numero de jugador.
        cout << elemento;
        cout << " " << str_aux << endl;

        if (elemento == 0) //leo una linea que no es un jugador
        {
            if (jugador == 0) //tomo jugador 0 como los materiales
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));
            
            else if (jugador == 1) //agrego edificios del jugador 1
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));

            else if (jugador == 2) //agrego edificios del jugador 2
                this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, addBuildingFromLocations(nombre_aux));
        }
        else if (elemento == 1)
        {
            jugador = 1;
            this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, '1');
        }
        else if (elemento == 2)
        {
            jugador = 2;
            this->map->setSquareName(jugador, x_aux, y_aux, nombre_aux, '2');
        }
    }

    archivo_ubicaciones.close();
}


void Andypolis::saveChanges(string path_locations)
{
    //saveBuildingsChanges(path_buildings);
    //saveMaterialsChanges(path_materials);
    saveMapChanges(path_locations);
}

v/*oid Andypolis::saveBuildingsChanges(string filename)
{
    ofstream file(filename);

    for (int i = 0; i < this->building_quantity; i++)
    {

        setTotalBuilding(this->buildings[i]->getQuantity());

        file << this->buildings[i]->getName() << " " << this->buildings[i]->getStone() << " " << this->buildings[i]->getWood() << " " << this->buildings[i]->getIron() << " " << this->buildings[i]->getMax() << "\n";

        delete this->buildings[i];
    }

    delete[] this->buildings;
    file.close();
}
*/
/*
void Andypolis::saveMapChanges(string filename_locations)
{
    this->map->saveChanges(filename_locations, this->building_quantity_total);
}

Andypolis::~Andypolis()
{
}

*/