//
//  socketconnector.hpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#ifndef socketconnector_hpp
#define socketconnector_hpp

#include <iostream>
#include <initializer_list>

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/Packet.hpp>

class Connector
{
public:
    Connector ( );
    ~Connector ( );

    sf::Packet sRead ( );
    
    bool bCheckIfCanRad ( );

    template<typename T, typename... Args>
    void vSend ( T tIn, Args... AArgs )
    {
        pPacketToSend << tIn;
        
        vSend ( AArgs... );
    }
    
    template <typename T>
    void vSend ( T tIn )
    {
        pPacketToSend << tIn;
        tSocket.send( pPacketToSend );
        pPacketToSend.clear();
    }
    
    bool bIsReciving = true;
private:
    sf::TcpSocket tSocket;
    sf::TcpListener tListener;
    std::string sIP = "localhost";
    sf::Packet pPacketToSend;
    sf::Packet pLastSent;

    int iPort = 3000;
    bool bIsSearching = true;
    
    void server ( );
    void client ( );
};

#endif /* socketconnector_hpp */
