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

struct Spawner{
    
    Spawner(sf::RenderWindow* _App) : App(_App)
    {}
    
    sf::RenderWindow* App;
    sf::Clock timer;
    unsigned resp1for = 1.5;
    unsigned resp2for = 5;
    unsigned resp3for = 10;
    
    
    void operator()(std::vector<std::unique_ptr<Obstacle>>& vector){
        
        if (timer.getElapsedTime().asSeconds()> resp1for) {
            vector.push_back(makeObstacle(1, App->getSize().x,rand()%App->getSize().y,sf::Color::Blue,sf::CircleShape(80)));
            resp1for += 1.5;
        }
        
        if (timer.getElapsedTime().asSeconds()> resp2for) {
            vector.push_back(makeObstacle(2, App->getSize().x,rand()%App->getSize().y,sf::Color::Yellow,sf::CircleShape(80)));
            resp2for += 5;
        }
        
        if (timer.getElapsedTime().asSeconds()> resp3for) {
            vector.push_back(makeObstacle(3, App->getSize().x,rand()%App->getSize().y,sf::Color::Green,sf::CircleShape(80)));
            resp3for += 10;
        }
        
    }
    
    
};


int screen_01::Run (sf::RenderWindow &App) {
    
    
    Spawner spawner(&App);
    
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


