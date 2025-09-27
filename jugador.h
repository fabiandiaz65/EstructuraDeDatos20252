#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class jugador{
private:
    string nombre;
    char simbolo; // 'X' o 'O'

public:
    jugador(const string& nombre, char simbolo);

    string Nombrej() const;
    char Simboloj() const;
};
#endif // JUGADOR_H