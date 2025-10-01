#include "juego.h"
#include <iostream>

using namespace std;

juego::juego(const string& nombre1, const string& nombre2) : jugador1(nombre1, 'X'), jugador2(nombre2, 'O') {}


void juego::iniciarJuego() {
    int fila, columna;
    bool turnoJugador1 = true;

    while (true) {
        tablero.mostrarTablero();
        jugador actual = turnoJugador1 ? jugador1 : jugador2;

        cout << actual.Nombrej() << " (" << actual.Simboloj() << "), ingresa fila (0-2): ";
        cin >> fila; 
        cout << actual.Nombrej() << " (" << actual.Simboloj() << "), ingresa columna (0-2): ";
        cin >> columna;
        
        // Validar y marcar la casilla
        if (!tablero.marcarCasilla(fila, columna, actual.Simboloj())) {
            cout << "Movimiento invalido. Intenta de nuevo.\n";
            continue;
        }
        
        // Verificar ganador
        if (tablero.verificarGanador(actual.Simboloj())) {
            tablero.mostrarTablero();
            cout << "Felicidades " << actual.Nombrej() << ", has ganado!\n";
            break;
        }

        // Verificar empate
        if (tablero.tableroLleno()) {
            tablero.mostrarTablero();
            cout << "El juego es un empate!\n";
            break;
        }

        // Cambiar turno
        turnoJugador1 = !turnoJugador1;
    }
}