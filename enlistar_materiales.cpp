#include <iostream>
#include <fstream>
#include <string>

#include "enlistar_materiales.h"

using namespace std;

void verificar_existencia_archivo_materiales()
{
    fstream archivo_materiales(NOMBRE_ARCHIVO_MATERIALES, ios::in);

	if (!archivo_materiales.is_open())
	{
		cout << "No se encontro un archivo con nombre \"" << NOMBRE_ARCHIVO_MATERIALES << "\", se va a crear el archivo" << endl;
		archivo_materiales.open(NOMBRE_ARCHIVO_MATERIALES, ios::out);

		archivo_materiales.close();
		archivo_materiales.open(NOMBRE_ARCHIVO_MATERIALES, ios::in);

		archivo_materiales.close();
	}
}

void enlistar_materiales(Material *** lista_jugador_1, unsigned * cantidad_jugador_1, Material *** lista_jugador_2, unsigned * cantidad_jugador_2)
{
    string nombre_material;
    string string_aux_cantidad_material_jugador_1;
    string string_aux_cantidad_material_jugador_2; 
    unsigned cantidad_material_jugador_1 = 0;
    unsigned cantidad_material_jugador_2 = 0;

    fstream archivo_materiales(NOMBRE_ARCHIVO_MATERIALES, ios::in);

    while (archivo_materiales >> nombre_material)
    {
        archivo_materiales >> string_aux_cantidad_material_jugador_1;
        archivo_materiales >> string_aux_cantidad_material_jugador_2;

        cantidad_material_jugador_1 = stoi(string_aux_cantidad_material_jugador_1);
        cantidad_material_jugador_2 = stoi(string_aux_cantidad_material_jugador_2);

        agregar_material(nombre_material, cantidad_material_jugador_1, lista_jugador_1, cantidad_jugador_1);
        agregar_material(nombre_material, cantidad_material_jugador_2, lista_jugador_2, cantidad_jugador_2);
        
    }

}

void agregar_material(string nombre_material, unsigned cantidad_material, Material *** lista, unsigned * largo_lista)
{
     if(!agregar_material_existente(nombre_material, cantidad_material, lista, *largo_lista))
            agregar_material_inexistente(nombre_material, cantidad_material, lista, largo_lista);
}

void agregar_material_inexistente(string nombre_material, unsigned cantidad_material, Material *** lista, unsigned * largo_lista)
{
    (*largo_lista)++;

    Material ** lista_mats_nueva = new Material * [(*largo_lista)];

    for(unsigned j = 0 ; j < ((*largo_lista)-1) ; j++)
    {
        lista_mats_nueva[j] = (*lista)[j];
    }

    eliminar_lista(lista, *largo_lista);
    lista_mats_nueva[((*largo_lista))-1]= new Material(nombre_material, cantidad_material);

    (*lista) = lista_mats_nueva;

}

bool agregar_material_existente(string nombre_material, unsigned cantidad_material, Material *** lista, unsigned  largo_lista)
{
    unsigned int i = 0;
    bool material_existente=false;

    while(i < largo_lista )
    {
        if((*lista)[i]->obtener_nombre() == nombre_material)
        {
            (*lista)[i]->sumar_materiales(cantidad_material);
            material_existente = true;
            break;
        }
        
        i++;
    }

    return material_existente;
}

bool decrementar_material(string nombre_material, unsigned cantidad_material, Material *** lista, unsigned largo_lista)
{
    unsigned int i = 0;
    bool material_existente=false;

    while(i < largo_lista )
    {
        if((*lista)[i]->obtener_nombre() == nombre_material)
        {
            if((*lista)[i]->obtener_cantidad()>=cantidad_material)
            {
                (*lista)[i]->restar_materiales(cantidad_material);
                material_existente = true;
            }
            
            break;
        }
        
        i++;
    }

    return material_existente;
}

void eliminar_lista(Material *** lista, unsigned largo)
{
    // for(unsigned j = 0 ; j < largo ; j++)
    // {
    //     delete *(lista[j]);
    // }
    // acá me caigo a pedazos
    
}

void imprimir_lista_materiales(Material ** lista_jugador_1, unsigned cantidad_jugador_1, Material ** lista_jugador_2, unsigned cantidad_jugador_2)
{
    cout << "------  Jugador 1 - Lista de materiales   ------" << endl;


    for(unsigned int i = 0 ; i < cantidad_jugador_1 ; i++)
    {
        cout << "\t" << lista_jugador_1[i]->obtener_cantidad() << "\t ------> \t" << lista_jugador_1[i]->obtener_nombre() <<  endl;
    }
    cout << "-----------------------------------------------";
    cout << endl;
    cout << endl;
    cout << "------  Jugador 2 - Lista de materiales  ------" << endl;

     for(unsigned int i = 0 ; i < cantidad_jugador_2 ; i++)
    {
        cout << "\t" << lista_jugador_2[i]->obtener_cantidad() << "\t ------> \t" << lista_jugador_2[i]->obtener_nombre() <<  endl;
    }
    cout << "-----------------------------------------------";
    cout << endl;
}

unsigned obtener_cantidad_material(string nombre_material, Material ** lista, unsigned cantidad_items)
{
    unsigned int cantidad=0;
    unsigned int i=0;

    while (i < cantidad_items)
    {
        if(lista[i]->obtener_nombre() == nombre_material)
        {
            cantidad = lista[i]->obtener_cantidad();
            break;
        }

        i++;   
    }

    return cantidad;
}


void guardar_archivo_materiales(Material ** lista_jugador_1, unsigned cantidad_jugador_1, Material ** lista_jugador_2, unsigned cantidad_jugador_2)
{
    ofstream archivo_materiales(NOMBRE_ARCHIVO_MATERIALES);

    if(cantidad_jugador_2 > cantidad_jugador_1)
    {
        for(unsigned i = 0 ; i < cantidad_jugador_2 ; i++)
        {
            archivo_materiales << lista_jugador_2[i]->obtener_nombre();
            archivo_materiales << ' ';
            archivo_materiales << lista_jugador_2[i]->obtener_cantidad();
            archivo_materiales << ' ';
            archivo_materiales << obtener_cantidad_material(lista_jugador_2[i]->obtener_nombre(),lista_jugador_1,cantidad_jugador_1);
            archivo_materiales << '\n';
        }
    }
    else
    {
        for(unsigned i = 0 ; i < cantidad_jugador_1 ; i++)
        {
            archivo_materiales << lista_jugador_1[i]->obtener_nombre();
            archivo_materiales << ' ';
            archivo_materiales << lista_jugador_1[i]->obtener_cantidad();
            archivo_materiales << ' ';
            archivo_materiales << obtener_cantidad_material(lista_jugador_1[i]->obtener_nombre(),lista_jugador_2,cantidad_jugador_2);
            archivo_materiales << '\n';
        }
    }
    
    

    archivo_materiales.close();
}

