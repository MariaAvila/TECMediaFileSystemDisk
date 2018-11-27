//
// Created by maria on 11/21/18.
//

#ifndef NODES_DISKNODEFACADE_H
#define NODES_DISKNODEFACADE_H

#import "DiskNodes.h"
#include <string>
#include <list>
#include <tinyxml.h>
#include "json.hpp"
#include "Client.h"

using json = nlohmann::json;
/**
 * Class that interacts with the controller Node server
 */
class DiskNodeFacade {
    struct Video{
        std::string code;
        DiskNodes *nodes[4];
        int currentOrder;
    };
private:
    std::list<Video> storage;
    char* IP;
    int port;
    std::string path;
    int currentDiskNode = 0;
public:
    Client *client = new Client(port,IP);
    void GetXML();
    void SwitchOn(int disk);
    DiskNodeFacade(char* ip, int Port, std::string Path);

};


#endif //NODES_DISKNODEFACADE_H
