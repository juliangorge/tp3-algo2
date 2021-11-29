#include "Andypolis.h"
//#include <string>
//#include <fstream>
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
    this->map = new Map();

    this->processBuildingsFile();
    this->processMaterialsFile();
    this->processLocationsFile();
}

Andypolis:: ~Andypolis(){
    this->saveChanges();
}