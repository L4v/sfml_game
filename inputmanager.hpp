#pragma once

#include <SFML/Graphics.hpp>

class InputManager{
public:
    /*
    * Default constructor and destructor
    */
    InputManager(){}
    ~InputManager(){}

    /*
    * Check whether a sprite is clicked
    */
    bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
        sf::RenderWindow& window);

    /*
    * Gets current mouse position in requested window
    */
    sf::Vector2i getMousePosition(sf::RenderWindow& window);

};
