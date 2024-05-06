#include "server.h"

using namespace std;

int main() {
    Server &server{Server::getServer()};
    server.init(2453);

    cout << "Server is Running" << endl;

    server.start();

    return 0;
}
