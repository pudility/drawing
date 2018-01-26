//
//  app.hpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#ifndef app_hpp
#define app_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "updatedirector.hpp"

class App
{
public:
    void run ( );
private:
    sf::RenderWindow m_RenderWindow;
    sf::Sprite m_View;
    sf::Image *m_Frame;
    Updater *m_Updater;
};

#endif /* app_hpp */
