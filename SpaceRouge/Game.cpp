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
#include "screen_02.hpp"

void Game::exec(){
    
    //Applications variables
    std::vector<cScreen*> Screens;
    int screen = 1;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Close);
    window.setFramerateLimit(60);
    
    
    screen_01 s1; //game
    screen_02 s2; //menu
    Screens.push_back(&s2);
    Screens.push_back(&s1);
    
    
    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(window);
    }
    

    
    
}
