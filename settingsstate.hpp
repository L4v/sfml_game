#ifndef SETTINGSSTATE_HPP
#define SETTINGSSTATE_HPP

#include "state.hpp"
#include "button.hpp"

class SettingsState : public State{
private:
    sf::RectangleShape mBackground;
    sf::Font mFont;
    sf::Texture mBackgroundTexture;

    std::map<std::string, Button*> mButtons;

    // Initializers
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();
public:

    /*
    * Constructor and destructor
    */
    SettingsState(sf::RenderWindow* window,
        std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~SettingsState();

    // Getters and setters

    // Functions
    void updateButtons();
    void updateInput(const float& dt);
    void update(const float& dt);
    void renderButtons(sf::RenderTarget&);
    void render(sf::RenderTarget* target = nullptr);

};

#endif
