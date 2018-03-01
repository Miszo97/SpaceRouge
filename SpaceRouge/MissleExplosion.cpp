//
//  MissleExplosion.cpp
//  SpaceRouge
//
//  Created by Miszo on 24.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//
#include <iostream>
#include "MissleExplosion.hpp"

MissleExplosion::MissleExplosion(int x, int y, sf::Texture* texture) : Explosion(x ,y, texture)
{
    current_sprite.first  = 0;
    current_sprite.second = 0;
    expired               = false;
    expired_time          = 1;
    shape                 = sf::CircleShape(40);

    shape.setFillColor(sf::Color::Red);
    shape.setPosition(pos.x, pos.y);
    sprite.setPosition(pos.x-26, pos.y-26);
    sprite.setTextureRect(sf::IntRect(0,0,0,0));
}


void MissleExplosion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(sprite);
    //target.draw(shape);
  
}


void MissleExplosion::checkForExpired() noexcept{
    
    if(timer.getElapsedTime().asSeconds()> 1 )
         expired = true;;
        
    
    
}

void MissleExplosion::update()  noexcept{
    
    checkForExpired();
    sprite.setTextureRect(getIntRect());
    
}

sf::IntRect MissleExplosion::getIntRect() noexcept{
    
    auto rec = sf::IntRect(30+current_sprite.first*128,64+current_sprite.second*126,72,72);
    
    ++current_sprite.first;
    
    if (current_sprite.first == 8){
        
        current_sprite.first = 0;
        ++current_sprite.second;
        
    }
    
    if(current_sprite.second == 8)
        current_sprite.first = current_sprite.second = 0;
        
        return rec;
}
