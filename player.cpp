#include "player.hpp"

// Initialization functions
void Player::initVariables(){

}

void Player::initComponents(){
    this->createMovementComponent(100.f);
}


Player::Player(float x, float y, sf::Texture& texture){
    this->initVariables();
    this->initComponents();

    this->setTexture(texture);
    this->setPosition(x, y);
}

Player::~Player(){}
