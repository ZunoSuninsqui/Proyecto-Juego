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
    Escena(sf::VideoMode tamaño,const std::string path) {
        //Contiene Texto dir Imagen Background, Lista de personajes, Botones de movimiento, objeto de dialogo
        this->windowSizeHeight = tamaño.height;
        this->windowSizeWidth = tamaño.width;
        textura.loadFromFile(path);
        sprite.setTexture(textura);
        sprite.setScale(getScales(tamaño.width,tamaño.height)[0],getScales(tamaño.width,tamaño.height)[1]);
    }
    void addButton(std::string text, const sf::Font& font, unsigned int characterSize, const sf::Color& textColor, const sf::Color& buttonColor, float PositionX, float PositionY) {
        Button Boton = Button(text, font,characterSize,textColor,buttonColor,PositionX,PositionY );
        Botones.push_back(Boton);
    }
    void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }
    void drawButtons(sf::RenderWindow& window) {
        for (Button Bo : Botones) {
            Bo.draw(window);
        }
    }
    Button getButton(unsigned int NumeroDeBoton) {
        return Botones[NumeroDeBoton-1];
    }


private:
    std::vector<Button> Botones;
    unsigned int windowSizeHeight;
    unsigned int windowSizeWidth;
    sf::Texture textura;
    sf::Sprite sprite;

    std::vector<float> getScales(int x, int y) {
        sf::Vector2u textureSize = textura.getSize();
        float scaleX = static_cast<float>(x) / textureSize.x;
        float scaleY = static_cast<float>(y) / textureSize.y;
        std::cout<<"Tamaño de la ventana en X : "<<x<<"\nTamaño de la ventana en Y : "<<y<<std::endl;
        std::cout<<"Tamaño del Scale  en X : "<<scaleX<<"\nTamaño de la Scale  en Y : "<<scaleY<<std::endl;
        std::vector<float> vectorScale;
        vectorScale.push_back(scaleX);
        vectorScale.push_back(scaleY);
        return vectorScale;
    }
};



#endif //ESCENA_H
