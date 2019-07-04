#include <sstream>
#include <iostream>

#include "gamestate.hpp"
#include "DEFINITIONS.hpp"

GameState::GameState(GameDataRef data) : _data(data){}

void GameState::init(){
    gameState = STATE_PLAYING;

    this->_supportedKeys = this->_data->input.getKeys();
    this->initKeybinds();

    // Loading the assets
    this->_data->assets.loadTexture("Pause Button", PAUSE_BUTTON);


    // Setting the textures
    // Reusing the background
    _background.setTexture(this->_data->assets.getTexture("Background"));
    _pauseButton.setTexture(this->_data->assets.getTexture("Pause Button"));

    // Set position for pause button
    _pauseButton.setPosition(this->_data->window.getSize().x
        - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);


}

void GameState::initKeybinds(){
    /*this->keybinds["QUIT"] = this->_supportedKeys.at("Escape");
    this->keybinds["MOVE_LEFT"] = this->_supportedKeys.at("A");
    this->keybinds["MOVE_RIGHT"] = this->_supportedKeys.at("D");
    this->keybinds["MOVE_DOWN"] = this->_supportedKeys.at("S");
    this->keybinds["MOVE_UP"] = this->_supportedKeys.at("W");*/

    std::ifstream ifs("_config/gamestate_keybinds.ini");

    if(ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2)
            this->_keybinds[key] = this->_supportedKeys.at(key2);
    }

    ifs.close();

}

void GameState::handleInput(float dt){

    // Player movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_LEFT"))))
        this->player.move(dt, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.f, 1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_UP"))))
        this->player.move(dt, 0.f, -1.f);


    sf::Event event;

    // Check for events
    while(this->_data->window.pollEvent(event)){
        // Close event
        if(sf::Event::Closed == event.type)
            this->_data->window.close();

        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Key(this->_keybinds.at("QUIT")))
                this->_data->window.close();
        }

        // Check if pause button is clicked
        if(this->_data->input.isSpriteClicked(this->_pauseButton,
                sf::Mouse::Left, this->_data->window))
            std::cout << "Pause the game" << std::endl;


    }
}

void GameState::update(float dt){
    this->player.update(dt);
}

void GameState::draw(float dt){
    this->_data->window.clear();

    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_pauseButton);
    this->player.draw(this->_data->window);

    this->_data->window.display();
}
