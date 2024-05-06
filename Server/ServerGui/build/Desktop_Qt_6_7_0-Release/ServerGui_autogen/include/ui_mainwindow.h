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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *OperationLogs;
    QListWidget *UsersLog;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *ActiveUsers;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Label;
    QLabel *TotalDeposited;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *TotalWithdraw;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 425);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        OperationLogs = new QListWidget(centralwidget);
        OperationLogs->setObjectName("OperationLogs");
        OperationLogs->setGeometry(QRect(10, 110, 531, 241));
        OperationLogs->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        OperationLogs->setProperty("isWrapping", QVariant(false));
        OperationLogs->setWordWrap(false);
        OperationLogs->setSelectionRectVisible(true);
        UsersLog = new QListWidget(centralwidget);
        UsersLog->setObjectName("UsersLog");
        UsersLog->setGeometry(QRect(570, 110, 211, 241));
        UsersLog->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        UsersLog->setProperty("isWrapping", QVariant(false));
        UsersLog->setWordWrap(false);
        UsersLog->setSelectionRectVisible(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 10, 181, 71));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 90, 101, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(650, 90, 101, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 360, 141, 17));
        ActiveUsers = new QLabel(centralwidget);
        ActiveUsers->setObjectName("ActiveUsers");
        ActiveUsers->setGeometry(QRect(170, 360, 81, 17));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(500, 360, 272, 19));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(layoutWidget);
        Label->setObjectName("Label");

        horizontalLayout_3->addWidget(Label);

        TotalDeposited = new QLabel(layoutWidget);
        TotalDeposited->setObjectName("TotalDeposited");

        horizontalLayout_3->addWidget(TotalDeposited);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(220, 360, 264, 19));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        TotalWithdraw = new QLabel(widget);
        TotalWithdraw->setObjectName("TotalWithdraw");

        horizontalLayout->addWidget(TotalWithdraw);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Server", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome to Smart Wallet", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Operations", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Users", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "No of Active Users: ", nullptr));
        ActiveUsers->setText(QString());
        Label->setText(QCoreApplication::translate("MainWindow", "Total deposited amount.", nullptr));
        TotalDeposited->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Total withdrawn amount.", nullptr));
        TotalWithdraw->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
