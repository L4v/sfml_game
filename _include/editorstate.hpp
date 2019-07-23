#pragma once

#include "state.hpp"
#include "button.hpp"

class EditorState : public State{
    sf::Font font;

    std::map<std::string, Button*> buttons;

    // Initializers
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();
    public:
    EditorState(GameDataRef);
    virtual ~EditorState();

    void updateButtons();
    void updateInput(const float&);
    void update(const float&);

    void renderButtons(sf::RenderTarget&);
    void render(sf::RenderTarget* target = nullptr);
};
