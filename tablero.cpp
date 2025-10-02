#include "tablero.h"
#include <iostream>
using namespace std;

tablero::tablero() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            grid[i][j] = ' ';
}

void tablero::mostrarTablero() const {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << grid[i][j];
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "  ---+---+---\n";
    }
    cout << "\n";
}

bool tablero::marcarCasilla(int fila, int columna, char jugador) {
    if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3 || grid[fila][columna] != ' ')
        return false;
    grid[fila][columna] = jugador;
    return true;
}

bool tablero::verificarGanador(char jugador) const {
    // Verificar filas y columnas
    for (int i = 0; i < 3; ++i) {
        if ((grid[i][0] == jugador && grid[i][1] == jugador && grid[i][2] == jugador) ||
            (grid[0][i] == jugador && grid[1][i] == jugador && grid[2][i] == jugador))
            return true;
    }
    // Verificar diagonales
    if ((grid[0][0] == jugador && grid[1][1] == jugador && grid[2][2] == jugador) ||
        (grid[0][2] == jugador && grid[1][1] == jugador && grid[2][0] == jugador))
        return true;
    return false;
}

bool tablero::tableroLleno() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] == ' ')
                return false;
    return true;
}

void tablero::reiniciarTablero() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            grid[i][j] = ' ';
}