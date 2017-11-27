//
//  Player.cpp
//  SpaceRouge
//
//  Created by Miszo on 03.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Player.hpp"
#include <iostream>


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    target.draw(sprite);
    //target.draw(triangle);
}

Player::Player() : Element(40,200){
    
    pos.x = 40;
    pos.y = 200;
    hp = 3;
    
    
    triangle = sf::CircleShape(50,3);
    triangle.setOrigin(100, 100);
    triangle.rotate(90);
    triangle.setFillColor(sf::Color::Black);
    triangle.setPosition(pos.x, pos.y);
    
    std::string path = "/Users/miszo97/Desktop/SpaceRouge/SpaceRouge/blueships1.png";
    if (!Textures[0].loadFromFile(path)) {
        std::cerr << "Error loading blueships1.png" << std::endl;
        return (-1);
    }
    
    path = "/Users/miszo97/Desktop/SpaceRouge/SpaceRouge/shot.png";
    if (!Textures[1].loadFromFile(path)) {
        std::cerr << "Error loading shot.png" << std::endl;
        return (-1);
    }
    
    sprite.setTexture(Textures[0]);
    
    sprite.setScale(0.15, 0.15);
    sf::FloatRect rect = sprite.getGlobalBounds();
    sprite.setOrigin(pos.x + rect.width, pos.y+ rect.height);
    
    
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
    sprite.setPosition(pos.x, pos.y);

    std::for_each(Missles.begin(), Missles.end(), [](Missle& m){m.move(); m.update();});
}

void Player::shoot() noexcept{
    Missles.emplace_back(pos.x+100,pos.y+5, Textures[1]);
}

std::vector<Missle>& Player::getMissles() noexcept{
    return Missles;
}


inline sf::CircleShape& Player::getTriangle() { return triangle; }
int Player::getHp() noexcept {return hp;}
void Player::setHp(int _hp) noexcept {hp = _hp;}

