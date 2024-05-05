#include "signin.h"
#include "ui_signin.h"
#include "mainwindow.h"
#include "validator.h"
#include <QTimer>


SignIn::SignIn(QWidget *parent) : QDialog(parent), ui(new Ui::SignIn) {
    ui->setupUi(this);
    setFixedSize(380, 320);
}

SignIn::~SignIn() { delete ui; }

void SignIn::on_LoginButton_clicked()
{
    Validator validator;
    std::string username {ui->UsenameBox->text().toStdString()};
    std::string password {ui->PasswordBox->text().toStdString()};

    if(validator.isValidUsername(username) && validator.isValidPassword(password)){
        ui->ErrorLabel->setStyleSheet("color: green;");
        ui->ErrorLabel->setText("Your Wallet Created\n Your wallet will be lanched automatically");

        QTimer::singleShot(1500, this, [this](){
            this->close();
        });
    }
    else{
        ui->ErrorLabel->setText("Incorrect Username or Password");
    }
}


void SignIn::on_BackToMainWindow_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    //the current window
    close();
    deleteLater();
}

