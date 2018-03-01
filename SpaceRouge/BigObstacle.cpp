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
                               const sf::CircleShape& _shape, sf::Texture* _texture) : Obstacle(x,y, _texture)
{
    size  = 70;
    hp    = 50;
    speed = 2;
    color = _color;
    shape = _shape;
    
    shape.setFillColor(color);
    shape.setPosition(pos.x, pos.y);
    shape.setRadius(size);
    
    
    current_sprite.first = 0;
    current_sprite.second = 0;
}


void BigObstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(sprite);
}

void BigObstacle::update() noexcept{

    sprite.setPosition(pos.x, pos.y);

    if(++newSpriteEvery==4){
    sprite.setTextureRect(getIntRect());
    newSpriteEvery =0;
    }
  
}

sf::IntRect BigObstacle::getIntRect() noexcept{
    
    auto rec = sf::IntRect(current_sprite.first*205,current_sprite.second*195,205,195);
    
    ++current_sprite.first;
    
    if (current_sprite.first == 2){
        
        current_sprite.first = 0;
        ++current_sprite.second;
        
    }
    
    if(current_sprite.second == 8)
        current_sprite.first = current_sprite.second = 0;
        
        return rec;
}
