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
const char CARACTER_ANDYCOINS = 'Q';
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

// Nombres de los casilleros

const string NOMBRE_BETUN = "Casillero Betun transitable";
const string NOMBRE_CAMINO = "Casillero Camino transitable";
const string NOMBRE_LAGO = "Casillero Lago intransitable";
const string NOMBRE_MUELLE = "Casillero Muelle transitable";
const string NOMBRE_TERRENO = "Casillero Terreno construible";

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

// Delimitadores del archivo ubicaciones.txt
const string PRIMER_DELIMITADOR = " (";
const string SEGUNDO_DELIMITADOR = ", ";
const string TERCER_DELIMITADOR = ")";

// Factores de resta de materiales por construiccion y reparacion
const unsigned int FACTOR_CONSTRUCCION = 1;
const unsigned int FACTOR_REPARACION = 4;
const unsigned int FACTOR_DEMOLICION = 2;

// Cantidad de materiales proveido por edificios
const unsigned int MATERIAL_PROVEIDO_MINA = 15;
const unsigned int MATERIAL_PROVEIDO_PLANTA_ELEC = 15;
const unsigned int MATERIAL_PROVEIDO_ASERRADERO = 25;
const unsigned int MATERIAL_PROVEIDO_ESCUELA = 25;
const unsigned int MATERIAL_PROVEIDO_FABRICA = 40;
const unsigned int MATERIAL_PROVEIDO_MINA_ORO = 50;

// Materiales que proveen los materiales en el mapa
const unsigned int CANTIDAD_MATERIAL_MAD_MET = 50;
const unsigned int CANTIDAD_MATERIAL_PIEDRA = 100;
const unsigned int CANTIDAD_MATERIAL_ANDYCOINS = 250;
const unsigned int CANTIDAD_MATERIAL_OTRO = 0;

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

// Costos de cada casillero dependiendo del jugador

// Casillero Betun
const unsigned int ENERGIA_BETUN_JUG_UNO = 0;
const unsigned int ENERGIA_BETUN_JUG_DOS = 0;

// Casillero Camino
const unsigned int ENERGIA_CAMINO_JUG_UNO = 4;
const unsigned int ENERGIA_CAMINO_JUG_DOS = 4;

// Casillero Lago
const unsigned int ENERGIA_LAGO_JUG_UNO = 2;
const unsigned int ENERGIA_LAGO_JUG_DOS = 5;

// Casillero terreno
const unsigned int ENERGIA_MUELLE_JUG_UNO = 5;
const unsigned int ENERGIA_MUELLE_JUG_DOS = 2;

// Casillero Terreno
const unsigned int ENERGIA_TERRENO_JUG_UNO = 25;
const unsigned int ENERGIA_TERRENO_JUG_DOS = 25;

// Opciones de menu

// Lista
const int POSICION_NO_ENCONTRADA = -1;

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

// Cantidades minimas y maximas para la lluvia de materiales

// Piedra
const unsigned int MIN_LLUVIA_PIEDRA = 1;
const unsigned int MAX_LLUVIA_PIEDRA = 2;

// Madera
const unsigned int MIN_LLUVIA_MADERA = 0;
const unsigned int MAX_LLUVIA_MADERA = 3;

// Metal
const unsigned int MIN_LLUVIA_METAL = 2;
const unsigned int MAX_LLUVIA_METAL = 4;

// Andycoins
const unsigned int MIN_LLUVIA_ANDYCOINS = 0;
const unsigned int MAX_LLUVIA_ANDYCOINS = 3;

// Objetivos

// Constantes de objetivos
const unsigned int CANTIDAD_OBJETIVOS_CUMPLIDOS = 2;
const unsigned int CANTIDAD_OBJETIVOS = 3;
const unsigned int OBJETIVO_MINIMO = 1;
const unsigned int OBJETIVO_MAXIMO = 10;


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

// Posiciones de los valores enteros para verificar objetivos
const unsigned int CANTIDAD_VALORES_OBJETIVOS = 8;
const unsigned int POS_ANDYCOINS_ACUM = 0;
const unsigned int POS_BOMBAS_COMPRADAS = 1;
const unsigned int POS_BOMBAS_USADAS = 2;
const unsigned int POS_ENERGIA = 3;
const unsigned int POS_CANTIDAD_PIEDRA = 4;
const unsigned int POS_CANTIDAD_BOMBAS = 5;
const unsigned int POS_ESCUELAS_CONST = 6; 
const unsigned int POS_ESCUELAS_MAX = 7;

