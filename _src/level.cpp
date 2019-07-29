#include "level.hpp"

Level::Level(int width, int height, int x, int y){
    this->mWidth = width;
    this->mHeight = height;

    // TODO : TMP HARDCODED
    this->mX = 1920 / 2 - 16 * width;
    this->mY = 1080 / 2 - 16 * height;
    this->mTileSize = 32;

    this->mPlayerSpawn.x = 1;
    this->mPlayerSpawn.y = 1;


    this->mAtlas.loadFromFile("_assets/_sprites/level_0.png");
    this->mSprites = new sf::Sprite[width * height];
    //this->mMap = new int[width * height];


    // for(int row = 0; row < this->mHeight; ++row){
    //     for(int column = 0; column < this->mWidth; ++column){
    //         this->mMap[index(column, row)] = 1;
    //     }
    // }

    // TODO : READ LEVEL FROM FILE HARDCODED FOR NOW
    int tmp[width * height] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };
    this->mMap = tmp;

    sf::IntRect tmpRect = sf::IntRect(
        this->mX, this->mY,
        this->mTileSize, this->mTileSize
    );

    for(int row = 0; row < this->mHeight; ++row){
        for(int column = 0; column < this->mWidth; ++column){
            this->mSprites[index(column, row)].setTexture(this->mAtlas);
            tmpRect.left = this->mMap[index(column, row)] * this->mTileSize;
            tmpRect.top = 0; // FOR NOW
            this->mSprites[index(column, row)].setTextureRect(tmpRect);

            this->mSprites[index(column, row)].setPosition(
                sf::Vector2f(this->mX + column * this->mTileSize,
                    this->mY + row * this->mTileSize));
        }
    }
}

inline size_t Level::index(int x, int y){
    return x + this->mWidth * y;
}

sf::Vector2i Level::getSpawnPoint(){
    sf::Vector2i res(this->mPlayerSpawn.x * this->mTileSize + this->mX ,
        this->mPlayerSpawn.y * this->mTileSize + this->mY);
    return res;
}

Level::~Level(){
    delete [] this->mSprites;
    //delete this->mMap;
    //delete [] this->mMap;

}

void Level::update(const float& dt){}

void Level::render(sf::RenderTarget& target){
    for(int row = 0; row < this->mHeight; ++row){
        for(int column = 0; column < this->mWidth; ++column)
            target.draw(this->mSprites[index(column, row)]);
    }
}
