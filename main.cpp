#include "juego.h"
#include <iostream>
using namespace std;

int main() {
    string nombre1, nombre2;
    cout << "Ingrese el nombre del Jugador 1 (X): ";
    getline(cin, nombre1);
    cout << "Ingrese el nombre del Jugador 2 (O): ";
    getline(cin, nombre2);

    juego partida(nombre1, nombre2);
    partida.iniciarJuego();

    return 0;
}