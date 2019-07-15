#pragma once

#include "state.hpp"
#include "pausemenu.hpp"

// TODO : STRUCT FOR ALL THE PARAMETERS (window, keys, states)?

class GameState : public State{
private:
    PauseMenu mPmenu;

    Player *player;
    sf::Texture mTexture; // ??

// Initializers
    void initKeybinds();
    void initTextures();
    void initPlayers();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
            std::stack<State*>* states);
    virtual ~GameState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};
