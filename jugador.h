#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    char ficha; // 'X' o 'O'

public:
    Jugador(const string& nombre, char ficha);
    string getNombre() const;
    char getFicha() const;
};

#endif // JUGADOR_H