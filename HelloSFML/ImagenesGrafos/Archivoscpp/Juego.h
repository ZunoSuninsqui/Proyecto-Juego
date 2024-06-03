//
// Created by usuario 1 on 3/06/2024.
//

#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "Escena.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


class Juego {
public:
    explicit Juego(const sf::VideoMode &tamaño) {
        this->tamaño = tamaño;
        this->windowSizeHeight = tamaño.height;
        this->windowSizeWidth = tamaño.width;
        this->currentEscena = Escena(tamaño, leerBackground(1)[0]);
    }

    void crearEscenaInicial() {
        std::vector<std::string> paths = leerBackground(1);
        if (!paths.empty()) {
            this->currentEscena = Escena(tamaño, paths[0]);
            this->currentEscena.addButton(paths[1], 50, static_cast<float>(this->windowSizeHeight) - 100);
            this->currentEscena.addButton(paths[2], 350, static_cast<float>(this->windowSizeHeight) - 100);
            this->currentEscena.addButton(paths[3], 650, static_cast<float>(this->windowSizeHeight - 100));
        }
    }

    void cambiarEscena(int valorIngresado) {
        std::vector<std::string> paths = leerBackground(valorIngresado);
        if (!paths.empty()) {
            this->currentEscena = Escena(tamaño, paths[0]);
            this->currentEscena.addButton(paths[1], 50, static_cast<float>(this->windowSizeHeight) - 100);
            this->currentEscena.addButton(paths[2], 350, static_cast<float>(this->windowSizeHeight) - 100);
            this->currentEscena.addButton(paths[3], 650, static_cast<float>(this->windowSizeHeight - 100));
        }
    }

    std::vector<std::string> leerBackground(int indice) {
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
                // Verificar si el primer elemento es el índice buscado
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

    void draw(sf::RenderWindow &window){
        this->currentEscena.draw(window);
        this->currentEscena.drawButtons(window);
    }

    Escena getEscena() {
        return this->currentEscena;
    }

private:
    Escena currentEscena;
    sf::VideoMode tamaño;
    unsigned int windowSizeHeight;
    unsigned int windowSizeWidth;
};

#endif // JUEGO_H

