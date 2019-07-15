#include "pausemenu.hpp"

PauseMenu::PauseMenu(sf::RenderWindow& window){

    // Init background
    this->mBackground.setSize(
        sf::Vector2f(
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y))
        );
    this->mBackground.setFillColor(sf::Color(20, 20, 20, 100));

    // Init container
    this->mContainer.setSize(
        sf::Vector2f(
            static_cast<float>(window.getSize().x) / 4.f,
            static_cast<float>(window.getSize().y))
        );

    this->mContainer.setFillColor(sf::Color(20, 20, 20, 200));
    this->mContainer.setPosition(
        static_cast<float>(window.getSize().x) / 2.f
         - this->mContainer.getSize().x / 2.f, 0.f
        );

}

PauseMenu::~PauseMenu(){
    for(auto it = this->mButtons.begin(); it != this->mButtons.end(); ++it)
        delete it->second;
}

// Functions

void PauseMenu::update(){}

void PauseMenu::render(sf::RenderTarget& target){
    target.draw(mBackground);
    target.draw(mContainer);

    for(auto &i : this->mButtons){
        i.second->render(target);
    }
}
