#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager{
public:
    /*
    * Default constructor and destructor
    */
    AssetManager(){}
    ~AssetManager(){}

    /*
    * Loads texture from fileName path and gives it a name
    */
    void loadTexture(std::string name, std::string fileName);
    /*
    * Returns requested texture
    */
    sf::Texture& getTexture(std::string name);

    /*
    * Loads font, same as loadTexture
    */
    void loadFont(std::string name, std::string fileName);
    /*
    * Returns requested font
    */
    sf::Font& getFont(std::string name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;

};
