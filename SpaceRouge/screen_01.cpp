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
#include "SmallObstacle.hpp"
#include "MediumObstacle.hpp"
#include "BigObstacle.hpp"
#include "functions.hpp"


int screen_01::Run (sf::RenderWindow &App) {
    
    Obstacles.push_back(makeObstacle(1, 400,10,sf::Color::Green,sf::CircleShape(80)));
    
    //Obstacles.push_back(std::unique_ptr<Obstacle>( new SmallObstacle(400,10,sf::Color::Green,sf::CircleShape(80))));
    
    //Obstacles.push_back(std::unique_ptr<Obstacle>( new MediumObstacle(400,60,sf::Color::Green,sf::CircleShape(80))));

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
        
        for(const auto& o: Obstacles){
            o->move();
            o->update();
            App.draw(*o);
        }
        
        App.display();
        
        
        
        
        
    }
    
    
    
}
