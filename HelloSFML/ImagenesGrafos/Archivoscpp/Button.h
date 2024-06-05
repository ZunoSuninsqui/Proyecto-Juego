// Button.h

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class Button {
public:
    Button(const std::string& imagePath, const float &positionX, const float &positionY)
        : buttonTexture(std::make_shared<sf::Texture>()) {
        // Cargar la textura de la imagen
        if (!buttonTexture->loadFromFile(imagePath)) {
            throw std::runtime_error("No se pudo cargar la imagen del botón.");
        }

        // Configurar el sprite con la textura
        buttonSprite.setTexture(*buttonTexture);
        buttonSprite.setPosition(positionX, positionY);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(buttonSprite);
    }

    bool isClicked(const sf::Vector2i& mousePos) const {
        return buttonSprite.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }

private:
    std::shared_ptr<sf::Texture> buttonTexture;
    sf::Sprite buttonSprite;
};

#endif //BUTTON_H
