// Escena.h

#ifndef ESCENA_H
#define ESCENA_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Button.h"

class Escena {
public:
    Escena(const sf::VideoMode &tamaño, const std::string &path);
    Escena();

    void addButton(const std::string &path, const float &PositionX, const float &PositionY); // Aquí está la declaración
    void draw(sf::RenderWindow& window) const;
    void drawButtons(sf::RenderWindow& window);
    std::vector<Button> getButtons() const;
    Button getButton(unsigned int NumeroDeBoton) const;

private:
    std::vector<Button> Botones;
    unsigned int windowSizeHeight;
    unsigned int windowSizeWidth;
    std::shared_ptr<sf::Texture> texturePtr;
    sf::Sprite sprite;

    std::vector<float> getScales(int x, int y) const;
};

#endif // ESCENA_H
