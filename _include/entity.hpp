#pragma once

#include "movementcomponent.hpp"
#include "animationcomponent.hpp"
#include "hitboxcomponent.hpp"

class Entity{
private:
    // Initializers
    void initVariables();

protected:
    sf::Sprite sprite;

    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;
    HitboxComponent* hitboxComponent;

public:
    Entity();
    virtual ~Entity();

    // Functions
    void setTexture(sf::Texture& texture);

    // Component functions

    /*
    * Creates the MovementComponent
    */
    void createMovementComponent(const float maxVelocity,
        const float acceleration, const float deceleration);

    /*
    * Creates the AnimationComponent
    */
    void createAnimationComponent(sf::Texture&);

    /*
    * Creates the HitboxComponent
    */
    void createHitboxComponent(sf::Sprite&, float, float, float, float);

    // Virtual stuff
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float& x_dir, const float& y_dir);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget&);
};
