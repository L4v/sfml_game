#include "movementcomponent.hpp"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity):
    sprite(sprite), maxVelocity(maxVelocity)
{
    
}

MovementComponent::~MovementComponent(){}

// Getters
const sf::Vector2f& MovementComponent::getVelocity() const{
    return this->velocity;
}

// Functions
void MovementComponent::move(const float& dt, const float x_dir, const float y_dir){
    this->velocity.x = this->maxVelocity * x_dir;
    this->velocity.y = this->maxVelocity * y_dir;

    this->sprite.move(this->velocity * dt); // Uses it

}

void MovementComponent::update(const float& dt){

}
