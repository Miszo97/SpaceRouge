//
//  SmallObstacle.hpp
//  SpaceRouge
//
//  Created by Miszo on 05.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef SmallObstacle_hpp
#define SmallObstacle_hpp

#include <stdio.h>
#include "Obstacle.hpp"


class SmallObstacle : public Obstacle {
    
public:
    SmallObstacle(int x, int y,
                  sf::Color color,
                  const sf::CircleShape& shape, sf::Texture*);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void update() noexcept override;
    sf::IntRect getIntRect() noexcept;

    
};

#endif /* SmallObstacle_hpp */
