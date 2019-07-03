#pragma once

#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "game.hpp"

class MainMenuState : public State{
public:
    MainMenuState(GameDataRef data);

    void init();

    void handleInput();
    void update(float dt);
    void draw(float dt);

private:
    GameDataRef _data;

    sf::Sprite _background;
    sf::Sprite _playButton;
    sf::Sprite _title;

    void initKeybinds();
};
