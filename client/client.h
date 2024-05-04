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

    Client() : m_clientSocket{-1} {}

    Client(const Client &) = delete;
    Client &operator=(const Client &) = delete;

    Client(const Client &&) = delete;
    Client &operator=(const Client &&) = delete;

  public:
    static Client &getClient();

    bool init(unsigned short portNumber);
    void start(void);

    ~Client() { close(m_clientSocket); }
};