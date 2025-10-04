#include <iostream>
#include "juego.h"
using namespace std;

int main() {
    string nombre1, nombre2;
    cout << "Ingrese el nombre del Jugador 1 (X): ";
    getline(cin, nombre1);
    cout << "Ingrese el nombre del Jugador 2 (O): ";
    getline(cin, nombre2);

    char opcion;
    cout << "¿Desea cargar la partida anterior? (s/n): ";
    cin >> opcion;
    cin.ignore();
    Juego partida(nombre1, nombre2);
    if (opcion == 's' || opcion == 'S') {
        if (partida.cargarPartida("partida.txt"))
            cout << "Partida cargada correctamente.\n";
        else
            cout << "No se pudo cargar la partida.\n";
    }   

    
    partida.iniciarJuego();
    partida.guardarPartida("partida.txt");

    return 0;
}