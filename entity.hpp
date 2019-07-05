#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

class Entity{
protected:
    sf::RectangleShape shape; // Placeholder

    float movementSpeed;

public:
    Entity();
    virtual ~Entity();

    virtual void move(const float& dt, const float& x_dir, const float& y_dir);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};
