//
//  Spawner.cpp
//  SpaceRouge
//
//  Created by Miszo on 09.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef Spawner_cpp
#define Spawner_cpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Obstacle.hpp"
#include "functions.hpp"
#include <array>


struct Spawner{
    
    Spawner(sf::RenderWindow*, std::array<sf::Texture, 3>*);
    
    std::array<sf::Texture, 3>* Textueres;
    sf::RenderWindow* App;
    sf::Clock timer;
    unsigned resp1for = 1.5;
    unsigned resp2for = 5;
    unsigned resp3for = 10;
    
    
    void operator()(std::vector<std::unique_ptr<Obstacle>>& vector){
        
        if (timer.getElapsedTime().asSeconds()> resp1for) {
            vector.push_back(makeObstacle(1, App->getSize().x,rand()%App->getSize().y,sf::Color::Blue,sf::CircleShape(80), &(*Textueres)[0]));
            resp1for += 1.5;
        }
        
        if (timer.getElapsedTime().asSeconds()> resp2for) {
            vector.push_back(makeObstacle(2, App->getSize().x,rand()%App->getSize().y,sf::Color::Yellow,sf::CircleShape(80), &(*Textueres)[0]));
            resp2for += 5;
        }
        
        if (timer.getElapsedTime().asSeconds()> resp3for) {
            vector.push_back(makeObstacle(3, App->getSize().x,rand()%App->getSize().y,sf::Color::Green,sf::CircleShape(80), &(*Textueres)[0]));
            resp3for += 10;
        }
        
    }
    
    
};

inline Spawner::Spawner(sf::RenderWindow* _App, std::array<sf::Texture, 3>* _Textures) : App(_App), Textueres(_Textures)
{
    
    
}

#endif
