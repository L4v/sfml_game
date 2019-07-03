#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"

class Entity{
public:
    /*
    * Default constructor and destructor
    */
    Entity(int hp = 100, float movementSpeed = 50.f,
        const sf::RectangleShape& box = sf::RectangleShape(sf::Vector2f(
            DEFAULT_ENTITY_HEIGHT,
            DEFAULT_ENTITY_WIDTH
        )));
    ~Entity();

    virtual void move(float& dt, float x_offset, float y_offset);

    virtual void update(float& dt);
    virtual void draw(sf::RenderTarget& target);

protected:
    bool _isAlive;

    int _hp;

    float _movementSpeed;

    sf::RectangleShape _box;
};
