#include "state.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
            std::stack<State*>* states)
    : window(window), supportedKeys(supportedKeys), states(states), quit(false),
    mPaused(false)
{

}

State::~State(){}

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

const bool& State::getQuit() const{
    return this->quit;
}
