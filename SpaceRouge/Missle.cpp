//
//  Missle.cpp
//  SpaceRouge
//
//  Created by Miszo on 08.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Missle.hpp"


void Missle::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    
    target.draw(shape);
    
}


Missle::Missle(int x, int y) : Element(x,y){
    
    shape = sf::CircleShape(5);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(pos.x, pos.y);
    speed = 5;
    
    
}

void Missle::move() noexcept{
    
    pos.x += speed;
    
    
}
void Missle::update() noexcept{
    
    shape.setPosition(pos.x, pos.y);
}
