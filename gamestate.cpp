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
    this->keybinds.emplace("MOVE_LEFT", this->_supportedKeys.at("A"));
    this->keybinds.emplace("MOVE_RIGHT", this->_supportedKeys.at("D"));
    this->keybinds.emplace("MOVE_DOWN", this->_supportedKeys.at("S"));
    this->keybinds.emplace("MOVE_UP", this->_supportedKeys.at("W"));
}

void GameState::handleInput(float dt){
    sf::Event event;

    // Check for events
    while(this->_data->window.pollEvent(event)){
        // Close event
        if(sf::Event::Closed == event.type)
            this->_data->window.close();

        // Check if pause button is clicked
        if(this->_data->input.isSpriteClicked(this->_pauseButton,
                sf::Mouse::Left, this->_data->window))
            std::cout << "Pause the game" << std::endl;


    }

    // TODO : IMPLEMENT KEYBOARD EVENT THROUGH KEYBIND
    //https://www.youtube.com/watch?v=se3nCCxH2Aw&list=PL6xSOsbVA1ebkU66okpi-KViAO8_9DJKg&index=9

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
