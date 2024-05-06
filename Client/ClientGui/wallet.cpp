/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <wallet.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This source file defines the Wallet class, managing the wallet dialog interface with functionalities for financial transactions,
 *  log management, and input validation.
 * ---------------------------------------------------------------------------------------------------
 */

#include "ui_wallet.h"
#include "wallet.h"
#include <queue>

// queues to communicate with the client node thread
extern std::queue<std::string, std::deque<std::string>> reqQueue;
extern std::queue<std::string, std::deque<std::string>> recQueue;

// construct the wallet GUI
Wallet::Wallet(int balance, std::string name, QString username,
               std::string gender, std::string logs, QWidget *parent)
  : QDialog(parent), ui(new Ui::Wallet), m_username{username} {
    ui->setupUi(this);
    ui->BalanceShow->display(balance);
    // show greeting message
    std::string greeting{"Hello, "};
    if (gender == "M") {
        greeting += "Mr ";
    } else {
        greeting += "Mrs ";
    }
    ui->GreetingLabel->setText(QString::fromStdString(greeting) +
                               QString::fromStdString(name));
    ui->tabWidget->setCurrentWidget(0);
    ui->tabWidget->setCurrentIndex(0);
    std::vector logVector{splitString(logs)};
    parselogsToList(logVector);
}

std::string Wallet::getWordAtIndex(const std::string &line, int index) {
    std::istringstream iss(line);
    std::string word;

    for (int i = 0; i <= index; ++i) {
        if (!(iss >> word)) {
            return "";
        }
    }

    return word;
}

// add logs to the list
void Wallet::parselogsToList(const std::vector<std::string> &strVec) {
    ui->LogList->clear();
    for (const std::string &element : strVec) {
        QString item = QString::fromStdString(element);
        ui->LogList->addItem(item);
    }
    return;
}

