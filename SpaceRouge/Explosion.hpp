//
//  Explosion.hpp
//  SpaceRouge
//
//  Created by Miszo on 22.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Explosion_hpp
#define Explosion_hpp
#include "Element.hpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>

class Explosion : public Element, public sf::Drawable {
    
public:
    Explosion(int, int);
    virtual ~Explosion() = 0;
    
    
    
};

#endif /* Explosion_hpp */

inline Explosion::~Explosion()
{}
