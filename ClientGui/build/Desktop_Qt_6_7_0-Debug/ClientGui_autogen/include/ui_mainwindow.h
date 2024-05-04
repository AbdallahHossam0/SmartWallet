/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *line;
    QLabel *icon;
    QPushButton *LoginToWallet;
    QPushButton *CreateNewWallet;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 250);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("wallet.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 40, 181, 91));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(230, 120, 118, 3));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        icon = new QLabel(centralwidget);
        icon->setObjectName("icon");
        icon->setGeometry(QRect(270, 10, 41, 51));
        icon->setPixmap(QPixmap(QString::fromUtf8("wallet.png")));
        LoginToWallet = new QPushButton(centralwidget);
        LoginToWallet->setObjectName("LoginToWallet");
        LoginToWallet->setGeometry(QRect(320, 150, 161, 31));
        CreateNewWallet = new QPushButton(centralwidget);
        CreateNewWallet->setObjectName("CreateNewWallet");
        CreateNewWallet->setGeometry(QRect(100, 150, 161, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Wallet", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome to Smart Wallet", nullptr));
        icon->setText(QString());
        LoginToWallet->setText(QCoreApplication::translate("MainWindow", "Login to Wallet", nullptr));
        CreateNewWallet->setText(QCoreApplication::translate("MainWindow", "Create New Wallet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
