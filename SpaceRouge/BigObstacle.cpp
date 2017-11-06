//
//  BigObstacle.cpp
//  SpaceRouge
//
//  Created by Miszo on 05.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "BigObstacle.hpp"

BigObstacle::BigObstacle(
                               int x, int y,
                               sf::Color _color,
                               const sf::CircleShape& _shape) : Obstacle(x,y)
{
    size = 70;
    hp = 50;
    speed = 2;
    color = _color;
    shape = _shape;
    
    shape.setFillColor(color);
    shape.setPosition(pos.x, pos.y);
    shape.setRadius(size);
}


void BigObstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(shape);
}
