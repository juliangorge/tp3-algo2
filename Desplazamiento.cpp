#include "Desplazamiento.h"


void moverse_coordenada(Jugador *jugador)
{
    int energia_necesaria = 0;
    int x=0, y=0;

    pedir_punto_final(&x, &y);
    energia_necesaria = calcular_energia_desplazamiento(jugador);
    if(energia_necesaria>jugador->obtener_energia())
        cout << "Energia insuficiente para realizar el desplazamiento" << endl;
}

/*unsigned int calcular_energia_desplazamiento(Jugador *jugador, int x, int y)
{
    
}*/

void pedir_punto_final(int *x, int*y)
{

}