#include "client.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <queue>
#include <thread>

std::queue<std::string, std::deque<std::string>> reqQueue;
std::queue<std::string, std::deque<std::string>> recQueue;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Client &client{Client::getClient()};

    // init the client node
    if (!client.init(2453)) { // Pass the port number and server IP address
        std::cout << "Failed to initialize the client" << std::endl;
        QMessageBox msgBox;
        msgBox.setWindowTitle("Server Error");
        msgBox.setText("Server is not working, Please try again later");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return 0;
    }
    MainWindow w;
    w.show();
    // start the client node in a seperate thread
    std::thread clientStartMethod{[&client]() { client.start(); }};
    return a.exec();
}
