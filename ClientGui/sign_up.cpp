#include "sign_up.h"
#include "ui_sign_up.h"
#include "mainwindow.h"
#include "validator.h"
#include <QTimer>

Sign_Up::Sign_Up(QWidget *parent) : QDialog(parent), ui(new Ui::Sign_Up) {
    ui->setupUi(this);
    setFixedSize(410, 675);
    for (int i = 18; i < 100; ++i) {
        ui->AgeCombo->addItem(QString::number(i));
    }

    ui->GenderCompo->addItem("Female");
    ui->GenderCompo->addItem("Male");
}

Sign_Up::~Sign_Up() { delete ui; }

void Sign_Up::on_BackToMainWindow_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    close();
    deleteLater();
}


void Sign_Up::on_SignUpButton_clicked()
{
    Validator validator;

    std::string toCheck = ui->FirstNameBox->text().toStdString();
    if(!validator.isValidName(toCheck)){
        ui->ErrorLabel->setText("Incorrect First Name, Only Use Latters\nSize should be between 3 and 9");
        return;
    }

    toCheck = ui->LastNameBox->text().toStdString();
    if(!validator.isValidName(toCheck)){
        ui->ErrorLabel->setText("Incorrect Last Name, Only Use letters\nSize should be between 3 and 9");
        return;
    }

    toCheck = ui->UsernameBox->text().toStdString();
    if(!validator.isValidUsername(toCheck)){
        ui->ErrorLabel->setText("Invalid Username: Use only letters, numbers, and underscores\nSize should be between 3 and 15");
        return;
    }

    toCheck = ui->NationalIdBox->text().toStdString();
    if(!validator.isValidID(toCheck)){
        ui->ErrorLabel->setText("Incorrect Ntional ID\nSize should be exactly 14");
        return;
    }

    toCheck = ui->MobileNumberBox->text().toStdString();
    if(!validator.isValidMobileNumber(toCheck)){
        ui->ErrorLabel->setText("Incorrect Mobile Number\nSize should be exactly 11");
        return;
    }
    std::string toCheck2;

    toCheck2 = ui->Password1Box->text().toStdString();
    toCheck = ui->Password2Box->text().toStdString();

    if(!validator.isPasswordMatched(toCheck, toCheck2)){
        ui->ErrorLabel->setText("Passwords are not Matched");
        return;
    }

    if(!validator.isValidPassword(toCheck)){
        ui->ErrorLabel->setText("Incorrect Password\nEnsure password consists of 6 numbers");
        return;
    }
    ui->ErrorLabel->setStyleSheet("color: green;");
    ui->ErrorLabel->setText("Your Wallet Created\n Your wallet will be lanched automatically");

    QTimer::singleShot(1500, this, [this](){
        this->close();
    });

    return;
}

