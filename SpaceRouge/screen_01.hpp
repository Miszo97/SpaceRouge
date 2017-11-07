//
//  screen_01.hpp
//  SpaceRouge
//
//  Created by Miszo on 02.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef screen_01_hpp
#define screen_01_hpp
#include "cScreen.hpp"
#include "Player.hpp"
#include "Element.hpp"
#include "Obstacle.hpp"
#include <stdio.h>
#include <chrono>
#include "functions.hpp"




class screen_01 : public cScreen {
    
public:
    virtual int Run (sf::RenderWindow &App) override;
    
private:
    sf::Event event;
    Player p;
    std::vector<std::unique_ptr<Obstacle>> Obstacles;
    void remove_if();
    
    
    
};







#endif /* screen_01_hpp */
