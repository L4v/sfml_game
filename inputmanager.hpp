#pragma once

#include <SFML/Graphics.hpp>
#include <map>

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

    /*
    * Initializes supported keys
    */
    void initKeys();

    /*
    * Getter for supported keys
    */
    std::map<std::string, int>& getKeys();

private:
    std::map<std::string, int> supportedKeys;

};
