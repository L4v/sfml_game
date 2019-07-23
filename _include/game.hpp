#pragma once

#include "mainmenustate.hpp"
#include <memory>


/*
* Data containing info about the window, state stack, keys, etc..
*/
struct GameData{
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::stack<State*>* states;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game{
private:
    // Game data pointer
    GameDataRef mData = std::make_shared<GameData>();

    //sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    //std::stack<State*> states;
    //std::map<std::string, int> supportedKeys;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings windowSettings;
    bool fullscreen;



    /*
    * Initializes variables
    */
    void initVariables();

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
