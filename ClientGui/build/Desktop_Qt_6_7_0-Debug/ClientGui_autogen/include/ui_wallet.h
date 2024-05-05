/********************************************************************************
** Form generated from reading UI file 'wallet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WALLET_H
#define UI_WALLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wallet
{
public:
    QTabWidget *tabWidget;
    QWidget *BalanceTab;
    QLCDNumber *BalanceShow;
    QLabel *label_3;
    QWidget *tab_2;
    QLineEdit *WithdrawBox;
    QPushButton *pushButton;
    QLabel *label_4;
    QWidget *tab;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QWidget *tab_4;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QWidget *tab_3;
    QTextEdit *textEdit;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *icon;
    QLabel *label_2;

    void setupUi(QDialog *Wallet)
    {
        if (Wallet->objectName().isEmpty())
            Wallet->setObjectName("Wallet");
        Wallet->resize(757, 418);
        tabWidget = new QTabWidget(Wallet);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 110, 751, 291));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    min-width: 150px; /* Adjust the minimum width as needed */\n"
"}\n"
""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(25, 25));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        BalanceTab = new QWidget();
        BalanceTab->setObjectName("BalanceTab");
        BalanceShow = new QLCDNumber(BalanceTab);
        BalanceShow->setObjectName("BalanceShow");
        BalanceShow->setGeometry(QRect(30, 40, 591, 131));
        BalanceShow->setSmallDecimalPoint(false);
        BalanceShow->setDigitCount(10);
        BalanceShow->setSegmentStyle(QLCDNumber::Filled);
        BalanceShow->setProperty("value", QVariant(353.000000000000000));
        BalanceShow->setProperty("intValue", QVariant(353));
        label_3 = new QLabel(BalanceTab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(640, 40, 71, 121));
        QFont font;
        font.setPointSize(100);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("accessories-text-editor")));
        tabWidget->addTab(BalanceTab, icon1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        WithdrawBox = new QLineEdit(tab_2);
        WithdrawBox->setObjectName("WithdrawBox");
        WithdrawBox->setGeometry(QRect(160, 50, 401, 51));
        QFont font1;
        font1.setPointSize(20);
        WithdrawBox->setFont(font1);
        WithdrawBox->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 140, 181, 31));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 189, 401, 41));
        label_4->setAlignment(Qt::AlignCenter);
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("go-down")));
        tabWidget->addTab(tab_2, icon2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(260, 140, 181, 31));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(160, 50, 401, 51));
        lineEdit_2->setFont(font1);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 186, 381, 41));
        label_5->setAlignment(Qt::AlignCenter);
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("go-up")));
        tabWidget->addTab(tab, icon3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(270, 160, 181, 31));
        lineEdit_3 = new QLineEdit(tab_4);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(170, 20, 401, 51));
        QFont font2;
        font2.setPointSize(18);
        lineEdit_3->setFont(font2);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(tab_4);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(170, 90, 401, 51));
        lineEdit_4->setFont(font1);
        lineEdit_4->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(tab_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, 200, 381, 41));
        label_6->setAlignment(Qt::AlignCenter);
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("go-next")));
        tabWidget->addTab(tab_4, icon4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 10, 291, 231));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setReadOnly(true);
        listWidget = new QListWidget(tab_3);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(450, 60, 256, 192));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listWidget->setProperty("isWrapping", QVariant(false));
        listWidget->setWordWrap(false);
        listWidget->setSelectionRectVisible(true);
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("text-x-script")));
        tabWidget->addTab(tab_3, icon5, QString());
        label = new QLabel(Wallet);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 0, 181, 91));
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        icon = new QLabel(Wallet);
        icon->setObjectName("icon");
        icon->setGeometry(QRect(510, 20, 41, 51));
        icon->setPixmap(QPixmap(QString::fromUtf8("wallet.png")));
        label_2 = new QLabel(Wallet);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 331, 61));
        QFont font3;
        font3.setPointSize(16);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        retranslateUi(Wallet);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Wallet);
    } // setupUi

    void retranslateUi(QDialog *Wallet)
    {
        Wallet->setWindowTitle(QCoreApplication::translate("Wallet", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Wallet", "$", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(BalanceTab), QCoreApplication::translate("Wallet", "Balance ", nullptr));
        WithdrawBox->setPlaceholderText(QCoreApplication::translate("Wallet", "Enter Amount to withdraw", nullptr));
        pushButton->setText(QCoreApplication::translate("Wallet", "Withdraw", nullptr));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Wallet", "Withdraw", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Wallet", "Deposit", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Wallet", "Enter amount to Deposit", nullptr));
        label_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Wallet", "Deposit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Wallet", "Transfer", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("Wallet", "Enter Username", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("Wallet", "Enter the Amount of Money", nullptr));
        label_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Wallet", "Transfer", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Wallet", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Wallet", "Abdallah", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Wallet", "cdlkncldmclkdmlkcnlkdnclkdnlckndlknclkdncldnclndjncldkncjdncd", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Wallet", "Account Logs", nullptr));
        label->setText(QCoreApplication::translate("Wallet", "Welcome to Smart Wallet", nullptr));
        icon->setText(QString());
        label_2->setText(QCoreApplication::translate("Wallet", "Hello, Mr. Abdallah Hossam", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wallet: public Ui_Wallet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WALLET_H
