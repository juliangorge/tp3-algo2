#ifndef Andypolis_INCLUDED
#define Andypolis_INCLUDED

#include "Map.h"
#include "Material.h"
#include "Building.h"
#include <string>

using namespace std;

class Andypolis {

    // Attributes
    private:
        Building** buildings;
        Material** materials;
        Map* map;

        int building_quantity;
        int building_quantity_total;
        int material_quantity;
    
    // Methods
    public:

        // PRE: Los parametros deben ser validos.
	    // POST: Crea un objeto Andypolis.
        Andypolis();

        // PRE:
        // POST: Destruye un objeto Andypolis.
        ~Andypolis();

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda cada linea en un objeto Location.
        void procesar_archivo_ubicaciones(string filename);

        void saveChanges(string path_locations);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda en dicho archivo todos los cambios producidos en el objeto Building,
        // Siguiendo el formato:
        // nombre_edificio piedra madera metal cantidad_construidos máxima_cantidad_permitidos.
        void saveBuildingsChanges(string filename);

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda en dicho archivo todos los cambios producidos en el objeto Material,
        // Siguiendo el formato:
        // nombre_material cantidad_material.
        void saveMaterialsChanges(string filename);

        void saveMapChanges(string filename_locations);

        int validar_linea(char *aux);


};

#endif