#include "Edificio.h"

Edificio::Edificio(string nombre, unsigned int piedra, unsigned int madera, unsigned int metal, unsigned int maximo)
{
    this->nombre = nombre;
    this->piedra = piedra;
    this->madera = madera;
    this->metal = metal;
    this->cantidad = 0;

    // separar cantidad para cada jugador

    this->maximo = maximo;
    this->caracter = 'B';
    this->provee_materiales = true;

    //this->getCaracter();
}

string Edificio::obtener_nombre(){
    return this->nombre;
}

unsigned int Edificio::obtener_piedra(){
    return this->piedra;
}

unsigned int Edificio::obtener_madera(){
    return this->madera;
}

unsigned int Edificio::obtener_metal(){
    return this->metal;
}

unsigned int Edificio::obtener_cantidad(){
    return this->cantidad;
}

unsigned int Edificio::obtener_restantes(){
    return (this->maximo - this->cantidad);
}

char Edificio:: obtener_caracter(){
    return this->caracter;
}

string Edificio:: obtener_provee_materiales(){
    if(this->provee_materiales) return "Si";
    return "No";

}

void Edificio:: actualizar_materiales(unsigned int piedra, unsigned int madera, unsigned int metal){
    this->piedra = piedra;
    this->madera = madera;
    this->metal = metal;
}

ostream& operator<<(ostream& salida, Edificio& edificio)
{
    /*
    Se deberán listar todos los edificios indicando para cada uno de ellos: cuantas unidades de cada
    material se requieren para construir uno, cuantos fueron construidos hasta el momento, cuantos más
    puedo construir3, sin superar el máximo permitido y si me brinda algún tipo de material4.
    */
    salida << endl << "Edificio: " << edificio.obtener_nombre() << endl;
    salida << "Construidos: " << edificio.obtener_cantidad() << " (" << edificio.obtener_restantes() << " restantes para construir)" << endl;
    salida << "Materiales: " << endl;
    salida << "# Piedra: " << edificio.obtener_piedra() << endl;
    salida << "# Madera: " << edificio.obtener_madera() << endl;
    salida << "# Metal: " << edificio.obtener_metal() << endl;
    salida << "Brinda materiales: " << edificio.obtener_provee_materiales() << endl;
    salida << endl;

    return salida;
}