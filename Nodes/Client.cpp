//
// Created by maria on 11/26/18.
//

#include "Client.h"

Client::Client(int port, char* ip) {
    this->port = htons(port);
    this->clientSocket = socket(AF_INET,SOCK_STREAM,0);
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = this->port;
    serverAddress.sin_addr.s_addr = inet_addr(ip);
    connect(this->clientSocket,(struct sockaddr *)&serverAddress, sizeof(serverAddress));
}

void Client::send(json Json) {
    write(this->clientSocket, Json.dump().data(),256);
}

std::string Client::receive() {
    std::string message;
    char buffer[1];
    while (true){
        read(this->clientSocket,buffer,1);
        if ((int)buffer[0] == 4){
            break;
        }
        message.push_back(buffer[0]);
    }
    return message;
}