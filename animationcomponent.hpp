#pragma once

#include <iostream>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>


class AnimationComponent{
private:
    /*
    * Private helper class for handling animations
    */
    class Animation{
    public:
        // Variables
        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        sf::IntRect startRect, endRect, currRect;
        int width, height;
        float animTimer, timer;

        Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
            float animTimer, int start_x, int start_y,int end_x, int end_y,
            int width, int height)
            : sprite(sprite),
            textureSheet(textureSheet),
            animTimer(animTimer),
            width(width),
            height(height)
        {
            this->startRect = sf::IntRect(start_x, start_y, width, height);
            this->currRect = this->startRect;
            this->endRect = sf::IntRect(end_x, end_y, width, height);

            // Sets the texture of the sprite to the whole sprite
            this->sprite.setTexture(this->textureSheet, true);
            // Sets the rectangle to the first frame of the animation
            this->sprite.setTextureRect(this->startRect);

        }
        virtual ~Animation();

        // Functions

        /*
        * Handles the updates
        */
        void update(const float& dt){

            // TODO : Make it nicer
            // Update timer
            this->timer = 10.f * dt;
            if(this->timer >= animTimer){
                // Resets timer
                this->timer = 0.f;

                // Animate
                // TODO : Optimize, check only one side, instead of whole rect
                if(this->currRect != this->endRect){
                    this->currRect.left += this->width;
                // Reset
                }else{
                    this->currRect.left = this->startRect.left;
                }
            }
        }
        //void play();

        /*
        * Pauses the animation
        */
        void pause();

        /*
        * Resets the animation
        */
        void reset();

    };


    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    // Map for handling animations
    std::map<std::string, Animation> animations;

public:


    /*
    * Constructor and destructor
    */
    AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
    virtual ~AnimationComponent();

    // Functions

    /*
    * Adds an animation
    */
    void addAnimation(const std::string key);

    /*
    * Starts the appropriate animation
    */
    void startAnimation(const std::string animation);

    /*
    * Pauses the appropriate animation
    */
    void pauseAnimation(const std::string animation);

    /*
    * Resets the appropriate animation
    */
    void resetAnimation(const std::string animation);

    /*
    * Updates all animations
    */
    void update(const float& dt);
};
