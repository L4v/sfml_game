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

// Getters

const bool& AnimationComponent::isDone(const std::string key){
    return this->animations[key]->isDone();
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

    // Checks to see if the current animation is a priority
    if(this->priorityAnimation){
        if(this->priorityAnimation == this->animations[key]){
            if(this->lastAnimation != this->animations[key]){
                if(!this->lastAnimation)
                    this->lastAnimation = this->animations[key];
                else{
                    this->lastAnimation->reset();
                    this->lastAnimation = this->animations[key];
                }
            }
            this->animations[key]->flip(toFlip);

            // If the priority animation is done, remove it
            if(this->animations[key]->play(dt))
                this->priorityAnimation = NULL;
        }
    // Else play the other animation
    }else{
        // If the animation is a priority, sets it as such
        if(priority)
            this->priorityAnimation = this->animations[key];
        // Resetting the last animation
        if(this->lastAnimation != this->animations[key]){
            if(!this->lastAnimation)
                this->lastAnimation = this->animations[key];
            this->lastAnimation->reset();
            this->lastAnimation = this->animations[key];
        }
        this->animations[key]->flip(toFlip);

        // If the priority animation is done, remove it
        if(this->animations[key]->play(dt))
            this->priorityAnimation = NULL;

    }
}

void AnimationComponent::AnimationComponent::play(const std::string key,
    const float& dt, const float& modifier, const float& modifierMax,
    const bool priority, const bool toFlip)
{
    // Checks to see if the current animation is a priority
    if(this->priorityAnimation){
        if(this->priorityAnimation == this->animations[key]){
            if(this->lastAnimation != this->animations[key]){
                if(!this->lastAnimation)
                    this->lastAnimation = this->animations[key];
                else{
                    this->lastAnimation->reset();
                    this->lastAnimation = this->animations[key];
                }
            }
            this->animations[key]->flip(toFlip);
            // If the priority animation is done, removes it
            if(this->animations[key]->play(dt, modifier / modifierMax))
                this->priorityAnimation = NULL;
        }
    // Else play the other animation
    }else{
        // If the animation is a priority, sets it as such
        if(priority)
            this->priorityAnimation = this->animations[key];
    // Resetting the last animation
        if(this->lastAnimation != this->animations[key]){
            if(!this->lastAnimation)
                this->lastAnimation = this->animations[key];
            else{
            this->lastAnimation->reset();
            this->lastAnimation = this->animations[key];
            }
        }
        this->animations[key]->flip(toFlip);

        // If the priority animation is done, removes it
        if(this->animations[key]->play(dt, modifier / modifierMax))
            this->priorityAnimation = NULL;
    }
}
