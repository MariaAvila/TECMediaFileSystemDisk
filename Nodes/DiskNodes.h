//
// Created by maria on 11/21/18.
//

#ifndef NODES_DISKNODES_H
#define NODES_DISKNODES_H

#include <iostream>
/**
 * Class that simulates the Nodes for the RAID 5 scheme
 */
class DiskNodes {
public:
    int diskSize = 0;
    unsigned char *diskBuffer;
    bool on = true;
    int busySection = 0;
    DiskNodes(int size);
    void Add(unsigned char toAdd[]);
};


#endif //NODES_DISKNODES_H
