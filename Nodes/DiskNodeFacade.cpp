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
DiskNodeFacade::DiskNodeFacade(char* ip, int Port, std::string Path) {
    IP = ip;
    port = Port;
    path = Path;
    this->client = new Client(Port,ip);
}
/**
 * Function that adds videos to the storage
 */
void DiskNodeFacade::GetXML() {
    char buffer[1];
    std::string jsonString = client.receive();
    json data = json::parse(jsonString);
    int opCode = data["opcode"];
    std::string code = data["code"];
    switch (opCode){
        case 0:
            std::string disk1 = data["data1"];
            DiskNodes *node1 = new DiskNodes(disk1.length());
            node1->diskBuffer = disk1;
            std::string disk2 = data["data2"];
            DiskNodes *node2 = new DiskNodes(disk2.length());
            node2->diskBuffer = disk2;
            std::string disk3 = data["data3"];
            DiskNodes *node3 = new DiskNodes(disk3.length());
            node3->diskBuffer = disk3;
            std::string parity = data["parity"];
            DiskNodes *nodeParity = new DiskNodes(parity.length());
            nodeParity->diskBuffer = parity;
            Video *newVid;
            newVid->code = code;
            newVid->currentOrder = currentDiskNode%4;
            if (currentDiskNode%4 ==0){
                newVid->nodes[0] = node1;
                newVid->nodes[1] = node2;
                newVid->nodes[2] = node3;
                newVid->nodes[3] = nodeParity;
                storage.push_back(*newVid);
                currentDiskNode++;
                break;
            }
            if (currentDiskNode%4 ==1){
                newVid->nodes[0] = node1;
                newVid->nodes[1] = node2;
                newVid->nodes[2] = nodeParity;
                newVid->nodes[3] = node3;
                storage.push_back(*newVid);
                currentDiskNode++;
                break;

            }
            if (currentDiskNode%4 ==2){
                newVid->nodes[0] = node1;
                newVid->nodes[1] = nodeParity;
                newVid->nodes[2] = node2;
                newVid->nodes[3] = node3;
                storage.push_back(*newVid);
                currentDiskNode++;
                break;

            }
            if (currentDiskNode%4 ==3){
                newVid->nodes[0] = nodeParity;
                newVid->nodes[1] = node1;
                newVid->nodes[2] = node2;
                newVid->nodes[3] = node3;
                storage.push_back(*newVid);
                currentDiskNode++;
                break;
            }
            else{
                break;
            }
        case 1:
            json Send;
            for(Video vid : storage){
                if (vid.code == code){
                    switch (vid.currentOrder){
                        case 0:
                            Send = {{"data1",vid.nodes[0]->diskBuffer},{"data2",vid.nodes[1]->diskBuffer},{"data3",vid.nodes[2]->diskBuffer},{"parity",vid.nodes[3]->diskBuffer}};
                            break;
                        case 1:
                            Send = {{"data1",vid.nodes[0]->diskBuffer},{"data2",vid.nodes[1]->diskBuffer},{"data3",vid.nodes[3]->diskBuffer},{"parity",vid.nodes[2]->diskBuffer}};
                            break;
                        case 2:
                            Send = {{"data1",vid.nodes[0]->diskBuffer},{"data2",vid.nodes[2]->diskBuffer},{"data3",vid.nodes[3]->diskBuffer},{"parity",vid.nodes[1]->diskBuffer}};
                            break;
                        case 3:
                            Send = {{"data1",vid.nodes[1]->diskBuffer},{"data2",vid.nodes[2]->diskBuffer},{"data3",vid.nodes[3]->diskBuffer},{"parity",vid.nodes[0]->diskBuffer}};
                            break;
                        default:
                            break;
                    }
                }
            }
            break;
        case 2:
            for(Video vid : storage){
                if (vid.code == code){
                    storage.remove(vid);
                }
            }
            break;
        default:
            break;
    }

}

/**
 * Function that allows the user to turn off a disk node
 * @param disk
 */
void DiskNodeFacade::SwitchOn(int disk) {
    for (Video vid : storage){
        vid.nodes[disk]->on = false;
        vid.nodes[disk]->delNode();
    }
}