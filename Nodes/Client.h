//
// Created by maria on 11/26/18.
//

#include "json.hpp"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <arpa/inet.h>

using json = nlohmann::json;

#ifndef NODES_CLIENT_H
#define NODES_CLIENT_H


class Socket {
protected:
    unsigned char socketInZero[8];

    sockaddr_in serverAddress;
    sockaddr_in clientAddress;
    socklen_t clientLenght;
    char buffer[256];
    Socket(){};
};

class Client: Socket{
public:
    void send(json Json);
    std::string receive();
    int clientSocket;
    int port;
    Client(int port, char* ip);

};


#endif //NODES_CLIENT_H
