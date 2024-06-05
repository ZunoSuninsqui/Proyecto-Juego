// Juego.h

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
    explicit Juego(const sf::VideoMode &tamaño);

    void crearEscenaInicial();
    void cambiarEscena(int valorIngresado);
    std::vector<std::string> leerBackground(int indice);
    void draw(sf::RenderWindow &window);
    Escena getEscena() const;

private:
    Escena currentEscena;
    sf::VideoMode tamaño;
    unsigned int windowSizeHeight;
    unsigned int windowSizeWidth;
};

#endif // JUEGO_H
