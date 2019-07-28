#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>


class Tilemap{
private:
    // TEST
    std::vector<sf::Sprite> mSprites;

    sf::Texture mAtlas; // Tile atlas, main texture for all the tiles
    std::vector<int> mTiles; // Contains tile ids
    int mWidth; // How many tiles in width
    int mHeight; // How many tiles in height
    int mTileSize; // The size of one side of the tile square

public:
    /*
    * Constructor and destructor
    */
    Tilemap(int width = 10, int height = 10);
    virtual ~Tilemap();

    void update(const float& dt);
    void render(sf::RenderTarget&);
};

#endif
