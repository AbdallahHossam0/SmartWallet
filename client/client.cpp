#include "client.h"

Client &Client::getClient(void) {
    static Client instance;
    return instance;
}

bool Client::init(unsigned short portNumber) {
    m_clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_clientSocket < 0) {
        std::cout << "Error creating socket" << std::endl;
        return false;
    }

    m_clientAddr.sin_family = AF_INET;
    m_clientAddr.sin_port = htons(portNumber);
    m_clientAddr.sin_addr.s_addr = INADDR_ANY;

    if (connect(m_clientSocket, (sockaddr *)&m_clientAddr,
                sizeof(m_clientAddr)) == -1) {
        std::cout << "Error connecting to server" << std::endl;
        return false;
    }

    std::string buffer;
    buffer.resize(23);
    int bytesReceived = recv(m_clientSocket, &buffer[0], buffer.size(), 0);

    if (bytesReceived <= 0 || buffer == "Server full. Try later") {
        std::cout << "Reject the connection" << std::endl;
        return false;
    }

    return true;
}

void Client::start(void) {
    std::string message;
    constexpr unsigned char bufferSize{255};
    std::string buffer;
    buffer.resize(bufferSize);
    int bytesReceived;

    while (true) {
        std::getline(std::cin, message);
        if (send(m_clientSocket, message.c_str(), message.length(), 0) == -1) {
            std::cerr << "Error sending data to server\n";
            continue;
        }
        buffer.resize(bufferSize);
        bytesReceived = recv(m_clientSocket, &buffer[0], sizeof(buffer) - 1, 0);
        if (bytesReceived <= 0) {
            std::cout << "Error receiving data from server" << std::endl;
            continue;
        }
        buffer.resize(bytesReceived);
        std::cout << "Received from server: " << buffer << std::endl;
        if (buffer == "close") {
            break;
        }
    }
    return;
}