#include "level.hpp"

Level::Level(int width, int height){
    this->mWidth = width;
    this->mHeight = height;
    this->mTileSize = 32;

    this->mAtlas.loadFromFile("_assets/_sprites/level_0.png");
    this->mMap.resize(width*height);
    this->mSprites.resize(width*height);

    for(int i = 0; i < this->mMap.size(); ++i)
        this->mMap[i] = 2;

    this->mMap[5] = 1;

    sf::IntRect tmpRect = sf::IntRect(
        0, 0,
        this->mTileSize, this->mTileSize
    );
    for(int i = 0; i < this->mSprites.size(); ++i){
        this->mSprites[i].setTexture(this->mAtlas);
        tmpRect.left = this->mMap[i] * this->mTileSize;
        tmpRect.top =  0;
        this->mSprites[i].setTextureRect(tmpRect);

        this->mSprites[i].setPosition(sf::Vector2f((i % this->mWidth) * this->mTileSize,
            (i / this->mHeight) * this->mTileSize));
    }



}

Level::~Level(){}

void Level::update(const float& dt){}

void Level::render(sf::RenderTarget& target){
    for(int i = 0; i < this->mMap.size(); ++i){
        target.draw(this->mSprites[i]);

    }
}
