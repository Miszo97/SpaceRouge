//
//  functions.hpp
//  SpaceRouge
//
//  Created by Miszo on 06.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp


#include "Obstacle.hpp"
#include "SmallObstacle.hpp"
#include "MediumObstacle.hpp"
#include "BigObstacle.hpp"



template <typename T, typename... Ts>
std::unique_ptr<Obstacle> makeObstacle(T choice, Ts... args){
    
    std::unique_ptr<Obstacle> ptr(nullptr);
    
    if (choice == 1)
    {
        ptr.reset(new SmallObstacle(std::forward<Ts>(args)...));
    }
    
    if (choice == 2)
    {
        ptr.reset(new MediumObstacle(std::forward<Ts>(args)...));
    }
    
    if (choice == 3)
    {
        ptr.reset(new BigObstacle(std::forward<Ts>(args)...));
    }
    
    
    return ptr;
    
}



#endif /* functions_hpp */
