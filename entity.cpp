#include "entity.hpp"

Entity::Entity()
{
    this->_isAlive = true;
    this->_movementSpeed = 500.f;

    this->_box.setSize(sf::Vector2f(50.f, 50.f));
    this->_box.setFillColor(sf::Color::Red);
}

Entity::~Entity(){}

void Entity::move(float& dt, float x_offset, float y_offset){
    this->_box.move(x_offset * this->_movementSpeed * dt,
            y_offset * this->_movementSpeed * dt);
}

void Entity::update(float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->move(dt, -1.f, 0.f);
}

void Entity::draw(sf::RenderTarget& target){
    target.draw(this->_box);
}
