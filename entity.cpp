#include "entity.hpp"

// Initializers

void Entity::initVariables(){
    this->movementComponent = NULL;
}

Entity::Entity(){
    this->initVariables();
}

Entity::~Entity(){
    // Delete the saved sprite
    //delete this->sprite;
}

// Component functions
void Entity::setTexture(sf::Texture& texture){
    this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity){
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity);
}


void Entity::setPosition(const float x, const float y){
    this->sprite.setPosition(x, y);
}

void Entity::move(const float& dt, const float& x_dir, const float& y_dir){
    if(this->movementComponent){
        this->movementComponent->move(dt, x_dir, y_dir); // Sets velocity
    }

}

void Entity::update(const float& dt){
}

void Entity::render(sf::RenderTarget* target){
    target->draw(this->sprite);
}
