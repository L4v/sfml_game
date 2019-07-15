#include "hitboxcomponent.hpp"

HitboxComponent::HitboxComponent(sf::Sprite& sprite,
    float xOff, float yOff,
    float width, float height)
    : sprite(sprite), xOff(xOff), yOff(yOff)
{
    this->hitbox.setPosition(this->sprite.getPosition().x + xOff,
        this->sprite.getPosition().y + yOff);
    this->hitbox.setSize(sf::Vector2f(width, height));
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineThickness(1.f);
    this->hitbox.setOutlineColor(sf::Color::Green);
}

HitboxComponent::~HitboxComponent(){}

bool HitboxComponent::checkIntersect(const sf::FloatRect& frect){
    return this->hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::update(){
    this->hitbox.setPosition(this->sprite.getPosition().x + this->xOff,
        this->sprite.getPosition().y + this->yOff);
}

void HitboxComponent::render(sf::RenderTarget& target){
    target.draw(this->hitbox);
}
