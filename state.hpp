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

class State{
private:
    std::vector<sf::Texture*> textures;


public:
    State();
    virtual ~State();

    virtual void update() = 0;
    virtual void render() = 0;
};
