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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wallet
{
public:
    QTabWidget *tabWidget;
    QWidget *BalanceTab;
    QLCDNumber *BalanceShow;
    QLabel *label_3;
    QWidget *Withdraw;
    QLineEdit *MoneyToWithdraw;
    QPushButton *WithdrawButton;
    QLabel *WithdrawLabel;
    QWidget *Deposite;
    QPushButton *DepositButton;
    QLineEdit *MoneyToDepositeBox;
    QLabel *DepositLabel;
    QWidget *Transfer;
    QPushButton *TransferButton;
    QLabel *TransferStatusLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *ReceiverUsernameBox;
    QLineEdit *MoneyToTransfer;
    QWidget *Logs;
    QListWidget *LogList;
    QPushButton *UndoButton;
    QPushButton *RedoButton;
    QLabel *LogLabel;
    QLabel *label;
    QLabel *GreetingLabel;
    QPushButton *RefreshButton;
    QLabel *RefreshLabel;

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
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("accessories-text-editor")));
        tabWidget->addTab(BalanceTab, icon, QString());
        Withdraw = new QWidget();
        Withdraw->setObjectName("Withdraw");
        MoneyToWithdraw = new QLineEdit(Withdraw);
        MoneyToWithdraw->setObjectName("MoneyToWithdraw");
        MoneyToWithdraw->setGeometry(QRect(120, 50, 481, 51));
        QFont font1;
        font1.setPointSize(20);
        MoneyToWithdraw->setFont(font1);
        MoneyToWithdraw->setAlignment(Qt::AlignCenter);
        WithdrawButton = new QPushButton(Withdraw);
        WithdrawButton->setObjectName("WithdrawButton");
        WithdrawButton->setGeometry(QRect(260, 140, 181, 31));
        WithdrawLabel = new QLabel(Withdraw);
        WithdrawLabel->setObjectName("WithdrawLabel");
        WithdrawLabel->setGeometry(QRect(160, 189, 401, 41));
        WithdrawLabel->setAlignment(Qt::AlignCenter);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("go-down")));
        tabWidget->addTab(Withdraw, icon1, QString());
        Deposite = new QWidget();
        Deposite->setObjectName("Deposite");
        DepositButton = new QPushButton(Deposite);
        DepositButton->setObjectName("DepositButton");
        DepositButton->setGeometry(QRect(260, 140, 181, 31));
        MoneyToDepositeBox = new QLineEdit(Deposite);
        MoneyToDepositeBox->setObjectName("MoneyToDepositeBox");
        MoneyToDepositeBox->setGeometry(QRect(160, 50, 401, 51));
        MoneyToDepositeBox->setFont(font1);
        MoneyToDepositeBox->setAlignment(Qt::AlignCenter);
        DepositLabel = new QLabel(Deposite);
        DepositLabel->setObjectName("DepositLabel");
        DepositLabel->setGeometry(QRect(170, 186, 381, 41));
        DepositLabel->setAlignment(Qt::AlignCenter);
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("go-up")));
        tabWidget->addTab(Deposite, icon2, QString());
        Transfer = new QWidget();
        Transfer->setObjectName("Transfer");
        TransferButton = new QPushButton(Transfer);
        TransferButton->setObjectName("TransferButton");
        TransferButton->setGeometry(QRect(270, 160, 181, 31));
        TransferStatusLabel = new QLabel(Transfer);
        TransferStatusLabel->setObjectName("TransferStatusLabel");
        TransferStatusLabel->setGeometry(QRect(180, 200, 381, 41));
        TransferStatusLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(Transfer);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(170, 20, 391, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ReceiverUsernameBox = new QLineEdit(layoutWidget);
        ReceiverUsernameBox->setObjectName("ReceiverUsernameBox");
        QFont font2;
        font2.setPointSize(18);
        ReceiverUsernameBox->setFont(font2);
        ReceiverUsernameBox->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ReceiverUsernameBox);

        MoneyToTransfer = new QLineEdit(layoutWidget);
        MoneyToTransfer->setObjectName("MoneyToTransfer");
        MoneyToTransfer->setFont(font1);
        MoneyToTransfer->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(MoneyToTransfer);

        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("go-next")));
        tabWidget->addTab(Transfer, icon3, QString());
        Logs = new QWidget();
        Logs->setObjectName("Logs");
        LogList = new QListWidget(Logs);
        LogList->setObjectName("LogList");
        LogList->setGeometry(QRect(10, 10, 721, 171));
        LogList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        LogList->setProperty("isWrapping", QVariant(false));
        LogList->setWordWrap(false);
        LogList->setSelectionRectVisible(true);
        UndoButton = new QPushButton(Logs);
        UndoButton->setObjectName("UndoButton");
        UndoButton->setGeometry(QRect(440, 220, 131, 31));
        RedoButton = new QPushButton(Logs);
        RedoButton->setObjectName("RedoButton");
        RedoButton->setGeometry(QRect(140, 220, 131, 31));
        LogLabel = new QLabel(Logs);
        LogLabel->setObjectName("LogLabel");
        LogLabel->setGeometry(QRect(40, 190, 671, 17));
        LogLabel->setAlignment(Qt::AlignCenter);
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("text-x-script")));
        tabWidget->addTab(Logs, icon4, QString());
        label = new QLabel(Wallet);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 0, 181, 91));
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        GreetingLabel = new QLabel(Wallet);
        GreetingLabel->setObjectName("GreetingLabel");
        GreetingLabel->setGeometry(QRect(10, 0, 331, 61));
        QFont font3;
        font3.setPointSize(16);
        GreetingLabel->setFont(font3);
        GreetingLabel->setAlignment(Qt::AlignCenter);
        GreetingLabel->setWordWrap(true);
        RefreshButton = new QPushButton(Wallet);
        RefreshButton->setObjectName("RefreshButton");
        RefreshButton->setGeometry(QRect(0, 80, 89, 25));
        RefreshLabel = new QLabel(Wallet);
        RefreshLabel->setObjectName("RefreshLabel");
        RefreshLabel->setGeometry(QRect(100, 80, 81, 21));

        retranslateUi(Wallet);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Wallet);
    } // setupUi

    void retranslateUi(QDialog *Wallet)
    {
        Wallet->setWindowTitle(QCoreApplication::translate("Wallet", "Wallet", nullptr));
        label_3->setText(QCoreApplication::translate("Wallet", "$", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(BalanceTab), QCoreApplication::translate("Wallet", "Balance ", nullptr));
        MoneyToWithdraw->setPlaceholderText(QCoreApplication::translate("Wallet", "Enter Amount to withdraw", nullptr));
        WithdrawButton->setText(QCoreApplication::translate("Wallet", "Withdraw", nullptr));
        WithdrawLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Withdraw), QCoreApplication::translate("Wallet", "Withdraw", nullptr));
        DepositButton->setText(QCoreApplication::translate("Wallet", "Deposit", nullptr));
        MoneyToDepositeBox->setPlaceholderText(QCoreApplication::translate("Wallet", "Enter Money to Deposit", nullptr));
        DepositLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Deposite), QCoreApplication::translate("Wallet", "Deposit", nullptr));
        TransferButton->setText(QCoreApplication::translate("Wallet", "Transfer", nullptr));
        TransferStatusLabel->setText(QString());
        ReceiverUsernameBox->setPlaceholderText(QCoreApplication::translate("Wallet", "Enter Username", nullptr));
        MoneyToTransfer->setPlaceholderText(QCoreApplication::translate("Wallet", "Enter the Amount of Money", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Transfer), QCoreApplication::translate("Wallet", "Transfer", nullptr));
        UndoButton->setText(QCoreApplication::translate("Wallet", "Undo", nullptr));
        RedoButton->setText(QCoreApplication::translate("Wallet", "Redo", nullptr));
        LogLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Logs), QCoreApplication::translate("Wallet", "Account Logs", nullptr));
        label->setText(QCoreApplication::translate("Wallet", "Welcome to Smart Wallet", nullptr));
        GreetingLabel->setText(QCoreApplication::translate("Wallet", "Hello, Mr. Abdallah Hossam", nullptr));
        RefreshButton->setText(QCoreApplication::translate("Wallet", "Refresh", nullptr));
        RefreshLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Wallet: public Ui_Wallet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WALLET_H
