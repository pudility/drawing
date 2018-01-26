//
//  updatedirector.hpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#ifndef updatedirector_hpp
#define updatedirector_hpp

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "socketconnector.hpp"

class Updater
{
public:
    int Update ( sf::Image *iFrame, sf::Vector2i vWindowPos );
private:
    int const TOP_OFFSET = 90;
    int const WINDOW_HEIGHT = 800;
    
    int iLastXPos = 0;
    int iLastYPos = 0;
    
    Connector *m_Connector = new Connector ( );
    
    void logMousePos ( int iXPos, int iYPos );
    void Send ( sf::Uint16 iXPos, sf::Uint16 iYPos );
    void Clear ( sf::Image *iFrame );
};

#endif /* updatedirector_hpp */
