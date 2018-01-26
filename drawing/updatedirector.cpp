//
//  updatedirector.cpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#include "updatedirector.hpp"

void Updater::logMousePos ( int iXPos, int iYPos )
{
    if ( m_Connector->bIsReciving )
        std::cout << "Recived: ";
    std::cout << "X: " << iXPos << " Y: " << iYPos << "\n";
}

void Updater::Clear ( sf::Image *iFrame )
{
    std::cout << "Clearing \n";
    
    for ( int x = 0; x < 100; x++ )
        for ( int y = 0; y < 100; y++ )
            iFrame->setPixel ( x, y, sf::Color( 0, 0, 0 ) );
}

int Updater::Update( sf::Image *iFrame, sf::Vector2i vWindowPos )
{
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
        Clear ( iFrame );
    
    sf::Uint16 iXPos = 1;
    sf::Uint16 iYPos = 1;
    
    if ( m_Connector->bIsReciving )
    {
        if (m_Connector->sRead( ) >> iXPos >> iYPos) { }
        else
            std::cerr << "ERROR: decoding \n";
    }
    else
    {
        sf::Vector2i v2MousePos = sf::Mouse::getPosition ( );
        iXPos = v2MousePos.x - vWindowPos.x;
        iYPos = v2MousePos.y - vWindowPos.y - sf::VideoMode::getDesktopMode ( ).height/2 - WINDOW_HEIGHT - TOP_OFFSET;
    }
    
    if ( iXPos >= 0 && iXPos <= 800 &&  iYPos >= 0 &&  iYPos <= 800 )
    {
        if ( !m_Connector->bIsReciving )
            Send ( iXPos, iYPos );
        
        iFrame->setPixel( iXPos/8, iYPos/8, sf::Color ( 0, 255, 255 ) );
    }
    
    return 1;
}

void Updater::Send ( sf::Uint16 iXPos, sf::Uint16 iYPos )
{
    if ( iXPos != iLastXPos || iYPos != iLastYPos )
    {
        m_Connector->vSend ( iXPos, iYPos );
        iLastXPos = iXPos;
        iLastYPos = iYPos;
    }
}
