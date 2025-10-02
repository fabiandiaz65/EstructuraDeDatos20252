#include "jugador.h"

Jugador::Jugador(const string& nombre, char ficha) : nombre(nombre), ficha(ficha) {}

string Jugador::getNombre() const {
    return nombre;
}

char Jugador::getFicha() const {
    return ficha;
}