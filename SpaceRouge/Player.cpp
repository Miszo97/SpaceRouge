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
    
    std::string path = "/Users/miszo97/Desktop/SpaceRouge/SpaceRouge/Resources/blueships1.png";
    if (!Textures[0].loadFromFile(path)) {
        std::cerr << "Error loading blueships1.png" << std::endl;
        //return (-1);
    }
    
    path = "/Users/miszo97/Desktop/SpaceRouge/SpaceRouge/Resources/shot.png";
    if (!Textures[1].loadFromFile(path)) {
        std::cerr << "Error loading shot.png" << std::endl;
        //return (-1);
    }
    
    path = "/Users/miszo97/Desktop/SpaceRouge/SpaceRouge/Resources/blaster_sound.wav";
    // Open it from an audio file
    if (!sound_effects[0].openFromFile(path))
    {
        std::cerr<<"Couldn't load the sound";
    }
    
    sprite.setTexture(Textures[0]);
    
    sprite.setScale(0.15, 0.15);
    sf::FloatRect rect = sprite.getGlobalBounds();
    sprite.setOrigin(pos.x + rect.width, pos.y+ rect.height);
    
    
}


Player::Player(int x, int y) : Element(40,200){
    
}

void Player::setPosistion(int _x,int _y){
    
    
    pos.x = _x;
    pos.y = _y;
    
}

void Player::update(){
    
    sprite.setPosition(pos.x, pos.y);

    std::for_each(Missles.begin(), Missles.end(), [](Missle& m){m.move(); m.update();});
}

void Player::shoot() noexcept{
    Missles.emplace_back(pos.x+100,pos.y+5, Textures[1]);
    sound_effects[0].play();
}

std::vector<Missle>& Player::getMissles() noexcept{
    return Missles;
}



