#include "gamestate.hpp"

// Initializer functions

void GameState::initKeybinds(){
    // Fetches the adequate keybinds for the state
    std::ifstream ifs("_config/gamestate_keybinds.ini");

    if(ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2)
            this->keybinds[key] = this->mData->supportedKeys.at(key2);
    }

    ifs.close();
}

void GameState::initTextures(){
    // TODO : USE SPRITESHEETS?
    // Not really safe
    if(!this->textures["PLAYER_SHEET"].loadFromFile(
        "_assets/_sprites/character_spritesheet.png"))
        throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
}

void GameState::initPlayers(){
    this->player = new Player(0, 0, this->textures["PLAYER_SHEET"]);
}

void GameState::initFonts(){
    if(!this->mFont.loadFromFile("_assets/_fonts/SHPinscher-Regular.otf"))
        std::cout << "Could not load font in main menu state" << std::endl;
}

void GameState::initPauseMenu(){
    this->mPmenu = new PauseMenu(*this->mData->window, this->mFont);

    this->mPmenu->addButton("QUIT", "", 0, "Quit");
}

GameState::GameState(GameDataRef data) :
    State(data)
{
    this->initKeybinds();
    this->initFonts();
    this->initTextures();
    this->initPauseMenu();
    this->initPlayers();
}

GameState::~GameState(){
    delete this->mPmenu;
    delete this->player;
}

void GameState::updateInput(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))
        && this->getKeytime())
        if(!this->mPaused)
            this->pauseState();
        else
            this->resumeState();

}

void GameState::updatePlayerInput(const float& dt){

    // Update player inptu
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player->move(dt, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player->move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player->move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player->move(dt, 0.f, 1.f);
}

void GameState::updatePauseMenuButtons(){
    if(this->mPmenu->isButtonPressed("QUIT"))
        this->endState();
}

void GameState::update(const float& dt){

    this->updateMousePositions(); // Needs to work in paused
    this->updateKeytime(dt);
    this->updateInput(dt);

    if(!this->mPaused){
        // Unpaused updates

        this->updatePlayerInput(dt); // Needs to work in paused
        this->player->update(dt);
    }else{
        // Paused updates

        this->mPmenu->update(this->mousePosView);
    }
}

void GameState::render(sf::RenderTarget* target){
    if(!target)
        target = this->mData->window;

    this->player->render(*target);
    // Pause menu render
    if(this->mPaused){
        this->mPmenu->render(*target);
        this->updatePauseMenuButtons();
    }

}
