//
// Created by dominikoso on 14.01.17.
//

#include <SFML/Graphics.hpp>

#include "AnimationEngine.h"
#include "Tile.h"

void Tile::draw(sf::RenderWindow& window, float dt)
{
    /* Change the sprite to reflect the tile variant */
    this->animHandler.changeAnim(this->tileVariant);

    /* Update the animation */
    this->animHandler.update(dt);

    /* Update the sprite */
    this->sprite.setTextureRect(this->animHandler.bounds);

    /* Draw the tile */
    window.draw(this->sprite);

    return;
}

void Tile::update()
{
    /* If the population is at the maximum value for the tile,
     * there is a small chance that the tile will increase its
     * building stage */
    if((this->tileType == TileType::RESIDENTIAL ||
        this->tileType == TileType::COMMERCIAL ||
        this->tileType == TileType::INDUSTRIAL ||
       this->tileType == TileType::PYLON) &&
       this->population == this->maxPopPerLevel * (this->tileVariant+1) &&
       this->tileVariant < this->maxLevels)
    {
        if(rand() % int(1e4) < 1e2 / (this->tileVariant+1)) ++this->tileVariant;
    }

    return;
}

std::string tileTypeToStr(TileType type)
{
    switch(type)
    {
        default:
        case TileType::VOID:            return "Void";
        case TileType::GRASS:           return "Flatten";
        case TileType::FOREST:          return "Forest";
        case TileType::MOUNTAIN:        return "Mountain";
        case TileType::WATER:           return "Water";
        case TileType::RESIDENTIAL:     return "Residential Zone";
        case TileType::COMMERCIAL:      return "Commercial Zone";
        case TileType::INDUSTRIAL:      return "Industrial Zone";
        case TileType::PYLON:           return "Pylon";
    }
}