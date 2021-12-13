#include "Edificio.h"

Edificio::Edificio(string nombre, unsigned int piedra, unsigned int madera, unsigned int metal, unsigned int maximo)
{
    this->nombre = nombre;
    this->piedra = piedra;
    this->madera = madera;
    this->metal = metal;
    this->maximo = maximo;
    this->fue_atacado = false;
    this->establecer_parametros();
}

Edificio:: ~Edificio(){
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

unsigned int Edificio::obtener_maximo(){
    return this->maximo;
}

unsigned int Edificio::obtener_restantes(unsigned int cantidad_construida){
    return (this->maximo - cantidad_construida);
}

void Edificio:: establecer_parametros(){
    switch(this->nombre[POSICION_PRIMER_LETRA]){
        case PRIMER_LETRA_MINA:
            if(nombre == NOMBRE_MINA){
                this->caracter = CARACTER_MINA;
                this->provee_materiales = true;
                this->materiales_proveidos = MATERIAL_PROVEIDO_MINA;
                this->contiene_escudo = true;
                this->fue_atacado = false;
            }
            else{
                this->caracter = CARACTER_MINA_ORO;
                this->provee_materiales = true;
                this->materiales_proveidos = MATERIAL_PROVEIDO_MINA_ORO;
                this->contiene_escudo = true;
                this->fue_atacado = false;
            }
            break;
        case PRIMER_LETRA_ASERRADERO:
            this->caracter = CARACTER_ASERRADERO;
            this->provee_materiales = true;
            this->materiales_proveidos = MATERIAL_PROVEIDO_ASERRADERO;
            this->contiene_escudo = false;
            break;
        case PRIMER_LETRA_FABRICA:
            this->caracter = CARACTER_FABRICA;
            this->provee_materiales = true;
            this->materiales_proveidos = MATERIAL_PROVEIDO_FABRICA;
            this->contiene_escudo = true;
            this->fue_atacado = false;
            break;
        case PRIMER_LETRA_ESCUELA:
            this->caracter = CARACTER_ESCUELA;
            this->provee_materiales = true;
            this->materiales_proveidos = MATERIAL_PROVEIDO_ESCUELA;
            this->contiene_escudo = false;
            break;
        case PRIMER_LETRA_OBELISCO:
            this->caracter = CARACTER_OBELISCO;
            this->provee_materiales = false;
            this->contiene_escudo = false;
            break;
        case PRIMER_LETRA_PLANTA_ELEC:
            this->caracter = CARACTER_PLANTA_ELEC;
            this->provee_materiales = true;
            this->materiales_proveidos = MATERIAL_PROVEIDO_PLANTA_ELEC;
            this->contiene_escudo = false;
            break;
        default: 
            this->caracter = CARACTER_EDIFICIO_OTRO;
            this->provee_materiales = false;
            this->contiene_escudo = false;
            break;
    }
}

char Edificio:: obtener_caracter(){
    return this->caracter;
}

bool Edificio:: obtener_provee_materiales(){
    return this->provee_materiales;
}

unsigned int Edificio:: obtener_materiales_proveidos()
{
    return this->materiales_proveidos;
}

bool Edificio::obtener_contiene_escudo()
{
    return this->contiene_escudo;
}

bool Edificio::obtener_fue_atacado()
{
    return this->fue_atacado;
}

void Edificio::cambio_estado_edificio()
{
    if(!this->fue_atacado)
        this->fue_atacado = true;
    else
        this->fue_atacado = false;
}

void Edificio:: actualizar_materiales(unsigned int piedra, unsigned int madera, unsigned int metal){
    this->piedra = piedra;
    this->madera = madera;
    this->metal = metal;
}

ostream& operator>>(ostream& salida, Edificio& edificio)
{
    salida << edificio.obtener_nombre() << " " << edificio.obtener_piedra();
    return salida;
}

ostream& operator<<(ostream& salida, Edificio& edificio)
{
    salida << endl << "Edificio: " << edificio.obtener_nombre() << endl;
    salida << "Cantidad maxima posible: " << edificio.obtener_maximo() << endl;
    salida << "Materiales: " << endl;
    salida << "# Piedra: " << edificio.obtener_piedra() << endl;
    salida << "# Madera: " << edificio.obtener_madera() << endl;
    salida << "# Metal: " << edificio.obtener_metal() << endl;
    salida << "Brinda materiales: " << (edificio.obtener_provee_materiales() ? "Sí" : "No") << endl;
    salida << endl;

    return salida;
}