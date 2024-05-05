#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./signin.h"
#include "./sign_up.h"


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setFixedSize(600, 250);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    QPixmap pix("/home/abdallah/Siemens/Gui/Client/ClientGui/wallet.png");
    int w{ui->icon->width()};
    int h{ui->icon->height()};

    ui->icon->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_CreateNewWallet_clicked()
{
    Sign_Up *signUpWindow = new Sign_Up();

    signUpWindow->show();

    close();

}


void MainWindow::on_LoginToWallet_clicked()
{
    SignIn *signInWindow = new SignIn();

    signInWindow->show();

    close();
}

