/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <client.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DESCRIPTION]: This header file implements a singleton Client class responsible for socket communication with a server in a client-server architecture.
 * ---------------------------------------------------------------------------------------------------
 */

#pragma once

#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

class Client {
  private:
    int m_clientSocket;
    sockaddr_in m_clientAddr;

    Client() : m_clientSocket{-1} {} // this class is a singleton

    Client(const Client &) = delete;
    Client &operator=(const Client &) = delete;

    Client(const Client &&) = delete;
    Client &operator=(const Client &&) = delete;

  public:
    static Client &getClient(); // to get the instance from this class

    bool init(unsigned short portNumber); // method to init the client, should be run before the start method
    void start(void); // this method, once it called the client starts

    ~Client() { close(m_clientSocket); }
};
