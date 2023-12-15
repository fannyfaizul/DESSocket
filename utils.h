#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <pthread.h>
#include <string>

int createTCPIPV4Socket(){
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if(socketFD == -1){
        std::cout << "Socket creation failed" << std::endl;
        return -1;
    }
    return socketFD;
}
struct sockaddr_in* createTCPIP4Address(const char* ip, int port){
    sockaddr_in* address = new sockaddr_in;
    address->sin_family = AF_INET;
    address->sin_port = htons(port);
    // handle empty ip
    if(strcmp(ip, "") == 0){
        address->sin_addr.s_addr = INADDR_ANY;
        return address;
    }
    inet_pton(AF_INET, ip, &(address->sin_addr));
    return address;
}

#endif