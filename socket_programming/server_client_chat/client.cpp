#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main() {
    // Create a socket
    // SOCK_STREAM = TCP
    int ClientSock = socket(AF_INET, SOCK_STREAM, 0);
    if (ClientSock == -1) {
        std::cerr << "Can't create socket! Quitting" << std::endl;
        return -1;
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    int connResult = connect(ClientSock, (sockaddr*)&hint, sizeof(hint));
    if (connResult == -1) {
        std::cerr << "Can't connect to server! Quitting" << std::endl;
        close(ClientSock);
        return -1;
    }
    std::string userInput = "Hello from the client";
    send(ClientSock, userInput.c_str(), userInput.size() + 1, 0);

    close(ClientSock);

    return 0;
}
