#pragma once

#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "game.hpp"
#include "entity.hpp"

class GameState : public State{
public:
    GameState(GameDataRef data);

    void init();

    void handleInput();
    void update(float dt);
    void draw(float dt);

private:
    GameDataRef _data;

    Entity player;

    sf::Sprite _background;
    sf::Sprite _pauseButton;
    int gameState;

    void initKeybinds();
};
