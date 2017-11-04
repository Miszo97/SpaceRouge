//
//  screen_02.cpp
//  SpaceRouge
//
//  Created by Miszo on 04.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "screen_02.hpp"
#include "ResourcePath.hpp"
#include <iostream>

int screen_02::Run (sf::RenderWindow &App)  {
    
    
    if (!Font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }
    
    start.setFont(Font);
    start.setCharacterSize(40);
    start.setString("Play");
    start.setPosition({ 280.f, 160.f });
    
    exit.setFont(Font);
    exit.setCharacterSize(40);
    exit.setString("Exit");
    exit.setPosition({ 280.f, 220.f });
    
    
}
