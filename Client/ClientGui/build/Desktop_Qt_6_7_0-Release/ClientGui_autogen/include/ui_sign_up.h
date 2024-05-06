/********************************************************************************
** Form generated from reading UI file 'sign_up.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_UP_H
#define UI_SIGN_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sign_Up
{
public:
    QGroupBox *groupBox;
    QLabel *ErrorLabel;
    QPushButton *SignUpButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_9;
    QLabel *GenderLabel;
    QComboBox *GenderCompo;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_3;
    QComboBox *AgeCombo;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QLineEdit *FirstNameBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *LastNameBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLineEdit *UsernameBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *NationalIdBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_17;
    QLineEdit *MobileNumberBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLineEdit *Password1Box;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLineEdit *Password2Box;
    QLabel *label;
    QPushButton *BackToMainWindow;

    void setupUi(QDialog *Sign_Up)
    {
        if (Sign_Up->objectName().isEmpty())
            Sign_Up->setObjectName("Sign_Up");
        Sign_Up->resize(410, 675);
        groupBox = new QGroupBox(Sign_Up);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 90, 381, 531));
        ErrorLabel = new QLabel(groupBox);
        ErrorLabel->setObjectName("ErrorLabel");
        ErrorLabel->setGeometry(QRect(60, 470, 281, 51));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        ErrorLabel->setFont(font);
        ErrorLabel->setStyleSheet(QString::fromUtf8("color: red;\n"
""));
        ErrorLabel->setScaledContents(false);
        ErrorLabel->setAlignment(Qt::AlignCenter);
        ErrorLabel->setWordWrap(true);
        SignUpButton = new QPushButton(groupBox);
        SignUpButton->setObjectName("SignUpButton");
        SignUpButton->setGeometry(QRect(120, 440, 138, 25));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(220, 370, 88, 50));
        verticalLayout_9 = new QVBoxLayout(widget);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        GenderLabel = new QLabel(widget);
        GenderLabel->setObjectName("GenderLabel");
#if QT_CONFIG(accessibility)
        GenderLabel->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        GenderLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(GenderLabel);

        GenderCompo = new QComboBox(widget);
        GenderCompo->setObjectName("GenderCompo");
        GenderCompo->setMaximumSize(QSize(16777215, 650));
        GenderCompo->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));

        verticalLayout_9->addWidget(GenderCompo);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(60, 370, 88, 50));
        verticalLayout_8 = new QVBoxLayout(widget1);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");
#if QT_CONFIG(accessibility)
        label_3->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_3);

        AgeCombo = new QComboBox(widget1);
        AgeCombo->setObjectName("AgeCombo");
        AgeCombo->setMaximumSize(QSize(16777215, 650));
        AgeCombo->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
""));

        verticalLayout_8->addWidget(AgeCombo);

        widget2 = new QWidget(groupBox);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(20, 30, 341, 334));
        verticalLayout_10 = new QVBoxLayout(widget2);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_9 = new QLabel(widget2);
        label_9->setObjectName("label_9");
#if QT_CONFIG(accessibility)
        label_9->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_9);

        FirstNameBox = new QLineEdit(widget2);
        FirstNameBox->setObjectName("FirstNameBox");
        FirstNameBox->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        FirstNameBox->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(FirstNameBox);


        verticalLayout_10->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(widget2);
        label_2->setObjectName("label_2");
#if QT_CONFIG(accessibility)
        label_2->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        LastNameBox = new QLineEdit(widget2);
        LastNameBox->setObjectName("LastNameBox");
        LastNameBox->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        LastNameBox->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(LastNameBox);


        verticalLayout_10->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_8 = new QLabel(widget2);
        label_8->setObjectName("label_8");
#if QT_CONFIG(accessibility)
        label_8->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_8);

        UsernameBox = new QLineEdit(widget2);
        UsernameBox->setObjectName("UsernameBox");
        UsernameBox->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        UsernameBox->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(UsernameBox);


        verticalLayout_10->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(widget2);
        label_4->setObjectName("label_4");
#if QT_CONFIG(accessibility)
        label_4->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        NationalIdBox = new QLineEdit(widget2);
        NationalIdBox->setObjectName("NationalIdBox");
        NationalIdBox->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        NationalIdBox->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(NationalIdBox);


        verticalLayout_10->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_17 = new QLabel(widget2);
        label_17->setObjectName("label_17");
#if QT_CONFIG(accessibility)
        label_17->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_17);

        MobileNumberBox = new QLineEdit(widget2);
        MobileNumberBox->setObjectName("MobileNumberBox");
        MobileNumberBox->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        MobileNumberBox->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(MobileNumberBox);


        verticalLayout_10->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_6 = new QLabel(widget2);
        label_6->setObjectName("label_6");
#if QT_CONFIG(accessibility)
        label_6->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_6);

        Password1Box = new QLineEdit(widget2);
        Password1Box->setObjectName("Password1Box");
        Password1Box->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        Password1Box->setEchoMode(QLineEdit::Password);
        Password1Box->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(Password1Box);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_7 = new QLabel(widget2);
        label_7->setObjectName("label_7");
#if QT_CONFIG(accessibility)
        label_7->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_7);

        Password2Box = new QLineEdit(widget2);
        Password2Box->setObjectName("Password2Box");
        Password2Box->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        Password2Box->setEchoMode(QLineEdit::Password);
        Password2Box->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(Password2Box);


        horizontalLayout->addLayout(verticalLayout_7);


        verticalLayout_10->addLayout(horizontalLayout);

        label = new QLabel(Sign_Up);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 0, 181, 91));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        BackToMainWindow = new QPushButton(Sign_Up);
        BackToMainWindow->setObjectName("BackToMainWindow");
        BackToMainWindow->setGeometry(QRect(100, 630, 200, 31));

        retranslateUi(Sign_Up);

        QMetaObject::connectSlotsByName(Sign_Up);
    } // setupUi

    void retranslateUi(QDialog *Sign_Up)
    {
        Sign_Up->setWindowTitle(QCoreApplication::translate("Sign_Up", "New Wallet", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Sign_Up", "New Wallet", nullptr));
        ErrorLabel->setText(QString());
        SignUpButton->setText(QCoreApplication::translate("Sign_Up", "Make a New Wallet", nullptr));
        GenderLabel->setText(QCoreApplication::translate("Sign_Up", "Gender", nullptr));
        label_3->setText(QCoreApplication::translate("Sign_Up", "Age", nullptr));
        label_9->setText(QCoreApplication::translate("Sign_Up", "First Name", nullptr));
        FirstNameBox->setPlaceholderText(QCoreApplication::translate("Sign_Up", "Enter your first name", nullptr));
        label_2->setText(QCoreApplication::translate("Sign_Up", "Last Name", nullptr));
        LastNameBox->setPlaceholderText(QCoreApplication::translate("Sign_Up", "Enter your Last Name", nullptr));
        label_8->setText(QCoreApplication::translate("Sign_Up", "Username", nullptr));
        UsernameBox->setPlaceholderText(QCoreApplication::translate("Sign_Up", "Enter your username", nullptr));
        label_4->setText(QCoreApplication::translate("Sign_Up", "National ID", nullptr));
        NationalIdBox->setPlaceholderText(QCoreApplication::translate("Sign_Up", "Enter your national ID", nullptr));
        label_17->setText(QCoreApplication::translate("Sign_Up", "Mobile Number", nullptr));
        MobileNumberBox->setPlaceholderText(QCoreApplication::translate("Sign_Up", "Enter your mobile number", nullptr));
        label_6->setText(QCoreApplication::translate("Sign_Up", "Password", nullptr));
        Password1Box->setPlaceholderText(QCoreApplication::translate("Sign_Up", "Enter password", nullptr));
        label_7->setText(QCoreApplication::translate("Sign_Up", "Confirm Password", nullptr));
        Password2Box->setText(QString());
        Password2Box->setPlaceholderText(QCoreApplication::translate("Sign_Up", "Confirm Password", nullptr));
        label->setText(QCoreApplication::translate("Sign_Up", "Welcome to Smart Wallet", nullptr));
        BackToMainWindow->setText(QCoreApplication::translate("Sign_Up", "Back To Main Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sign_Up: public Ui_Sign_Up {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_UP_H
