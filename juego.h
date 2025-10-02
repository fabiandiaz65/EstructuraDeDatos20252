#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "jugador.h"

class juego {
private:
    tablero tablero;
    jugador jugador1;
    jugador jugador2;
    
public:
    juego(const string& nombre1, const string& nombre2);
    void iniciarJuego();
};

#endif
