//
//  BigObstacle.hpp
//  SpaceRouge
//
//  Created by Miszo on 05.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef BigObstacle_hpp
#define BigObstacle_hpp
#include "Obstacle.hpp"
#include <stdio.h>

class BigObstacle : public Obstacle {
    
public:
    BigObstacle(int x, int y,
                   sf::Color color,
                   const sf::CircleShape& shape, sf::Texture*);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void update() noexcept;
private:
    

    
    
};

#endif /* BigObstacle_hpp */
