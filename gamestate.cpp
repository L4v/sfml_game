#include "gamestate.hpp"

// Initializer functions

void GameState::initKeybinds(){
    // Fetches the adequate keybinds for the state
    std::ifstream ifs("_config/gamestate_keybinds.ini");

    if(ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2)
            this->keybinds[key] = this->supportedKeys->at(key2);
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

GameState::GameState(sf::RenderWindow* window,
    std::map<std::string, int>* supportedKeys, std::stack<State*>* states) :
    State(window, supportedKeys, states), mPmenu(*window){
    this->initKeybinds();
    this->initTextures();
    this->initPlayers();
}

GameState::~GameState(){
    delete this->player;
}

void GameState::updateInput(const float& dt){

    // Update player inptu
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player->move(dt, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player->move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player->move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player->move(dt, 0.f, 1.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
        if(!this->mPaused)
            this->pauseState();
        // else
        //     this->resumeState();
}

void GameState::update(const float& dt){

    if(!this->mPaused){ // Unpaused update
        this->updateMousePositions();
        this->updateInput(dt);

        this->player->update(dt);
    }else{ // Paused update
        this->mPmenu.update();
    }
}

void GameState::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;

    this->player->render(*target);
    // Pause menu render
    if(this->mPaused){
        this->mPmenu.render(*target);
    }

}
