//
//  screen_02.hpp
//  SpaceRouge
//
//  Created by Miszo on 04.11.2017.
//  Copyright © 2017 Miszo. All rights reserved.
//

#ifndef screen_02_hpp
#define screen_02_hpp

#include "cScreen.hpp"



class screen_02 : public cScreen {
    
public:
    virtual int Run (sf::RenderWindow &App) override;
    
private:
    sf::Text start;
    sf::Text exit;
    sf::Font Font;
};



#endif /* screen_02_hpp */
