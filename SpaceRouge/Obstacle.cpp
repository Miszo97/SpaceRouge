//
//  Obstacle.cpp
//  SpaceRouge
//
//  Created by Miszo on 05.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Obstacle.hpp"

Obstacle::Obstacle(int x, int y, sf::Texture* _texture) : Element(x,y), texture(_texture)
{
    sprite.setTexture(*texture);
    newSpriteEvery = 0;
}


void Obstacle::move() noexcept {
    pos.x -= speed;
}


void Obstacle::update() noexcept
{}



sf::Sprite& Obstacle::getSprite() noexcept{
    return sprite;
}

sf::IntRect Obstacle::getIntRect() noexcept
{}
