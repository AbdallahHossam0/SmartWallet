/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <server.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file declares the Server class, managing server-side functionality such as initialization, client connection handling, and multithreading.
 * ---------------------------------------------------------------------------------------------------
 */

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

    void handleClient(int clientSocket); // to handle the client, it starts a seperate thread for each client

  public:
    static Server &getServer();

    bool init(int port); // this method should be called and returen true before the start method
    void start(void); // the server node runs after calling this function
    int getActiveUser(void) { return m_activeClients; }

    ~Server() { close(m_serverSocket); }
};
