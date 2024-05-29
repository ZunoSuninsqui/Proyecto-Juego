//
// Created by usuario 1 on 25/05/2024.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
class Button {
public:
    Button(const std::string& text, const sf::Font& font, unsigned int characterSize, const sf::Color& textColor, const sf::Color& buttonColor, float PositionX, float PositionY) {
        // Configure the text
        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(characterSize);
        buttonText.setFillColor(textColor);
        buttonText.setPosition(PositionX, PositionY);

        // Configure the button shape
        buttonShape.setSize(sf::Vector2f(buttonText.getGlobalBounds().width, buttonText.getGlobalBounds().height));
        buttonShape.setFillColor(buttonColor);
        buttonShape.setPosition(PositionX, PositionY);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(buttonShape);
        window.draw(buttonText);
    }

    bool isClicked(const sf::Vector2i& mousePos) const {
        return buttonShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
    std::string getTextString() {
        return buttonText.getString();
    }

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
};


#endif //BUTTON_H
