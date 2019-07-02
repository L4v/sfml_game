#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "statemachine.hpp"
#include "assetmanager.hpp"
#include "inputmanager.hpp"

struct GameData{
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game{
public:
    /*
    * Constructor with paramaters
    */
    Game(int width, int height, std::string title);

private:
    // Framerate, 60 updates per second (FPS)
    const float dt = 1.0f / 60.0f;
    sf::Clock _clock;

    GameDataRef _data = std::make_shared<GameData>();


    /*
    * For starting the game
    */
    void run();
};
