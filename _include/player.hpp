#pragma once

#include "entity.hpp"

class Player : public Entity{
private:
    // Variables
    bool mAttacking;

    // Initialization functions
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, sf::Texture& textureSheet);
    virtual ~Player();

    // Functions
    void updateAttack();
    void updateAnimations(const float&);
    void update(const float&);
};
