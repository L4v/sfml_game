#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class HitboxComponent{
private:
    sf::Sprite& sprite;
    sf::RectangleShape hitbox;

    float xOff, yOff;

public:

    /*
    * Constructor / destructor
    */
    HitboxComponent(sf::Sprite&,
        float, float,
        float, float);
    virtual ~HitboxComponent();

    // Functions
    bool checkIntersect(const sf::FloatRect&);

    void update();
    void render(sf::RenderTarget&);
};
