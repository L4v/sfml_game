#pragma once

#include "state.hpp"


class Game{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    /*
    * Create a SFML window using a window.ini file
    */
    void initWindow();


public:
    Game();
    virtual ~Game();

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
    * The run loop
    */
    void run();
};
