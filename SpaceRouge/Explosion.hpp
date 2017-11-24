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
    Explosion(int, int, sf::Texture*);
    virtual ~Explosion() = 0;
    bool expired;
    sf::Clock timer;
    virtual void checkForExpired()  noexcept;
    virtual void update() noexcept;
protected:
    unsigned expired_time;
    sf::Texture* texture;
    sf::Sprite sprite;
    std::pair<int, int> current_sprite;
    int newSpriteEvery;

};

#endif /* Explosion_hpp */

inline Explosion::~Explosion()
{}

inline void Explosion::checkForExpired()  noexcept
{}

inline void Explosion::update()  noexcept
{}
