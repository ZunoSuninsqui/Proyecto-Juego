// main.cpp

#include "Juego.h"
#include <SFML/Graphics.hpp>

int main() {
    // Obtener la resolución de la pantalla
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Crear una ventana en modo de pantalla completa
    sf::RenderWindow window(desktopMode, "Mostrar Imágenes", sf::Style::Fullscreen);

    Juego juego(desktopMode);
    juego.crearEscenaInicial();

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            // Manejar clics del ratón
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (juego.getEscena().getButton(1).isClicked(mousePos)) {
                        juego.cambiarEscena(1);
                    }
                    if (juego.getEscena().getButton(2).isClicked(mousePos)) {
                        juego.cambiarEscena(2);
                    }
                    if (juego.getEscena().getButton(3).isClicked(mousePos)) {
                        juego.cambiarEscena(3);
                    }
                }
            }
        }

        window.clear();
        juego.draw(window);
        window.display();
    }

    return 0;
}
