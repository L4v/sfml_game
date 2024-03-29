#pragma once

#include "state.hpp"
#include "pausemenu.hpp"
#include "player.hpp"

// TEST
#include "level.hpp"

// TODO : STRUCT FOR ALL THE PARAMETERS (window, keys, states)?

class GameState : public State{
private:
    // TEST
    Level mLevel0;

    sf::Font mFont;
    PauseMenu* mPmenu;

    Player *player;
    sf::Texture mTexture; // ??

// Initializers
    void initKeybinds();
    void initTextures();
    void initPlayers();
    void initFonts();
    void initPauseMenu();

public:
    GameState(GameDataRef);
    virtual ~GameState();

    // Functions

    void updateInput(const float&);
    void updatePlayerInput(const float&);
    void updatePauseMenuButtons();
    void update(const float&);
    void render(sf::RenderTarget* target = nullptr);
};
