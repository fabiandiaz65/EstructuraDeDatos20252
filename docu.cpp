#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 5;   // tamaño del tablero
const int SHIP = 3;   // tamaño del barco

// Mostrar tablero
void mostrarTablero(char tablero[SIZE][SIZE]) {
    cout << "  ";
    for (int i = 0; i < SIZE; i++) cout << i << " ";
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

// Inicializar tablero con '~'
void inicializarTablero(char tablero[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tablero[i][j] = '~';
        }
    }
}

// Colocar un barco horizontalmente
void colocarBarco(char tablero[SIZE][SIZE]) {
    srand(time(0));
    int fila = rand() % SIZE;
    int col = rand() % (SIZE - SHIP + 1);

    for (int i = 0; i < SHIP; i++) {
        tablero[fila][col + i] = 'B';
    }
}

int main() {
    char tablero[SIZE][SIZE];
    char tableroOculto[SIZE][SIZE];

    inicializarTablero(tablero);
    inicializarTablero(tableroOculto);

    colocarBarco(tableroOculto);

    int intentos = 0;
    int aciertos = 0;

    cout << "=== Batalla Naval ===" << endl;

    while (aciertos < SHIP) {
        mostrarTablero(tablero);
        int fila, col;
        cout << "Ingresa coordenadas (fila columna): ";
        cin >> fila >> col;

        if (fila < 0 || fila >= SIZE || col < 0 || col >= SIZE) {
            cout << "Coordenada fuera de rango." << endl;
            continue;
        }

        if (tablero[fila][col] != '~') {
            cout << "Ya atacaste aquí." << endl;
            continue;
        }

        intentos++;
        if (tableroOculto[fila][col] == 'B') {
            cout << "Impacto!" << endl;
            tablero[fila][col] = 'X';
            aciertos++;
        } else {
            cout << "Agua..." << endl;
            tablero[fila][col] = 'O';
        }
    }

    cout << "¡Hundiste el barco en " << intentos << " intentos!" << endl;
    return 0;
}
