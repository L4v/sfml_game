#include "state.hpp"

State::State(GameDataRef data)
    : mData(data), quit(false),
    mPaused(false), mKeytime(0.f), mKeytimeMax(10.f)
{

}

State::~State(){}

// Getters and setters

const bool& State::getQuit() const{
    return this->quit;
}

const bool State::getKeytime(){
    if(this->mKeytime >= this->mKeytimeMax){
        this->mKeytime = 0.f;
        return true;
    }
    return false;
}

// Functions

void State::endState(){
    this->quit = true;
}

void State::pauseState(){ this->mPaused = true; }

void State::resumeState(){ this->mPaused = false; }

void State::updateMousePositions(){
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->mData->window);
    this->mousePosView = this->mData->window->mapPixelToCoords(
            sf::Mouse::getPosition(*this->mData->window));

}

void State::updateKeytime(const float& dt){
    if(this->mKeytime < this->mKeytimeMax)
        this->mKeytime += 50.f * dt;
}
