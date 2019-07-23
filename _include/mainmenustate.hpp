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
    MainMenuState(GameDataRef);
    virtual ~MainMenuState();

    void updateButtons();
    void updateInput(const float&);
    void update(const float&);

    void renderButtons(sf::RenderTarget&);
    void render(sf::RenderTarget* target = nullptr);
};
