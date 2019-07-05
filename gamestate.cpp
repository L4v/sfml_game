#include "gamestate.hpp"

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

GameState::GameState(sf::RenderWindow* window,
    std::map<std::string, int>* supportedKeys) : State(window, supportedKeys){
    this->initKeybinds();
}

GameState::~GameState(){}

void GameState::endState(){
    std::cout << "Ending gamestate" << std::endl;
}

void GameState::updateInput(const float& dt){
    this->checkForQuit();

    // Update player inptu
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.move(dt, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.f, 1.f);
}

void GameState::update(const float& dt){
    this->updateMousePositions();
    this->updateInput(dt);

    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;

    this->player.render(this->window);

}
