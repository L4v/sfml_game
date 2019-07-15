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


enum DIRECTION{
    LEFT = 0, RIGHT
};

class MovementComponent{
private:
    sf::Sprite& sprite;

    float maxVelocity;
    float acceleration;
    float deceleration;

    sf::Vector2f velocity;

    DIRECTION direction;
    // Initializer functions


public:

    MovementComponent(sf::Sprite& sprite, float maxVelocity,
        float acceleration, float deceleration);
    virtual ~MovementComponent();

    // Getters
    const float& getMaxVelocity() const;
    const sf::Vector2f& getVelocity() const;

    // Functions
    const bool idle() const;

    DIRECTION getDirection();
    void move(const float& dt, const float x_dir, const float y_dir);
    void update(const float& dt);
};
