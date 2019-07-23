#pragma once

#include "game.hpp"
#include <SFML/System.hpp>

class State{

protected:

    GameDataRef mData;
    //std::stack<State*>* states;
    //sf::RenderWindow* window;
    //std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit; // Whether to quit a state
    bool mPaused;

    // For adding delay to keys
    float mKeytime;
    float mKeytimeMax;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    std::map<std::string, sf::Texture> textures;

    virtual void initKeybinds() = 0;


public:
    /*
    * Constructor and destructor
    */
    State(GameDataRef);
    virtual ~State();

    // Getters and setters

    /*
    * Returns whether the state wishes to quit or not
    */
    const bool& getQuit() const;

    /*
    * Returns whether the keytime has elapsed
    */
    const bool getKeytime();


    // Functions

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
    * Updates the keytime, so one keypress isn't registered as a bunch
    */
    virtual void updateKeytime(const float& dt);

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