std::vector<std::string> Wallet::splitString(const std::string &s,
                                             char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Wallet::~Wallet() { delete ui; }

void Wallet::on_WithdrawButton_clicked() {
    std::string money = ui->MoneyToWithdraw->text().toStdString();
    if (m_validator.isValidMoney(money)) {
        std::string frame = "2/" + m_username.toStdString() + "/" + money;

        reqQueue.push(frame);
        while (recQueue.empty())
            ;

        std::string received = recQueue.front();
        recQueue.pop();

        if (received == "0" || received == "1" || received == "2") {
            ui->WithdrawLabel->setText(
            QString::fromStdString("Failed, Check Your Balance")); // balance can't cover the requested amount
        } else {
            std::vector<std::string> vec = splitString(received, '/');
            ui->BalanceShow->display(stoi(vec[1]));
            vec = splitString(vec[2], '-');
            parselogsToList(vec);
        }
        ui->MoneyToWithdraw->clear();
    } else {
        ui->WithdrawLabel->setText(
            "Enter Valid Money, Max Available Transaction is 99999");
    }
}

void Wallet::on_DepositButton_clicked() {
    std::string money = ui->MoneyToDepositeBox->text().toStdString();
    if (m_validator.isValidMoney(money)) {
        std::string frame = "3/" + m_username.toStdString() + "/" + money;
        reqQueue.push(frame);
        while (recQueue.empty())
            ;

        std::string received = recQueue.front();
        recQueue.pop();

        if (received == "0" || received == "1" || received == "2") {
            ui->DepositLabel->setText(QString::fromStdString("Failed"));
        } else {
            std::vector<std::string> vec = splitString(received, '/');
            ui->BalanceShow->display(stoi(vec[1]));
            vec = splitString(vec[2], '-');
            parselogsToList(vec);
        }
        ui->MoneyToDepositeBox->clear();
    } else {
        ui->DepositLabel->setText(
            "Enter Valid Money, Max Available Transaction is 99999");
    }
}

void Wallet::on_TransferButton_clicked() {
    std::string money = ui->MoneyToTransfer->text().toStdString();
    std::string other = ui->ReceiverUsernameBox->text().toStdString();
    if (m_validator.isValidMoney(money) && m_validator.isValidUsername(other)) {

        std::string frame =
            "4/" + m_username.toStdString() + "/" + other + "/" + money;
        reqQueue.push(frame);
        while (recQueue.empty())
            ;

        std::string received = recQueue.front();
        recQueue.pop();

        if (received == "0" || received == "1") {
            ui->TransferStatusLabel->setText(
                QString::fromStdString("Check Username"));
        } else if (received == "2") {
            ui->TransferStatusLabel->setText(
                QString::fromStdString("Check your Balance"));
        } else {
            std::vector<std::string> vec = splitString(received, '/');
            ui->BalanceShow->display(stoi(vec[1]));
            vec = splitString(vec[2], '-');
            parselogsToList(vec);
        }

        ui->MoneyToTransfer->clear();
        ui->ReceiverUsernameBox->clear();
    } else if (m_validator.isValidUsername(other)) {
        ui->TransferStatusLabel->setText(
            "Enter Valid Money, Max Available Transaction is 99999");
    } else {
        ui->TransferStatusLabel->setText("Enter Valid Username");
    }
}

void Wallet::on_RefreshButton_clicked() {
    std::string frame = "5/" + m_username.toStdString();
    reqQueue.push(frame);
    while (recQueue.empty())
        ;

    std::string received = recQueue.front();
    recQueue.pop();
    if (received == "0" || received == "0") {
        ui->RefreshLabel->setText(QString::fromStdString("Error"));
    } else {
        std::vector<std::string> vec = splitString(received, '/');
        ui->BalanceShow->display(stoi(vec[1]));
        vec = splitString(vec[2], '-');
        parselogsToList(vec);
    }
}

void Wallet::on_UndoButton_clicked() {
    QListWidgetItem *currentItem = ui->LogList->currentItem();
    if (!currentItem) {
        ui->LogLabel->setText("Please select a valid Log");
        return;
    }
    std::string log = currentItem->text().toStdString();

    std::string money = getWordAtIndex(log, 1);
    std::string frame;
    std::string received;
    switch (log[0]) {
    case 'D':
        frame = "2/" + m_username.toStdString() + "/" + money;

        reqQueue.push(frame);
        while (recQueue.empty())
            ;

        received = recQueue.front();
        recQueue.pop();

        if (received == "0" || received == "1" || received == "2") {
            ui->LogLabel->setText(
                QString::fromStdString("Failed, Check Your Balance"));
        } else {
            std::vector<std::string> vec = splitString(received, '/');
            ui->BalanceShow->display(stoi(vec[1]));
            vec = splitString(vec[2], '-');
            parselogsToList(vec);
        }

        break;
    case 'W':
        frame = "3/" + m_username.toStdString() + "/" + money;

        reqQueue.push(frame);
        while (recQueue.empty())
            ;

        received = recQueue.front();
        recQueue.pop();
        if (received == "0" || received == "1" || received == "2") {
            ui->LogLabel->setText(QString::fromStdString("Failed"));
        } else {
            std::vector<std::string> vec = splitString(received, '/');
            ui->BalanceShow->display(stoi(vec[1]));
            vec = splitString(vec[2], '-');
            parselogsToList(vec);
        }
        break;
    default:
        ui->LogLabel->setText(
            "You only can undo deposit and withdraw transactions");
    }
}

void Wallet::on_RedoButton_clicked() {
    QListWidgetItem *currentItem = ui->LogList->currentItem();
    if (!currentItem) {
        ui->LogLabel->setText("Please select a valid Log");
        return;
    }
    std::string log = currentItem->text().toStdString();
    std::string money = getWordAtIndex(log, 1);
    std::string other = getWordAtIndex(log, 3);
    std::string frame;
    std::string received;
    switch (log[0]) {
    case 'D':
        frame = "3/" + m_username.toStdString() + "/" + money;

        reqQueue.push(frame);
        while (recQueue.empty())
            ;

        received = recQueue.front();
        recQueue.pop();
        if (received == "0" || received == "1" || received == "2") {
            ui->LogLabel->setText(QString::fromStdString("Failed"));
        } else {
            std::vector<std::string> vec = splitString(received, '/');
            ui->BalanceShow->display(stoi(vec[1]));
            vec = splitString(vec[2], '-');
            parselogsToList(vec);
        }
        break;
    case 'W':
        frame = "2/" + m_username.toStdString() + "/" + money;

        reqQueue.push(frame);
        while (recQueue.empty())
            ;

        received = recQueue.front();
        recQueue.pop();
        if (received == "0" || received == "1" || received == "2") {
            ui->LogLabel->setText(
                QString::fromStdString("Failed, Check Your Balance"));
        } else {
            std::vector<std::string> vec = splitString(received, '/');
            ui->BalanceShow->display(stoi(vec[1]));
            vec = splitString(vec[2], '-');
            parselogsToList(vec);
        }
        break;
    case 'T':
        frame = "4/" + m_username.toStdString() + "/" + other + "/" + money;
        reqQueue.push(frame);
        while (recQueue.empty())
            ;

        received = recQueue.front();
        recQueue.pop();
        if (received == "0" || received == "1") {
            ui->LogLabel->setText(QString::fromStdString("Check Username"));
        } else if (received == "2") {
            ui->LogLabel->setText(QString::fromStdString("Check your Balance"));
        } else {
            std::vector<std::string> vec = splitString(received, '/');
            ui->BalanceShow->display(stoi(vec[1]));
            vec = splitString(vec[2], '-');
            parselogsToList(vec);
        }
        break;
    default:
        ui->LogLabel->setText(
            "You only can undo deposit and withdraw transactions");
    }
}
