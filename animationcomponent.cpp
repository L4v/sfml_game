#include "animationcomponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite& sprite,
    sf::Texture& textureSheet)
    : sprite(sprite),
    textureSheet(textureSheet),
    lastAnimation(NULL),
    priorityAnimation(NULL)
    {}

AnimationComponent::~AnimationComponent(){
    for(auto &it : this->animations)
        delete it.second;
}

// Functions
void AnimationComponent::addAnimation(const std::string key,
    float animTimer, int start_frame_x,
    int start_frame_y,int frame_x, int frame_y,
    int width, int height, int maxFrame)
    {

    this->animations[key] = new Animation(this->sprite, this->textureSheet, animTimer,
        start_frame_x, start_frame_y, frame_x, frame_y, width, height, maxFrame);
}

void AnimationComponent::AnimationComponent::play(const std::string key,
    const float& dt, const bool priority, const bool toFlip)
{
    // Resetting the last animation
    if(this->lastAnimation != this->animations[key]){
        if(!this->lastAnimation)
            this->lastAnimation = this->animations[key];
        this->lastAnimation->reset();
        this->lastAnimation = this->animations[key];
    }
    this->animations[key]->flip(toFlip);
    this->animations[key]->play(dt);
}

void AnimationComponent::AnimationComponent::play(const std::string key,
    const float& dt, const float& modifier, const float& modifierMax,
    const bool priority, const bool toFlip)
{
    // Resetting the last animation
    if(this->lastAnimation != this->animations[key]){
        if(!this->lastAnimation)
            this->lastAnimation = this->animations[key];
        this->lastAnimation->reset();
        this->lastAnimation = this->animations[key];
    }
    this->animations[key]->flip(toFlip);
    this->animations[key]->play(dt, modifier / modifierMax);
}
