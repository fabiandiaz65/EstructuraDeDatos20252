#pragma once
#include <string>
#include <unordered_map>
#include <optional>

struct GameState {
    int save_version = 1;
    // Campos mínimos sugeridos (ajústalos a tu diseño):
    // Estado del jugador:
    int jugador_x = 0;
    int jugador_y = 0;
    int vida = 100;
    // Estado del tablero:
    int nivel = 1;
    int puntaje = 0;

    // Si necesitas más, agrégalos y recuerda serializarlos abajo.
};

namespace SaveSystem {
    bool Save(const std::string& slot, const GameState& gs, std::string* outErr=nullptr);
    std::optional<GameState> Load(const std::string& slot, std::string* outErr=nullptr);
}