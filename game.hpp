#pragma once

#include "mainmenustate.hpp"


class Game{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;
    std::map<std::string, int> supportedKeys;

    /*
    * Create a SFML window using a window.ini file
    */
    void initWindow();

    /*
    * Initializes the states stack
    */
    void initStates();

    /*
    * Initializes the supported keys
    */
    void initKeys();

public:
    Game();
    virtual ~Game();

    /*
    * Ends the application
    */
    void endApplication();

    /*
    * Updates the delta time (dt)
    */
    void updateDt();

    /*
    * For updating SFML events
    */
    void updateSFMLEvents();

    /*
    * For updates
    */
    void update();

    /*
    * Handling all the renders
    */
    void render();

    /*
    * The main run loop
    */
    void run();
};
