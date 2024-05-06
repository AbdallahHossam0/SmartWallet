/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <mainwindow.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This source file defines the MainWindow class, handling the main window interface for the application, including buttons for creating a new wallet and logging in.
 * ---------------------------------------------------------------------------------------------------
 */

#include "./sign_up.h"
#include "./signin.h"
#include "./ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setFixedSize(600, 250);     // disable the window to resize
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    // add an icon to the GUI
    QPixmap pix("/home/abdallah/Siemens/Gui/Client/ClientGui/wallet.png");
    int w{ui->icon->width()};
    int h{ui->icon->height()};

    ui->icon->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_CreateNewWallet_clicked() {
    Sign_Up *signUpWindow = new Sign_Up();

    signUpWindow->show();

    signUpWindow->setAttribute(Qt::WA_DeleteOnClose, true); // to free the window when it is closed

    close();
}

void MainWindow::on_LoginToWallet_clicked() {
    SignIn *signInWindow = new SignIn();

    signInWindow->show();

    signInWindow->setAttribute(Qt::WA_DeleteOnClose, true); // to free the window when it is closed

    close();
}
