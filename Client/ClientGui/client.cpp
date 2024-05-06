/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <client.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DESCRIPTION]: This source file implements a singleton Client class responsible for socket communication with a server in a client-server architecture.
 * ---------------------------------------------------------------------------------------------------
 */

#include "client.h"
#include <chrono>
#include <queue>
#include <thread>

// pass the requests between the GUI thread and client node to send it to the server
extern std::queue<std::string, std::deque<std::string>> reqQueue;
// pass the response of the server to the GUI from the client node
extern std::queue<std::string, std::deque<std::string>> recQueue;

Client &Client::getClient(void) {
    static Client instance;
    return instance;
}

bool Client::init(unsigned short portNumber) {
    m_clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // create the socket
    if (m_clientSocket < 0) {
        std::cout << "Error creating socket" << std::endl;
        return false;
    }

    m_clientAddr.sin_family = AF_INET;
    m_clientAddr.sin_port = htons(portNumber); // passes the port numver
    m_clientAddr.sin_addr.s_addr = INADDR_ANY; // the server is on the same machine

    // connect to the socket
    if (connect(m_clientSocket, (sockaddr *)&m_clientAddr,
                sizeof(m_clientAddr)) == -1) {
        std::cout << "Error connecting to server" << std::endl;
        return false;

    }

    std::string buffer;
    buffer.resize(23);
    // checks the connection
    int bytesReceived = recv(m_clientSocket, &buffer[0], buffer.size(), 0);
    if (bytesReceived <= 0 || buffer == "Server full. Try later") {
        std::cout << "Reject the connection" << std::endl;
        return false;
    }

    return true;
}

void Client::start(void) {

    std::string message;
    constexpr unsigned short bufferSize{1000};
    std::string buffer;
    buffer.resize(bufferSize);
    int bytesReceived;

    while (true) {
        if (reqQueue.empty()) {
            // checks the queue periodically if it has requests to send
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            continue;
        }
        // send messages on the queue
        message = reqQueue.front();
        reqQueue.pop();
        if (send(m_clientSocket, message.c_str(), message.length(), 0) == -1) {
            std::cout << "Error sending data to server\n";
            continue;
        }
        buffer.resize(bufferSize);
        bytesReceived = recv(m_clientSocket, &buffer[0], buffer.length(), 0);
        if (bytesReceived <= 0) {
            std::cout << "Error receiving data from server" << std::endl;
            continue;
        }
        buffer.resize(bytesReceived);
        std::cout << "Received from server: " << buffer << std::endl;
        // send the response back to the user
        recQueue.push(buffer);
    }
    return;
}
