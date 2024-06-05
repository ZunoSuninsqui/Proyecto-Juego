// Juego.cpp

#include "Juego.h"

Juego::Juego(const sf::VideoMode &tamaño)
    : tamaño(tamaño), windowSizeHeight(tamaño.height), windowSizeWidth(tamaño.width), currentEscena(tamaño, leerBackground(1)[0]) {}

void Juego::crearEscenaInicial() {
    std::vector<std::string> paths = leerBackground(1);
    if (!paths.empty()) {
        this->currentEscena = Escena(tamaño, paths[0]);
        this->currentEscena.addButton(paths[1], 50, static_cast<float>(this->windowSizeHeight) - 300);
        this->currentEscena.addButton(paths[2], 350, static_cast<float>(this->windowSizeHeight) - 300);
        this->currentEscena.addButton(paths[3], 650, static_cast<float>(this->windowSizeHeight) - 300);
    }
}

void Juego::cambiarEscena(int valorIngresado) {
    std::vector<std::string> paths = leerBackground(valorIngresado);
    if (!paths.empty()) {
        this->currentEscena = Escena(tamaño, paths[0]);
        this->currentEscena.addButton(paths[1], 50, static_cast<float>(this->windowSizeHeight) - 300);
        this->currentEscena.addButton(paths[2], 350, static_cast<float>(this->windowSizeHeight) - 300);
        this->currentEscena.addButton(paths[3], 650, static_cast<float>(this->windowSizeHeight) - 300);
    }
}

std::vector<std::string> Juego::leerBackground(int indice) {
    std::ifstream archivo("D:/Java/Proyecto-Juego/HelloSFML/ImagenesGrafos/Archivoscpp/ListaBackgroundPaths.txt");
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return {};
    }

    std::vector<std::string> lista;
    std::string linea;
    std::string numero_str = std::to_string(indice);

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string item;
        int item_count = 0;
        bool correctoIndice = false;

        while (std::getline(ss, item, '|')) {
            if (item_count == 0) {
                if (item == numero_str) {
                    correctoIndice = true;
                } else {
                    break;
                }
            } else if (correctoIndice) {
                lista.push_back(item);
            }
            item_count++;
        }
    }

    archivo.close();
    return lista;
}

void Juego::draw(sf::RenderWindow &window) {
    this->currentEscena.draw(window);
    this->currentEscena.drawButtons(window);
}

Escena Juego::getEscena() const {
    return this->currentEscena;
}

