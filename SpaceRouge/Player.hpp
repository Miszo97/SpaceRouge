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

class Player : public sf::Drawable {
    
public:
    
    Player(const Player& other) = delete;
    Player& operator=(const Player& other) = delete;
    
    
private:
    
    
    
};

#endif /* Player_hpp */
