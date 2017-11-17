//
//  Missle.cpp
//  SpaceRouge
//
//  Created by Miszo on 08.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Missle.hpp"
#include "Obstacle.hpp"
#include "functions.hpp"

void Missle::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    
    target.draw(sprite);
    
}


Missle::Missle(int x, int y, sf::Texture& texture) : Element(x,y){
    
    shape = sf::CircleShape(5);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(pos.x, pos.y);
    speed = 5;
    sprite.setTexture(texture);
    
}

void Missle::move() noexcept{
    
    pos.x += speed;
    
    
}
void Missle::update() noexcept{
    
    
    sprite.setPosition(pos.x, pos.y);
}

sf::Sprite& Missle::getSprite() noexcept{
    return sprite;
}

bool Missle::checkForCollision(std::vector<std::unique_ptr<Obstacle>>& obs) noexcept{
    
    for(auto const& it: obs){
        if(CollisionDetector(*this, *it)){
            it->reduceHp(5); return true;
        }
    }
    return false;
    
}
