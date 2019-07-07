#include "entity.hpp"

// Initializers

void Entity::initVariables(){
    this->texture = NULL;
    this->sprite = NULL;
    this->movementSpeed = 100.f;
}

Entity::Entity(){
    this->initVariables();
}

Entity::~Entity(){
    // Delete the saved sprite
    delete this->sprite;
}

// Component functions
void Entity::createSprite(sf::Texture* texture){
    this->texture = texture;
    this->sprite = new sf::Sprite(*this->texture);
}

void Entity::setPosition(const float x, const float y){
    this->sprite->setPosition(x, y);
}

void Entity::move(const float& dt, const float& x_dir, const float& y_dir){
    if(this->sprite)
        this->sprite->move(x_dir * this->movementSpeed * dt,
            y_dir * this->movementSpeed * dt);

}

void Entity::update(const float& dt){
}

void Entity::render(sf::RenderTarget* target){
    if(this->sprite)
        target->draw(*this->sprite);
}
