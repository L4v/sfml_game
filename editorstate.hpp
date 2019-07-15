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
    EditorState(sf::RenderWindow* window,
        std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~EditorState();

    void updateButtons();
    void updateInput(const float& dt);
    void update(const float& dt);

    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};
