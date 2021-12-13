#include "Utilidades.h"


unsigned int aleatorio(unsigned int cota_inferior, unsigned int cota_superior)
{
    unsigned int rand = unsigned(std::rand());
    return rand % cota_superior + cota_inferior;

}
