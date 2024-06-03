//
// Created by usuario 1 on 27/05/2024.
//

#ifndef ESCENA_H
#define ESCENA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"

class Escena {
public:
    Escena(const sf::VideoMode &tamaño, const std::string &path); // Declaración del primer constructor
    Escena(); // Declaración del segundo constructor

    void addButton(std::string &path, const float &PositionX, const float &PositionY);
    void draw(sf::RenderWindow& window) const;
    void drawButtons(sf::RenderWindow& window);
    std::vector<Button> getButtons();
    Button getButton(unsigned int NumeroDeBoton);

private:
    std::vector<Button> Botones;
    unsigned int windowSizeHeight;
    unsigned int windowSizeWidth;
    sf::Texture textura;
    sf::Sprite sprite;

    std::vector<float> getScales(int x, int y);
};

#endif // ESCENA_H

