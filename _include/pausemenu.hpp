#pragma once

#include <map>
#include <SFML/Graphics.hpp>

#include "button.hpp"

class PauseMenu{
private:
    sf::RectangleShape mBackground;
    sf::RectangleShape mContainer;

    sf::Font& mFont;
    sf::Text mMenuText;

    std::map<std::string, Button*> mButtons;

    // Private functions

public:
    PauseMenu(sf::RenderWindow&, sf::Font&);
    virtual ~PauseMenu();

    // Getters and setters

    /*
    * Returns all the buttons
    */
    std::map<std::string, Button*>& getButtons();

    // Functions

    /*
    * Adds a button with a specific key, position and text, button is
    * placed below key2 button
    */
    void addButton(const std::string, std::string,
        float,
        const std::string);

    /*
    * Returns whether a specific button is pressed
    */
    const bool isButtonPressed(const std::string);

    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget&);
};
