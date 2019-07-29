#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

struct spawn_pos{
    int x;
    int y;
};

class Level{
private:
    // TEST
    sf::Sprite* mSprites;
    int* mMap; // Contains tile ids
    spawn_pos mPlayerSpawn;

    sf::Texture mAtlas; // Tile atlas, main texture for all the tiles

    int mX; // Top left x coordinate of level
    int mY; // Top left y coordinate of level
    int mWidth; // How many tiles in width
    int mHeight; // How many tiles in height
    int mTileSize; // The size of one side of the tile square

    inline size_t index(int, int);

public:
    /*
    * Constructor and destructor
    */
    Level(int width = 10, int height = 10, int x = 10, int y = 10); // In tiles
    virtual ~Level();

    sf::Vector2i getSpawnPoint();

    void update(const float& dt);
    void render(sf::RenderTarget&);
};

#endif
