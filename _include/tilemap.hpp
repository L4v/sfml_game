#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

struct Tile{
    int mId;
    sf::IntRect mRect;
    sf::Sprite mSprite;
};

class Tilemap{
private:
    sf::Texture& mAtlas; // Tile atlas, main texture for all the tiles
    std::vector<Tile> mTiles;
    int mWidth, mHeight; // Width and height of the atlas
    int mTileSize; // The size of one side of the tile square

public:
    /*
    * Constructor and destructor
    */
    Tilemap(int width = 10, int height = 10);
    virtual ~Tilemap();

    void update(const float& dt);
    void render(sf::RenderTarget);
};

#endif
