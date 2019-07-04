#pragma once

#include "entity.hpp"

class Player : public Entity{
public:
    Player(int hp = 100, float movementSpeed = 50.f,
        const sf::RectangleShape& box = sf::RectangleShape(sf::Vector2f(
            DEFAULT_ENTITY_HEIGHT,
            DEFAULT_ENTITY_WIDTH)));
};

    void move(float& dt, float x_offset, float y_offset);

    void update(float& dt);
    void draw(sf::RenderTarget& target);

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
