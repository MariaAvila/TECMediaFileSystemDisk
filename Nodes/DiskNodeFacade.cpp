//
// Created by maria on 11/21/18.
//

#include "DiskNodeFacade.h"
/**
 * Constructor function that determines the connection parameters
 * for the client
 * @param ip
 * @param Port
 * @param Path
 */
DiskNodeFacade::DiskNodeFacade(std::string ip, int Port, std::string Path) {
    IP = ip;
    port = Port;
    path = Path;
}
/**
 * Function that adds videos to the storage
 */
void DiskNodeFacade::Add() {

}
/**
 * Function that reads videos from the storage
 */
void DiskNodeFacade::Get() {

}
/**
 * Function that allows the user to turn off a disk node
 * @param disk
 */
void DiskNodeFacade::SwitchOn(int disk) {
    for (Video vid : storage){
        vid.nodes[disk]->on = false;
    }
}