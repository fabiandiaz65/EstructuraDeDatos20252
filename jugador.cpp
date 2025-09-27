#include "jugador.h"

jugador::jugador(const string& nombre, char simbolo) : nombre(nombre), simbolo(simbolo) {}

string jugador::Nombrej() const {
    return nombre;
}

char jugador::Simboloj() const {
    return simbolo;
}
