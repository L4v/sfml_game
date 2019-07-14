#import "animationcomponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite& sprite,
    sf::Texture& textureSheet)
    : sprite(sprite),
    textureSheet(textureSheet)
    {}

AnimationComponent::~AnimationComponent(){
    for(auto *it : this->animations)
        delete i.second;
}

// Functions
void addAnimation(const std::string key,
    float animTimer, int start_frame_x,
    int start_frame_y,int frame_x, int frame_y,
    int width, int height)
    {

    this->animations[key] = new Animation(this->sprite, this->textureSheet, animTimer,
        start_frame_x, start_frame_y, frame_x, frame_y, width, height);
}

void AnimationComponent::play(const std::string key, const float& dt){
    this->animations[key]->play(dt);
}
