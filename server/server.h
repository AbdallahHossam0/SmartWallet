#pragma once

#include "customer_management.h"
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>

class Server {
  private:
    int m_serverSocket;
    int m_activeClients;
    std::vector<std::thread> m_clientThreads;
    sockaddr_in m_serverAddress;

    Server() : m_serverSocket{-1}, m_activeClients{0} {}

    Server(const Server &) = delete;
    Server &operator=(const Server &) = delete;

    Server(Server &&) = delete;
    Server &operator=(Server &&) = delete;

    void handleClient(int clientSocket);

  public:
    static Server &getServer();

    bool init(int port);
    void start(void);

    ~Server() { close(m_serverSocket); }
};
