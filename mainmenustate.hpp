#pragma once

#include "gamestate.hpp"
#include "button.hpp"

class MainMenuState : public State{
private:
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    // Initializers
    void initFonts();
    void initKeybinds();
    void initButtons();
public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    void endState();
    void updateButtons();
    void updateInput(const float& dt);
    void update(const float& dt);

    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};
