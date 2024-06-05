// Escena.cpp

#include "Escena.h"

// Definición del primer constructor
Escena::Escena(const sf::VideoMode &tamaño, const std::string &path)
    : texturePtr(std::make_shared<sf::Texture>()) {
    this->windowSizeHeight = tamaño.height;
    this->windowSizeWidth = tamaño.width;
    std::cout << path << std::endl;

    if (!texturePtr->loadFromFile(path)) {
        throw std::runtime_error("No se pudo cargar la textura desde el archivo: " + path);
    }
    sprite.setTexture(*texturePtr);
    sprite.setScale(getScales(tamaño.width, tamaño.height)[0], getScales(tamaño.width, tamaño.height)[1]);
}

// Definición del segundo constructor
Escena::Escena() : texturePtr(std::make_shared<sf::Texture>()) {
    this->windowSizeHeight = 600; // Por ejemplo
    this->windowSizeWidth = 800;  // Por ejemplo
}

// Definición de las demás funciones miembro
void Escena::addButton(const std::string &path, const float &PositionX, const float &PositionY) { // Aquí está la definición
    Button Boton = Button(path, PositionX, PositionY);
    Botones.push_back(Boton);
}

void Escena::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Escena::drawButtons(sf::RenderWindow& window) {
    for (const Button& Bo : Botones) {
        Bo.draw(window);
    }
}

std::vector<Button> Escena::getButtons() const {
    return this->Botones;
}

Button Escena::getButton(unsigned int NumeroDeBoton) const {
    return Botones[NumeroDeBoton-1];
}

std::vector<float> Escena::getScales(int x, int y) const {
    sf::Vector2u textureSize = texturePtr->getSize();
    float scaleX = static_cast<float>(x) / textureSize.x;
    float scaleY = static_cast<float>(y) / textureSize.y;
    std::cout << "Tamaño de la ventana en X : " << x << "\nTamaño de la ventana en Y : " << y << std::endl;
    std::cout << "Tamaño del Scale  en X : " << scaleX << "\nTamaño de la Scale  en Y : " << scaleY << std::endl;
    return { scaleX, scaleY };
}
