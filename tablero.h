#ifndef TABLERO_H
#define TABLERO_H

#include <string>

class Tablero {
private:
    char casillas[3][3]; // Matriz para el tablero

public:
    Tablero(); // Constructor
    void mostrar() const; // Muestra el tablero
    bool colocarFicha(int fila, int columna, char ficha); // Coloca ficha en el tablero
    bool estaCompleto() const; // Verifica si el tablero está lleno
    char verificarGanador() const; // Verifica si hay ganador
    void reiniciar(); // Reinicia el tablero
    bool guardarTablero(std::ofstream& archivo) const;
    bool cargarTablero(std::ifstream& archivo);
};

#endif // TABLERO_H