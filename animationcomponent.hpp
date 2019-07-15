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
        int width, height, maxFrame;
        float animTimer, timer;
        bool flipped;

        Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
            float animTimer, int start_frame_x, int start_frame_y,int frame_x, int frame_y,
            int width, int height, int maxFrame)
            : sprite(sprite),
            textureSheet(textureSheet),
            animTimer(animTimer),
            width(width),
            height(height),
            maxFrame(maxFrame){
            flipped = false;
            this->timer = 0;
            this->startRect = sf::IntRect(start_frame_x * width, start_frame_y
                 * height, width, height);
            this->currRect = this->startRect;
            this->endRect = sf::IntRect(frame_x * width, frame_y * height,
                width, height);

            // Sets the texture of the sprite to the whole sprite
            this->sprite.setTexture(this->textureSheet, true);
            // Sets the rectangle to the first frame of the animation
            this->sprite.setTextureRect(this->startRect);

        }
        virtual ~Animation(){

        }

        // Functions

        /*
        * Flips the sprite vertically
        */
        void flip(bool toFlip){
            if(toFlip && !flipped){
                sprite.setOrigin({ sprite.getLocalBounds().width, 0 });
                sprite.setScale({ -1, 1 });
                this->flipped = true;
            }else if(!toFlip && flipped){
                sprite.setOrigin({ 0, 0 });
                sprite.setScale({ 1, 1 });
                this->flipped = false;
            }
        }

        /*
        * Plays the animation
        */
        void play(const float& dt)
        {
            // TODO : Make it nicer
            // Update timer
            // Timer with completion percentage using modifier
            this->timer += 100.f * dt;
            if(this->timer >= animTimer){
                // Resets timer
                this->timer = 0.f;

                // Animate
                // TODO : Optimize, check only one side, instead of whole rect
                if(this->currRect.left != this->endRect.left
                    && this->currRect.left != this->maxFrame*this->width){
                    // While on same height, go right
                    this->currRect.left += this->width;

                // Check if at end on horizontal
                }else if(this->currRect.left == this->endRect.left
                    || this->currRect.left == this->maxFrame*this->width){
                    // Check if the animation wraps on lower part of sheet
                    if(this->currRect.top == this->endRect.top){
                        // Reset
                        this->currRect = this->startRect;
                    }else{
                        // Wrap
                        this->currRect.top += this->height;
                        this->currRect.left = 0;
                    }
                }
                this->sprite.setTextureRect(this->currRect);
            }
        }

        /*
        * Plays the animation using the speed modifier
        */
        void play(const float& dt, const float& percentage)
        {
            // TODO : Make it nicer
            // Update timer

            this->timer += (percentage < 0.5f ? 0.5f : percentage) * 100.f * dt;
            if(this->timer >= animTimer){
                // Resets timer
                this->timer = 0.f;

                // Animate
                // TODO : Optimize, check only one side, instead of whole rect
                if(this->currRect.left != this->endRect.left
                    && this->currRect.left != this->maxFrame*this->width){
                    // While on same height, go right
                    this->currRect.left += this->width;

                // Check if at end on horizontal
                }else if(this->currRect.left == this->endRect.left
                    || this->currRect.left == this->maxFrame*this->width){
                    // Check if the animation wraps on lower part of sheet
                    if(this->currRect.top == this->endRect.top){
                        // Reset
                        this->currRect = this->startRect;
                    }else{
                        // Wrap
                        this->currRect.top += this->height;
                        this->currRect.left = 0;
                    }
                }
                this->sprite.setTextureRect(this->currRect);
            }
        }
        //void play();

        /*
        * Pauses the animation
        */
        //void pause();

        /*
        * Resets the animation
        */
        void reset(){
            this->timer = this->animTimer;
            this->currRect = this->startRect;
        }

    };


    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    // Map for handling animations
    std::map<std::string, Animation*> animations;
    Animation* lastAnimation;
    Animation* priorityAnimation;

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
    void addAnimation(const std::string, float,int, int, int, int, int, int, int);

    /*
    * Starts the appropriate animation
    */
    //void startAnimation(const std::string animation);

    /*
    * Pauses the appropriate animation
    */
    //void pauseAnimation(const std::string animation);

    /*
    * Resets the appropriate animation
    */
    //void resetAnimation(const std::string animation);

    /*
    * Plays specific animation
    */
    void play(const std::string, const float&, const bool priority = false,
        bool toFlip = false);
    void play(const std::string, const float&, const float&, const float&,
        const bool priority = false, const bool toFlip = false);

};
