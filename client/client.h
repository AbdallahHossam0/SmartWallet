#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>


class Client{
private:
    int m_clientSocket;
    sockaddr_in m_clientAddr;

public:
    Client() : m_clientSocket{-1} {} 

    ~Client() {close(m_clientSocket);}

    bool init(unsigned short portNumber);
    void start(void);

};