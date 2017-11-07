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

struct option{
    option(std::string t, int _return_code, sf::Font& _f, int size, sf::Vector2f pos, sf::Color color): return_code(_return_code)
    {
        text.setString(std::move(t));
        text.setFont(_f);
        text.setCharacterSize(size);
        text.setPosition(pos);
        text.setFillColor(color);
    }
    sf::Text text;
    int return_code;
    
};




class screen_02 : public cScreen {
    
public:
    virtual int Run (sf::RenderWindow &App) override;
    
private:
    std::vector<option> options;
    sf::Font Font;
    sf::Event event;
    int menu;
};



#endif /* screen_02_hpp */
