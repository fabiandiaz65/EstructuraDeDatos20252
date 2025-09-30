#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "jugador.h"
#include "SaveManager.h"


class juego {
private:
    tablero tablero;
    jugador jugador1;
    jugador jugador2;
    
public:
    juego(const string& nombre1, const string& nombre2);
    GameState captureState() const;
    void applyState(const GameState&);
    void iniciarJuego();
    void update(int input);
    void render() const;
    GameState captureState() const;
    void applyState(const GameState& gs);
};

#endif
