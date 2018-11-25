//
// Created by maria on 11/21/18.
//

#include "DiskNodes.h"
/**
 * Constructor that allocates the size needed per disk
 * @param size
 */
DiskNodes::DiskNodes(int size) {
    diskSize = size;
    diskBuffer = new (std::nothrow) unsigned char [size];
    if (diskBuffer == nullptr){
        std::cout << "Error in memory allocation";
        diskSize = 0;
    }
}
/**
 *Function that allows the user to add values
 * @param toAdd
 */
void DiskNodes::Add(unsigned char toAdd[]) {
    for (int i = 0; i < diskSize; i++){
        diskBuffer[busySection] = toAdd[i];
        busySection++;
    }
}