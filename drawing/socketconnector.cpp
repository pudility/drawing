//
//  socketconnector.cpp
//  drawing
//
//  Created by Zoe IAMZOE.io on 1/15/18.
//  Copyright © 2018 Zoe IAMZOE.io. All rights reserved.
//

#include "socketconnector.hpp"

bool bFetchUserInput ( )
{
    //get an input from the user
    std::cout << "Start: ";
    std::string input;
    std::cin >> input;
    std::cout << "Starting: " << input << std::endl;
    
    //figure out what the user said
    if (input == "server")
        return true;
    else
        return false;
}

Connector::Connector ( )
{
    bIsReciving = bFetchUserInput();
    
    if (bIsReciving)
        server();
    else
        client();
}

Connector::~Connector ( )
{
    tListener.close();
}

void Connector::server ( )
{
    tListener.listen(iPort);
    tListener.accept(tSocket);
}

void Connector::client ( )
{
    tSocket.connect(sIP, iPort);
}

sf::Packet Connector::sRead ( )
{
    sf::Packet pRecived;
    pRecived.clear();
    tSocket.receive( pRecived );
    return pRecived;
}

bool Connector::bCheckIfCanRad ( )
{
    std::string sCheck;
    sRead() >> sCheck;
    if (sCheck == "R")
        return true;
    else
        return false;
}
