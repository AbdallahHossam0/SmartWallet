/********************************************************************************
** Form generated from reading UI file 'sign_in.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_H
#define UI_SIGN_IN_H

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

class Ui_sign_in
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *LoginButton;
    QLabel *label;
    QPushButton *BackToMainWindow;
    QLabel *ErrorLabel;

    void setupUi(QDialog *sign_in)
    {
        if (sign_in->objectName().isEmpty())
            sign_in->setObjectName("sign_in");
        sign_in->resize(380, 320);
        groupBox = new QGroupBox(sign_in);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 100, 331, 141));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 30, 311, 95));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        LoginButton = new QPushButton(widget);
        LoginButton->setObjectName("LoginButton");

        verticalLayout_2->addWidget(LoginButton);

        label = new QLabel(sign_in);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 10, 181, 91));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        BackToMainWindow = new QPushButton(sign_in);
        BackToMainWindow->setObjectName("BackToMainWindow");
        BackToMainWindow->setGeometry(QRect(80, 280, 200, 31));
        ErrorLabel = new QLabel(sign_in);
        ErrorLabel->setObjectName("ErrorLabel");
        ErrorLabel->setGeometry(QRect(36, 250, 321, 20));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        ErrorLabel->setFont(font1);
        ErrorLabel->setStyleSheet(QString::fromUtf8("color: red;\n"
""));
        ErrorLabel->setScaledContents(false);
        ErrorLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(sign_in);

        QMetaObject::connectSlotsByName(sign_in);
    } // setupUi

    void retranslateUi(QDialog *sign_in)
    {
        sign_in->setWindowTitle(QCoreApplication::translate("sign_in", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("sign_in", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("sign_in", "User Name", nullptr));
        label_3->setText(QCoreApplication::translate("sign_in", "Password", nullptr));
        LoginButton->setText(QCoreApplication::translate("sign_in", "Login", nullptr));
        label->setText(QCoreApplication::translate("sign_in", "Welcome to Smart Wallet", nullptr));
        BackToMainWindow->setText(QCoreApplication::translate("sign_in", "Back To Main Window", nullptr));
        ErrorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class sign_in: public Ui_sign_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_H
