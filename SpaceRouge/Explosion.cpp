//
//  Explosion.cpp
//  SpaceRouge
//
//  Created by Miszo on 22.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "Explosion.hpp"

Explosion::Explosion(int x, int y, sf::Texture* _texture) : Element(x, y)
{
    texture = _texture;
    sprite.setTexture(*texture);
    newSpriteEvery = 3;
}
