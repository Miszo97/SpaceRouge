//
//  MissleExplosion.cpp
//  SpaceRouge
//
//  Created by Miszo on 24.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "MissleExplosion.hpp"

MissleExplosion::MissleExplosion(int x, int y) : Explosion(x ,y)
{
    shape = sf::CircleShape(40);
    shape.setPosition(pos.x, pos.y);
    shape.setFillColor(sf::Color::Red);
}


void MissleExplosion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(shape);
  
}
