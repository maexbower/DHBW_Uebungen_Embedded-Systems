//
// Created by max on 15.05.17.
//

#ifndef EMBEDDEDUEBUNGEN05_CLIENTSERVER_H
#define EMBEDDEDUEBUNGEN05_CLIENTSERVER_H
#include <sys/socket.h>
#include <netinet/in.h>

class ClientServerImplementation : public ClientServer
{
public:
    bool Start(Mode mode, unsigned int port, const char *ip);
    enum Command : uint16_t {
        Invalid = 0,
        GeneralErrorReply = 1,
        Echo = 2,
        EchoReply = 3,
        Shutdown = 4,
        ShutdownReply = 5,
        Unsupported = 6
    };
protected:
    int sockfd, newsockfd, portno, n;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    typedef struct packet{
        uint16_t payload_length;
        uint16_t sequence_Number;
        uint16_t command;
        uint16_t handle;
        char* data;
    }packet;
};



#endif //EMBEDDEDUEBUNGEN05_CLIENTSERVER_H
