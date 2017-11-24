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
    MissleExplosion(int, int, sf::Texture*);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void checkForExpired() noexcept override;
    virtual void update() noexcept override;
private:
    sf::IntRect getIntRect() noexcept;
    sf::CircleShape shape;

    
    
};

#endif /* MissleExplosion_hpp */
