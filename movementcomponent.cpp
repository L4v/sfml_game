#include "movementcomponent.hpp"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity,
    float acceleration, float deceleration):
    sprite(sprite), maxVelocity(maxVelocity),
    acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent(){}

// Getters
const sf::Vector2f& MovementComponent::getVelocity() const{
    return this->velocity;
}

// Functions
void MovementComponent::move(const float& dt, const float x_dir, const float y_dir){
    // Acceleration
    this->velocity.x += this->acceleration * x_dir;

    // Check for right movement max velocity
    if(this->velocity.x > 0.f){
        if(this->velocity.x > this->maxVelocity)
            this->velocity.x = this->maxVelocity;
    // Check for left movement max velocity
    } else if(this->velocity.x < 0.f){
        if(-this->velocity.x > -this->maxVelocity)
            this->velocity.x = -this->maxVelocity;
    }
    this->velocity.y += this->acceleration * y_dir;

    // Check for down movement max velocity
    if(this->velocity.y > 0.f){
        if(this->velocity.y > this->maxVelocity)
            this->velocity.y = this->maxVelocity;
    // Check for up movement max velocity
    } else if(this->velocity < 0.f){
        if(-this->velocity.y > -this->maxVelocity)
            this->velocity.y = -this->maxVelocity;
    }

}

void MovementComponent::update(const float& dt){
    // Deceleration

    // Right direction
    if(this->velocity.x > 0.f){
        this->velocity.x -= deceleration;
        if(this->velocity.x < 0.f)
            this->velocity.x = 0.f;

    // Left direction
    }else if(this->velocity.x < 0.f){
        this->velocity.x += deceleration;
        if(this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }

    // Final move
    this->sprite.move(this->velocity * dt);

}
