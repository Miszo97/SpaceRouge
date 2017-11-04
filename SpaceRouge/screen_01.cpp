//
//  screen_01.cpp
//  SpaceRouge
//
//  Created by Miszo on 02.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#include "screen_01.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int screen_01::Run (sf::RenderWindow &App) {
    
    
    
    while(1){
        
        
        while (App.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                return -1;
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return -1;
            }
        }
        
        p.setPosistion(40, sf::Mouse::getPosition().y);
        
        p.update();
        
        App.clear(sf::Color::White);
        
        App.draw(p);
        
        App.display();
        
        
        
        
        
    }
    
    
    
}
