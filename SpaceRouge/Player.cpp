//
//  Player.cpp
//  SpaceRouge
//
//  Created by Miszo on 03.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Player.hpp"


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(triangle);
}

Player::Player() : Element(40,200){
    
    pos.x = 40;
    pos.y = 200;
    
    
    triangle = sf::CircleShape(50,3);
    triangle.setOrigin(100, 100);
    triangle.rotate(90);
    triangle.setFillColor(sf::Color::Black);
    triangle.setPosition(pos.x, pos.y);
    
}


Player::Player(int x, int y) : Element(40,200){
    
    triangle = sf::CircleShape(3,80);
}

void Player::setPosistion(int _x,int _y){
    
    pos.x = _x;
    pos.y = _y;
    
}

void Player::update(){
    
    triangle.setPosition(pos.x, pos.y);
    std::for_each(Missles.begin(), Missles.end(), [](Missle& m){m.move(); m.update();});
}

void Player::shoot() noexcept{
    Missles.emplace_back(pos.x,pos.y);
}

std::vector<Missle>& Player::getMissles() noexcept{
    return Missles;
}


inline sf::CircleShape& Player::getTriangle() { return triangle; }
