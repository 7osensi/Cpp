#include <iostream>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

int NewServerSockFD;

int main() {
    // Create socket
    /* domain (Socket family) : (AF_INET, AF_IPX, and AF_PACKET)
       type   (Socket type)   : (SOCK_STREAM or SOCK_DGRAM) */
    int ServerSock = socket(AF_INET, SOCK_STREAM, 0);
    if (ServerSock == -1) {
        std::cerr << "Can't create socket! Quitting" << std::endl;
        return -1;
    }

    // Bind socket
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(54000);

    int bind_server = bind(ServerSock, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    if (bind_server == 0) {
        std::cerr << "Server is bind to port 54000" << std::endl;
    } else {
        std::cout << "Binding failed" << std::endl;
        return -1;
    }

    // Listen to the clients connection requests
    if (listen(ServerSock, 1)) {
        std::cerr << "Listening..." << std::endl;
    }

    // Set up timeout
    struct timeval timeout;
    timeout.tv_sec = 5;  // 5 seconds
    timeout.tv_usec = 0;

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(ServerSock, &readfds);

    // Wait for incoming connections with timeout
    int activity = select(ServerSock + 1, &readfds, NULL, NULL, &timeout);

    if (activity == -1) {
        std::cerr << "Error in select" << std::endl;
        return -1;
    } else if (activity == 0) {
        std::cerr << "Timeout occurred" << std::endl;
        return -1;
    } else {
        // Accept requests
        struct sockaddr_in connectedClientAddress;
        socklen_t clientAddLength = sizeof(connectedClientAddress);

        /* Serversock, creates a new connected socket, and returns a new file descriptor referring to that socket. At this point, 
        *  the connection is established between client and server, and they are ready to transfer data.
        */
        NewServerSockFD = accept(ServerSock, (struct sockaddr*)&connectedClientAddress, &clientAddLength);

        if (NewServerSockFD == -1) {
            std::cerr << "Problem with client connecting! Quitting" << std::endl;
            return -1;
        }
    }

    // Receive message
    char buf[4096];
    recv(NewServerSockFD, buf, 4096, 0);

    std::cout << buf << std::endl;

    // Close the newly-created socket
    close(NewServerSockFD);
    // Close the listening socket
    close(ServerSock);

    return 0;
}
