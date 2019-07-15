#pragma once

#include "player.hpp"

class State{
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit; // Whether to quit a state
    bool mPaused;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    std::map<std::string, sf::Texture> textures;

    virtual void initKeybinds() = 0;


public:
    /*
    * Constructor and destructor
    */
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
        std::stack<State*>* states);
    virtual ~State();

    /*
    * Returns whether the state wishes to quit or not
    */
    const bool& getQuit() const;

    /*
    * Performs tasks before ending the state
    */
    void endState();

    /*
    * Pauses the state
    */
    void pauseState();

    /*
    * Resumes paused state
    */
    void resumeState();

    /*
    * Updates the mouse positions
    */
    virtual void updateMousePositions();

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
