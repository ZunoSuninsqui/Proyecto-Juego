//
// Created by usuario 1 on 3/06/2024.
//

#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Juego {
public:
    Juego(sf::VideoMode tamaño) {
        this->windowSizeHeight = tamaño.height;
        this->windowSizeWidth = tamaño.width;
    }

    void crearEscenaInicial(sf::Font &font) {
        this->currentEscena = new Escena(tamaño,leerBackground(1)[0]);
        this->currentEscena.addButton(leerBackground(1)[1],)
    }

    static std::vector<std::string> leerBackground(int indice) {
        std::ifstream archivo("ListaBackgroundPaths.txt");
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

    draw(sf::RenderWindow &window) {
        currentEscena.draw(window);
    }

private:
    Escena currentEscena;
    unsigned int windowSizeHeight;
    unsigned int windowSizeWidth;
};


#endif //JUEGO_H
