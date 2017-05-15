//
// Created by max on 08.05.17.
//

#include "../include/Communication.h"
#include "../include/ClientServer.h"

bool ClientServerImplementation::Start ( Mode mode , unsigned int port , const char * ip )
{
    char buffer[256];
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(0 > sockfd)
    {
        return false;
    }
    //Set Adress Family
    serv_addr.sin_family = AF_INET;
    //Set Port No
    serv_addr.sin_port = htons(static_cast<uint16_t >(port));

    if(mode == Mode::Server)
    {
        clilen = sizeof(cli_addr);
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        {
            return false;
        }
        for (;;) {
            ssize_t recvlen = recvfrom(sockfd, buffer, 255, 0, (struct sockaddr *)&cli_addr, &clilen);
            if (recvlen > 0) {
                buffer[recvlen] = 0;
            }
        }
    }else if(ClientServer::Mode::Client == mode){
        if(!ip)
        {
            return false;
        }
        sendto(sockfd, "Teshkbvhjvghkcghkvgjvjvt123", 300, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    }else{
        return false;
    }
    return true;
}