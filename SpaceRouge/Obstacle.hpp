//
//  Obstacle.hpp
//  SpaceRouge
//
//  Created by Miszo on 05.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Obstacle_hpp
#define Obstacle_hpp
#include "Element.hpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>



class Obstacle : public Element, public sf::Drawable {
    
public:
    virtual ~Obstacle() = 0;
    Obstacle(int x, int y, sf::Texture*);
    void move() noexcept;
    virtual void update() noexcept;

protected:
    int speed;
    int size;
    int hp;
    sf::Color color;
    sf::CircleShape shape;
    sf::Texture* texture;
    sf::Sprite sprite;
    
    int current_sprite;
    
    
};

inline Obstacle::~Obstacle()
{}


#endif /* Obstacle_hpp */


