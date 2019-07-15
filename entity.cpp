#include "entity.hpp"

// Initializers

void Entity::initVariables(){
    this->movementComponent = NULL;
    this->animationComponent = NULL;
    this->hitboxComponent = NULL;
}

Entity::Entity(){
    this->initVariables();
}

Entity::~Entity(){
    // Delete the saved sprite
    //delete this->sprite;
    delete this->movementComponent;
    delete this->animationComponent;
    delete this->hitboxComponent;
}

// Component functions

void Entity::createMovementComponent(const float maxVelocity,
    const float acceleration, const float deceleration){
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity,
         acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& textureSheet)
{
    this->animationComponent = new AnimationComponent(this->sprite, textureSheet);
}

void Entity::createHitboxComponent(sf::Sprite& sprite, float xOff, float yOff,
    float width, float height)
{
    this->hitboxComponent = new HitboxComponent(sprite, xOff, yOff,
        width, height);
}

void Entity::setTexture(sf::Texture& texture){
    this->sprite.setTexture(texture);
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

void Entity::render(sf::RenderTarget& target){
    target.draw(this->sprite);

    if(this->hitboxComponent)
        this->hitboxComponent->render(target);
}
