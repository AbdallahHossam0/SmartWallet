#include "mainwindow.h"
#include "server.h"
#include <QApplication>
#include <thread>

int main(int argc, char *argv[]) {

    Server &server{Server::getServer()};
    server.init(2453);
    std::cout << "Server is Running" << std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::thread clientStartMethod{[&server]() { server.start(); }};
    return a.exec();
}
