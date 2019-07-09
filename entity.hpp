#pragma once

#include "movementcomponent.hpp"

class Entity{
private:
    // Initializers
    void initVariables();

protected:
    sf::Sprite sprite;

    MovementComponent* movementComponent;

public:
    Entity();
    virtual ~Entity();

    // Component functions
    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float maxVelocity,
        const float acceleration, const float deceleration);

    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float& x_dir, const float& y_dir);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};
