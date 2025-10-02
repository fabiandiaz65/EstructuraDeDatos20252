#ifndef TABLERO_H
#define TABLERO_H

class tablero
{
private:
    char grid[3][3]; // 3x3 fija
public:
    tablero();
    void mostrarTablero() const;
    bool marcarCasilla(int fila, int columna, char jugador);
    bool verificarGanador(char jugador) const;
    bool tableroLleno() const;
    void reiniciarTablero();
};

#endif // TABLERO_H

