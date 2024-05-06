/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignIn
{
public:
    QLabel *ErrorLabel;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *UsenameBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *PasswordBox;
    QPushButton *LoginButton;
    QLabel *label;
    QPushButton *BackToMainWindow;

    void setupUi(QDialog *SignIn)
    {
        if (SignIn->objectName().isEmpty())
            SignIn->setObjectName("SignIn");
        SignIn->resize(380, 320);
        ErrorLabel = new QLabel(SignIn);
        ErrorLabel->setObjectName("ErrorLabel");
        ErrorLabel->setGeometry(QRect(36, 229, 321, 41));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        ErrorLabel->setFont(font);
        ErrorLabel->setStyleSheet(QString::fromUtf8("color: red;\n"
""));
        ErrorLabel->setScaledContents(false);
        ErrorLabel->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(SignIn);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 80, 331, 141));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 30, 311, 95));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        UsenameBox = new QLineEdit(layoutWidget);
        UsenameBox->setObjectName("UsenameBox");
        UsenameBox->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(UsenameBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        PasswordBox = new QLineEdit(layoutWidget);
        PasswordBox->setObjectName("PasswordBox");
        PasswordBox->setEchoMode(QLineEdit::Password);
        PasswordBox->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(PasswordBox);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        LoginButton = new QPushButton(layoutWidget);
        LoginButton->setObjectName("LoginButton");

        verticalLayout_2->addWidget(LoginButton);

        label = new QLabel(SignIn);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 10, 181, 91));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        BackToMainWindow = new QPushButton(SignIn);
        BackToMainWindow->setObjectName("BackToMainWindow");
        BackToMainWindow->setGeometry(QRect(90, 280, 200, 31));

        retranslateUi(SignIn);

        QMetaObject::connectSlotsByName(SignIn);
    } // setupUi

    void retranslateUi(QDialog *SignIn)
    {
        SignIn->setWindowTitle(QCoreApplication::translate("SignIn", "SignIn", nullptr));
        ErrorLabel->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("SignIn", "Login", nullptr));
        UsenameBox->setPlaceholderText(QCoreApplication::translate("SignIn", "Enter your Username", nullptr));
        PasswordBox->setPlaceholderText(QCoreApplication::translate("SignIn", "Enter Your Password", nullptr));
        LoginButton->setText(QCoreApplication::translate("SignIn", "Login", nullptr));
        label->setText(QCoreApplication::translate("SignIn", "Welcome to Smart Wallet", nullptr));
        BackToMainWindow->setText(QCoreApplication::translate("SignIn", "Back To Main Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignIn: public Ui_SignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