// Posiciones de los edificios construidos para verificar objetivos
const unsigned int CANTIDAD_TIPOS_EDIFICIOS = 7;
const unsigned int POS_MINA = 0;
const unsigned int POS_MINA_ORO = 1;
const unsigned int POS_ASERRADERO = 2;
const unsigned int POS_FABRICA = 3;
const unsigned int POS_ESCUELA = 4;
const unsigned int POS_PLANTA_ELEC = 5;
const unsigned int POS_OBELISCO = 6; 


// Valores a alcanzar en objetivos
const int CANTIDAD_ANDYCOINS_OBJETIVO = 100000;
const int CANTIDAD_PIEDRA_OBJETIVO = 50000;
const int BOMBAS_USADAS_OBJETIVO = 5;
const int CANTIDAD_CANSADO_OBJETIVO = 0;
const int CANTIDAD_ARMADO_OBJETIVO = 10;
const int CANTIDAD_EXTREMISTA_OBJETIVO = 500;

// Cotas de valores para los numeros ingresados por consola

// Cotas de cantidades para las bombas a comprar
const unsigned int CANTIDAD_MINIMA_BOMBAS = 1;
const unsigned int CANTIDAD_MAXIMA_BOMBAS = 1000;

// Cotas de cantidades requeridas de material para el edificio
const unsigned int CANTIDAD_MINIMA_MATERIAL = 0;
const unsigned int CANTIDAD_MAXIMA_MATERIAL = 50000;

// Cotas de opciones a elegir del primer menu
const unsigned int OPCION_PRIMER_MENU_MINIMA = 1;
const unsigned int OPCION_PRIMER_MENU_MAXIMA = 5;

// Cotas de opciones a elegir del segundo menu
const unsigned int OPCION_SEGUNDO_MENU_MINIMA = 1;
const unsigned int OPCION_SEGUNDO_MENU_MAXIMA = 13;

// Numero de jugador posible de seleccionar
const unsigned int ELEMENTO_NO_JUGADOR = 0;
const unsigned int NUMERO_JUGADOR_UNO = 1;
const unsigned int NUMERO_JUGADOR_DOS = 2;

// Mensajes del programa

const string MSJ_CONFIRMACION = "Escribe `Y` para confirmar: ";
const string MSJ_INGRESAR_EDIFICIO = "Escribe el nombre del edificio: ";
const string MSJ_ELEGIR_OPCION = "Ingrese la opcion deseada: ";
const string MSJ_ACTUALIZACION_EDIFICIOS = "Materiales requeridos del edificio actualizados";
const string MSJ_CANTIDAD_BOMBAS = "Ingrese la cantidad de bombas a comprar [0,1000]: ";
const string MSJ_CANTIDAD_MATERIAL_REQ = "Ingrese la cantidad de material requerido [0,50000]: ";
const string MSJ_INGRESAR_FILA = "Ingrese el número de Fila: ";
const string MSJ_INGRESAR_COLUMNA = "Ingrese el número de Columna: ";
const string MSJ_INGRESAR_JUGADOR = "Ingrese que jugador desea ser [1/2]: ";
const string MSJ_JUGADOR_INGRESADO = "El jugador que inicia la partida es el jugador ";
const string MSJ_CONSTRUICCION_EXITOSA = "Construcción del edificio realizada exitosamente";
const string MSJ_DEMOLICION_EXITOSA = "Demolición del edificio realizada exitosamente";
const string MSJ_ATAQUE_EXITOSO = "Ataque al edificio del jugador contrario exitoso";
const string MSJ_REPARACION_EXITOSA = "Reparacion del edificio exitosa";
const string MSJ_JUGADOR_UNO_SIN_ENERGIA = "El jugador 1 se ha quedado sin energia, se finaliza el turno";
const string MSJ_JUGADOR_DOS_SIN_ENERGIA = "El jugador 2 se ha quedado sin energia, se finaliza el turno";
const string MSJ_ENERGIA_DISPONIBLE = "Energia disponible: ";
const string MSJ_TURNO_FINALIZADO = " Finalizo el turno";
const string MSJ_COMPRA_BOMBAS_EXITOSA = "Se realizo la compra de bombas con exito";
const string MSJ_EDIFICIOS_CONSTRUIDOS = "Total de edificios construidos: ";
const string MSJ_MATERIALES_DISPONIBLES = "Materiales disponibles en el inventario";
const string MSJ_MOSTRAR_INVENTARIO = "Inventario del jugador: ";
const string MSJ_EDIFICIOS_CONSTRUIDOS_JUGADOR = "Edificios construidos por el jugador: ";
const string MSJ_ERROR_CASILLEROS_TRANSITABLES_OCUPADOS = "No se puede realizar mas lluvia de recursos porque no se disponen de casilleros transitables libres";

