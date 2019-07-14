#include "movementcomponent.hpp"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity,
    float acceleration, float deceleration):
    sprite(sprite), maxVelocity(maxVelocity),
    acceleration(acceleration), deceleration(deceleration),
    direction(RIGHT)
{

}

MovementComponent::~MovementComponent(){}

// Getters
const sf::Vector2f& MovementComponent::getVelocity() const{
    return this->velocity;
}

// Functions

const bool MovementComponent::idle() const{
    // Usually bad practice to compare floats to exact 0, but here we set them
    if(this->velocity.x == 0.f && this->velocity.y == 0.f)
        return true;
    else
        return false;
}

DIRECTION MovementComponent::getDirection(){ return this->direction; }

void MovementComponent::move(const float& dt, const float x_dir, const float y_dir){
    // Acceleration

    this->velocity.x += this->acceleration * x_dir;
    this->velocity.y += this->acceleration * y_dir;

}

void MovementComponent::update(const float& dt){

    this->direction = this->velocity.x > 0.f ? RIGHT
        : this->velocity.x == 0 ? this->direction : LEFT;

    // Max velocity check

    // Check for right movement max velocity
    if(this->velocity.x > 0.f){
        if(this->velocity.x > this->maxVelocity){
            this->velocity.x = this->maxVelocity;
        }
        // Check for left movement max velocity
    } else if(this->velocity.x < 0.f){
        if(this->velocity.x < -this->maxVelocity)
            this->velocity.x = -this->maxVelocity;
    }

    // Check for down movement max velocity
    if(this->velocity.y > 0.f){
        if(this->velocity.y > this->maxVelocity){
            this->velocity.y = this->maxVelocity;
        }
        // Check for up movement max velocity
    } else if(this->velocity.y < 0.f){
        if(this->velocity.y < -this->maxVelocity)
            this->velocity.y = -this->maxVelocity;
    }

    // Deceleration

    // Right direction
    if(this->velocity.x > 0.f){
        this->velocity.x -= deceleration;
        if(this->velocity.x < 0.f){
            this->velocity.x = 0.f;
        }

    // Left direction
    }else if(this->velocity.x < 0.f){
        this->velocity.x += deceleration;
        if(this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }

    // Down direction
    if(this->velocity.y > 0.f){
        this->velocity.y -= deceleration;
        if(this->velocity.y < 0.f){
            this->velocity.y = 0.f;
        }

    // Up direction
    }else if(this->velocity.y < 0.f){
        this->velocity.y += deceleration;
        if(this->velocity.y > 0.f)
            this->velocity.y = 0.f;
    }

    // Final move
    this->sprite.move(this->velocity * dt);

}
