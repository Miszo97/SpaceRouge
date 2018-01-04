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
    hp = 5;
    speed = 10;
    color = _color;
    shape = _shape;
    
    shape.setFillColor(color);
    shape.setPosition(pos.x, pos.y);
    shape.setRadius(size);
    
    current_sprite.first = 0;
    current_sprite.second = 0;
}


void SmallObstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(sprite);
}


void SmallObstacle::update() noexcept{
    sprite.setPosition(pos.x, pos.y);
    if(++newSpriteEvery==4){
        sprite.setTextureRect(getIntRect());
        newSpriteEvery =0;
    }
}

sf::IntRect SmallObstacle::getIntRect() noexcept{
    
    auto rec = sf::IntRect(current_sprite.first*44,current_sprite.second*43,44,43);
    
    ++current_sprite.first;
    
    if (current_sprite.first == 1){
        
        current_sprite.first = 0;
        ++current_sprite.second;
        
    }
    
    if(current_sprite.second == 16)
        current_sprite.first = current_sprite.second = 0;
    
    return rec;
}
