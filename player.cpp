#include "player.hpp"

// Initialization functions
void Player::initVariables(){

}

void Player::initComponents(){
    this->createMovementComponent(250.f, 10.f, 4.f);
    this->createAnimationComponent(this->sprite, this->textureSheet);
}


Player::Player(float x, float y, sf::Texture& textureSheet){
    this->setTexture(textureSheet);
    this->setPosition(x, y);

    this->initVariables();
    this->initComponents();

    this->animationComponent->addAnimation("IDLE_LEFT", 100.f, 1, 1, 4, 1, 50, 37);
}

Player::~Player(){}
