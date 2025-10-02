#include "tablero.h"
#include <iostream>
#include <fstream>
using namespace std;

Tablero::Tablero() {
    reiniciar();
}

void Tablero::reiniciar() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            casillas[i][j] = ' ';
}

void Tablero::mostrar() const {
    cout << "  0   1   2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << casillas[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << " ---+---+---\n";
    }
}

bool Tablero::colocarFicha(int fila, int columna, char ficha) {
    if (fila < 0 || fila > 2 || columna < 0 || columna > 2)
        return false;
    if (casillas[fila][columna] != ' ')
        return false;
    casillas[fila][columna] = ficha;
    return true;
}

bool Tablero::estaCompleto() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (casillas[i][j] == ' ')
                return false;
    return true;
}

char Tablero::verificarGanador() const {
    // Filas y columnas
    for (int i = 0; i < 3; ++i) {
        if (casillas[i][0] != ' ' && casillas[i][0] == casillas[i][1] && casillas[i][1] == casillas[i][2])
            return casillas[i][0];
        if (casillas[0][i] != ' ' && casillas[0][i] == casillas[1][i] && casillas[1][i] == casillas[2][i])
            return casillas[0][i];
    }
    // Diagonales
    if (casillas[0][0] != ' ' && casillas[0][0] == casillas[1][1] && casillas[1][1] == casillas[2][2])
        return casillas[0][0];
    if (casillas[0][2] != ' ' && casillas[0][2] == casillas[1][1] && casillas[1][1] == casillas[2][0])
        return casillas[0][2];
    return ' '; // Sin ganador
}

bool Tablero::guardarTablero(std::ofstream& archivo) const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            archivo << casillas[i][j];
    return true;
}

bool Tablero::cargarTablero(std::ifstream& archivo) {
    char c;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            archivo >> c;
            casillas[i][j] = c;
        }
    return true;
}