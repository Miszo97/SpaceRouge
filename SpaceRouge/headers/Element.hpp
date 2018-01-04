//
//  Element.hpp
//  SpaceRouge
//
//  Created by Miszo on 03.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Element_hpp
#define Element_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Element {
public:
    virtual ~Element() = 0;
    Element(int, int);

    sf::Vector2i pos;
    
};

inline Element::~Element()
{}

#endif /* Element_hpp */
