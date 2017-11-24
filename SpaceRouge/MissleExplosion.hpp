//
//  MissleExplosion.hpp
//  SpaceRouge
//
//  Created by Miszo on 24.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef MissleExplosion_hpp
#define MissleExplosion_hpp
#include "Explosion.hpp"
#include <stdio.h>

class MissleExplosion : public Explosion  {
public:
    MissleExplosion(int, int);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    
    sf::CircleShape shape;

    
    
};

#endif /* MissleExplosion_hpp */
