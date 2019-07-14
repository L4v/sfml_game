#pragma once

#include "movementcomponent.hpp"
#include "animationcomponent.hpp"

class Entity{
private:
    // Initializers
    void initVariables();

protected:
    sf::Sprite sprite;

    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;

public:
    Entity();
    virtual ~Entity();

    // Component functions
    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float maxVelocity,
        const float acceleration, const float deceleration);
    void createAnimationComponent(sf::Sprite&, sf::Texture&);

    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float& x_dir, const float& y_dir);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};
