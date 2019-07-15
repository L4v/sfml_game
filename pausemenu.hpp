#pragma once

#include <map>
#include <SFML/Graphics.hpp>

#include "button.hpp"

class PauseMenu{
private:
    sf::RectangleShape mBackground;
    sf::RectangleShape mContainer;

    std::map<std::string, Button*> mButtons;

public:
    PauseMenu(sf::RenderWindow&);
    virtual ~PauseMenu();

    // Functions

    void update();
    void render(sf::RenderTarget&);
};
