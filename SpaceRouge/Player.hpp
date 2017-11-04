//
//  Player.hpp
//  SpaceRouge
//
//  Created by Miszo on 03.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Element.hpp"

class Player : public sf::Drawable, public Element  {
    
public:
    Player();
    Player(int, int);
    
    Player(const Player& other) = delete;
    Player& operator=(const Player& other) = delete;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::CircleShape& getTriangle();
    void setPosistion(int,int);
    void update();
    

    
private:
    sf::CircleShape triangle;
    
    
};

#endif /* Player_hpp */
