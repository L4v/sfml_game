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
    std::ifstream ifs("_config/supported_keys.ini");

    if(ifs.is_open()){
        std::string key = "";
        int key_value = 0;

        while(ifs >> key >> key_value)
            this->_supportedKeys[key] = key_value;
    }

    ifs.close();
}

std::map<std::string, int>& InputManager::getKeys() { return this->_supportedKeys; }
