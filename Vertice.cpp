#include "Vertice.h"

Vertice::Vertice(Casillero *casillero) {
    this -> casillero = casillero;
}

Casillero *Vertice::obtener_casillero() {
    return casillero;
}

Vertice::~Vertice() {
}