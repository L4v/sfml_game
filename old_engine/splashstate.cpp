#include <sstream>
#include <iostream>

#include "splashstate.hpp"
#include "mainmenustate.hpp"
#include "DEFINITIONS.hpp"

SplashState::SplashState(GameDataRef data) : _data(data){}

void SplashState::init(){
    this->_data->assets.loadTexture("Splash State Background",
                            SPLASH_SCENE_BACKGROUND_FILEPATH);
    _background.setTexture(
            this->_data->assets.getTexture("Splash State Background"));
}

void SplashState::handleInput(float dt){
    sf::Event event;

    while(this->_data->window.pollEvent(event)){
        if(sf::Event::Closed == event.type)
            this->_data->window.close();

    }
}

void SplashState::update(float dt){
    if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        // TODO : Switch to main menu
        this->_data->machine.addState(StateRef(new MainMenuState(_data)), true);
}

void SplashState::draw(float dt){
    this->_data->window.clear(sf::Color::Red);
    this->_data->window.draw(this->_background);
    this->_data->window.display();
}

void SplashState::initKeybinds(){}
