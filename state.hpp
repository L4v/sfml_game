#pragma once

#include "entity.hpp"

class State{
protected:
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit; // Whether to quit a state


    std::vector<sf::Texture*> textures;

    virtual void initKeybinds() = 0;


public:
    /*
    * Constructor and destructor
    */
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~State();

    /*
    * Checks for quit signal
    */
    virtual void checkForQuit();

    /*
    * Returns whether the state wishes to quit or not
    */
    const bool& getQuit() const;

    /*
    * Performs tasks before ending the state
    */
    virtual void endState() = 0;


    /*
    * Updates the keybinds
    */
    virtual void updateInput(const float& dt) = 0;

    /*
    * Does state updates
    */
    virtual void update(const float& dt) = 0;

    /*
    * Renders the state
    */
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
