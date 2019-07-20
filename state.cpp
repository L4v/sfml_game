#include "state.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
            std::stack<State*>* states)
    : window(window), supportedKeys(supportedKeys), states(states), quit(false),
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
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(
            sf::Mouse::getPosition(*this->window));

}

void State::Update(const float& dt){
    if(this->mKeytime < this->mKeytimeMax)
        this->mKeytime += 10.f * dt;
}
