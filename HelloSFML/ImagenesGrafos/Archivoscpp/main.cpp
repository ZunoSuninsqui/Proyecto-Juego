#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Button.h"  // Asegúrate de tener un archivo Button.h donde definas la clase Button
#include "Escena.h"
int main() {

    // Obtener la resolución de la pantalla
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Crear una ventana en modo de pantalla completa
    sf::RenderWindow window(desktopMode, "Mostrar Imágenes", sf::Style::Fullscreen);

    // Lista de rutas de imágenes
    std::vector<std::string> imagePaths = {
        "C:/Users/usuario 1/Documentos/CLionProjects/HelloSFML/ImagenesGrafos/Imagenes/convertidas/imagen1.jpg",
        "C:/Users/usuario 1/Documentos/CLionProjects/HelloSFML/ImagenesGrafos/Imagenes/convertidas/imagen2.jpg",
        "C:/Users/usuario 1/Documentos/CLionProjects/HelloSFML/ImagenesGrafos/Imagenes/convertidas/imagen3.jpg"
    };

    // Vector para almacenar las texturas y sprites
    //std::vector<sf::Texture> textures;
    //std::vector<sf::Sprite> sprites;

    //sf::Texture Texturaim1;
    //Texturaim1.loadFromFile("C:/Users/usuario 1/Documentos/CLionProjects/HelloSFML/ImagenesGrafos/Imagenes/convertidas/imagen1.jpg");
    //sf::Sprite spriteim1(Texturaim1);

    int Contador = 0;

    // Cargar las imágenes
    //sf::Texture TexturaIm1;


    // Verificar si hay al menos una imagen cargada
    //if (sprites.empty()) {
      //  std::cerr << "No se pudieron cargar las imágenes" << std::endl;
    //    return -1;
    //}

    // Posición inicial de la imagen actual
    int currentImageIndex = 0;

    // Crear botones
    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
        return -1;
    }

    Escena escena1 = Escena(desktopMode,imagePaths[0]);
    escena1.addButton("Imagen 1", font, 24, sf::Color::Black, sf::Color::Cyan, 50, desktopMode.height - 100);
    escena1.addButton("Imagen 2", font, 24, sf::Color::Black, sf::Color::Cyan, 200, desktopMode.height - 100);
    escena1.addButton("Imagen 3", font, 24, sf::Color::Black, sf::Color::Cyan, 350, desktopMode.height - 100);
    //Button button1("Imagen 1", font, 24, sf::Color::Black, sf::Color::Cyan, 50, desktopMode.height - 100);
    //Button button2();
    //Button button3();
    sf::Texture texturaBackground;
    texturaBackground.loadFromFile(imagePaths[0]);
    // Bucle principal
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

                    if (escena1.getButton(1).isClicked(mousePos)) {
                        currentImageIndex = 0;
                        std::cout<<"Boton : "<<escena1.getButton(1).getTextString()<<std::endl;
                        std::cout << "Cambiado a Imagen 1, índice actual: " << currentImageIndex << std::endl;
                        texturaBackground.loadFromFile(imagePaths[currentImageIndex]);
                    }
                    if (escena1.getButton(2).isClicked(mousePos)) {
                        currentImageIndex = 1;
                        std::cout<<"Boton : "<<escena1.getButton(2).getTextString()<<std::endl;
                        std::cout << "Cambiado a Imagen 2, índice actual: " << currentImageIndex << std::endl;
                        texturaBackground.loadFromFile(imagePaths[currentImageIndex]);
                    }
                    if (escena1.getButton(3).isClicked(mousePos)) {
                        currentImageIndex = 2;
                        std::cout<<"Boton : "<<escena1.getButton(3).getTextString()<<std::endl;
                        std::cout << "Cambiado a Imagen 3, índice actual: " << currentImageIndex << std::endl;
                        texturaBackground.loadFromFile(imagePaths[currentImageIndex]);
                    }
                }
            }
        }
        sf::Sprite sprite;
        sprite.setTexture(texturaBackground);
        // Limpiar la ventana
        window.clear();
        escena1.draw(window);
        //window.draw(sprite);
        // Dibujar la imagen actual
        //window.draw(sprites[currentImageIndex]);
        //window.draw(spriteim1);
        // Dibujar los botones
        escena1.drawButtons(window);

        // Mostrar todo en la ventana
        window.display();
    }

    return 0;
}

