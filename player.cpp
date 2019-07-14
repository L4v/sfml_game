#include "player.hpp"

// Initialization functions
void Player::initVariables(){

}

void Player::initComponents(){
    this->createMovementComponent(250.f, 10.f, 4.f);
}


Player::Player(float x, float y, sf::Texture& textureSheet){
    this->setPosition(x, y);

    this->initVariables();
    this->initComponents();

    this->createAnimationComponent(textureSheet);
    this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 3, 0, 50, 37);
    this->animationComponent->addAnimation("WALK", 10.f, 1, 1, 6, 1, 50, 37);
}

Player::~Player(){}

// Functions

void Player::update(const float& dt){
    this->movementComponent->update(dt);

    if(this->movementComponent->idle())
        this->animationComponent->play("IDLE", dt,
            this->movementComponent->getDirection() == LEFT ? true : false);
    else
        this->animationComponent->play("WALK", dt,
            this->movementComponent->getDirection() == LEFT ? true : false);
}
