//
//  MediumObstacle.hpp
//  SpaceRouge
//
//  Created by Miszo on 05.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef MediumObstacle_hpp
#define MediumObstacle_hpp

#include <stdio.h>
#include "Obstacle.hpp"


class MediumObstacle : public Obstacle {
    
public:
    MediumObstacle(int x, int y,
                  sf::Color color,
                  const sf::CircleShape& shape, sf::Texture*);

    MediumObstacle& operator=(const MediumObstacle&) = default;
    MediumObstacle& operator=(MediumObstacle&&) = default;
    
    MediumObstacle(const MediumObstacle&) = default;
    MediumObstacle(MediumObstacle&&) = default;
    
   
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void update() noexcept;
    sf::IntRect getIntRect() noexcept;
};

#endif /* MediumObstacle_hpp */
