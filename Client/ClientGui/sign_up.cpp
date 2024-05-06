/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <sign_up.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This source file defines the Sign_Up class, managing the sign-up dialog interface, including navigation and sign-up functionality.
 * ---------------------------------------------------------------------------------------------------
 */

#include "mainwindow.h"
#include "sign_up.h"
#include "stringhasher.h"
#include "ui_sign_up.h"
#include "validator.h"
#include "wallet.h"
#include <QTimer>
#include <queue>

// queues to communicate with the client node thread
extern std::queue<std::string, std::deque<std::string>> reqQueue;
extern std::queue<std::string, std::deque<std::string>> recQueue;


Sign_Up::Sign_Up(QWidget *parent) : QDialog(parent), ui(new Ui::Sign_Up) {
    ui->setupUi(this);
    setFixedSize(410, 675);
    // fill possible ages on the ages compo box min age = 18 and max age = 99
    for (int i = 18; i < 100; ++i) {
        ui->AgeCombo->addItem(QString::number(i));
    }

    // fill the gender into the gender compo box
    ui->GenderCompo->addItem("Female");
    ui->GenderCompo->addItem("Male");
}

Sign_Up::~Sign_Up() { delete ui; }

void Sign_Up::on_BackToMainWindow_clicked() {
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose, true); // to free the window when it is closed
    close();
}

void Sign_Up::on_SignUpButton_clicked() {
    Validator validator;
    StringHasher hasher;

    std::string toCheck = ui->FirstNameBox->text().toStdString();

    // check user input first name
    if (!validator.isValidName(toCheck)) {
        ui->ErrorLabel->setText("Incorrect First Name, Only Use Latters\nSize "
                                "should be between 3 and 9");
        return;
    }

    // check user input last name
    toCheck = ui->LastNameBox->text().toStdString();
    if (!validator.isValidName(toCheck)) {
        ui->ErrorLabel->setText("Incorrect Last Name, Only Use letters\nSize "
                                "should be between 3 and 9");
        return;
    }

    // check user input username
    toCheck = ui->UsernameBox->text().toStdString();
    if (!validator.isValidUsername(toCheck)) {
        ui->ErrorLabel->setText(
            "Invalid Username: Use only letters, numbers, and "
            "underscores\nSize should be between 3 and 15");
        return;
    }

    //checks the national id
    toCheck = ui->NationalIdBox->text().toStdString();
    if (!validator.isValidID(toCheck)) {
        ui->ErrorLabel->setText(
            "Incorrect Ntional ID\nSize should be exactly 14");
        return;
    }

    // checks the mobile number
    toCheck = ui->MobileNumberBox->text().toStdString();
    if (!validator.isValidMobileNumber(toCheck)) {
        ui->ErrorLabel->setText(
            "Incorrect Mobile Number\nSize should be exactly 11");
        return;
    }
    std::string toCheck2;

    toCheck2 = ui->Password1Box->text().toStdString();
    toCheck = ui->Password2Box->text().toStdString();

    // checks if passwords are matched
    if (!validator.isPasswordMatched(toCheck, toCheck2)) {
        ui->ErrorLabel->setText("Passwords are not Matched");
        return;
    }

    // check if password consists of 6 numbers
    if (!validator.isValidPassword(toCheck)) {
        ui->ErrorLabel->setText(
            "Incorrect Password\nEnsure password consists of 6 numbers");
        return;
    }

    std::string gender;

    if (ui->GenderCompo->currentText() == "Male") {
        gender = 'M';
    } else {
        gender = 'F';
    }

    // construct the frame to send it to the server
    std::string frame{"0/" + ui->FirstNameBox->text().toStdString() + '/' +
                      ui->UsernameBox->text().toStdString() + '/' +
                      hasher(ui->Password1Box->text().toStdString()) + '/' +
                      gender};

    // send the frame
    reqQueue.push(frame);
    // wait for the response
    while (recQueue.empty())
        ;

    // read the response
    std::string received = recQueue.front();
    recQueue.pop();

    // process the response
    if (received != "11") {
        ui->ErrorLabel->setText("Username is already token");
    } else {
        Wallet *walletWindow =
            new Wallet(0, ui->FirstNameBox->text().toStdString(),
                       ui->UsernameBox->text(), gender, "");
        walletWindow->show();
        walletWindow->setAttribute(Qt::WA_DeleteOnClose, true);
        this->close();
    }

    return;
}
