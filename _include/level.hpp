#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>



class Level{
private:
    // TEST
    std::vector<sf::Sprite> mSprites;

    sf::Texture mAtlas; // Tile atlas, main texture for all the tiles
    std::vector<int> mMap; // Contains tile ids
    int mWidth; // How many tiles in width
    int mHeight; // How many tiles in height
    int mTileSize; // The size of one side of the tile square

public:
    /*
    * Constructor and destructor
    */
    Level(int width = 10, int height = 10); // In tiles
    virtual ~Level();

    void update(const float& dt);
    void render(sf::RenderTarget&);
};

#endif
