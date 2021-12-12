#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Archivos a procesar
const string ARCHIVO_MAPA = "mapa.txt";
const string ARCHIVO_MATERIALES = "materiales.txt";
const string ARCHIVO_UBICACIONES = "ubicaciones.txt";
const string ARCHIVO_EDIFICIOS = "edificios.txt";

// Caracteres mostrados en el mapa

// Caracteres de casillero
const char CARACTER_CAMINO = 'C';
const char CARACTER_BETUN = 'B';
const char CARACTER_MUELLE = 'M';
const char CARACTER_LAGO = 'L';
const char CARACTER_TERRENO = 'T';

// Caracteres de materiales
const char CARACTER_MADERA = 'W';
const char CARACTER_PIEDRA = 'S';
const char CARACTER_METAL = 'I';
const char CARACTER_ANDYCOINS = 'C';
const char CARACTER_MATERIAL_OTRO = '#';

// Caracteres de edificios
const char CARACTER_MINA = 'N';
const char CARACTER_MINA_ORO = 'G';
const char CARACTER_ASERRADERO = 'A';
const char CARACTER_FABRICA = 'F';
const char CARACTER_ESCUELA = 'E';
const char CARACTER_OBELISCO = 'O';
const char CARACTER_PLANTA_ELEC = 'P';
const char CARACTER_EDIFICIO_OTRO = 'R';

// Caracteres de jugadores
const char CARACTER_JUGADOR_UNO = 'J';
const char CARACTER_JUGADOR_DOS = 'U';

// Caracteres de confirmacion
const char CARACTER_CONFIRMACION_MAYUS = 'Y';
const char CARACTER_CONFIRMACION_MINUS = 'y';

// Nombres

// Nombres de materiales
const string NOMBRE_PIEDRA = "piedra";
const string NOMBRE_MADERA = "madera";
const string NOMBRE_METAL = "metal";
const string NOMBRE_BOMBAS = "bombas";
const string NOMBRE_ANDYCOINS = "andycoins";

// Nombres de edificios
const string NOMBRE_MINA = "mina";
const string NOMBRE_MINA_ORO = "mina oro";
const string NOMBRE_ASERRADERO = "aserradero";
const string NOMBRE_FABRICA = "fabrica";
const string NOMBRE_ESCUELA = "escuela";
const string NOMBRE_OBELISCO = "obelisco";
const string NOMBRE_PLANTA_ELEC = "planta electrica";

// Letras de primer nombre
const unsigned int POSICION_PRIMER_LETRA = 0;

// Letra de primer nombre material
const char PRIMER_LETRA_MAD_MET = 'm';
const char PRIMER_LETRA_PIEDRA = 'p';
const char PRIMER_LETRA_ANDYCOINS = 'a';

// Letra de primer nombre edificio
const char PRIMER_LETRA_MINA = 'm';
const char PRIMER_LETRA_ASERRADERO = 'a';
const char PRIMER_LETRA_FABRICA = 'f';
const char PRIMER_LETRA_ESCUELA = 'e';
const char PRIMER_LETRA_OBELISCO = 'o';
const char PRIMER_LETRA_PLANTA_ELEC = 'p';

// Cantidad de materiales proveido por edificios
const unsigned int MATERIAL_PROVEIDO_MINA = 15;
const unsigned int MATERIAL_PROVEIDO_PLANTA_ELEC = 15;
const unsigned int MATERIAL_PROVEIDO_ASERRADERO = 25;
const unsigned int MATERIAL_PROVEIDO_ESCUELA = 25;
const unsigned int MATERIAL_PROVEIDO_FABRICA = 40;
const unsigned int MATERIAL_PROVEIDO_MINA_ORO = 50;

// Energia

