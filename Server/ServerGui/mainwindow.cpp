/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <mainwindow.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This source file declares the MainWindow class, responsible for managing the main window interface of the application
 *  and providing methods for updating its components.
 * ---------------------------------------------------------------------------------------------------
 */

#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "server.h"
#include <QTimer>
#include <filesystem>
#include <fstream>
#include <queue>

std::queue<std::string> usersQueue;
std::queue<std::string> Operations;
unsigned int withdrawns;
unsigned int deposits;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setFixedSize(800, 425);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    timer = new QTimer(this);

    std::string filename = "logger.txt";
    std::filesystem::path currentDir = std::filesystem::current_path();
    std::filesystem::path filePath = currentDir / filename;
    if (!std::filesystem::exists(filePath)) {
        std::ofstream logger(filePath);
    }

    connect(timer, &QTimer::timeout, this, &MainWindow::Update);
    timer->start(1000);
    Update();
}

void MainWindow::Update() {
    updateActiveUsers();
    updateUserLog();
    updateOperation();
    updateWithdraws();
    updateDeposits();
}

void MainWindow::updateWithdraws() {
    ui->TotalWithdraw->setText(QString::number(withdrawns));
}

void MainWindow::updateDeposits() {
    ui->TotalDeposited->setText(QString::number(deposits));
}

void MainWindow::updateActiveUsers() {
    ui->ActiveUsers->setText(
        QString::number(Server::getServer().getActiveUser()));
}

void MainWindow::updateOperation() {

    while (!Operations.empty()) {
        std::string op = Operations.front();
        Operations.pop();
        ui->OperationLogs->addItem(QString::fromStdString(op));
        std::ofstream logger("logger.txt", std::ios::app);
        if (logger.is_open()) {
            logger << op << std::endl;
            logger.close();
        } else {
            std::cout << "Error Occured" << std::endl;
        }
    }
}

void MainWindow::updateUserLog() {
    while (!usersQueue.empty()) {
        std::string user = usersQueue.front();
        usersQueue.pop();
        ui->UsersLog->addItem(QString::fromStdString(user));
    }
}

MainWindow::~MainWindow() { delete ui; }
