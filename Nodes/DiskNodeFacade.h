//
// Created by maria on 11/21/18.
//

#ifndef NODES_DISKNODEFACADE_H
#define NODES_DISKNODEFACADE_H

#import "DiskNodes.h"
#include <string>
#include <list>
/**
 * Class that interacts with the controller Node server
 */
class DiskNodeFacade {
    struct Video{
        std::string code;
        DiskNodes *nodes[4];
    };
private:
    std::list<Video> storage;
    std::string IP;
    int port;
    std::string path;
public:
    void Add();
    void Get();
    void SwitchOn(int disk);
    DiskNodeFacade(std::string ip, int Port, std::string Path);

};


#endif //NODES_DISKNODEFACADE_H
