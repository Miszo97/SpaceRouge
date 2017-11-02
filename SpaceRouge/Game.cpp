//
//  Game.cpp
//  SpaceRouge
//
//  Created by Miszo on 02.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.hpp"
#include "cScreen.hpp"
#include "screen_01.hpp"

void Game::exec() noexcept{
    
    //Applications variables
    std::vector<cScreen*> Screens;
    int screen = 0;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Close);
    window.setFramerateLimit(60);
    
    
    
    screen_01 s0;
    Screens.push_back(&s0);
    
    
    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(window);
    }
    

    
    
}
