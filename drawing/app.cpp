//
//  app.cpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#include "app.hpp"

void App::run()
{
    m_RenderWindow.create( sf::VideoMode ( 800, 800 ), "Draw", sf::Style::Default );

    m_View.setPosition( 0, 0 );
    m_View.setScale( 8, 8 );
    
    m_Frame = new sf::Image ( );
    m_Frame->create( 100, 100 );
    
    m_Updater = new Updater ( );
    
    while ( m_RenderWindow.isOpen( ) )
    {
        sf::Event event;
        while ( m_RenderWindow.pollEvent( event ) )
            if ( event.type == sf::Event::Closed )
                m_RenderWindow.close( );
        
        if ( m_Updater->Update( m_Frame, m_RenderWindow.getPosition ( ) ) == 1 ) {
            sf::Texture tFrameTexture;
            tFrameTexture.loadFromImage( *m_Frame );
            m_View.setTexture( tFrameTexture );
            m_RenderWindow.draw( m_View );
            m_RenderWindow.setActive( );
            m_RenderWindow.display( );
        }
    }
}
