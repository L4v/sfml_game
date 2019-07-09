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

class MovementComponent{
private:
    sf::Sprite& sprite;

    float maxVelocity;
    float acceleration;
    float deceleration;

    sf::Vector2f velocity;
    // Initializer functions

public:

    MovementComponent(sf::Sprite& sprite, float maxVelocity,
        float acceleration, float deceleration);
    virtual ~MovementComponent();

    // Getters
    const sf::Vector2f& getVelocity() const;

    // Functions
    void move(const float& dt, const float x_dir, const float y_dir);
    void update(const float& dt);
};
