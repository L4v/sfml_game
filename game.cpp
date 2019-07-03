#include "game.hpp"
#include "splashstate.hpp"
#include <iostream>

Game::Game(int width, int height, std::string title){
    this->_data->input.initKeys();
    _data->window.create(sf::VideoMode(width, height), title,
                        sf::Style::Close | sf::Style::Titlebar);
    _data->machine.addState(StateRef(new SplashState(this->_data)));


    this->run();
}

void Game::run(){
    float newTime, frameTime, interpolation;
    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while(this->_data->window.isOpen()){
        this->_data->machine.updateStateChanges();
        newTime = this->_clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if(frameTime > 0.25f) frameTime = 0.25f;

        currentTime = newTime;
        accumulator += frameTime;
        std::cout << frameTime << std::endl;


        while(accumulator > dt){
            this->_data->machine.getActiveState()->handleInput();
            this->_data->machine.getActiveState()->update(dt);

            accumulator -= dt;
            if(accumulator < 0) accumulator = 0;
        }

        interpolation = accumulator / dt;
        this->_data->machine.getActiveState()->draw(interpolation);
    }
}
