#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "jugador.h"

class Juego {
private:
    Tablero tablero;
    Jugador jugador1;
    Jugador jugador2;
    int turno; // 0 para jugador1, 1 para jugador2

public:
    Juego(const std::string& nombre1, const std::string& nombre2);
    void iniciarJuego();
    bool guardarPartida(const std::string& ruta) const;
    bool cargarPartida(const std::string& ruta);
};

#endif // JUEGO_H

