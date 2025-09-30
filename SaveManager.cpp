#include "SaveManager.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace {
    std::filesystem::path saveDir() {
        std::filesystem::path dir = std::filesystem::current_path() / "saves";
        std::error_code ec;
        std::filesystem::create_directories(dir, ec);
        return dir;
    }
    std::filesystem::path slotPath(const std::string& slot) {
        return saveDir() / (slot + ".sav");
    }

    // Utilidades simples de parseo "clave=valor"
    static inline std::string trim(const std::string& s) {
        size_t a = s.find_first_not_of(" \t\r\n");
        size_t b = s.find_last_not_of(" \t\r\n");
        if (a==std::string::npos) return "";
        return s.substr(a, b-a+1);
    }
    std::unordered_map<std::string,std::string> readKv(std::istream& in) {
        std::unordered_map<std::string,std::string> kv;
        std::string line;
        while (std::getline(in, line)) {
            auto pos = line.find('=');
            if (pos==std::string::npos) continue;
            std::string k = trim(line.substr(0,pos));
            std::string v = trim(line.substr(pos+1));
            if (!k.empty()) kv[k]=v;
        }
        return kv;
    }
    template<typename T> bool toInt(const std::string& s, T& out) {
        std::istringstream iss(s);
        long long tmp;
        if (!(iss>>tmp)) return false;
        out = static_cast<T>(tmp);
        return true;
    }
}

namespace SaveSystem {
    bool Save(const std::string& slot, const GameState& gs, std::string* outErr) {
        try {
            auto pathTmp = slotPath(slot).string() + ".tmp";
            std::ofstream f(pathTmp, std::ios::trunc);
            if (!f) { if (outErr) *outErr = "No se pudo abrir el archivo temporal."; return false; }

            // Serialización: clave=valor (puedes añadir nuevas líneas cuando amplíes el estado)
            f << "save_version=" << gs.save_version << "\n";
            f << "jugador_x="   << gs.jugador_x   << "\n";
            f << "jugador_y="   << gs.jugador_y   << "\n";
            f << "vida="        << gs.vida        << "\n";
            f << "nivel="       << gs.nivel       << "\n";
            f << "puntaje="     << gs.puntaje     << "\n";

            f.close();
            // Escrita atómica
            std::filesystem::rename(pathTmp, slotPath(slot));
            return true;
        } catch (const std::exception& e) {
            if (outErr) *outErr = e.what();
            return false;
        }
    }

    std::optional<GameState> Load(const std::string& slot, std::string* outErr) {
        try {
            auto path = slotPath(slot);
            std::ifstream f(path);
            if (!f) { if (outErr) *outErr = "No existe el archivo de guardado."; return std::nullopt; }

            auto kv = readKv(f);
            GameState gs;

            // Lectura segura (si falta una clave, se deja el valor por defecto)
            if (kv.count("save_version")) toInt(kv["save_version"], gs.save_version);
            if (kv.count("jugador_x"))    toInt(kv["jugador_x"],    gs.jugador_x);
            if (kv.count("jugador_y"))    toInt(kv["jugador_y"],    gs.jugador_y);
            if (kv.count("vida"))         toInt(kv["vida"],         gs.vida);
            if (kv.count("nivel"))        toInt(kv["nivel"],        gs.nivel);
            if (kv.count("puntaje"))      toInt(kv["puntaje"],      gs.puntaje);

            return gs;
        } catch (const std::exception& e) {
            if (outErr) *outErr = e.what();
            return std::nullopt;
        }
    }
}
