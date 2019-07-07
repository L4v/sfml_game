#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

class Entity{
private:
    // Initializers
    void initVariables();

protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

    float movementSpeed;

public:
    Entity();
    virtual ~Entity();

    // Component functions
    void createSprite(sf::Texture* texture);

    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float& x_dir, const float& y_dir);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};
