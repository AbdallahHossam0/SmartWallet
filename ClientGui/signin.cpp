#include "signin.h"
#include "ui_signin.h"
#include "mainwindow.h"

SignIn::SignIn(QWidget *parent) : QDialog(parent), ui(new Ui::SignIn) {
    ui->setupUi(this);
}

SignIn::~SignIn() { delete ui; }

void SignIn::on_LoginButton_clicked()
{
    ui->ErrorLabel->setText("Incorrect Username or Password");
}


void SignIn::on_BackToMainWindow_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    //the current window
    close();
}

