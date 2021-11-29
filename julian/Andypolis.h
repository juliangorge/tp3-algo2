#ifndef Andypolis_INCLUDED
#define Andypolis_INCLUDED

//#include "Map.h"

#include "ABB.h"
#include "Edificio.h"

#include <string>

using namespace std;

//const string PATH_MATERIALS = "materiales.txt";
const string PATH_ARCHIVO_EDIFICIOS = "edificios.txt";
//const string PATH_MAP = "mapa.txt";
//const string PATH_LOCATIONS = "ubicaciones.txt";



class Andypolis {

    // Attributes
    private:
        
        ABB<Edificio*>* edificios;

        /*Building** buildings;
        Material** materials;
        Map* map;

        int building_quantity;
        int building_quantity_total;
        int material_quantity;*/
    
    // Methods
    public:

        // PRE: Los parametros deben ser validos.
	    // POST: Crea un objeto Andypolis.
        Andypolis();

        // PRE:
        // POST: Destruye un objeto Andypolis.
        ~Andypolis();

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda cada linea en un objeto Edificio.
        void procesarArchivoEdificios();

        /*
        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda cada linea en un objeto Material.
        void processMaterialsFile();

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda cada linea en un objeto Location.
        void processLocationsFile();

        // PRE: Recibe un objeto Building.
        // POST: Ingresa el objeto en un array dinámico.
        void addBuilding(Building* building);

        // PRE: Recibe coordenadas y el nombre de la construccion
        // POST: Retorna su building_char
        char addBuildingFromLocations(unsigned int row_pos, unsigned int column_pos, string name);

        // PRE: Recibe un objeto Material.
        // POST: Ingresa el objeto en un array dinámico.
        void addMaterial(Material* material);

        // PRE:
        // POST: Retorna la cantidad de Edificios.
        int getBuildingQuantity();

        // PRE:
        // POST: Retorna la cantidad de Materiales.
        int getMaterialQuantity();

        // PRE:
        // POST: Imprime una lista de Edificios construidos en pantalla.
        void showBuiltBuildings();

        // PRE:
        // POST: Imprime una lista de Edificios en pantalla.
        void showBuildings();

        // PRE:
        // POST: Genera un nuevo Edificio por nombre
        void newBuildingByName();

        // PRE:
        // POST: Consulta por pantalla el nombre del Edificio y si existe retorna su posicion, de lo contrario -1.
        int checkIfBuildingExistsByName(string name);

        // PRE: Recibe una posicion valida.
        // POST: Retorna TRUE si el Edificio puede construirse en base a la cantidad de material.
        bool checkByMaterials(int pos);
    
        // PRE: Recibe una posicion valida.
        // POST: Retorna TRUE si el Edificio puede construirse en base al maximo permitido.
        bool checkByMax(int pos);

        // PRE: Recibe una posicion valida.
        // POST: Disminuye la cantidad de materiales en base a los materiales del Edificio de la posicion ingresada.
        void decreaseMaterials(int pos);

        // PRE: Recibe una posicion valida.
        // POST: Incrementa la cantidad de materiales en base a los materiales del Edificio de la posicion ingresada.
        void increaseMaterials(int pos);

        // PRE:
        // POST: Muestra el Mapa en pantalla
        void showMap();

        // PRE:
        // POST: Resuelve si las coordenadas son validas
        void checkCoords();

        // PRE:
        // POST: Imprime una lista de Materiales en pantalla.
        void showInventory();

        // PRE: Recibe nombre del material y posicion
        // POST: Incrementa la cantidad de materiales
        void recolectByMaterial(string material, int j);

        // PRE:
        // POST: Si hay un edificio construido recolecta ciertos materiales
        void colectResources();

        // PRE:
        // POST:
        void rainResources();
        
        // PRE: Recibe una posicion valida.
        // POST: Retorna un objeto Building segun su posicion.
        Building* getBuildingByPos(int pos);

        // PRE: Recibe una posicion valida.
        // POST: Retorna un objeto Material segun su posicion.
        Material* getMaterialByPos(int pos);

        void saveChanges(string path_materials, string path_locations);

        // PRE:
        // POST: Aumenta la cantidad de Edificios totales (cantidad*edificio)
        void setTotalBuilding();

        // PRE: 
        // POST: Recibe coordenadas por parametro y elimina el Edificio
        void deleteBuildingByCoords();

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda en dicho archivo todos los cambios producidos en el objeto Building,
        // Siguiendo el formato:
        // nombre_edificio piedra madera metal cantidad_construidos máxima_cantidad_permitidos.
        void deleteBuildings();

        // PRE: Recibe una ruta de archivo valida.
        // POST: Guarda en dicho archivo todos los cambios producidos en el objeto Material,
        // Siguiendo el formato:
        // nombre_material cantidad_material.
        void saveMaterialsChanges(string filename);

        // PRE: Recibe una ruta de archivo valida
        // POST: Guarda en dicho archivo todos los cambios producidos en Square Terrain
        // Siguiendo el formato:
        // nombre (coordenada_x, coordenada_y)
        void saveLocationChanges(string filename_locations);
        */
};

#endif