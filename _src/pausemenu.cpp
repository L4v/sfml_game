#include "pausemenu.hpp"

PauseMenu::PauseMenu(sf::RenderWindow& window, sf::Font& font)
    : mFont(font)
{

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

    // Init text
    this->mMenuText.setFont(font);
    this->mMenuText.setFillColor(sf::Color(255, 255, 255, 200));
    this->mMenuText.setCharacterSize(64);
    this->mMenuText.setString("PAUSED");
    this->mMenuText.setPosition(
        this->mContainer.getPosition().x + this->mContainer.getSize().x / 2.f
            -this->mMenuText.getGlobalBounds().width / 2.f,
        this->mContainer.getPosition().y + 20.f
    );

}

PauseMenu::~PauseMenu(){
    for(auto it = this->mButtons.begin(); it != this->mButtons.end(); ++it)
        delete it->second;
}

// Getters and setters

std::map<std::string, Button*>& PauseMenu::getButtons(){ return this->mButtons; }

void PauseMenu::addButton(std::string key, std::string key2,
    float y, std::string text)
{

    float width = 150.f;
    float height = 50.f;
    float x = this->mContainer.getPosition().x
        + this->mContainer.getSize().x / 2.f - width / 2.f;
    float margin = 20.f;
    if(key2 != ""){
        this->mButtons[key] = new Button(
            x,
            this->mButtons[key2]->getShape().getPosition().y
                + this->mButtons[key2]->getShape().getSize().y + margin,//this->background.getSize().y * 5 / 8,
            150, 50,
            &this->mFont, text, 24,
            sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),
            sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));
    }else{
        this->mButtons[key] = new Button(
            x,
            y == 0 ? (this->mMenuText.getGlobalBounds().width + margin) : y,
            150, 50,
            &this->mFont, text, 24,
            sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),
            sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0));
    }
}

// Functions

const bool PauseMenu::isButtonPressed(const std::string key){
    return this->mButtons[key]->isPressed();
}

void PauseMenu::update(const sf::Vector2f& mousePos){
    for(auto &it : this->mButtons)
        it.second->update(mousePos);
}

void PauseMenu::render(sf::RenderTarget& target){
    target.draw(this->mBackground);
    target.draw(this->mContainer);

    for(auto &i : this->mButtons){
        i.second->render(target);
    }
    target.draw(this->mMenuText);
}
