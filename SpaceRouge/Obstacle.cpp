//
//  Obstacle.cpp
//  SpaceRouge
//
//  Created by Miszo on 05.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Obstacle.hpp"

Obstacle::Obstacle(int x, int y) : Element(x,y)
{}


void Obstacle::move() noexcept {
    pos.x -= speed;
}


void Obstacle::update() noexcept{
    shape.setPosition(pos.x, pos.y);
}
