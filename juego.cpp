#include "juego.h"
#include "jugador.h"
#include <iostream>

using namespace std;

juego::juego(const string& nombre1, const string& nombre2) : jugador1(nombre1, 'X'), jugador2(nombre2, 'O') {}


GameState juego::captureState() const {
  GameState s;
  s.jugador_x = jugador.getX();
  s.jugador_y = jugador.getY();
  s.vida      = jugador.getVida();
  s.nivel     = tablero.getNivelActual();
  s.puntaje   = tablero.getPuntaje();
  return s;
}

void juego::applyState(const GameState& s) {
  jugador.setPos(s.jugador_x, s.jugador_y);
  jugador.setVida(s.vida);
  tablero.setNivel(s.nivel);
  tablero.setPuntaje(s.puntaje);
}


void juego::iniciarJuego() {
    int fila, columna;
    bool turnoJugador1 = true;

    while (true) {
        tablero.mostrarTablero();
        jugador actual = turnoJugador1 ? jugador1 : jugador2;

        cout << actual.Nombrej() << " (" << actual.Simboloj() << "), ingresa fila y columna (0-2): ";
        cin >> fila >> columna;
        
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