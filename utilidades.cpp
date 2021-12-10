#include "utilidades.h"


int aleatorio(int cota_inferior, int cota_superior)
{
    return int(rand()%cota_superior + cota_inferior);
}
