#include "server.h"

Server &Server::getServer() {
    static Server instance;
    return instance;
}

void Server::handleClient(int clientSocket) {
    constexpr unsigned char maxBufferSize = 255;

    while (true) {
        char buffer[maxBufferSize];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived <= 0) {
            std::cout << "Error receiving data from client" << std::endl;
            break;
        }
        buffer[bytesReceived] = '\0';
        std::cout << "Message from client: " << buffer << std::endl;
        CustomerManagement &manager = CustomerManagement::getCustomerManager();
        std::string bufferRec = manager.handleRequests(buffer);
        std::cout << "I sent " << bufferRec << std::endl;
        send(clientSocket, bufferRec.c_str(), bufferRec.length(), 0);
    }

    std::cout << "Socket Closed" << std::endl;
    close(clientSocket);
    m_activeClients--;
}

bool Server::init(int port) {

    m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_serverSocket < 0) {
        std::cout << "Error creating socket" << std::endl;
        return false;
    }

    m_serverAddress.sin_family = AF_INET;
    m_serverAddress.sin_port = htons(port);
    m_serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(m_serverSocket, (sockaddr *)&m_serverAddress,
             sizeof(m_serverAddress)) < 0) {
        std::cout << "Error binding socket" << std::endl;
        return false;
    }

    if (listen(m_serverSocket, 25) < 0) {
        std::cout << "Error listening for connections" << std::endl;
        return false;
    }

    std::cout << "Server listening on port " << port << std::endl;
    return true;
}

void Server::start() {
    sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int clientSocket;

    while (true) {
        clientSocket =
            accept(m_serverSocket, (sockaddr *)&clientAddr, &clientLen);
        if (clientSocket < 0) {
            std::cout << "Error accepting connection" << std::endl;
            continue;
        }

        if (m_activeClients >= 3) {
            std::cout << "Connection rejected, Server is Full" << std::endl;
            send(clientSocket, "Server full. Try later", 22, 0);
            close(clientSocket); // Close the socket to reject the connection
            continue;
        }
        send(clientSocket, "Done", 4, 0);
        std::cout << "Client connected" << std::endl;
        m_activeClients++;
        m_clientThreads.push_back(
            std::thread(&Server::handleClient, this, clientSocket));
    }
}