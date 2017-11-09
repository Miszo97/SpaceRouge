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
#include <chrono>
#include <random>
#include "ResourcePath.hpp"
#include "Spawner.cpp"

screen_01::screen_01(){
    std::string path = "/Users/miszo97/Desktop/SpaceRouge/asteroids/BigObstacleTextureSprite.png";
    if (!Textures[0].loadFromFile(path)) {
        std::cerr << "Error loading background.png" << std::endl;
        return (-1);
    }
}



int screen_01::Run (sf::RenderWindow &App) {
    
    
    Spawner spawner(&App, &Textures);
    
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
        
        spawner(Obstacles);
        
        p.setPosistion(40, sf::Mouse::getPosition().y);
        
        p.update();
        
        for(const auto& o: Obstacles){
            o->move();
            o->update();
        }
        
        //removing objectc if needed
        remove_obstacle_if();
        
        std::cout<<Obstacles.size()<<std::endl;
        
        App.clear(sf::Color::White);
        
        App.draw(p);
        
        //draw loop
        for(const auto& o: Obstacles)
            App.draw(*o);
   
        App.display();
        
        
        
        
        
    }
    
    
    
}

void screen_01::remove_obstacle_if(){
Obstacles.erase(std::remove_if(Obstacles.begin(), Obstacles.end(),
                               [](const std::unique_ptr<Obstacle>& ref){return ref->pos.x<0;})
                ,Obstacles.end());

}


