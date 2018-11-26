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
void DiskNodeFacade::GetXML() {
    TiXmlDocument doc("example.xml");
    if(doc.LoadFile()){
        TiXmlHandle hDoc(&doc);
        TiXmlElement* pElem;
        TiXmlAttribute * pAttrib;
        TiXmlHandle hRoot(0);

        pElem = hDoc.FirstChild().Element();
        pAttrib = pElem->FirstAttribute();
        int* opCode = (int*) pAttrib;
        switch (*opCode){
            case 0 :
                Video *newVid;
                pElem->NextSibling();
                TiXmlAttribute * one = pElem->FirstAttribute();
                std::string* diskOne = (std::string*) one;
                pElem->NextSibling();
                TiXmlAttribute * two = pElem->FirstAttribute();
                std::string* diskTwo= (std::string*) two;
                pElem->NextSibling();
                TiXmlAttribute * three = pElem->FirstAttribute();
                std::string* diskThree = (std::string*) three;
                pElem->NextSibling();
                TiXmlAttribute * parity = pElem->FirstAttribute();
                std::string* diskParity = (std::string*) parity;
                if(currentDiskNode % 4 == 0){

                    break;
                }
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                std::cout << "Invalid OPCode";
        }
    }
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