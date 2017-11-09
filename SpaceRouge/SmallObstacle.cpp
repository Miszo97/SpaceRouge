//
//  SmallObstacle.cpp
//  SpaceRouge
//
//  Created by Miszo on 05.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "SmallObstacle.hpp"


SmallObstacle::SmallObstacle(
              int x, int y,
              sf::Color _color,
              const sf::CircleShape& _shape, sf::Texture* _texture) : Obstacle(x,y, _texture)
{
    size = 20;
    hp = 20;
    speed = 10;
    color = _color;
    shape = _shape;
    
    shape.setFillColor(color);
    shape.setPosition(pos.x, pos.y);
    shape.setRadius(size);
}


void SmallObstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(sprite);
}


void SmallObstacle::update() noexcept{
    sprite.setPosition(pos.x, pos.y);
    sprite.setTextureRect(sf::IntRect(0,0,155,138));
}
