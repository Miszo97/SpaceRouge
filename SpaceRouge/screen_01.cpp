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
    
    std::string path = "/Users/miszo97/Desktop/SpaceRouge/SpaceRouge/SmallObstacleTextureSprite.png";
    if (!Textures[0].loadFromFile(path)) {
        std::cerr << "Error loading SmallObstacleTextureSprite.png" << std::endl;
        return (-1);
    }
    
    path = "/Users/miszo97/Desktop/SpaceRouge/SpaceRouge/MediumObstacleTextureSprite.png";
    if (!Textures[1].loadFromFile(path)) {
        std::cerr << "Error loading MediumObstacleTextureSprite.png" << std::endl;
        return (-1);
    }
    
    path = "/Users/miszo97/Desktop/SpaceRouge/SpaceRouge/BigObstacleTextureSprite.png";
    if (!Textures[2].loadFromFile(path)) {
        std::cerr << "Error loading BigObstacleTextureSprite.png" << std::endl;
        return (-1);
    }


    
}



int screen_01::Run (sf::RenderWindow &App) {
    
    srand( time( NULL ) );
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
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                p.shoot();
            }
        }
        
        spawner(Obstacles);
        
        
        p.setPosistion(40, sf::Mouse::getPosition(App).y);
        
        p.update();
        
        for(const auto& o: Obstacles){
            o->move();
            o->update();
        }
        
        //removing objects if needed
        remove_objects_if(&App);
        
        //std::cout<<Obstacles.size()<<" "<<p.getMissles().size()<<std::endl;
        
        App.clear(sf::Color::White);
        
        App.draw(p);
        
        //draw loop
        for(const auto& m: p.getMissles())
            App.draw(m);
        
        //draw loop
        for(const auto& o: Obstacles)
            App.draw(*o);
        
        
        //draw loop
        for(const auto& o: MissleExplosions)
            App.draw(o);
   
        App.display();
        
        
        
        
        
    }
    
    
    
}

void screen_01::remove_objects_if(sf::RenderWindow* App){
    
    auto prediction1 =  [](const std::unique_ptr<Obstacle>& ref){
        return  ref->pos.x<0 || ref->getHp()==0;
    };
    
    Obstacles.erase(std::remove_if(Obstacles.begin(), Obstacles.end(), prediction1) ,Obstacles.end());
    
    //convinient reference
    std::vector<Missle>& Missles = p.getMissles();
    
    
    auto prediction2 = [=](Missle& ref){
        if( ref.pos.x > App->getSize().x)
         return true;
        if( ref.checkForCollision(Obstacles)){
            MissleExplosions.emplace_front(ref.pos.x, ref.pos.y);
            std::cout<<"Explosion!"<<ref.pos.x<<" "<<ref.pos.y<<std::endl;
        return true;
        }
        return false;
    };
    
    Missles.erase(std::remove_if(Missles.begin(), Missles.end(),prediction2),Missles.end());
    
    
    

}


