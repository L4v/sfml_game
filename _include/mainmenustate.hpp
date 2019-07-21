#pragma once

#include "gamestate.hpp"
#include "editorstate.hpp"
#include "button.hpp"
#include "settingsstate.hpp"

class MainMenuState : public State{
private:
    sf::RectangleShape background;
    sf::Font font;
    sf::Texture backgroundTexture;

    std::map<std::string, Button*> buttons;

    // Init functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();
public:
    MainMenuState(sf::RenderWindow* window,
        std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    void updateButtons();
    void updateInput(const float& dt);
    void update(const float& dt);

    void renderButtons(sf::RenderTarget&);
    void render(sf::RenderTarget* target = nullptr);
};
