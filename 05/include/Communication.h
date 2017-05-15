//
// Created by max on 08.05.17.
//

#ifndef EMBEDDEDUEBUNGEN05_COMMUNICATION_H
#define EMBEDDEDUEBUNGEN05_COMMUNICATION_H


class ClientServer {
public :
    enum Mode : unsigned int {
        Server,
        Client
    };

    bool Start(Mode mode, unsigned int port, const char *ip);


};

#endif //EMBEDDEDUEBUNGEN05_COMMUNICATION_H
