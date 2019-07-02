#include <sstream>
#include <iostream>

#include "mainmenustate.hpp"
#include "DEFINITIONS.hpp"

MainMenuState::MainMenuState(GameDataRef data) : _data(data){}

void MainMenuState::init(){
    // Loading the assets
    this->_data->assets.loadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
    this->_data->assets.loadTexture("Game Title", MAIN_MENU_TITLE_PATH);
    this->_data->assets.loadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);

    // Setting the textures
    this->_background.setTexture(this->_data->assets.getTexture("Background"));
    this->_title.setTexture(this->_data->assets.getTexture("Game Title"));
    this->_playButton.setTexture(this->_data->assets.getTexture("Play Button"));

    // Center play button
    this->_playButton.setPosition((SCREEN_WIDTH / 2)
        - this->_playButton.getGlobalBounds().width / 2,
        (SCREEN_HEIGHT / 2) - this->_playButton.getGlobalBounds().height / 2);

    // Title bar centered on x-axis and put on top of the screen
    this->_title.setPosition((SCREEN_WIDTH / 2)
        - this->_title.getGlobalBounds().width / 2,
        this->_title.getGlobalBounds().height * 0.1);
}

void MainMenuState::handleInput(){
    sf::Event event;

    // Check for events
    while(this->_data->window.pollEvent(event)){
        // Close event
        if(sf::Event::Closed == event.type)
            this->_data->window.close();

        // Check if the play button sprite is clicked
        if(this->_data->input.isSpriteClicked(this->_playButton,
            sf::Mouse::Left, this->_data->window))
            // TODO : switch to Game Screen
            std::cout << "Go to Game Screen" << std::endl;

    }
}

void MainMenuState::update(float dt){

}

void MainMenuState::draw(float dt){
    this->_data->window.clear();

    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_playButton);
    this->_data->window.draw(this->_title);

    this->_data->window.display();
}
