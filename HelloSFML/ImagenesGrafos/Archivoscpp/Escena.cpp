//
// Created by usuario 1 on 27/05/2024.
//

#include "Escena.h"


#include "Escena.h"

// Definición del primer constructor
Escena::Escena(const sf::VideoMode &tamaño, const std::string &path) {
    this->windowSizeHeight = tamaño.height;
    this->windowSizeWidth = tamaño.width;
    textura.loadFromFile(path);
    sprite.setTexture(textura);
    sprite.setScale(getScales(tamaño.width, tamaño.height)[0], getScales(tamaño.width, tamaño.height)[1]);
}

// Definición del segundo constructor
Escena::Escena() {
    // Aquí puedes inicializar los valores predeterminados
    this->windowSizeHeight = 600; // Por ejemplo
    this->windowSizeWidth = 800;  // Por ejemplo
}

// Definición de las demás funciones miembro
void Escena::addButton(std::string &path, const float &PositionX, const float &PositionY) {
    Button Boton = Button(path, PositionX, PositionY);
    Botones.push_back(Boton);
}

void Escena::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Escena::drawButtons(sf::RenderWindow& window) {
    for (Button Bo : Botones) {
        Bo.draw(window);
    }
}

std::vector<Button> Escena::getButtons() {
    return this->Botones;
}

Button Escena::getButton(unsigned int NumeroDeBoton) {
    return Botones[NumeroDeBoton-1];
}

std::vector<float> Escena::getScales(int x, int y) {
    sf::Vector2u textureSize = textura.getSize();
    float scaleX = static_cast<float>(x) / textureSize.x;
    float scaleY = static_cast<float>(y) / textureSize.y;
    std::cout << "Tamaño de la ventana en X : " << x << "\nTamaño de la ventana en Y : " << y << std::endl;
    std::cout << "Tamaño del Scale  en X : " << scaleX << "\nTamaño de la Scale  en Y : " << scaleY << std::endl;
    std::vector<float> vectorScale;
    vectorScale.push_back(scaleX);
    vectorScale.push_back(scaleY);
    return vectorScale;
}
