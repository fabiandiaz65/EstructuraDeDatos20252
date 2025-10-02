#include "juego.h"
#include <iostream>
#include <fstream>
using namespace std;

Juego::Juego(const std::string& nombre1, const std::string& nombre2)
    : jugador1(nombre1, 'X'), jugador2(nombre2, 'O'), turno(0) {}

void Juego::iniciarJuego() {
    int fila, columna;
    char ganador = ' ';
    tablero.reiniciar();

    while (ganador == ' ' && !tablero.estaCompleto()) {
        tablero.mostrar();
        Jugador& actual = (turno == 0) ? jugador1 : jugador2;
        cout << actual.getNombre() << " (" << actual.getFicha() << "), ingrese fila y columna: ";
        cin >> fila >> columna;

        if (!tablero.colocarFicha(fila, columna, actual.getFicha())) {
            cout << "Movimiento inválido. Intente de nuevo.\n";
            continue;
        }

        ganador = tablero.verificarGanador();
        turno = 1 - turno;
    }

    tablero.mostrar();
    if (ganador != ' ')
        cout << "¡Felicidades " << ((ganador == jugador1.getFicha()) ? jugador1.getNombre() : jugador2.getNombre()) << "! Ganaste.\n";
    else
        cout << "¡Empate!\n";
}

bool Juego::guardarPartida(const std::string& ruta) const {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) return false;
    archivo << jugador1.getNombre() << '\n'
            << jugador2.getNombre() << '\n'
            << turno << '\n';
    tablero.guardarTablero(archivo);
    archivo.close();
    return true;
}

bool Juego::cargarPartida(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) return false;
    std::string nombre1, nombre2;
    int t;
    archivo >> nombre1 >> nombre2 >> t;
    jugador1 = Jugador(nombre1, 'X');
    jugador2 = Jugador(nombre2, 'O');
    turno = t;
    tablero.cargarTablero(archivo);
    archivo.close();
    return true;
}