// Mensajes que muestra consultar coordenadas

const string MSJ_CASILLERO_UNO = "Soy un ";
const string MSJ_CASILLERO_VACIO = "me encuentro vacío";
const string MSJ_CASILLERO_Y = " y ";
const string MSJ_CASILLERO_CONTIENE_JUG_UNO = "contengo al jugador 1";
const string MSJ_CASILLERO_CONTIENE_JUG_DOS = "contengo al jugador 2";
const string MSJ_CASILLERO_CONTIENE_MATERIAL = "contengo al material ";
const string MSJ_CASILLERO_CONTIENE_EDIFICIO = "contengo al edificio ";
const string MSJ_CASILLERO_CONTIENE_EDIFICIO_JUG_UNO = " del jugador 1";
const string MSJ_CASILLERO_CONTIENE_EDIFICIO_JUG_DOS = " del jugador 2";

// Mensajes que muestra el mostrado de edificios

const string MSJ_COORDENADAS = "Coordenadas:";
const string MSJ_NECESITA_REPARACION = "¿Necesita reparación?:";
const string MSJ_CONFIRMA_REPARACION = "Sí";
const string MSJ_NIEGA_REPARACION = "No";

// Mensajes que muestra el mapa

const string MSJ_FILAS_MAPA = "Filas: ";
const string MSJ_COLUMNAS_MAPA = "Columnas: ";
const string MSJ_ENCABEZADOS_MAPAS = "         Mapa vacío  \t  \t  \t      Mapa de la partida";
const string MSJ_SEPARACION_ENTRE_MAPAS = "\t  \t";

// Mensaje que se muestra si no se puedo abrir el archivo

const string MSJ_ERROR_LECTURA_ARCHIVO = "No se pudo leer el archivo: ";

// Mensajes que indican que se cumplió el objetivo

const string MSJ_OBJETIVO_CUMPLIDO_COMPRAR_ANDYPOLIS = "Objetivo Comprar Andypolis cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_EDAD_PIEDRA = "Objetivo Edad de piedra cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_BOMBARDERO = "Objetivo Bombardero cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_ENERGETICO = "Objetivo Energetico cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_LETRADO = "Objetivo Letrado cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_MINERO = "Objetivo Minero cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_CANSADO = "Objetivo Cansado cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_CONSTRUCTOR = "Objetivo Constructor cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_ARMADO = "Objetivo Armado cumplido";
const string MSJ_OBJETIVO_CUMPLIDO_EXTREMISTA = "Objetivo Extremista cumplido";
const string MSJ_OBJETIVO_PRINCPIAL_CUMPLIDO = "Se tiene construido al menos un obelisco ";

// Mensajes que indican el progreso del objetivo

const char SEPARADOR_CANTIDADES = '/';
const string MSJ_OBJETIVO_PROGRESO = "Progreso del objetivo secundario ";
const string MSJ_OBJETIVO_PROGRESO_PRINCIPAL = "Progreso el objetivo principal";
const string MSJ_OBJETIVO_PROGRESO_COMPRAR_ANDYPOLIS = "Anycoins acumulados hasta el momento: ";
const string MSJ_OBJETIVO_PROGRESO_EDAD_PIEDRA = "Cantidad de Piedra contenida en el inventario: ";
const string MSJ_OBJETIVO_PROGRESO_BOMBARDERO = "Cantidad de Bombas usadas hasta el momento: ";
const string MSJ_OBJETIVO_PROGRESO_ENERGETICO = "Energía restante por almacenar ";
const string MSJ_OBJETIVO_PROGRESO_LETRADO = "Cantidad de Escuelas restantes por construir : ";
const string MSJ_OBJETIVO_PROGRESO_MINERO = "Tipos y cantidad de Minas construidas: ";
const string MSJ_OBJETIVO_PROGRESO_CANSADO = "Cantidad de energía a consumir: ";
const string MSJ_OBJETIVO_PROGRESO_CONSTRUCTOR = "Tipos de edificios construidos: ";
const string MSJ_OBJETIVO_PROGRESO_ARMADO = "Cantidad de Bombas contenida en el inventario: ";
const string MSJ_OBJETIVO_PROGRESO_EXTREMISTA = "Cantidad de Bombas compradas hasta el momento: ";
const string MSJ_OBJETIVO_PRINCPIAL_NO_CUMPLIDO = "No se construyó ningún Obelisco ";

const string MSJ_JUGADOR_UNO_GANA = "El Jugador 1 ha ganado la partida ";
const string MSJ_JUGADOR_DOS_GANA = "El Jugador 2 ha ganado la partida ";










#endif //CONSTANTES_H
