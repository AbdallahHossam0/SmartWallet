/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <signin.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This source file defines the SignIn class, managing the sign-in dialog interface, including login functionality and navigation controls.
 * ---------------------------------------------------------------------------------------------------
 */

#include "mainwindow.h"
#include "signin.h"
#include "stringhasher.h"
#include "ui_signin.h"
#include "validator.h"
#include "wallet.h"
#include <QTimer>
#include <iostream>
#include <queue>

// queues to communicate with the client node thread
extern std::queue<std::string, std::deque<std::string>> reqQueue;
extern std::queue<std::string, std::deque<std::string>> recQueue;

SignIn::SignIn(QWidget *parent) : QDialog(parent), ui(new Ui::SignIn) {
    ui->setupUi(this);
    setFixedSize(380, 320);
}

SignIn::~SignIn() { delete ui; }

std::vector<std::string> SignIn::splitString(const std::string &s,
                                             char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void SignIn::on_LoginButton_clicked() {
    Validator validator;
    StringHasher hasher;
    std::string username{ui->UsenameBox->text().toStdString()};
    std::string password{ui->PasswordBox->text().toStdString()};

    // process the sign in request
    if (validator.isValidUsername(username) &&
        validator.isValidPassword(password)) {

        // construct the frame and send it
        std::string frame{"1/" + username + '/' + hasher(password)};

        reqQueue.push(frame);

        while (recQueue.empty())
            ;

        std::string received = recQueue.front();
        recQueue.pop();

        // process the response
        if (received == "0" || received == "1" || received == "2") {
            // Error occured
            ui->ErrorLabel->setText(
                QString::fromStdString("Incorrect Username or Password"));
        } else {
            // Sign in is done
            std::vector<std::string> vec = splitString(received, '/');

            int balance = std::stoi(vec[1]);
            Wallet *walletWindow;
            if (vec.size() == 5) {
                walletWindow = new Wallet(balance, vec[2],
                                          QString::fromStdString(username),
                                          vec[3], vec[4]);
            } else {
                walletWindow =
                    new Wallet(balance, vec[2],
                               QString::fromStdString(username), vec[3], "");
            }
            walletWindow->show();
            walletWindow->setAttribute(Qt::WA_DeleteOnClose, true);
            this->close();
        }
    } else {
        ui->ErrorLabel->setText("Incorrect Username or Password");
    }
}

void SignIn::on_BackToMainWindow_clicked() {
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    close();
}
