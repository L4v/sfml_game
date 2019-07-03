#include "inputmanager.hpp"

bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
    sf::RenderWindow& window){
    if(sf::Mouse::isButtonPressed(button)){
        sf::IntRect tmpRect(object.getPosition().x, object.getPosition().y,
                            object.getGlobalBounds().width,
                            object.getGlobalBounds().height);

        if(tmpRect.contains(sf::Mouse::getPosition(window)))
            return true;
    }
    return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window){
    return sf::Mouse::getPosition(window);
}

void InputManager::initKeys(){
    this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
}

std::map<std::string, int>& InputManager::getKeys() { return this->supportedKeys; }