// Costos de energia por accion
const unsigned int ENERGIA_CONSTRUIR_EDIFICIO = 15;
const unsigned int ENERGIA_DEMOLER_EDIFICIO = 15;
const unsigned int ENERGIA_ATACAR_EDIFICIO = 30;
const unsigned int ENERGIA_REPARAR_EDIFICIO = 25;
const unsigned int ENERGIA_COMPRAR_BOMBAS = 5;
const unsigned int ENERGIA_RECOLECTAR_RECURSOS = 20;

// Parametros de energia del jugador
const unsigned int ENERGIA_INICIAL = 50;
const unsigned int ENERGIA_MAXIMA = 100;
const unsigned int ENERGIA_RECUPERADA_POR_TURNO = 20;

// Opciones de menu

// Opciones de primer menu
const int OPCION_MODIFICAR_EDIFICIOS = 1;
const int OPCION_LISTAR_EDIFICIOS = 2;
const int OPCION_MOSTRAR_MAPA = 3;
const int OPCION_COMENZAR_PARTIDA = 4;
const int OPCION_SALIR_PRIMER_MENU = 5;

// Opciones de segundo menu
const int OPCION_CONSTRUIR_EDIFICIO = 1;
const int OPCION_LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int OPCION_DEMOLER_COORDENADA = 3;
const int OPCION_ATACAR_EDIFICIO = 4;
const int OPCION_REPARAR_EDIFICIO = 5;
const int OPCION_COMPRAR_BOMBAS = 6;
const int OPCION_CONSULTAR_COORDENADA = 7;
const int OPCION_MOSTRAR_INVENTARIO = 8;
const int OPCION_MOSTRAR_OBJETIVOS = 9;
const int OPCION_RECOLECTAR_RECURSOS = 10;
const int OPCION_MOVERSE_A_COORDENADA = 11;
const int OPCION_FINALIZAR_TURNO = 12;
const int OPCION_SALIR_SEGUNDO_MENU = 13;

// Opcion para elegir que jugador ser
const int OPCION_JUGADOR_UNO = 1;
const int OPCION_JUGADOR_DOS = 2;

// Parametros extra
const unsigned int ANDYCOINS_INICIALES = 0;
const unsigned int PRECIO_BOMBA = 100;

// Objetivos
const unsigned int CANTIDAD_OBJETIVOS = 3;

// Tipos de objetivos
const unsigned int COMPRAR_ANDYPOLIS=1;
const unsigned int EDAD_PIEDRA=2;
const unsigned int BOMBARDERO=3;
const unsigned int ENERGETICO=4;
const unsigned int LETRADO=5;
const unsigned int MINERO=6;
const unsigned int CANSADO=7;
const unsigned int CONSTRUCTOR=8;
const unsigned int ARMADO=9;
const unsigned int EXTREMISTA=10;

// Valores a alcanzar en objetivos
const int CANTIDAD_ANDYCOINS_OBJETIVO = 100000;
const int CANTIDAD_PIEDRA_OBJETIVO = 50000;
const int BOMBAS_USADAS_OBJETIVO = 5;
const int CANTIDAD_CANSADO_OBJETIVO = 0;
const int CANTIDAD_ARMADO_OBJETIVO = 10;
const int CANTIDAD_EXTREMISTA_OBJETIVO = 500;




const int PRIMER_CARACTER = 0;
const int SEGUNDO_CARACTER = 1;
const int TERCER_CARACTER = 2;

const unsigned int CANTIDAD_MINIMA_MATERIAL = 0;
const unsigned int CANTIDAD_MAXIMA_MATERIAL = 50000;

const unsigned int NUMERO_OPCION_PRIMER_MENU_MINIMA = 1;
const unsigned int NUMERO_OPCION_PRIMER_MENU_MAXIMA = 5;

const unsigned int NUMERO_OPCION_SEGUNDO_MENU_MINIMA = 1;
const unsigned int NUMERO_OPCION_SEGUNDO_MENU_MAXIMA = 13;

const unsigned int CANTIDAD_MINIMA_BOMBAS = 1;
const unsigned int CANTIDAD_MAXIMA_BOMBAS = 1000;


#endif //CONSTANTES_H