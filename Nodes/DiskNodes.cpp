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
}
 void DiskNodes::delNode() {
    if(!on){
        this->diskBuffer = "nullptr";
    }
}