#include "utils.h"
#include "des.h"

int main(){
    int socketFD = createTCPIPV4Socket();
    struct sockaddr_in* address = createTCPIP4Address("127.0.0.1", 2345);

    int result = connect(socketFD, (sockaddr*)address, sizeof(*address));
    if(result == -1){
        std::cout << "Connection failed" << std::endl;
        return -1;
    }
    while(true){
        string message;
        message.clear();
        cout << "Enter message: ";
        getline(cin, message);
        string cipher = encryptor(message);
        send(socketFD, cipher.c_str(), cipher.length(), 0);

        char buffer[1024];
        memset(buffer, 0, 1024);
        recv(socketFD, buffer, 1024, 0);

        size_t len = strlen(buffer);
        buffer[len] = '\0';
        printf("Message from cipher: %s\n", buffer);
        string decrypted = decryptor(buffer);

        std::cout << "Message from server: " << decrypted << std::endl;
    }
    close(socketFD);
    return 0;

}