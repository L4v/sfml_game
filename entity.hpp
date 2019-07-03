#pragma once
#include <SFML/Graphics.hpp>

class Entity{
public:
    /*
    * Default constructor and destructor
    */
    Entity();
    ~Entity();

    virtual void move(float& dt, float x_offset, float y_offset);

    virtual void update(float& dt);
    virtual void draw(sf::RenderTarget& target);

protected:
    bool _isAlive;

    int _hp;

    float _x, _y;
    float _movementSpeed;

    sf::RectangleShape _box;
};
