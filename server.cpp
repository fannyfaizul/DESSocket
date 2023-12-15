
#include "utils.h"
#include "des.h"

int main(){

    int serverSocketFD = createTCPIPV4Socket();
    struct sockaddr_in* serverAddress = createTCPIP4Address("", 2345);

    //bind
    if(bind(serverSocketFD, (sockaddr*)serverAddress, sizeof(*serverAddress)) == -1){
        std::cout << "Bind failed" << std::endl;
        return -1;
    }

    int listenResult = listen(serverSocketFD, 10);

    struct sockaddr_in clientAddress;
    int clientAddressSize = sizeof(clientAddress);
    int clientSocketFD = accept(serverSocketFD, (sockaddr*)&clientAddress, (socklen_t*)&clientAddressSize);
    while(true){
        char buffer[1024];
        memset(buffer, 0, 1024);
        ssize_t amount_recv = recv(clientSocketFD, buffer, 1024, 0);
        if(amount_recv == 0){
            std::cout << "Client disconnected" << std::endl;
            break;
        }
        size_t len = strlen(buffer);
        buffer[len] = '\0';

        printf("Message from client: %s\n", buffer);

        // sendback to client
        send(clientSocketFD, buffer, strlen(buffer), 0);
    }
    close(clientSocketFD);
    close(serverSocketFD);
    return 0;
}