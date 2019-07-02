#include <sstream>
#include <iostream>

#include "gamestate.hpp"
#include "DEFINITIONS.hpp"

GameState::GameState(GameDataRef data) : _data(data){}

void GameState::init(){
    gameState = STATE_PLAYING;

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

void GameState::handleInput(){
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
}

void GameState::update(float dt){

}

void GameState::draw(float dt){
    this->_data->window.clear();

    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_pauseButton);

    this->_data->window.display();
}
