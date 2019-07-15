#include "player.hpp"

// Initialization functions
void Player::initVariables(){

}

void Player::initComponents(){
}


Player::Player(float x, float y, sf::Texture& textureSheet){
    this->setPosition(x, y);

    this->initVariables();
    this->initComponents();

    this->createHitboxComponent(this->sprite, 17.f, 7.f, 16.f, 29.f); // Temp hardcode
    this->createMovementComponent(250.f, 10.f, 4.f);
    this->createAnimationComponent(textureSheet);

    this->animationComponent->addAnimation("IDLE", 20.f, 0, 0, 3, 0, 50, 37, 6);
    this->animationComponent->addAnimation("WALK", 10.f, 1, 1, 6, 1, 50, 37, 6);
    this->animationComponent->addAnimation("ATTACK", 10.f, 5, 6, 3, 7, 50, 37, 6);
}

Player::~Player(){}

// Functions

void Player::update(const float& dt){
    this->movementComponent->update(dt);

    if(this->movementComponent->idle())
        this->animationComponent->play("IDLE", dt,
            false,
            this->movementComponent->getDirection() == LEFT ? true : false);
    else
        this->animationComponent->play("WALK", dt,
            std::abs(this->movementComponent->getVelocity().x),
            std::abs(this->movementComponent->getMaxVelocity()),
            false,
            this->movementComponent->getDirection() == LEFT ? true : false);

    this->hitboxComponent->update();
}
