#include "tilemap.hpp"

Tilemap::Tilemap(int width, int height){
    this->mWidth = width;
    this->mHeight = height;
    this->mTileSize = 16;

    this->mTiles.resize(width*height);
    this->mSprites.resize(width*height);

    for(int i = 0; i < this->mTiles.size(); ++i)
        this->mTiles[i] = 1;

    this->mAtlas.loadFromFile("_assets/_sprites/testtile.png");

    for(int i = 0; i < this->mSprites.size(); ++i){
        this->mSprites[i].setTexture(this->mAtlas);
        this->mSprites[i].setPosition(sf::Vector2f((i % this->mWidth) * this->mTileSize,
            (i / this->mHeight) * this->mTileSize));
    }



}

Tilemap::~Tilemap(){}

void Tilemap::update(const float& dt){}

void Tilemap::render(sf::RenderTarget& target){
    for(int i = 0; i < this->mTiles.size(); ++i){
        if(this->mTiles[i] == 1)
            target.draw(this->mSprites[i]);

    }
}
