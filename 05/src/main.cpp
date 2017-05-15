#include "../include/Communication.h"
#include "../include/ClientServer.h"

int main() {
    ClientServerImplementation server;
    server.Start(ClientServer::Mode::Server, 25555, "127.0.0.1");
    ClientServerImplementation client;
    client.Start(ClientServer::Mode::Client, 25555, "127.0.0.1");

}