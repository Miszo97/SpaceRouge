//
//  Missle.hpp
//  SpaceRouge
//
//  Created by Miszo on 08.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Missle_hpp
#define Missle_hpp
#include <SFML/Graphics.hpp>
#include "Element.hpp"
#include "Obstacle.hpp"


class Missle : public Element, public sf::Drawable{
    
public:
    Missle(int, int, sf::Texture&);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)  const;
    void move() noexcept;
    void update() noexcept;
    sf::Sprite& getSprite() noexcept;
    bool checkForCollision(std::vector<std::unique_ptr<Obstacle>>&) noexcept;

private:
    
    sf::CircleShape shape;
    sf::Sprite sprite;
    int speed;
    
};

#endif /* Missle_hpp */
