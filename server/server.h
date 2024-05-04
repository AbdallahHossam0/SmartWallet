#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <vector>
#include <thread>
#include <string>
#include <cstring>

class Server {
private:
    int m_serverSocket;
    sockaddr_in m_serverAddress;
    std::vector<std::thread> m_clientThreads;
    int m_activeClients;

    void handleClient(int clientSocket);
public:
    Server() : m_serverSocket{-1}, m_activeClients{0} {}
    ~Server() {close(m_serverSocket);}
    bool init(int port);
    void start(void);
};

