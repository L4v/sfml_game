#pragma once

#include "state.hpp"
#include "pausemenu.hpp"

// TODO : STRUCT FOR ALL THE PARAMETERS (window, keys, states)?

class GameState : public State{
private:
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
