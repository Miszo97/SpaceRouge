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
    
    menu = 0;
    if (!Font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }
    
    //better option emplace_back. Additional cost of move constructor
    options.push_back(option("Start", 1, Font, 40, { 280.f, 160.f }, sf::Color::White));
    options.push_back(option("Exit", -1, Font, 40, { 280.f, 220.f }, sf::Color::Black));
    options.push_back(option("Settings", -1, Font, 40, { 280.f, 280.f }, sf::Color::Black));
    options.push_back(option("Credits", -1, Font, 40, { 280.f, 340.f }, sf::Color::Black));
    
    
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
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down){
                options[menu].text.setFillColor(sf::Color::Black);
                if(menu == options.size() -1)
                    menu = 0;
                else
                    menu++;
                options[menu].text.setFillColor(sf::Color(255, 255, 255, 255));
            }
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
                options[menu].text.setFillColor(sf::Color(sf::Color::Black));
                if(menu == 0)
                    menu = options.size() -1;
                else
                    menu--;
                options[menu].text.setFillColor(sf::Color(255, 255, 255, 255));
            }
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return){
                return options[menu].return_code;
            }
            
        }
        
       
        
       
        
        App.clear(sf::Color::Green);
        
        for(const auto& o: options)
            App.draw(o.text);
        
        App.display();
        
        
        
        
        
    }
    
    
}
