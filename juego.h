#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "jugador.h"

#include <string>

class juego {
private:
    tablero tablero;
    jugador jugador1;
    jugador jugador2;
    
public:
    juego(const std::string& nombre1, const std::string& nombre2); // Constructor
    void iniciarJuego();
};

#endif
